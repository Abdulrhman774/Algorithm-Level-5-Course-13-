#pragma once
#include <iostream>
using namespace std;


template <class T> class clsDynamicArray
{
protected:
	T _Size;
	T* _OriginalArray;
	T* _TempArr;
public:

	clsDynamicArray(T Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		_OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] _OriginalArray;
	}

	bool SetItem(T Index, T value)
	{
		if (Index >= _Size || Index < 0) return false;

		_OriginalArray[Index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	T Size()
	{
		return _Size;
	}

	void Resize(T NewSize)
	{
		if (NewSize < 0) NewSize = 0;

		_TempArr = new T[NewSize];

		if (NewSize < _Size) _Size = NewSize;


		for (T i = 0; i < NewSize; i++)
		{
			_TempArr[i] = _OriginalArray[i];
		}
		_Size = NewSize;
		delete[] _OriginalArray;

		_OriginalArray = _TempArr;
	}

	void Reverse()
	{
		if (IsEmpty())
			return;

		_TempArr = new T[_Size];

		for (T i = 0; i < _Size; i++)
		{
			_TempArr[i] = _OriginalArray[(_Size - 1) - i];
		}
		delete[] _OriginalArray;
		_OriginalArray = _TempArr;
	}

	bool DeleteItemAt(T Index)
	{
		if (IsEmpty() || ((Index < 0) || (Index >= _Size)))
			return false;

		_Size--;
		_TempArr = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArr[i] = _OriginalArray[i];
		}

		for (int i = Index + 1; i <= _Size; i++)
		{
			_TempArr[i - 1] = _OriginalArray[i];
		}

		delete[] _OriginalArray;
		_OriginalArray = _TempArr;
		return true;
	}

	bool DeleteFirstItem()
	{
		return DeleteItemAt(0);
	}

	bool DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}

	T GetItem(T Item)
	{
		return (Item >= 0 || Item < _Size) ? _OriginalArray[Item] : 0;
	}

	T Find(T Value)
	{
		for (short i = 0; i < _Size; i++)
		{
			if (_OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		if (IsEmpty()) return;

		T Index = Find(Value);

		if (Index == -1)
			return false;

		DeleteItemAt(Index);
		return true;
	}

	bool InsertAt(T Index, T Value)
	{
		if (Index > _Size || Index < 0) return false;

		_Size++;
		_TempArr = new T[_Size];

		for (int i = 0; i < Index; i++)
			_TempArr[i] = _OriginalArray[i];

		_TempArr[Index] = Value;

		for (int i = Index; i < _Size ; i++)
			_TempArr[i + 1] = _OriginalArray[i];


		delete[] _OriginalArray;
		_OriginalArray = _TempArr;
		return true;
	}

	bool InsertAtBeginning(T Value)
	{
		return InsertAt(0, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(T Index, T Value)
	{
		return (Index < 1) ? InsertAtBeginning(Value) : InsertAt(Index - 1, Value);
	}

	bool InsertAfter(T Index, T Value)
	{
		return (Index >= _Size) ? InsertAtEnd(Value) : InsertAt(Index + 1, Value);
	}

	void Clear()
	{
		this->Resize(0);

		// Resize حل استاذ محمد خطواته هي نفس خطوات ال 
		//_Size = 0;
		//_TempArray = new T[0];
		//delete[] OriginalArray;
		//OriginalArray = _TempArray;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << _OriginalArray[i] << " ";
			//cout << *(_OriginalArray + i) << " ";
		}
		cout << "\n";
	}
};
