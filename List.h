/*Proyecto realizado por : Valeria Mar�n Barquero y Gabriel Arguedas Soloano
*
*Estructura elaborada durante lecciones de Estructuras de Datos por el profesor Mauricio �viles
* 
* Clase abstracta List que define las funciones b�sicas de una lista
* Esta clase es gen�rica, por lo que se puede utilizar para cualquier tipo de dato.
*/

#pragma once

template <typename E>
class List {
private:
	List(const List<E>& other) {}
	void operator =(const List<E>& other) {}

public:
	List() {}
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void set(E element) = 0;
	virtual E remove() = 0;
	virtual void clear() = 0;
	virtual E getElement() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual int getSize() = 0;
	virtual int getPos() = 0;
	virtual void print() = 0;
};

