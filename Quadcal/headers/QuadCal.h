#ifndef QUADCAL_H
#define QUADCAL_H

#include <iostream>

class QuadCal{
    public:
    QuadCal(double a, double b, double c);
    void calDiscriminant();
    void calRoots();
    void mkEqn();
    std::wstring mkEqn(char y);
    void mkRange();
    void mkMinOrMax();
    void mkNature();
    std::wstring getEquation(char y);
    void mkCode();
    std::string Run();
    std::string Run(char y);
    void QuickRun();
    std::string handleRoots(double root);

//getters
    double* getRoots();
    /*
    This returns a pointer that directs to an array
    This array contains two values
    The first value is the root with the highest value
    The second value is the root with the lowest value
    Note that these roots exists considering the equation that is passed to this class actually has real roots
    Unless these values will be null
    */
   double getRoot(int i);
    /*
    Here also similar to above, 
    this returns only one root depending on the integer argument passed
    this argument only can be either 1 or 0
    Where these are similar to the index of the roots array
    similar to above this will raise an error if the root does not exist or a variable other than 1 or 0 is passed
   */
    double getDiscriminant();
    std::string getEquation();
    std::string getNature();
    std::string getRange();
    std::string getMinOrMax();
    int getCode();

    private:
    //primary members
    double a;
    double b;
    double c;
    double discriminant;
    double roots[2];
    std::string format(double input);
    std::wstring format(double input, char y);

    //secondary members
    int code = -1;
    std::string equation;
    std::string nature;
    std::string range;
    std::string MinOrMax;
};

#endif