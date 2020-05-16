//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------
#endif

#include "Stack.h"

template <typename T>
class HashTable {
protected:
	int key;							//размер таблицы
	int freeSlots;
	Stack<T> *table;					//массив стеков
	int h1(int key);
	int h2(int key);

public:
	HashTable(int size);
	~HashTable();
    int GetFreeSlots() { return freeSlots; }
	void Insert(int key, T data);
	int Search(int key);
	void Remove(int key);
	int GetSize() { return key; }		//получить размер таблицы
	int GetKey(int index);              //получить ключ €чейки
	bool isNull(int index);				//проверка на пустоту index'го стека
	void ShowKeyData(TMemo *Memo, int key);
	void ShowTableKeys(TMemo *Memo);
};

template<typename T>
HashTable<T>::HashTable(int size)
{
	freeSlots = key = size;
	table = new Stack<T>[key];

	for (int i = 0; i < key; i++)
	{
		table[i].isNull = true;
	}
}

template<typename T>
HashTable<T>::~HashTable()
{
	for (int i = 0; i < i < key; i++)
	{
		table[i].Clear();
	}
}

template<typename T>
int HashTable<T>::h1(int key)
{
	return key % this->key;
}

template<typename T>
int HashTable<T>::h2(int key)
{
	return 7 - key % 7;
}

template<typename T>
void HashTable<T>::Insert(int key, T data)
{
	int x = h1(key);
	int y = h2(key);

	for (int i = 0; i < this->key; i++)
	{
		if (key == table[x].key)
		{
			table[x].Push(data);
			return;
		}
		x = (x + y) % this->key;
	}

	x = h1(key);

	if(!freeSlots) return;
	for (int i = 0; i < this->key; i++)
	{
		if (table[x].isNull)
		{
			freeSlots--;
			table[x].key = key;
			table[x].Push(data);
			return;
		}
		x = (x + y) % this->key;
	}
}

template<typename T>
int HashTable<T>::Search(int key)
{
	int x = h1(key);
	int y = h2(key);

	for (int i = 0; i < this->key && !table[x].isNull; i++)
	{
		if (key == table[x].key)
		{
			return x;
		}
		x = (x + y) % this->key;
	}

	return -1;
}

template<typename T>
void HashTable<T>::Remove(int key)
{
	int x = h1(key);
	int y = h2(key);

	for (int i = 0; i < this->key; i++)
	{
		if (key == table[x].key)
		{
            freeSlots++;
			table[x].Clear();
            return;
		}
		x = (x + y) % this->key;
	}
}

template<typename T>
int HashTable<T>::GetKey(int index)
{
	if (!table[index].isNull)
	{
		return table[index].key;
    }
}

template<typename T>
bool HashTable<T>::isNull(int index)
{
	return table[index].isNull;
}

template<typename T>
void HashTable<T>::ShowKeyData(TMemo *Memo, int key)
{
	table[Search(key)].Show(Memo);
}

template<typename T>
void HashTable<T>::ShowTableKeys(TMemo *Memo)
{
	Memo->Clear();

	for (int i = 0; i < this->key; i++)
	{
		if(table[i].isNull)
		{
			Memo->Lines->Add("є " + IntToStr(i + 1) + " key - Empty");
		}
		else
		{
			Memo->Lines->Add("є " + IntToStr(i + 1) + " key - " + table[i].key);
		}

    }
}
