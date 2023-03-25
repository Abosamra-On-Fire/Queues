
#include "LinkedQueue.h"
#include "ArrayQueue.h"
#include "LLStack.h"
#include <Windows.h>
#include <string>
#include <iostream>
//================================================================
void RemoveDuplicates(ArrayQueue<int>& Q,int Size)
{
	if (Q.isEmpty())
		return;
	ArrayQueue<int> Aux(Size);
	int Current,Next;
	Q.dequeue(Current);
	Aux.enqueue(Current);
	while (Q.dequeue(Next))
	{
		if (Next == Current)
			continue;
		else
		{
			Aux.enqueue(Next);
			Current = Next;
		}
	}
	while (Aux.dequeue(Current))
	{
		Q.enqueue(Current);
	}
}
//================================================================
template <class T>
bool SameOrder(LLStack<T> S, ArrayQueue<T> Q)
{
	LLStack<T> Aux;
	T Temp;
	while (S.pop(Temp))
	{
		Aux.push(Temp);
	}
	while (!Aux.isEmpty())
	{
		T Temp2;
		if (Aux.pop(Temp) == Q.dequeue(Temp2))
		{
			if (Temp == Temp2)
				continue;
			else
				return false;
		}
		else
			return false;
	}
	return Aux.isEmpty() && Q.isEmpty();
}
//===============================================================
void QueueToStack(ArrayQueue<char> Q, LLStack<char>& S)
{
	char C;
	while (Q.dequeue(C))
	{
		S.push(C);
	}
}
void ReverseStack(LLStack<char>& Destination, LLStack<char> Original)
{
	char C;
	while (Original.pop(C))
	{
		Destination.push(C);
	}
}
//================================================
bool IsPalindrome(ArrayQueue<char> Q)
{
	LLStack<char> FromEnd;
	QueueToStack(Q, FromEnd);
	LLStack<char> FromBegin;
	ReverseStack(FromBegin, FromEnd);
	while (!FromBegin.isEmpty())
	{
		char C1, C2;
		FromBegin.pop(C1);
		FromEnd.pop(C2);
		if (C1 != C2)
			return false;
	}
	return true;
}
//=================================================
void Ex10()
{
	ArrayQueue<int> Inputs(100);                        // Recommended To Use LinkedList Implementation For This Problem
	int X;
	cin >> X;
	while (X != 0)
	{
		Inputs.enqueue(X);
		cin >> X;
	}
	LLStack<int> S;
	while (!Inputs.isEmpty())
	{
		int X;
		Inputs.dequeue(X);
		if (X < 0)
		{
			int Y;
			for (int i = 0; i < 5; i++)
			{
				if (S.pop(Y))
					cout << Y << " ";
				else
					throw("Play Sound");
			}
		}
		else
		{
			S.push(X);
		}
	}
}
using namespace std;
int main()
{

	// Bedo on the way 
	cout << "I want to marry her" << endl;
	cout << "wana kaman";
	Ex10();
}