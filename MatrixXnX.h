#include <iostream>
class MatrixXnX
{
private:
	int** matrix;	
public:
	int dim;
	MatrixXnX(const int iDim);
	int element(const int i, const int j) const;
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipalDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipalDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int iCol) const;
	int maxColumn(const int iCol) const;
	void freeMemory();
};
