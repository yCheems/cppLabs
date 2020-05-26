#pragma once
#include <fstream>
using namespace std;
class MatrixBase
{
public:
	unsigned int size() const;
	virtual int element(unsigned int i, unsigned int j) const;
	virtual int& elementAddress(unsigned int i, unsigned int j);
	void operator*=(int iMult);
	void operator+=(MatrixBase iAdd);
	void Fill();
	friend ostream& operator<<(ostream& os, MatrixBase& iMatrix); // äëÿ ðàáîòû cout íåîáõîäèìî áûëî óêàçàòü ostream âìåñòî ofstream
private:
	unsigned int m_size;
protected:
	MatrixBase(unsigned int iSize);
	int** matrix = nullptr;
};

