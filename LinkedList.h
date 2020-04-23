#pragma once
template<typename T>
class LinkedList
{
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext=nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T> *head;	
public:
	int Size;
	LinkedList()
	{
		Size = 0;
		head = nullptr;
	}
	void Add(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T> *current = this->head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = new Node<T>(data);
		}
		Size++; 
	}
	T& operator[](const int index)
	{
		int counter = 0;
		Node<T> *current = this->head;
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
	void RemoveDuples()
	{
		Node<T>* t, * p, * i, * prev;
		for (p = head; p != nullptr; p = p->pNext)
		{
			prev = p;
			for (i = p->pNext; i != nullptr; )
			{
				if (i->data == p->data)
				{
					t = prev->pNext = i->pNext;
					free(i);
					i = t;
					Size--;
					continue;
				}
				prev = i;
				i = i->pNext;
			}
		}
	}
	T FindFromEnd(int k)
	{
		Node<T> *first = head;
		Node<T> *second = head;
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
	void Clear()
	{
		while (Size)
		{
			Node<T>* temp = head;
			head = head->pNext;
			delete temp;
			Size--;
		}
	}
};

