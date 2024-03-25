#include <iostream>
#include <conio.h>
using namespace std;
const int MAX_ROW = 100;
const int MAX_COLUM = 100;
void inputMatrix(int mat[MAX_ROW][MAX_COLUM],int rows, int cols, const string matrixName)
{
    cout << "Enter The elements of " << matrixName << endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout << matrixName << "[" << i <<"][" << j << "]:";
            cin >> mat[i][j];
        }
    }
}
void matrixAddition(const int mat1[MAX_ROW][MAX_COLUM], const int mat2[MAX_ROW][MAX_COLUM], int matAdd[MAX_ROW][MAX_COLUM], int rows, int cols)
{
    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            matAdd[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrixMul(const int mat1[MAX_ROW][MAX_COLUM], const int mat2[MAX_ROW][MAX_COLUM], int matmul[MAX_ROW][MAX_COLUM], int row1, int cols1, int row2, int cols2)
{
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            matmul[i][j] = 0;
            for(int k=0; k<cols2; k++)
            {
                matmul[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}
void matrixSubtraction(const int mat1[MAX_ROW][MAX_COLUM], const int mat2[MAX_ROW][MAX_COLUM], int matAdd[MAX_ROW][MAX_COLUM], int rows, int cols)
{
    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            matAdd[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void matrixTranspose(const int mat1[MAX_ROW][MAX_COLUM], int matTrans[MAX_ROW][MAX_COLUM], int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            matTrans[i][j] = mat1[j][i];
        }
    }
}
void displayMatrix(const int mat[MAX_ROW][MAX_COLUM], int rows, int cols, string matrixName)
{
    cout << matrixName << "is: " << endl;
    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{

    int mat1[MAX_ROW][MAX_COLUM], mat2[MAX_ROW][MAX_COLUM], matAdd[MAX_ROW][MAX_COLUM], matmul[MAX_ROW][MAX_COLUM], matTrans[MAX_ROW][MAX_COLUM];
    int row1, col1, row2, col2;
    char choice;
    cout << "Welcome to Matrix Calculator"<<endl;
    cout << "Tell me what do you want to do: " <<endl;
    cout << "A.Addition\nB.Multiplication\nC.Subtraction\nD.Transpose" <<endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    choice = toupper(choice);

    switch (choice)
    {
        case 'A':
            cout << "Enter the number of rows for 1st Matrix: ";
            cin >> row1;
            cout << "Enter the number of columns for 1st Matrix: ";
            cin >> col1;
            cout << "Enter the number of rows for 2nd Matrix: ";
            cin >> row2;
            cout << "Enter the number of columns for 2nd Matrix: ";
            cin >> col2;
            inputMatrix(mat1, row1, col1, "Matrix1");
            inputMatrix(mat2, row2, col2, "Matrix2");
            matrixAddition(mat1, mat2, matAdd, row1, col1);
            displayMatrix(mat1, row1, col1, "1st Matrix: ");
            displayMatrix(mat2, row2, col2, "2nd Matrix: ");
            displayMatrix(matAdd, row1, col1, "Addition of the Matrix: ");
            break;
        case 'B':
            cout << "Enter the number of rows for 1st Matrix: ";
            cin >> row1;
            cout << "Enter the number of columns for 1st Matrix: ";
            cin >> col1;
            cout << "Enter the number of rows for 2nd Matrix: ";
            cin >> row2;
            cout << "Enter the number of columns for 2nd Matrix: ";
            cin >> col2;
            while (col1 != row2)
            {
                cout << "Colum of 1st Matrix not equal to row of 2nd Matrix" << endl;
                cout << "Enter the Row & Colum of 1st Matrix correctly: ";
                cin >> row1 >> col1;
                cout << "Enter the Row & Colum of 2nd Matrix correctly: ";
                cin >> row2 >> col2;
            }
            inputMatrix(mat1, row1, col1, "Matrix1");
            inputMatrix(mat2, row2, col2, "Matrix2");
            matrixMul(mat1, mat2, matmul, row1, col1, row2, col2);
            displayMatrix(mat1, row1, col1, "1st Matrix: ");
            displayMatrix(mat2, row2, col2, "2nd Matrix: ");
            displayMatrix(matmul, row1, col1, "Multiplication of the Matrix: ");
            break;
        case 'C':
            cout << "Enter the number of rows for 1st Matrix: ";
            cin >> row1;
            cout << "Enter the number of columns for 1st Matrix: ";
            cin >> col1;
            cout << "Enter the number of rows for 2nd Matrix: ";
            cin >> row2;
            cout << "Enter the number of columns for 2nd Matrix: ";
            cin >> col2;
            inputMatrix(mat1, row1, col1, "Matrix1");
            inputMatrix(mat2, row2, col2, "Matrix2");
            matrixSubtraction(mat1, mat2, matAdd, row1, col1);
            displayMatrix(mat1, row1, col1, "1st Matrix: ");
            displayMatrix(mat2, row2, col2, "2nd Matrix: ");
            displayMatrix(matAdd, row1, col1, "Subtraction of the Matrix: ");
            break;
        case 'D':
            cout << "Enter The number of rows: ";
            cin >> row1;
            cout << "Enter the number of columns: ";
            cin >> col1;
            inputMatrix(mat1, row1, col1, "Matrix");
            matrixTranspose(mat1, matTrans, row1, col1);
            displayMatrix(mat1, row1, col1, "Entered Matrix: ");
            displayMatrix(matTrans, row1, col1, "Transpose Matrix:" );
            break;
    }

    cout << "Press any key to Exit" << endl;
    getch();
}