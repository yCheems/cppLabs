#include <ctime>
#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int N = 10000;
int Search(int value, int *a); 
void QuickSortRec(int *p, int iFirst, int iLast);
int BSearchRec(int value, int* a, int left, int right);
int BSearch(int value, int* a, int left, int right);
int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    setlocale(LC_ALL, "Russian");
    int arra[N],someVal = -5;
    for (int i = 0; i < N; i++)
    {
        arra[i] = rand() % (10 + 10 + 1) - 10;
    }
    int index = Search(4, arra);
    if (index == -1)
        cout << endl << "Указанный элемент в данном массиве не найден." << endl;
    else
        cout << endl << "Индекс первого подходящего элемента: " << index << endl;

    int arr1[100];
    for (int i = 0; i < 100; i++)
    {
        arr1[i] = rand() % (10 - -10 + 1) + -10;        
    }
    for (int i = 0; i < 50; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    QuickSortRec(arr1, 0, 100 - 1);
    for (int i = 0; i < 50; i++)
    {
        cout << arr1[i] << " ";
    }
    start = chrono::system_clock::now();
    int SIndex = Search(someVal, arra);
    end = chrono::system_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    if (SIndex == -1)
        cout << endl << "Значение не найдено. Время поиска: " << time << endl;
    else
        cout << endl << "Search. Индекс искомого значения в массиве: " << SIndex << " Время поиска: " << time << endl;

    QuickSortRec(arra, 0, 10000 - 1);

    start = chrono::system_clock::now();
    int BSRIndex = BSearchRec(someVal, arra, 0, 10000 - 1);
    end = chrono::system_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    if (BSRIndex == -1)
        cout << "Значение не найдено. Время поиска: " << time << endl;
    else
        cout << endl << "BSearchRec. Индекс искомого значения в массиве: " << BSRIndex << " Время поиска: " << time << endl;  

    start = chrono::system_clock::now();
    int BSIndex = BSearch(someVal, arra, 0, 10000 - 1);
    end = chrono::system_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    if (BSIndex == -1)
        cout << "Значение не найдено. Время поиска: " << time << endl;
    else
        cout << endl << "BSearch. Индекс искомого значения в массиве: " << BSIndex << " Время поиска: " << time << endl;

    return 0;
}
int Search(int value, int *a)
{
    int i = 0;
    for (i; i < N; i++)
    {
        if (a[i] == value)
            break;
    }
    if (i >= N)
        i = -1;
    return i;
}
void QuickSortRec(int* p, int iFirst, int iLast)
{
    int temp;
    int holdFirst = iFirst;
    int holdLast = iLast;
    temp = p[iFirst];
    while (iFirst < iLast)
    {
        while ((p[iLast] >= temp) && (iFirst < iLast))
            iLast--;
        if (iFirst != iLast)
        {
            p[iFirst] = p[iLast];
            iFirst++;
        }
        while ((p[iFirst] <= temp) && (iFirst < iLast))
            iFirst++;
        if (iFirst != iLast)
        {
            p[iLast] = p[iFirst];
            iLast--;
        }
    }
        p[iFirst] = temp;
        temp = iFirst;
        iLast = holdLast;
        iFirst = holdFirst;
        if (iFirst < temp)
            QuickSortRec(p, iFirst, temp - 1);
        if (iLast > temp)
            QuickSortRec(p, temp + 1, iLast);  
}
int BSearchRec(int value, int *a, int left, int right)
{    
    if (right < left) return -1;
    int mid = (left + right) / 2;
    if (value == a[mid]) return mid;
    else if (a[mid] > value)
        return BSearchRec(value, a, left, mid - 1);
    else
       return BSearchRec(value, a, mid + 1, right);    
}
int BSearch(int value, int* a, int left, int right)
{
    int mid;
    int index = 0;
    while (index > -1) {
        if (left > right)
            index = -1;
        else {
            mid = (left + right) / 2;
            if (value == a[mid]) {
                index = mid;
                break;
            }
            else  if (value < a[mid])
                right = mid - 1;
            else if (value > a[mid])
                left = mid + 1;
        }
    }
    return index;
}

