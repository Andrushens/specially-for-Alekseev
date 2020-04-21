//---------------------------------------------------------------------------

#ifndef myQueueH
#define myQueueH
#include "queue.h"
//---------------------------------------------------------------------------
#endif

template<typename T>
class MyQueue : public Queue<T> {
public:
	MyQueue():Queue<T>(){};

	int GetIndexOfMax();//получить индес максимального элемента
	void insert(MyQueue<T> *queue, int index);//вставить новую очередь с индекса
};


template<typename T>
int MyQueue<T>::GetIndexOfMax()
{
	int indexOfMax = 0, counter = 0;

	if (MyQueue<T>::head != nullptr){
		T max = MyQueue<T>::head->data;
		Node<T>* current = MyQueue<T>::head;

		while (current->pNext != nullptr) {
			current = current->pNext;
			counter++;
			if (max < current->data) {
				max = current->data;
				indexOfMax = counter;
			}
		}
	}
	return indexOfMax;
}

template<typename T>
void MyQueue<T>::insert(MyQueue<T> *queue, int index)
{
	Node<T>* previous = MyQueue::head;

	for (int i = 0; i < index - 1; i++)
		previous = previous->pNext;

	while (queue->GetSize()) {
		previous->pNext = new Node<T>(queue->front(), previous->pNext);
		previous = previous->pNext;
		queue->pop();
		MyQueue::Size++;
	}
}
