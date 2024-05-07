/*Proyecto realizado por : Valeria Mar�n Barquero y Gabriel Arguedas Soloano
*
*Estructura elaborada durante lecciones de Estructuras de Datos por el profesor Mauricio �viles
*
*clase abstracta que define la interfaz para una cola de prioridad. 
*Esta clase es gen�rica, lo que significa que puede almacenar cualquier tipo de dato, especificado por el par�metro de plantilla E.
*
*
*
*
*/
#pragma once

template <typename E>
class PriorityQueue
{
private:
	PriorityQueue(const PriorityQueue<E>& other) {}
	void operator =(const PriorityQueue<E>& other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};

