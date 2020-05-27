#pragma once
#include <fstream>
using namespace std;
class MatrixBase
{
public:
	unsigned int size() const;
	virtual int element(unsigned int i, unsigned int j) const=0;
	virtual int& elementAddress(unsigned int i, unsigned int j)=0;
	void operator*=(int iMult);
	void operator+=(MatrixBase& iAdd);
	friend ostream& operator<<(ostream& os, MatrixBase& iMatrix); // для работы cout необходимо было указать ostream вместо ofstream
protected:
	MatrixBase(unsigned int iSize);	
private:
	unsigned int m_size;
};

