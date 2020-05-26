#include "MatrixBase.h"
using namespace std;
MatrixBase::MatrixBase(unsigned int iSize)
{
	m_size = iSize;
	matrix = new int* [m_size];
	for (unsigned int i = 0; i < m_size; i++)
		matrix[i] = new int[m_size];
}

unsigned int MatrixBase::size() const
{
	return m_size;
}

int MatrixBase::element(unsigned int i, unsigned int j) const
{
	return matrix[i][j];
}

int& MatrixBase::elementAddress(unsigned int i, unsigned int j)
{
	return matrix[i][j];
}

void MatrixBase::operator*=(int iMulti)
{
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			matrix[i][j] *= iMulti;
}

void MatrixBase::operator+=(MatrixBase iAdd)
{
	if (m_size != iAdd.size())
		throw std::exception("Äëÿ ñëîæåíèÿ íåîáõîäèìû ìàòðèöû îäèíàêîâîãî ðàçìåðà.");
	else
		for (unsigned int i = 0; i < m_size; i++)
			for (unsigned int j = 0; j < m_size; j++)
				matrix[i][j] += iAdd.matrix[i][j];
}

void MatrixBase::Fill()
{
	for (unsigned int i = 0; i < m_size; i++)
		for (unsigned int j = 0; j < m_size; j++)
			matrix[i][j] = 1 + j + i * m_size;
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
