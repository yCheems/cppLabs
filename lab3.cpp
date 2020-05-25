#include "iostream"
using namespace std;
int Min(int* fp, int* lp)
{
	int* min = fp;
	while (fp != lp+1)
	{
		if (*fp < *min) min = fp;
		fp++;
	}
	return *min;
}
int PreMin(int* fp, int* lp)
{
	int m = Min(fp, lp);
	int* pmin = fp;
	while (fp != lp + 1)
	{
		if (*fp < *pmin && *fp > m) pmin = fp;
		fp++;
	}
	return *pmin;
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
			if (*pw > * p)
			{
				int t = *p;
				*p = *pw;
				*pw = t;
			}
		}
		lp--;
	}
}
void LostElements(int* fp, int* lp)
{
	while (fp != lp)
	{ 
		if (*(fp + 1) - *fp > 1)
			for (int i = 1; i < (*(fp + 1) - *fp); i++)
				cout << *fp + i << ' ';
	fp++;
	}
}
int main()
{
	int A[6]{ 3, 9, 1, 4, 10, 8 };
	int* fp = &A[0];
	int* lp = &A[5];
	for (int i = 0; i <= 5; i++)
		cout << A[i] << ' ';
	cout << endl << "Minimum: " << Min(fp, lp) << ' ' << "PredMinimum: " << PreMin(fp,lp) << endl;
	Sort(fp, lp);
	for (int i = 0; i <= 5; i++)
		cout << A[i] << ' ';
	cout << endl << "Lost Elemenst: ";
	LostElements(fp, lp);
	return 0;
}

