#include "pch.h"
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using Matrix = array<array<double, 3>, 3>;

const int MATRIX_SIZE = 3;

enum class Error
{
	FailedToOpen,
	InvalidMatrix,
	Ok,
};

void InitMatrix(Matrix& matrix)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void PrintMatrix(const Matrix& resultMatrix)
{
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int col = 0; col < MATRIX_SIZE; col++)
		{
			cout.width(10);
			cout.setf(ios::left);
			cout << fixed << setprecision(3) << resultMatrix[row][col];
		}
		cout << endl;
	}
}

Error ReadMatrixFromFile(char* fileName, Matrix& matrix)
{
	ifstream inputFile(fileName);
	Error err = Error::Ok;

	if (!inputFile.is_open())
	{
		return err = Error::FailedToOpen;
	}

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			if (!(inputFile >> matrix[i][j]))
			{
				return err = Error::InvalidMatrix;
			}
		}
	}

	return err;
}

Matrix MultiplyMatrix(Matrix& matrix1, Matrix& matrix2)
{
	Matrix resultMatrix;
	InitMatrix(resultMatrix);

	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int col = 0; col < MATRIX_SIZE; col++)
		{
			for (int i = 0; i < MATRIX_SIZE; i++)
			{
				resultMatrix[row][col] += matrix1[row][i] * matrix2[i][col];
			}
		}
	}

	return resultMatrix;
}

Error PrintError(const char* fileName, Matrix& matrix)
{
	Error err = ReadMatrixFromFile(fileName, matrix);

	if (err == Error::FailedToOpen)
	{
		cout << "Failed to open " << fileName << " for reading" << endl;
	}
	else if (err == Error::InvalidMatrix)
	{
		cout << "In " << fileName << " entered invalid matrix \nUsage: matrix 3x3" << endl;
	}

	return err;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: multmatrix.exe <matrix file1> <matrix file2>" << endl;
		return 1;
	}

	char* inputFile1 = argv[1];
	char* inputFile2 = argv[2];
	Matrix matrix1;
	Matrix matrix2;
	Matrix resultMatrix;
	Error errorСode1 = PrintError(inputFile1, matrix1);

	if (errorСode1 == Error::Ok)
	{
		Error errorСode2 = PrintError(inputFile2, matrix2);

		if (errorСode2 == Error::Ok)
		{
			resultMatrix = MultiplyMatrix(matrix1, matrix2);
			PrintMatrix(resultMatrix);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}

	return 0;
}
