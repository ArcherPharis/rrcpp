#pragma once
#include <iostream>
#include <initializer_list>
template<typename T>
class LinkedList
{
public:
	LinkedList() { init(); }
	~LinkedList()
	{
		//we need to save the current node's next node before deleting it, else rest of the nodes
		//will result in lost data/memory leak. we will loop until the node being checked is not nullptr.
		Node* currentNode = head;
		Node* nextNode = nullptr;
		while (currentNode != nullptr)
		{
			//will return a nullptr if it doesn't exist
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}

	}


	T operator[](int index)
	{
		return get(index);
	}

	T get(int index)
	{
		Node* currentNode = head;
		int count = 0;
		while (currentNode != nullptr)
		{
			if (count == index)
			{
				return currentNode->value;
			}
			//if not the correct index, iterate and check the next node on next loop.
			count++;
			currentNode = currentNode->next;
		}
	}


	void insert(int pos, const T& val)
	{
		if (pos > size)
		{
			return;
		}
		Node* nodeToInsert = head;
		for (int i = 0; i < pos; ++i)
		{
			
			nodeToInsert = nodeToInsert->next; //actually if we set at pos 0, we never reach this loop.
			//so if it's 1, we grab the head's next. which is the node in zeroth position. which is now nodetoinstert
		}

		Node* newNode = new Node(val, nullptr, nullptr); //create a newNode.
		newNode->prev = nodeToInsert;  //since we never reached anywhere, newnode's previous is the head.
		//IF > 0 since we're inserting at 1, its previous becomes the zeroth node.
		newNode->next = nodeToInsert->next; // newnode's next is the head's next, which was the tail.
		// IF > 0 its next becomes the zeroth's next, which was the tail.

		newNode->prev->next = newNode; // the head's next WAS the tail, its next becomes the new head.
		//IF > 0 newnodes's previous, which we set as the zeroth's next becomes the new node.
		newNode->next->prev = newNode; //the tail previous WAS the head, its previous becomes the new previous
		// IF > 0 the tail's previous USED to be the zeroth, we set it as the node.
		
		++size;
		
	}

	void remove(int pos)
	{
		if (pos > size)
		{
			return;
		}
		Node* nodeToRemove = head; 
		for (int i = 0; i < pos; ++i)
		{
			nodeToRemove = nodeToRemove->next;
			
		}

		//we need to do two main things here, set the nodeToRemove's previous's next as the nTR's next.
		// (set the node on the left's next as the whichever next is assigned to nodeToRemove)
		//and then set the nTR's next's previous as the nTR's previous, which would be the head.
		//(set the node on the right's previous as whichever previous is assigned to nodeToRemove)

		nodeToRemove ->prev->next = nodeToRemove->next;
		nodeToRemove->next->prev = nodeToRemove->prev;
		

		delete nodeToRemove;
		nodeToRemove = nullptr;
		
		--size;

	}

private:
	struct Node
	{
		T value;
		Node* next;
		Node* prev;

		Node(const T& val = {}, Node* next = nullptr, Node* prev = nullptr )
			: value{val}, next{next}, prev{prev} {}

	};

	Node* head;
	Node* tail;
	int size;

	void init()
	{
		size = 0;
		//because we had default value in constructor, no need to add values.
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		
	}

};

