#include <time.h>
#include <iostream>
class MatrixXnX
{
	int** matrix;	
public:
	int dim;
	MatrixXnX(const int iDim)
	{
		dim = iDim;
		matrix = new int* [iDim];
		for (int i = 0; i < iDim; i++)
			matrix[i] = new int[iDim];
		for (int i = 0; i < iDim; i++)
			for (int j = 0; j < iDim; j++)
				matrix[i][j] = 0;
	}
	int element(const int i, const int j) const
	{
		return matrix[i][j];
	}
	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
	}
	void setElement(const int i, const int j, const int value)
	{
		matrix[i][j] = value;
	}
	int sumPrincipalDiag() const
	{
		int result = 0;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				if (i == j)
					result = result + matrix[i][j];
		return result;
	}
	int sumSecondaryDiag()
	{
		int result = 0;
		for (int i = 0; i < dim; i++)
			result = result + matrix[i][dim - 1 - i];
		return result;
	}
	int productPrincipalDiag() const
	{
		int result = 1;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				if (i == j)
					result = result * matrix[i][j];
		return result;
	}
	int productSecondaryDiag() const
	{
		int result = 1;
		for (int i = 0; i < dim; i++)
			result = result * matrix[i][dim - 1 - i];
		return result;
	}
	int sumRow(const int iRow) const
	{
		int result = 0;
		for (int j = 0; j < dim; j++)
			result += matrix[iRow][j];
		return result;
	}
	int minColumn(const int iCol) const
	{
		int result = INT32_MAX;
		for (int i = 0; i < dim; i++)
			if (matrix[i][iCol] < result)
				result = matrix[i][iCol];
		return result;
	}
	int maxColumn(const int iCol) const
	{
		int result = INT32_MIN;
		for (int i = 0; i < dim; i++)
			if (matrix[i][iCol] > result)
				result = matrix[i][iCol];
		return result;
	}
	void freeMemory()
	{
		for (int i = 0; i < dim; i++)
			delete[]matrix[i];        
		delete[]matrix;
	}

};

