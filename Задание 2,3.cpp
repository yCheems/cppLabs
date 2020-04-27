// Задача 2,3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    LinkedList list;
    list.Add(2);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(3);
    list.Add(2);  
    list.Add(8);
    list.Add(4);
    list.Add(13);
    list.Add(1);
    for (int i = 0; i < list.Size; i++)
        cout << list[i] << endl;
    cout << "Четвертый элемент с конца: "<< endl << list.FindFromEnd(4) << endl;
    cout << endl;
    list.RemoveDuples();
    cout << "Список без повторений:" << endl;
    for (int i = 0; i < list.Size; i++)
        cout << list[i] << endl;
    cout <<"Второй элемент с конца: " << endl << list.FindFromEnd(2);
    list.Clear();
}
