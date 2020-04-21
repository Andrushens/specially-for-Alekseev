//---------------------------------------------------------------------------

#ifndef myListH
#define myListH
//---------------------------------------------------------------------------
#endif

template<typename T>
	class Node {
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

template<typename T>
class List {
public:
	List();
	~List();

	void push_back(T data);//добавить элемент в конец
	void clear();//очистить список
	int GetSize() { return Size; }
	T& operator[](const int index);//перегрузка оператора []
	void pop_front();//удалить с начала
	void pop_back();//удалить с конца
	void push_front(T data);//добавить в начало
	void insert(T value, int index);//добавить на определённый индекс
	void removeAt(int index);//удалить на определённом индексе

private:
	int Size;
	Node<T> *head;

};


template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T> *current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = head;

	while (current != nullptr) {
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* temp = head;
	while (temp->pNext != nullptr)
		temp = temp->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0) {
		push_front(value);
	}
	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node<T>* NewNode = new Node<T>(value, previous->pNext);
		previous->pNext = NewNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node<T>* ToDelete = previous->pNext;
		previous->pNext = ToDelete->pNext;

		delete ToDelete;
		Size--;
	}
}
