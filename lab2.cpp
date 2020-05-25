#include "iostream"
using namespace std;
int Max(int* fp, int* lp)
{
	int* max = fp;
	while (fp != lp+1)
	{
		if (*fp > *max) max = fp;
		fp++;
	}
	return *max;
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
	cout << Max(fp, lp) << endl;
	Sort(fp, lp);	
	for (int i = 0; i <= 5; i++)
		cout << A[i] << ' ';
	return 0;
}

