#include "Matrix3x3.h"
#include <time.h>

	int N = 3;
	Matrix3x3::Matrix3x3() {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				matrix[i][j] = 0;
	}
	int Matrix3x3::element(const int i, const int j) const
	{
		return matrix[i][j];
	}
	void Matrix3x3::setElement(const int i, const int j, const int value)
	{
		matrix[i][j] = value;
	}
	void Matrix3x3::fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
	}
	int Matrix3x3::sumPrincipalDiag() const
	{
		int result = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i == j)
					result = result + matrix[i][j];
		return result;
	}
	int Matrix3x3::sumSecondaryDiag() const
	{
		int result = 0;
		for (int i = 0; i < N; i++)
			result = result + matrix[i][N - 1 - i];
		return result;
	}
	int Matrix3x3::productPrincipalDiag() const
	{
		int result = 1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i == j)
					result = result * matrix[i][j];
		return result;
	}
	int Matrix3x3::productSecondaryDiag() const
	{
		int result = 1;
		for (int i = 0; i < N; i++)
			result = result * matrix[i][N - 1 - i];
		return result;
	}
	int Matrix3x3::sumRow(const int iRow) const
	{
		int result = 0;
		for (int j = 0; j < N; j++)
			result += matrix[iRow][j];
		return result;
	}
	int Matrix3x3::minColumn(const int iCol) const
	{
		int result = INT32_MAX;
		for (int i = 0; i < N; i++)
			if (matrix[i][iCol] < result)
				result = matrix[i][iCol];
		return result;
	}
	int Matrix3x3::maxColumn(const int iCol) const
	{
		int result = INT32_MIN;
		for (int i = 0; i < N; i++)
			if (matrix[i][iCol] > result)
				result = matrix[i][iCol];
		return result;
	}
