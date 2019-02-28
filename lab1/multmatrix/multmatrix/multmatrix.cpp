#include "pch.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
using Matrix = vector<vector<double>>;
const int MATRIX_SIZE = 3;

enum class Error
{
	FailedToOpen,
	InvalidColumnsCount,
	InvalidRowsCount,
	Ok,
};

void InitMatrix(Matrix& matrix)
{
	vector<double> currentRow(MATRIX_SIZE, 0);
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		matrix.push_back(currentRow);
	}
}

void PrintResulMatrix(Matrix& resultMatrix)
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

Error ReadMatrixFromFile(char* input, Matrix& matrix)
{
	ifstream inputFile(input);
	Error err = Error::Ok;
	string line;

	if (!inputFile.is_open())
	{
		return err = Error::FailedToOpen;
	}

	while (getline(inputFile, line))
	{

		istringstream stringIterator(line);
		matrix.push_back(vector<double>(istream_iterator<double>(stringIterator), istream_iterator<double>()));

		if (matrix.back().size() != MATRIX_SIZE)
		{
			return err = Error::InvalidColumnsCount;
		}
	}

	if (matrix.size() != MATRIX_SIZE)
	{
		return err = Error::InvalidRowsCount;
	}

	//inputFile.close();
	//PrintResulMatrix(matrix);

	return err;
}

Matrix MultipleMatrix(Matrix& matrix1, Matrix& matrix2)
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

Error PrintErrorAnswer(char* input, Matrix& matrix)
{
	Error err = ReadMatrixFromFile(input, matrix);

	if (err == Error::FailedToOpen)
	{
		cout << "Failed to open " << input << " for reading" << endl;
	}
	else if (err == Error::InvalidColumnsCount)
	{
		cout << "Wrong number of colums in " << input << endl;
	}
	else if (err == Error::InvalidRowsCount)
	{
		cout << "Wrong number of rows in " << input << endl;
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
	Error answerMatrix1 = PrintErrorAnswer(inputFile1, matrix1);

	if (answerMatrix1 == Error::Ok)
	{
		Error answerMatrix2 = PrintErrorAnswer(inputFile2, matrix2);

		if (answerMatrix2 == Error::Ok)
		{
			resultMatrix = MultipleMatrix(matrix1, matrix2);
			PrintResulMatrix(resultMatrix);
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
