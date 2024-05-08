/*Proyecto realizado por : Valeria Marín Barquero y Gabriel Arguedas Soloano
*
*Estructura elaborada durante lecciones de Estructuras de Datos por el profesor Mauricio Áviles
*
*implementación de una cola de prioridad utilizando una lista enlazada. Hereda de la clase PriorityQueue y utiliza la clase LinkedQueue para almacenar los elementos.
* funciones:
* insert(E element, int priority) : inserta un elemento en la cola de prioridad con la prioridad dada.
* min() : retorna el elemento con la menor prioridad.
* removeMin() : remueve y retorna el elemento con la menor prioridad.
* removePriority(int priority) : remueve todos los elementos con la prioridad dada.
* clear() : remueve todos los elementos de la cola de prioridad.
* getSize() : retorna la cantidad de elementos en la cola de prioridad.
* getQueue() : retorna la lista de colas.
* isEmpty() : retorna true si la cola de prioridad está vacía.
* print() : imprime la cola de prioridad con los índices de las colas.
*
*
*
*
*/
#pragma once
#define DEFAULT_MAX_SIZE 1024


#include <iostream>
#include "PriorityQueue.h"
#include "LinkedQueue.h"


using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E>
{
private:
	LinkedQueue<E>* queues;
	int size;
	int priorities;

public: 
	LinkedPriorityQueue(int priorities = DEFAULT_MAX_SIZE) {
		queues = new LinkedQueue<E>[priorities];
		this->priorities = priorities;
		size = 0;
	}
	~LinkedPriorityQueue() {
		delete[] queues;
	}

	void insert(E element, int priority) {
		if (priority < 0 || priority >= priorities)
			throw runtime_error("Invalid priority.");
		queues[priority].enqueue(element);
		size++;
	}
	E min() {
		if (size == 0)
			throw runtime_error("Priority queue is empty.");
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty())
				return queues[i].frontValue();
		}
		throw runtime_error("Queues are empty, and they should have elements.");
	}
	E removeMin() {
		if (size == 0)
			throw runtime_error("Priority queue is empty.");
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				size--;
				return queues[i].dequeue();
			}
		}
		throw runtime_error("Queues are empty, and they should have elements.");
	}

	void removePriority(int priority) {
		if (priority < 0 || priority >= priorities)
			throw runtime_error("Invalid priority.");
		while (!queues[priority].isEmpty()) {
			queues[priority].dequeue();
			size--;
		}

		priorities--;
	}



	void clear() {
		for (int i = 0; i < priorities; i++) {
			queues[i].clear();
		}
	}
	int getSize() {
		return size;
	}

	int getPriorities() {
		return priorities;
	}


	LinkedQueue<E>* getQueue() {
		if (size==0)
			throw runtime_error("Queues are empty");
		return queues;
	}


	bool isEmpty() {
		return size == 0;
	}
	void print() {
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				cout << i << ": ";
				queues[i].print();
			}
		}
	}

	void printSinIndice() {
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty()) {
				queues[i].print();
			}
		}
	}

	


};

