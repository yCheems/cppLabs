#pragma once
#include "MatrixBase.h"
class Matrix2D : public MatrixBase
{
public:
	Matrix2D() : MatrixBase(mSize){}
	virtual int element(unsigned int i, unsigned int j) const override;
	virtual int& elementAddress(unsigned int i, unsigned int j) override;
private:
	static const int mSize = 2;
	int matrix[mSize][mSize];
};

