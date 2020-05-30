#pragma once
struct Node
{
	int data;
	Node* pNext;
};
class LinkedList
{
public:	
	LinkedList();
	void Add(int data);
	void RemoveDuples();
	int FindFromEnd(int k);
	void Clear();
	void printList();
private:
	Node* head;
};

