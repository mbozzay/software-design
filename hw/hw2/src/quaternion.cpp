#include "quaternion.h"



//initialize an empty quaternion
Quaternion::Quaternion(void){
    r = 0;
    x = 0;
    y = 0;
    z = 0;
}

//initialize a quaternion with args
Quaternion::Quaternion(double a, double b, double c, double d){
    r = a;
    x = b;
    y = c;
    z = d;
}

//set lhs to rhs
Quaternion Quaternion::operator=(const Quaternion rhs){
    r = rhs.r;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return(*this);
}
Quaternion Quaternion::operator+(double n){
    // Create a new quaternion with the sum of each vector as the return result
    return(Quaternion(r+n,x,y,z));
}
//add lhs to rhs
Quaternion Quaternion::operator+(const Quaternion rhs){
    // Create a new quaternion with the sum of each vector as the return result
    return (Quaternion(r + rhs.r, x + rhs.x, y + rhs.y, z + rhs.z));
}
Quaternion Quaternion::operator-(){
    // Create a new quaternion with the subtraction of each vector as the return result
    return (Quaternion(-r,-x,-y,-z));
}
Quaternion Quaternion::operator-(const Quaternion rhs){
    // Create a new quaternion with the subtraction of each vector as the return result
    return (Quaternion(r - rhs.r, x - rhs.x, y - rhs.y, z - rhs.z));
}
Quaternion Quaternion::operator*(double n){
    // Create a new quaternion with the multiplication of each vector as the return result
    return(Quaternion(r*n,x*n,y*n,z*n));
}
Quaternion Quaternion::operator*(const Quaternion rhs){
    // Create a new quaternion with the multiplication of each vector as the return result
    double lhs_r, lhs_x, lhs_y, lhs_z;
    lhs_r = r*rhs.r - (x*rhs.x + y*rhs.y + z*rhs.z);
    lhs_x = r*rhs.x + rhs.r*x + y*rhs.z - z*rhs.y;
    lhs_y = r*rhs.y + rhs.r*y - x*rhs.z + z*rhs.x;
    lhs_z = r*rhs.z + rhs.r*z + x*rhs.y - y*rhs.x; 
    return (Quaternion(lhs_r, lhs_x, lhs_y, lhs_z));
}
Quaternion Quaternion::operator/(double n){
    // Create a new quaternion with the multiplication of each vector as the return result
    return(Quaternion(r/n,x/n,y/n,z/n));
}
Quaternion Quaternion::operator/( Quaternion rhs){
    // Create a new quaternion with the multiplication of each vector as the return result
    Quaternion r = rhs.getReciprocal();
    return (*this * r);
}

// return a conjugate of this
Quaternion Quaternion::conj(){
    return(Quaternion(r,-x,-y,-z));
}

// return the real part of this
double Quaternion::getRe(){
    return(r);
}

//return the imaginary part of this at index n
double Quaternion::getIm(int n){
    if(n == 0)
        return(x);
    else if(n == 1)
        return(y);
    else if(n == 2)
        return(z);
    else
        return (0.0);
}

//get the total imaginary part of the quaternion
Quaternion Quaternion::getIm(){
    return(Quaternion(0.0, x, y, z));
}

//get euc length
double Quaternion::norm(){
    return(std::sqrt(std::pow(r,2) + std::pow(x,2) + std::pow(y,2) + std::pow(z,2)));
}

//reciprocal
Quaternion Quaternion::getReciprocal(){
    Quaternion top = this->conj();
    double bottom = 1/(std::pow(this->norm(),2));
    return(top * bottom);
}

bool Quaternion::operator!=(const Quaternion rhs){
    return(!(*this==rhs));
}
bool Quaternion::operator==(const Quaternion rhs){
    return(r == rhs.r && x == rhs.x && y == rhs.y && z == rhs.z);
}
    
//accessors
Quaternion Quaternion::getUnitVector(){
    double n = this->norm();
    return(Quaternion(r/n,x/n,y/n,z/n));
}

//output with ostream
std::ostream& operator<<(std::ostream& os, Quaternion out){
    os << "[ " << out.getRe() << " + " << out.getIm(0) << "i + " << out.getIm(1) << "j + " << out.getIm(2) << "k ]";
    return (os);
}
