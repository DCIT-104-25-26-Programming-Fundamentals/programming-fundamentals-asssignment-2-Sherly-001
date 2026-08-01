// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// #include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int transpose[10][10], int rows, int cols);
void addMatrices(int A[10][10], int B[10][10], int sum[10][10], int rows, int cols);
void multiplyMatrices(int A[10][10], int B[10][10], int product[10][10], int rowsA, int colsA, int colsB);

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int rows, cols;
    int rowsA, colsA, rowsB, colsB;

    // ===========================
    // PART A - Transpose Matrix
    // ===========================
    cout << "PART A - Transpose Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the elements:" << endl;
    inputMatrix(A, rows, cols);

    transposeMatrix(A, B, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(A, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(B, cols, rows);

    // ===========================
    // PART B - Add Matrices
    // ===========================
    cout << "\nPART B - Add Two Matrices" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter Matrix A:" << endl;
    inputMatrix(A, rows, cols);

    cout << "Enter Matrix B:" << endl;
    inputMatrix(B, rows, cols);

    addMatrices(A, B, C, rows, cols);

    cout << "\nSum Matrix:" << endl;
    displayMatrix(C, rows, cols);

    // ===========================
    // PART C - Multiply Matrices
    // ===========================
    cout << "\nPART C - Multiply Two Matrices" << endl;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter Matrix A:" << endl;
    inputMatrix(A, rowsA, colsA);

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible." << endl;
    }
    else
    {
        cout << "Enter Matrix B:" << endl;
        inputMatrix(B, rowsB, colsB);

        multiplyMatrices(A, B, C, rowsA, colsA, colsB);

        cout << "\nProduct Matrix:" << endl;
        displayMatrix(C, rowsA, colsB);
    }

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int transpose[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to add two matrices
void addMatrices(int A[10][10], int B[10][10], int sum[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[10][10], int B[10][10], int product[10][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
// =============================================================================



