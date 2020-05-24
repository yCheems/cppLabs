#include "LinkedList.h"		
	LinkedList::LinkedList()
	{
		Size = 0;
		head = nullptr;
	}
	void LinkedList::Add(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
		}
		else
		{
			Node* current = this->head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = new Node(data);
		}
		Size++;
	}
	int& LinkedList::operator[](const int index)
	{
		int counter = 0;
		Node* current = this->head;
		while (current != nullptr)
		{
			{
				if (counter == index)
					return current->data;
				current = current->pNext;
				counter++;
			}
		}
	}
	void LinkedList::RemoveDuples()
	{
		Node* t, * p, * i, * prev;
		for (p = head; p != nullptr; p = p->pNext)
		{
			prev = p;
			for (i = p->pNext; i != nullptr; )
			{
				if (i->data == p->data)
				{
					t = prev->pNext = i->pNext;
					delete(i);
					i = t;
					Size--;
					continue;
				}
				prev = i;
				i = i->pNext;
			}
		}
	}
	int LinkedList::FindFromEnd(int k)
	{
		Node* first = head;
		Node* second = head;
		int counter = 1;
		while (first->pNext != nullptr)
		{
			first = first->pNext;
			counter++;
			if (counter > k)
				second = second->pNext;
		}
		return second->data;
	}
	void LinkedList::Clear()
	{
		while (Size)
		{
			Node* temp = head;
			head = head->pNext;
			delete temp;
			Size--;
		}
	}
