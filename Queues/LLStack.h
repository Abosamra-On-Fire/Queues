#pragma once
#pragma once
#include"Node.h"
#include "StackADT.h"
template<class T>
class LLStack : public StackADT<T>
{
	Node<T>* Top;
	Node<T>* CreateNode(T X)
	{
		Node<T>* Ptr = new Node<T>(X);
		return Ptr;
	}
public:
	LLStack()
	{
		Top = NULL;
	}
	~LLStack()
	{
		while (Top)
		{
			Node<T>* Temp = Top;
			Top = Top->getNext();
			delete Temp;
		}
	}
	LLStack(LLStack<T>& L)
	{
		if (L.Top)
		{
			Top = CreateNode(L.Top->getItem());
			Node<T>* LPtr = L.Top->getNext();
			Node<T>* Ptr = Top;
			while (LPtr)
			{
				Ptr->setNext(CreateNode(LPtr->getItem()));
				Ptr = Ptr->getNext();
				LPtr = LPtr->getNext();
			}
		}
	}
	//============================================================
	virtual bool isEmpty() const
	{
		return Top == NULL;
	}
	virtual bool push(const T& newEntry)
	{
		if (!Top)
			Top = CreateNode(newEntry);
		else
		{
			Node<T>* Ptr = CreateNode(newEntry);
			Ptr->setNext(Top);
			Top = Ptr;
		}
		return true;
	}
	virtual bool pop(T& TopEntry)
	{
		if (!Top)
			return false;
		else
		{
			Node<T>* Ptr = Top;
			Top = Top->getNext();
			TopEntry = Ptr->getItem();
			delete Ptr;
			return true;
		}
	}
	virtual bool peek(T& TopEntry) const
	{
		if (!Top)
			return false;
		else
		{
			TopEntry = Top->getItem();
			return true;
		}
	}
	void Print()
	{
		Node<T>* Ptr = Top;
		while (Ptr)
		{
			std::cout << Ptr->getItem() << std::endl;
			Ptr = Ptr->getNext();
		}
	}
};