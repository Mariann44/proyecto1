/*Proyecto realizado por : Valeria Mar�n Barquero y Gabriel Arguedas Soloano
*
*Estructura elaborada durante lecciones de Estructuras de Datos por el profesor Mauricio �viles
*
*clase abstracta que define las funciones b�sicas de una cola
*Esta clase es gen�rica, por lo que se puede utilizar para cualquier tipo de dato.
*
*/

#pragma once

template <typename E>
class Queue
{
private:
	Queue(const Queue<E>& other) {}
	void operator =(const Queue<E>& other) {}

public:
	Queue() {}
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E frontValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};

