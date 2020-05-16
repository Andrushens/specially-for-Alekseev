//---------------------------------------------------------------------------

#include "HashTable.h"
#ifndef MyHashTableH
#define MyHashTableH
//---------------------------------------------------------------------------
#endif

template<typename T>
class MyHashTable : public HashTable<T>{
public:
	MyHashTable(int size) : HashTable<T>(size){};
	void Task();
};

template<typename T>
void MyHashTable<T>::Task()
{
	for (int i = 0; i < HashTable<T>::key; i++)
	{
		if (!(HashTable<T>::table[i].key % 2))
		{
			HashTable<T>::Remove(HashTable<T>::table[i].key);
		}
	}
}
