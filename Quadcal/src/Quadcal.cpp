#include "../headers/QuadCal.h"
#include "../headers/exception.h"
#include <math.h>
#include <sstream>

QuadCal::QuadCal(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
    calDiscriminant();
    calRoots();
    mkCode();
}

//getters
double* QuadCal::getRoots(){
    double* pRoots = roots;
    return pRoots;
}
double QuadCal::getRoot(int i){
    return roots[i];
}
double QuadCal::getDiscriminant(){
    return discriminant;
}
std::string QuadCal::getEquation(){
    mkEqn();
    return equation;
}
std::string QuadCal::getNature(){
    mkNature();
    return nature;
}
std::string QuadCal::getRange(){
    mkRange();
    return range;
}
std::string QuadCal::getMinOrMax(){
    mkMinOrMax();
    return MinOrMax;
}
int QuadCal::getCode(){
    return code;
}

std::string QuadCal::format(double input){
    std::stringstream str;
    str << input;

    return str.str();
}
std::wstring QuadCal::format(double input, char y){
    std::wstringstream str;
    str << input;

    return str.str();
}

void QuadCal::calDiscriminant(){
    discriminant = ((pow(b, 2)) - (4*a*c));
}

void QuadCal::calRoots(){
    if (discriminant > 0){
        roots[0] = (-b + sqrt(discriminant)) / (2*a);
        roots[1] = (-b - sqrt(discriminant)) / (2*a);

        if (roots[0] < roots[1]) {
            double tmp;
            tmp = roots[0];
            roots[0] = roots[1];
            roots[1] = tmp;
        }
    }
    else if (discriminant == 0){
        roots[0] = (-b + sqrt(discriminant)) / (2*a);
    }
}

void QuadCal::mkEqn(){
    std::string aStr;
    std::string bStr;
    std::string cStr;
    
    if (a == 1){
        aStr = "";
    }
    else if (a == -1){
        aStr = "-";
    }
    else if(a == 0){
        throw notQuadraticException();
    }
    else{
        aStr = format(a);
    }

    if(b == 1){
        bStr = "+";
    }
    else if(b == -1){
        bStr = "-";
    }
    else if (b == 0);
    else if(b > 0){
        bStr = "+" + format(b);
    }
    else{
        bStr = format(b);
    }

    if (c == 0){
        cStr = "";
    }
    else if(c>0) {
        cStr = "+" + format(c);
    }
    else{
        cStr = format(c);
    }
    
    if (bStr.empty()){
        equation = "y="+aStr + "x\u00b2" + cStr;
    }
    else{
        equation = "y="+aStr + "x\u00b2" + bStr + "x"+cStr;
    }
}
std::wstring QuadCal::mkEqn(char y) {
    std::wstring aStr;
    std::wstring bStr;
    std::wstring cStr;
    
    if (a == 1){
        aStr = L"";
    }
    else if (a == -1){
        aStr = L"-";
    }
    else if(a == 0){
        throw notQuadraticException();
    }
    else{
        aStr = format(a, y);
    }

    if(b == 1){
        bStr = L"+";
    }
    else if(b == -1){
        bStr = L"-";
    }
    else if (b == 0);
    else if(b > 0){
        bStr = L"+" + format(b, y);
    }
    else{
        bStr = format(b, y);
    }

    if (c == 0){
        cStr = L"";
    }
    else if(c>0) {
        cStr =  L"+" + format(c, y);
    }
    else{
        cStr = format(c, y);
    }
    
    if (bStr.empty()){
        return L"y=" + aStr + L"x\u00b2" + cStr;
    }
    else{
        return L"y=" + aStr + L"x\u00b2" + bStr + L"x" + cStr;
    }
}

void QuadCal::mkRange(){
    std::string *root1 = new std::string;
    std::string *root2 = new std::string;
    *root1 = format(getRoot(0));
    *root2 = format(getRoot(1));
    if (discriminant > 0 && a > 0) {
        range = "positive in the range of " + *root1 + " < x < " + *root2;
    }
    else if (discriminant > 0 && a < 0) {
        range = "positive in the range of " + *root1 + " > x U x > "+ *root2;
    }
    else if (discriminant <0 && a > 0) {
        range = "positive for all x real";
    }
    else if (discriminant<0 && a < 0) {
        range = "negative for all x real";
    }
    else if (discriminant == 0 && a > 0){
        range = "positive for all x real and equal to zero at " + *root1;
    }
    else if (discriminant == 0 && a < 0){
        range = "negative for all x real and equal to zero at " + *root1;
    }
}

void QuadCal::mkMinOrMax(){
    if (a > 0){
        MinOrMax = "minimum";
    }
    else {
        MinOrMax = "maximum";
    }
}

void QuadCal::mkCode(){
    if (discriminant < 0) {
        code = 0;
    }
    else if (discriminant == 0) {
        code = 1;
    }
    else if (discriminant > 0) {
        code = 2;
    }
    else {
        code = -2;
    }
}

void QuadCal::mkNature(){
    if (code == 0) {
        nature = "no real roots";
    }
    else if (code == 1) {
        nature = "one coincident root";
        code = 1;
    }
    else if (code == 2) {
        nature = "two distinct real roots";
        code = 2;
    }
}

std::string QuadCal::handleRoots(double root){
    if (root > 0) {
        return " " + format(root);
    }
    else {
        return format(root);
    }
}

std::string QuadCal::Run(){
    switch (getCode()){
        case -2:
        case -1: return "Something went wrong\nError code: -1";
        break;

        case 0: return "Equation: " + getEquation() + "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature();
        break;

        case 1: return "Equation: " + getEquation() + "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature() + "\nroots: " + format(getRoot(0));
        break;

        case 2: return "Equation: " + getEquation() + "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature() + "\nroots:\t" + handleRoots(getRoot(0)) + "\n\t" + handleRoots(getRoot(1));
        break;

        default: return "something went wrong";
    }
}

std::wstring QuadCal::getEquation(char y){
    return mkEqn(y);    
}

std::string QuadCal::Run(char y){
    switch (getCode()){
        case -2:
        case -1: return "Something went wrong\nError code: -1";
        break;

        case 0: return "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature();
        break;

        case 1: return "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature() + "\nroots: " + format(getRoot(0));
        break;

        case 2: return "\nDiscriminant: " + format(discriminant) + "\nEquation has a: " + getMinOrMax() + "\nEquation is:\n\t" + getRange() + "\nEquation has " + getNature() + "\nroots:\t" + handleRoots(getRoot(0)) + "\n\t\t" + handleRoots(getRoot(1));
        break;

        default: return "something went wrong";
    }
}

void QuadCal::QuickRun(){
    std::cout << Run() << std::endl;
}