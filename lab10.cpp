#include <iostream>
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;
int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    for (unsigned int i = 0; i < m2a.size(); i++)
        for (unsigned int j = 0; j < m2a.size(); j++)
        {
            m2a.elementAddress(i, j) = 1 + j + i*2;
            m2b.elementAddress(i,j) = 1 + j + i*2;
        }
    for (unsigned int i = 0; i < m3a.size(); i++)
        for (unsigned int j = 0; j < m3a.size(); j++)
        {
            m3a.elementAddress(i, j) = 1 + j + i * 3;
            m3b.elementAddress(i, j) = 1 + j + i * 3;
        }
   cout << "m2a and m2b: "<< endl; 
   cout << m2a << endl;
   cout << m2b << endl;
   cout << "m3a and m3b: " << endl;
   cout << m3a << endl;
   cout << m3b << endl;
   m2a *= 2; 
   cout << "m2a * 2: "<< endl << m2a << endl;
   m2a += m2b;
   cout << " m2a + m2b: "<< endl << m2a << endl;
   m3a *= 4;
   cout << "m3a * 4: " << endl << m3a << endl;
   m3a += m3b;
   cout << " m3a + m3b: " << endl << m3a << endl;
   return 0;
}
