#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <iostream>
#include <cmath>


class Quaternion {
private:
    double r, x, y, z;

public:
    //constructor
    Quaternion(void);
    Quaternion(double a, double b, double c, double d);

    //math operations
    Quaternion operator=(const Quaternion rhs);
    Quaternion operator+(double n);
    Quaternion operator+(const Quaternion rhs);
    Quaternion operator-();
    Quaternion operator-(const Quaternion rhs);
    Quaternion operator*(const Quaternion rhs);
    Quaternion operator*(double n);
    Quaternion operator/(Quaternion rhs);
    Quaternion operator/(double n);

    //boolean operators
    bool operator!=(const Quaternion rhs);
    bool operator==(const Quaternion rhs);

    //accessors
    Quaternion getReciprocal();
    double getRe();
    double getIm(int n);
    Quaternion getIm();
    Quaternion conj();
    Quaternion getUnitVector();
    double norm();
    
};

//output with ostream
std::ostream& operator<<(std::ostream& os,  Quaternion ); 

#endif