#include "../headers/exception.h"

const char* notQuadraticException::what() const throw(){
    return "This is not a quadratic equation";
}

const char* notQuadraticException::moreInfo(){
    return "In a quadratic equation, the coefficient x\u00b2 can't be zero";
}

const char* RootDoesntExistException::what() const throw(){
    return "This root is imaginary or does not exist";
}