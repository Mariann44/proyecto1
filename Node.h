/*Proyecto realizado por : Valeria Mar�n Barquero y Gabriel Arguedas Soloano
*
*Clase elaborada durante lecciones de Estructuras de Datos por el profesor Mauricio �viles
*
*
*
*
*
*
*/
#pragma once

template <typename E>
class Node
{
public:
	E element;
	Node<E>* next;

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}
	Node(Node<E>* next = nullptr) {
		this->next;
	}
};

