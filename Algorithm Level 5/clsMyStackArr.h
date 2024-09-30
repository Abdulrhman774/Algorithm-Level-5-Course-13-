#pragma once
#include <iostream>
#include "clsMyQueueArr.h"

template <class T> class clsMyStackArr : public clsMyQueueArr <T>
{
public:

	void push(T Item)
	{

		clsMyQueueArr <T>::_MyDynamicArr.InsertAtBeginning(Item);
	}

	void pop()
	{
		clsMyQueueArr <T>::_MyDynamicArr.DeleteLastItem();
	}

	T Top()
	{
		return clsMyQueueArr <T>::front();
	}

	T Bottom()
	{
		return clsMyQueueArr <T>::back();
	}

	void InsertAtTop(T Value)
	{
		clsMyQueueArr <T>::InsertAtFront(Value);
	}

	void InsertAtBottom(T Value)
	{
		clsMyQueueArr <T>::InsertAtBack(Value);
	}
};

