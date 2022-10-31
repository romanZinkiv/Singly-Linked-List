#pragma once
#include <iostream>
#include <string>
using namespace std;


template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void clear();
	void push_back(T data);
	int getSize();
	T& operator[](const int index);

	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();

private:

	template<typename T>
	class Node
	{
	public:
		Node* ptrNext;
		T data;

		Node(T data = T(), Node* ptrNext = nullptr)
		{
			this->data = data;
			this->ptrNext = ptrNext;
		}
	};

	Node<T>* head;
	int size;

};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->ptrNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;
		while (current->ptrNext != nullptr)
		{
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}

	size++;
}

template<typename T>
int List<T>::getSize()
{
	return size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->ptrNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->ptrNext);
		previous->ptrNext = newNode;

		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}
		//
		Node<T>* toDelete = previous->ptrNext;
		previous->ptrNext = toDelete->ptrNext;
		delete toDelete;

		size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);

	//if (head != nullptr)
	//{
	//	if (head->ptrNext != nullptr)
	//	{
	//		Node<T>* previous = head;
	//		while (previous->ptrNext->ptrNext != nullptr)
	//		{
	//			previous = previous->ptrNext;
	//		}

	//		delete previous->ptrNext;
	//		//previous->ptrNext = nullptr;

	//		size--;
	//	}
	//	else
	//	{
	//		pop_front();
	//	}
	//}
}