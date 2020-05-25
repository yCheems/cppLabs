#include "iostream"
using namespace std;
int Max(int* fp, int* lp)
{
	for (int i = 0; i < 6; i++)
	{
		if (fp == lp)
		{
			return *fp;
		}
		int p = *fp;
		fp++;
		if (p > * fp)
		{
			int q = p;
			p = *fp;
			*fp = q;
		}
	}
}
void Sort(int* fp, int* lp)
{	
	while (fp != lp)
	{
		int* p = fp;
		while (p <= lp)
		{
			int* pw = p;
			if (p == lp) break;
			p++;
			if (*pw > *p)
			{
				int t = *p;
				*p = *pw;
				*pw = t;
			}
		}
		lp--;
	}
}
int main()
{
	int A[6]{ 2, 1, 5, 4, 10, 8 };
	int* fp = &A[0];
	int* lp = &A[5];	
	Sort(fp, lp);
	cout << Max(fp, lp) << endl;
	for (int i = 0; i <= 5; i++)
		cout << A[i] << ' ';
	return 0;
}

