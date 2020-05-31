#include "LinkedList.h"		
	LinkedList::LinkedList()
	{
		head = nullptr;
	}
	void LinkedList::Add(int data)
	{
		Node* node = new Node;
		node->data = data;
		node->pNext = nullptr;
		if (head == nullptr)
			head = node;
		else
		{
			Node* current = head;
			while (current->pNext != nullptr)
				current = current->pNext;
			current->pNext = node;
		}
	}
	void LinkedList::RemoveDuples()
	{
		Node* node = head;
		while (node != nullptr && node->pNext != nullptr)
		{
			Node* current = node;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
				if (current->data == node->data)
				{
					Node* t = head;
					while (t->pNext != current)
						t = t->pNext;
					t->pNext = current->pNext;
				};
			};
			node = node->pNext;
		};
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
	void LinkedList::printList()
	{
		Node* current = head;
		cout << current->data << "  ";
		while (current->pNext != nullptr)
		{
			current = current->pNext;
			cout << current->data << "  ";
		}
	}
	void LinkedList::Clear()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->pNext;
			delete temp;
		}
	}
