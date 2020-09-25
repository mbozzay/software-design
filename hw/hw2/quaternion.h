#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <iostream>
#include <math.h>


class Quaternion {
private:
    double r, x, y, z;

public:
    //constructor
    Quaternion(void);
    Quaternion(double a, double b, double c, double d);

    //math operations
    Quaternion operator = (const Quaternion &rhs);
    Quaternion operator + (const Quaternion &rhs);
    Quaternion operator - (const Quaternion &rhs);
    Quaternion operator * (const Quaternion &rhs);
    Quaternion operator / (const Quaternion &rhs);

    //output with ostream
    std::ostream& operator<<(std::ostream& os, const Quaternion&); 

    //boolean operators
    bool Quaternion operator != (const Quaternion &rhs);
    bool Quaternion operator == (const Quaternion &rhs);

    //accessors
    Quaternion getReciprocal();
    double getRe();
    double getIm(int n);
    Quaternion getIm();
    Quaternion conj();
    Quaternion getUnitVector();
    double euclideanLength();


}

#endif