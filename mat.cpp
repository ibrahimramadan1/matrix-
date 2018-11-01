// Program: CS213-2018-A2-T1-P0
// Purpose: separate class in files
// Author:  Ibrahim Ramadan 20170002
//          Athar Atef      20170005
//          Ahmed Elsayed   20170011
// Date:    22 October  2018
// Version: 2.0





#include "mat.h"
#include <iostream>
using namespace std;
mat::mat () {}
mat::mat (const mat &obj)
{
    row = obj.row;
    col = obj.col;
    data = new int* [obj.row];
    for (int i = 0; i < obj.row; i++) // turn pointer of pointer into 2d array
        data[i] = new int [obj.col];


    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = obj.data[i][j];
}

mat& mat:: operator=(mat obj)
{
    row = obj.row;
    col = obj.col;

    for(int i = 0;i < col;i++)
        delete data[i];
    delete [] data;

    data = new int* [obj.row];
    for (int i = 0; i < obj.row; i++) // turn pointer of pointer into 2d array
        data[i] = new int [obj.col];


    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = obj.data[i][j];
}



// student #1 :ibrahim ramadan abdou
// ID: 20170002
// G1

// Takes an array of data and stores in matrix according
// to rows and columns
mat:: mat(int row, int col, int num[], mat& mat)
{
    mat.row = row;
    mat.col = col;             //set the dimensions of new matrix


    mat.data = new int* [row];
    for (int i = 0; i < row; i++) // turn pointer of pointer into 2d array
        mat.data[i] = new int [col];


    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];      //save the data of new matrix
};



// Add 2 matrices if they have the same dimensions and return in new matrix
mat mat::operator+(mat mat1)
{
    mat mat3;
    mat3.row=mat1.row;          //create matrix to store mat1+mat2 then be returned
    mat3.col=mat1.col;


    mat3.data= new int* [mat3.row];
    for (int i = 0; i < mat3.row; i++)  //turn the pointer of pointer into 2d array
        mat3.data[i]=new int [mat3.col];

    for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat3.data[i][j] = data[i][j]+mat1.data[i][j]; // save the data of new matrix
    return mat3;//return it
}


// sub 2 matrices if they have the same dimensions and return in new matrix
mat mat::operator-(mat mat1)
{
    mat mat3;
    mat3.row=mat1.row;          //create matrix to store mat1-mat2 then be returned
    mat3.col=mat1.col;


    mat3.data= new int* [mat3.row];
    for (int i = 0; i < mat3.row; i++)      //turn the pointer of pointer into 2d array
        mat3.data[i]=new int [mat3.col];

    for (int i = 0; i < mat1.row; i++)
        for (int j = 0; j < mat1.col; j++)
            mat3.data[i][j] = data[i][j]-mat1.data[i][j];   // save the data of new matrix
    return mat3;        //return it
}


