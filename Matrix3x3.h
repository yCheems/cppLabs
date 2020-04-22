#include <iostream>
#include <time.h>
class Matrix3x3
{
public:
	int matrix[3][3] = { 
	{0,0,0},
	{0,0,0},
	{0,0,0}
	};
	int element(const int i, const int j) const
	{
		return matrix[i][j];
	}
	void setElement(const int i, const int j, const int value)
	{
		matrix[i][j] = value;
	}
	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
	}
	int sumPrincipalDiag() const
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i == j)
					result = result + matrix[i][j];
		return result;
	}
	int sumSecondaryDiag()
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
			result = result + matrix[i][3 - 1 - i];
		return result;
	}
	int productPrincipalDiag() const
	{
		int result = 1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i == j)
					result = result * matrix[i][j];
		return result;
	}
	int productSecondaryDiag() const
	{
		int result = 1;
		for (int i = 0; i < 3; i++)
			result = result * matrix[i][3 - 1 - i];
		return result;
	}
	int sumRow(const int iRow) const
	{
		int result = 0;
		for (int j = 0; j < 3; j++)
			result += matrix[iRow][j];
		return result;
	}
	int minColumn(const int iCol) const
	{
		int result = INT32_MAX;
		for (int i = 0; i < 3; i++)
			if (matrix[i][iCol] < result)
				result = matrix[i][iCol];
		return result;
	}
	int maxColumn(const int iCol) const
	{
		int result = INT32_MIN;
		for (int i = 0; i < 3; i++)
			if (matrix[i][iCol] > result)
				result = matrix[i][iCol];
		return result;
	}
};

