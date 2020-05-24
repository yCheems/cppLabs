#pragma once
class LinkedList
{
public:
	class Node
	{
	public:
		Node* pNext;
		int data;
		Node(int data = 0, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node* head;
	int Size;
	LinkedList();
	void Add(int data);
	int& operator[](const int index);
	void RemoveDuples();
	int FindFromEnd(int k);
	void Clear();
};

