#pragma once
#include <iostream>
#include "clsDynamicArray.h"

template <class T> class clsMyQueueArr
{
protected:

	clsDynamicArray <T> _MyDynamicArr;

public:

	void push(T Item)
	{
		_MyDynamicArr.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyDynamicArr.DeleteFirstItem();
	}

	void Print()
	{
		_MyDynamicArr.PrintList();
	}

	T Size()
	{
		return _MyDynamicArr.Size();
	}

	T front()
	{
		return _MyDynamicArr.GetItem(0);
	}

	T back()
	{
		return _MyDynamicArr.GetItem(_MyDynamicArr.Size() - 1);
	}

	T GetItem(T Item)
	{
		return _MyDynamicArr.GetItem(Item);
	}

	void Reverse()
	{
		_MyDynamicArr.Reverse();
	}

	bool UpdateItem(T Item, T NewValue)
	{
		return _MyDynamicArr.SetItem(Item, NewValue);
	}

	bool InsertAfter(T Index, T NewValue)
	{
		return _MyDynamicArr.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T NewValue)
	{
		_MyDynamicArr.InsertAtBeginning(NewValue);
	}

	void InsertAtBack(T NewValue)
	{
		this->push(NewValue);
		//_MyDynamicArr.InsertAtEnd(NewValue);
	}

	void Clear()
	{
		_MyDynamicArr.Clear();
	}

};

