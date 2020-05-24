#include "MatrixXnX.h"
#include <time.h>
#include <iostream>	
	MatrixXnX::MatrixXnX(const int iDim)
	{
		dim = iDim;
		matrix = new int* [iDim];
		for (int i = 0; i < iDim; i++)
			matrix[i] = new int[iDim];
		for (int i = 0; i < iDim; i++)
			for (int j = 0; j < iDim; j++)
				matrix[i][j] = 0;
	}
	int MatrixXnX::element(const int i, const int j) const
	{
		return matrix[i][j];
	}
	void MatrixXnX::fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
	}
	void MatrixXnX::setElement(const int i, const int j, const int value)
	{
		matrix[i][j] = value;
	}
	int MatrixXnX::sumPrincipalDiag() const
	{
		int result = 0;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				if (i == j)
					result = result + matrix[i][j];
		return result;
	}
	int MatrixXnX::sumSecondaryDiag() const
	{
		int result = 0;
		for (int i = 0; i < dim; i++)
			result = result + matrix[i][dim - 1 - i];
		return result;
	}
	int MatrixXnX::productPrincipalDiag() const
	{
		int result = 1;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				if (i == j)
					result = result * matrix[i][j];
		return result;
	}
	int MatrixXnX::productSecondaryDiag() const
	{
		int result = 1;
		for (int i = 0; i < dim; i++)
			result = result * matrix[i][dim - 1 - i];
		return result;
	}
	int MatrixXnX::sumRow(const int iRow) const
	{
		int result = 0;
		for (int j = 0; j < dim; j++)
			result += matrix[iRow][j];
		return result;
	}
	int MatrixXnX::minColumn(const int iCol) const
	{
		int result = INT32_MAX;
		for (int i = 0; i < dim; i++)
			if (matrix[i][iCol] < result)
				result = matrix[i][iCol];
		return result;
	}
	int MatrixXnX::maxColumn(const int iCol) const
	{
		int result = INT32_MIN;
		for (int i = 0; i < dim; i++)
			if (matrix[i][iCol] > result)
				result = matrix[i][iCol];
		return result;
	}
	void MatrixXnX::freeMemory()
	{
		for (int i = 0; i < dim; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
