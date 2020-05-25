#pragma once
#include <fstream>
using namespace std;
class MatrixBase
{
protected:
	MatrixBase(unsigned int iSize);
	int** matrix = nullptr;
private:
	unsigned int m_size;
public:
	unsigned int size() const;
	virtual int element(unsigned int i, unsigned int j) const;
	virtual int& elementAddress(unsigned int i, unsigned int j);
	void operator*=(int iMult);
	void operator+=(MatrixBase iAdd);
	friend ostream& operator<<(ostream& os, MatrixBase& iMatrix); // для работы cout необходимо было указать ostream вместо ofstream
};

