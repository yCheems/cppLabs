#include "MatrixBase.h"
#include <iostream>
using namespace std;

MatrixBase::MatrixBase(unsigned int iSize) : m_size(iSize) {}

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMulti)
{
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			elementAddress(i, j) = iMulti * element(i,j);
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	if (m_size != iAdd.size())
		throw std::exception("Для сложения необходимы матрицы одинакового размера.");
	else
		for (unsigned int i = 0; i < m_size; i++)
			for (unsigned int j = 0; j < m_size; j++)
				elementAddress(i, j) = iAdd.element(i, j) + element(i,j);
}

ostream& operator<<(ostream& os, MatrixBase& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.size(); i++)
	{
		for (unsigned int j = 0; j < iMatrix.size(); j++)
			os << iMatrix.element(i, j) << ' ';
		os << endl;
	}
	return os;
}