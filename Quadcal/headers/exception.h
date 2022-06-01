#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class notQuadraticException : std::exception{
    const char* what() const throw();
    const char* moreInfo();
};

class RootDoesntExistException : std::exception{
    const char* what() const throw();
};

#endif