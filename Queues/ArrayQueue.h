#pragma once
#include "QueueADT.h"
#include <iostream>
template <class T>
class ArrayQueue
{
	T* Data;
	int Front;
	int Tail;
	int MaxSize;
public :
	ArrayQueue(int Size)
	{
		MaxSize = Size;
		Data = new T[Size];
		Tail = -1;
		Front = -1;
	}
	~ArrayQueue()
	{
		delete[] Data;
		Data = NULL;
	}
	ArrayQueue(ArrayQueue<T>& Q)
	{
		if (Q.Front != -1)
		{
			Front = Q.Front;
			Tail = Q.Tail;
			MaxSize = Q.MaxSize;
			Data = new T  [MaxSize];
			for (int i = 0; i < MaxSize; i++)
			{
				Data[i] = Q.Data[i];
			}
		}
	}
	virtual bool isEmpty() const
	{
		return Front == -1;
	}
	virtual bool enqueue(const T& newEntry)
	{
		if ((Tail-Front)+1 == MaxSize)
			return false;
		if (Front == -1 && Tail == -1)
		{
			Data[++Front] = newEntry;
			++Tail;
		}
		else
		{
			Tail = (Tail + 1) % MaxSize;
			Data[Tail] = newEntry;
		}
		return true;
	}
	virtual bool dequeue(T& FrontEntry)
	{
		if (Front == -1)
			return false;
		if (&Data[Front] == &Data[Tail])
		{
			FrontEntry = Data[Front];
			Front = -1;
			Tail = -1;
		}
		else
		{
			FrontEntry = Data[Front];
			Front = (Front + 1) % MaxSize;
		}
		return true;
	}
	virtual bool peek(T& FrontEntry) const
	{
		if (Front == -1)
			return false;
		else
		{
			FrontEntry = Data[Front];
			return true;
		}
	}
	void Print()
	{
		if (Front == -1)
		{
			std::cout << "Empty Queue" << std::endl;
			return;
		}
		if (&Data[Front] == &Data[Tail])
			std::cout << Data[Front];
		else
		{
			int i = Front;
			while (&Data[i] != &Data[Tail])
			{
				std::cout << Data[i] << " ";
				i++;
				i = i % MaxSize;
			} 
			std::cout << Data[Tail] << std::endl;
		}
	}
};