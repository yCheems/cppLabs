﻿#include <iostream>
#include "MatrixBase.h"
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;
void Fill(MatrixBase& matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
        for (unsigned int j = 0; j < matrix.size(); j++)
            matrix.elementAddress(i, j) = 1 + j + i * matrix.size();
}
int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    Fill(m2a);
    Fill(m2b);
    Fill(m3a);
    Fill(m3b);
   cout << "m2a and m2b: "<< endl << m2a << endl << m2b << endl;
   cout << "m3a and m3b: " << endl << m3a << endl << m3b << endl;
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
