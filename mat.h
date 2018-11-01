// Program: CS213-2018-A2-T1-P0
// Purpose: separate class in files
// Author:  Ibrahim Ramadan 20170002
//          Athar Atef      20170005
//          Ahmed Elsayed   20170011
// Date:    22 October  2018
// Version: 2.0





#ifndef MAT_H
#define MAT_H

#include <iostream>
using namespace std;
class mat
{

private:
    int row, col ;
    int **data;

public:
    mat ();
    mat (const mat &obj);
    mat& operator=(mat obj);

    mat(int row, int col, int num[], mat& mat);
    mat operator+  (mat mat1); // mat1+mat2
    mat operator-  (mat mat1);// mat1-mat2
    mat operator+ (int scalar);//mat1+scalar
    mat operator- (int scalar);//mat1-scalar
    mat operator* (mat mat1);//mat1*mat2
    mat operator* (int saclar);//mat1*scalar



    mat operator+= ( mat mat2); //function that overload operator +=to add mat2 to mat1
    mat operator -= (mat mat2);
    mat operator+= ( int scalar);
    mat operator-= ( int scalar);
    mat operator++();
    mat operator--();


    bool operator== (mat mat2);//mat1==mat2
    bool operator!= (mat mat2);//mat1!=mat2

    bool isSquare (mat mat);
    bool isSymetric (mat mat);

    bool isIdentity (mat mat);
    mat transpose(mat mat);

    friend istream& operator>> (istream& input, mat& mat);
    friend ostream& operator<<(ostream& output, mat mat);



};

#endif // MAT_H
