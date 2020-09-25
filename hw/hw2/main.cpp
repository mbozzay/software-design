#include <iostream>
#include "quaternion.h"
using namespace std; 

void exerciseQ(); 
int main(int argc, char *argv[]) {
    exerciseQ();     
    return 0; 
} 


void exerciseQ() {
    Quaternion q[] = { Quaternion(1, 0, 0, 0), Quaternion(2, 2, 2, 2), Quaternion(0, -1, 0, 1) };     
    Quaternion q_r = Quaternion(1, 0, 0, 0);
    Quaternion q_i = Quaternion(0, 1, 0, 0);
    Quaternion q_j = Quaternion(0, 0, 1, 0);
    Quaternion q_k = Quaternion(0, 0, 0, 1);
    Quaternion q_ijk = Quaternion(0, 1, 1, 1);
    Quaternion q_rijk = Quaternion(1, 1, 1, 1);
    Quaternion q_seq = Quaternion(1, 2, 3, 4);
    double d = 2.5;
    cout << "q[0] = " << q[0] << ",  q[1] = " << q[1] << ",  q[2] = " << q[2] << endl;     
    cout << "q[0].conj() = " << q[0].conj() << ", q[1].conj() = " << q[1].conj() << ", q[2].conj() = " << q[2].conj() << endl;    
    cout << "q[0] + q[2] = " << q[0] + q[2] << endl;     
    cout << "q[1] - q_ijk = " << q[1] - q_ijk << endl;     
    cout << "q_seq == [1, 2, 3, 4] is " << (q_seq == Quaternion(1, 2, 3, 4) ? "TRUE" : "FALSE") << endl;     
    cout << "-q_rijk = " << -q_rijk << endl;     
    cout << "q[2] + 2.5 = " << q[2] + d << endl;     
    cout << "q_r * q_i = " << q_r * q_i << endl;     
    cout << "q_i * q_j = " << q_i * q_j << endl;     
    cout << "q_k * q_j = " << q_k * q_j << endl;     
    cout << "q_ijk * q_seq = " << q_ijk * q_seq << endl;     
    cout << "q[2] * 1.5 = " << q[2] * 1.5 << endl;     
    cout << "q[2] * 2 = " << q[2] * 2 << endl;     
    cout << "q[2] / 2.5 = " << q[2] / 2.5 << endl;     
    cout << "3.5 * q[2] = " << 3.5 * q[2] << endl;     
    cout << "unit vector of " << q[2] << " is " << q[2].getUnitVector() << endl;     
    cout << "norm of " << q_ijk << " is " << q_ijk.norm() << endl;     
    cout << "norm of " << q_rijk << " is " << q_rijk.norm() << endl;     
    cout << "norm of " << q_seq << " is " << q_seq.norm() << endl;    
    cout << endl << endl << endl; 
} 
