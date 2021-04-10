#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T value;
	Node<T>* ptr;
	Node<T>(T value);
};
template<typename T>
class Queue {
	Node<T>* front;
	Node<T>* rear;
	int size = 0;
public:
	T Peek();
	Queue();
	~Queue();
	int GetSize();
	Queue(T value);
	Queue(const Queue& other);
	Queue(Queue&& other);
	Queue& operator=(Queue&& other);
	Queue operator=(const Queue& other);
	template<typename T> friend ostream& operator<<(ostream& out, const Queue<T>& queue);
	void push(T value);
	T pop();
};

template<typename T>
Node<T>::Node(T value) {
	this->value = value;
	this->ptr = nullptr;
}
template<typename T>
Queue<T>::Queue() {
	this->front = nullptr;
	this->rear = nullptr;
}
template<typename T>
Queue<T>::Queue(T value) {
	this->push(value);
	this->size = 1;
}
template<typename T>
Queue<T>::~Queue() {
	while (this->size > 1) {
		this->pop();
	}
	delete rear;
}
template<typename T>
Queue<T>::Queue(const Queue& other) {
	Node* temp = other.front;
	for (int i = 1; i <= other.size; i++) {
		this->push(temp->value);
		temp = temp->ptr;
	}
}
template<typename T>
Queue<T>::Queue(Queue&& other) {
	this->front = other.front;
	this->rear = other.rear;
	this->size = other.size;
	other.front = nullptr;
	other.rear = nullptr;
	other.size = 0;
}
template<typename T>
void Queue<T>::push(const T value) {
	Node<T>* temp = new Node<T>(value);
	this->size++;
	if (rear == nullptr) {
		front = rear = temp;
		return;
	}
	this->rear->ptr = temp;
	this->rear = temp;
}
template<typename T>
T Queue<T>::pop() {
	if (front == nullptr)
		return NULL;
	this->size--;
	Node<T>* temp = front;
	this->front = front->ptr;
	if (front == nullptr)
		rear = nullptr;
	T res = temp->value;
	delete temp;
	return res;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) {
	if (this == &other) {
		return *this;
	}

	this->rear = other.rear;
	this->front = other.front;
	other.rear = nullptr;
	other.front = nullptr;
	other.size = 0;
	return *this;
}

template<typename T>
Queue<T> Queue<T>::operator=(const Queue<T>& other) {
	Node<T>* temp = other.front;
	for (int i = 1; i <= other.size; i++) {
		this->push(temp->value);
		temp = temp->ptr;
	}
	return *this;
}

template<typename T>
ostream& operator<<(ostream& out, const Queue<T>& queue) {
	Node<T>* temp = queue.front;
	out << temp->value;
	for (int i = 2; i <= queue.size; i++) {
		temp = temp->ptr;
		out << " " << temp->value;
	}
	return out;
}

template<typename T>
T Queue<T>::Peek() {
	return this->front->value;
}

template<typename T>
int Queue<T>::GetSize() {
	return this->size;
}