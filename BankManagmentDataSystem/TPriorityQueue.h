#pragma once
template <class T>
class TPriorityQueue {
	int size;
	T** data;
	int count;
public:
	TPriorityQueue(int size);
	~TPriorityQueue();
	void Insert(T* item);

	T* Remove();
	bool IsEmpty();
	bool IsFull();
	int Size();
};



template <class T>
TPriorityQueue<T>::TPriorityQueue(int size) :size(size) {
	data = new T * [size];
	count = 0;
}

template <class T>
TPriorityQueue<T>::~TPriorityQueue() {
}


template <class T>
void TPriorityQueue<T>::Insert(T* item) {
	// Queue is empty
	if (count == 0) {
		data[count++] = item;
	}
	else {
		int j;
		// Start at the end work backwards
		for (j = (count - 1); j >= 0; j--) {
			// If the new item is larger than current
			if (*item > * data[j]) {
				// Shift the current up
				data[j + 1] = data[j];
			}
			else {
				// Finished shifting
				break;
			}
		}

		data[j + 1] = item;
		count++;
	}
}



template <class T>
T* TPriorityQueue<T>::Remove() {
	return data[--count];
}

template <class T>
bool TPriorityQueue<T>::IsEmpty() {
	return count == 0;
}

template <class T>
bool TPriorityQueue<T>::IsFull() {
	return count == size;
}

template <class T>
int TPriorityQueue<T>::Size() {
	return size;
}