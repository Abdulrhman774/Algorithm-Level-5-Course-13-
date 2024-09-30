#pragma once
#include <iostream>
#include "clsDblLinkedList.h"


template <class T> class clsMyQueue
{
protected:

	clsDblLinkedList <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	T Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(_MyList.Size() - 1);
	}

	T GetItem(T Item)
	{
		return _MyList.GetItem(Item);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	bool UpdateItem(T Item, T NewValue)
	{
		return _MyList.UpdateItem(Item, NewValue);
	}

	bool InsertAfter(T Index, T NewValue)
	{
		return _MyList.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T NewValue)
	{
		_MyList.InsertAtBeginning(NewValue);
	}

	void InsertAtBack(T NewValue)
	{
		this->push(NewValue);
		//_MyList.InsertAtEnd(NewValue);
	}

	void Clear()
	{
		_MyList.Clear();
	}

};