mat mat::operator+(int scalar)
{
    mat mat2;
    mat2.row=row ;              //create matrix to store mat1+scalar then be returned
    mat2.col= col;

    mat2.data= new int* [mat2.row];
    for (int i = 0; i < mat2.row; i++)          //turn the pointer of pointer into 2d array
        mat2.data[i]=new int [mat2.col];

    for (int i = 0; i < mat2.row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat2.data[i][j] = data[i][j]+scalar;        // save the data of new matrix


    return mat2;            //return it
}

mat mat::operator- (int scalar)
{
    mat mat2;
    mat2.row=row ;          //create matrix to store mat1-scalar then be returned
    mat2.col= col;

    mat2.data= new int* [mat2.row];
    for (int i = 0; i < mat2.row; i++)      //turn the pointer of pointer into 2d array
        mat2.data[i]=new int [mat2.col];

    for (int i = 0; i < mat2.row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat2.data[i][j] = data[i][j]-scalar;     // save the data of new matrix


    return mat2;            //return it

}

mat mat::operator*(int scalar)
{
    mat mat2;
    mat2.row=row ;              //create matrix to store mat1+scalar then be returned
    mat2.col= col;

    mat2.data= new int* [mat2.row];
    for (int i = 0; i < mat2.row; i++)          //turn the pointer of pointer into 2d array
        mat2.data[i]=new int [mat2.col];

    for (int i = 0; i < mat2.row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat2.data[i][j] = data[i][j]*scalar;        // save the data of new matrix


    return mat2;            //return it
}


mat mat::operator*(mat mat1)
{
    mat mat3;
    mat3.row=row;                   //create matrix to store mat1*mat2 then be returned
    mat3.col=mat1.col;


    mat3.data= new int* [mat3.row];
    for (int i = 0; i < mat3.row; i++)              //turn pointer of pointer into 2d array
        mat3.data[i]=new int [mat3.col];


    for (int i=0; i<mat3.row; i++)
        for (int j=0; j<mat3.col; j++)
            mat3.data[i][j]=0;          //set initial value of all elements 0


    for (int co=0; co<mat3.row; co++)
    {
        for (int co1=0; co1<mat3.col; co1++)
        {
            for (int co2=0; co2<col; co2++)
            {
                mat3.data[co][co1]+=data[co][co2]*mat1.data[co2][co1];      //save the data of new mat
            }
        }
    }
    return mat3;        // return it

}

//student #2: athar atef hussein
// ID: 20170005
// G1

mat mat:: operator+= (mat mat2)  //function that overload operator +=to add mat2 to mat1
{
    if(row!=mat2.row || col!=mat2.col)  //check if row of mat1 equal row of mat2 and col of mat1 equal col of mat2
    {
        cout<<"error"<<endl; //print error to the screen
    }
    else
    {
        for(int i=0; i<row; i++) //for loop that loop on the rows of the mat
        {
            for(int j=0; j<col; j++) //for loop that loop on the cols of the mat
            {
                data[i][j]+=mat2.data[i][j]; //add mat2 to mat1 and store it in mat1
            }
        }
        return *this; //return back mat1
    }
}

mat mat:: operator-= (mat mat2)  //function that overload operator -=to add mat2 to mat1
{
    if(row!=mat2.row || col!=mat2.col)  //check if row of mat1 equal row of mat2 and col of mat1 equal col of mat2
    {
        cout<<"error"<<endl; //print error to the screen
    }
    else
    {
        for(int i=0; i<row; i++) //for loop that loop on the rows of the mat
        {
            for(int j=0; j<col; j++) //for loop that loop on the cols of the mat
            {
                data[i][j]-=mat2.data[i][j]; //sub mat2 to mat1 and store it in mat1
            }
        }
        return *this; //return back mat1
    }
}


mat mat:: operator+= (int scalar)  //function that overload operator +=to add mat2 to mat1
{

    for(int i=0; i<row; i++) //for loop that loop on the rows of the mat
    {
        for(int j=0; j<col; j++) //for loop that loop on the cols of the mat
        {
            data[i][j]+=scalar; //add mat2 to mat1 and store it in mat1
        }
    }
    return *this; //return back mat1
}




mat mat ::  operator-- ()  //function that overload operator -- to subtract one from each element in the matrix
{
    mat m = *this;
    for(int i=0; i<row; i++) //for loop that loop on the rows of the matrix
    {
        for(int j=0; j<col; j++) //for loop that loop on the cols of the matrix
        {
            --data[i][j]; //subtract one from each element in the matrix
        }
    }
    return m;
}
mat mat ::  operator++ ()  //function that overload operator -- to subtract one from each element in the matrix
{
    mat m = *this;
    for(int i=0; i<row; i++) //for loop that loop on the rows of the matrix
    {
        for(int j=0; j<col; j++) //for loop that loop on the cols of the matrix
        {
            ++data[i][j]; //subtract one from each element in the matrix
        }
    }

    return m;

}


istream& operator>> (istream& input, mat& mat)
{
    cout<<"Enter no. rows and columns: "; // ask user for the no. rows and columns
    input>>mat.row>>mat.col;        //take them as input


    mat.data = new int* [mat.row];
    for (int i = 0; i < mat.row; i++)       //turn pointer of pointer into 2d array
        mat.data[i] = new int [mat.col];


    for(int i=0; i<mat.row; i++)
    {
        cout<<"Enter "<<i+1<<" row: ";
        for(int j=0; j<mat.col; j++)
        {

            input>>mat.data[i][j];      //take the data from user
        }
    }
    return input;       //return the data

}


// student #3: ahmed elsayed ali
// ID: 20170011
// G1


ostream& operator<< (ostream& output, mat mat1)
{

    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            output<<mat1.data[i][j]<<"   ";      //print the data
        }
        cout<<endl;
    }
    return output;          //return it
}






bool mat ::  operator== (mat mat2)
{
    for (int i = 0; i < mat2.col; i++)       // For loop to check the two matrices is identical or no.
        for (int j = 0; j < col; j++)
            if (data[i][j] != mat2.data[i][j]) // Condition to check if the two matrices is identical or no
                return 0;                           // and return false if condition true.
    return 1;                                       // else return true if condition false.
}



bool mat:: operator!= (mat mat2)
{
    for (int i = 0; i < col; i++)      // For loop to check the two matrices is not identical or no.
        for (int j = 0; j < mat2.col; j++)
            if (data[i][j] != mat2.data[i][j]) // Condition to check if the two matrices is not identical or no
                return 1;                           // and return true if condition true.
    return 0;                                       // else return false if condition false.
}
bool mat:: isSquare (mat mat)
{
    if (mat.row == mat.col) // Condition to check if mat square or not if the number of rows equal the number of columns.
        return 1;           // return true if the mat is square.
    return 0;               // return false if the mat is not square.
}
bool mat:: isSymetric (mat mat)
{
    if (mat.row == mat.col) // Condition to check if mat square or not if the number of rows equal the number of columns.
    {
        for (int i = 0; i < mat.row; i++) // For loop to check the mat is Symetric.
            for (int j = 0; j < i; j++)
                if (mat.data[i][j] != mat.data[j][i]) // condition to check the mat is not symetric and return false.
                    return 0;
        return 1;                                     // Else return true.
    }
    else
        return 0; // return false if the mat is not square.
}

bool mat:: isIdentity (mat mat)
{
    int flag = 1;                         // Variable to check if the mat identity or no.
    if (mat.row == mat.col)               // Condition to check if mat square or not if the number of rows equal the number of columns.
    {
        for (int i = 0; i < mat.row; i++)  // For loop to check the mat is identity.
        {
            for (int j = 0; j < mat.col; j++)
            {
                if ( i == j && mat.data[i][j]!=1)  // condition to check the mat is not identity if row equal col and the value
                {
                    // not equal 1 then the variable "flag" become 0 and will break from loop.
                    flag = 0;
                    break;
                }
                if (i != j && mat.data[i][j]!=0)   // condition to check the mat is not identity if row not equal col and the value
                {
                    // not equal 0 then the variable "flag" become 0 and will break from loop.
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1)  // condition to check the mat is identity if the variable "flag" equal 1 then the condition
            return 1;   // will be true and the mat is identity.
        else            // else the mat is not identity and return false.
            return 0;
    }
    else
        return 0;      // return false if the mat is not square.
}
//_____________________________________________________________________________________________

//Function to take mat and return new mat with the transpose

mat mat:: transpose(mat mat2)
{
    mat mat1;         //Create new mat to receive mat with the transpose.
    mat1.row=mat2.col;    // rows will be columns.
    mat1.col=mat2.row;

    mat1.data = new int* [mat1.row];         //  Construct row pointers to integers.
    for (int i = 0; i < mat2.row; i++)        // For loop to create new mat.
        mat1.data[i] = new int [mat1.col];   // For each row, construct col integers.

    for (int i = 0; i < mat2.col; i++ )       // For loop to transpose the mat.
    {
        for (int j = 0; j < mat2.row; j++)
        {
            mat1.data[i][j]=mat2.data[j][i];  // Each row will be col.
        }

    }
    return mat1;                                 // Return new mat with transpose.
}




