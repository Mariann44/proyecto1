/*Proyecto realizado por : Valeria Marín Barquero y Gabriel Arguedas Soloano
*
*
* implementación de un servicio en un sistema de colas. 
* Esta clase contiene información sobre la descripción del servicio, su prioridad, el área a la que pertenece y la cantidad de servicios realizados.
*
*funciones:
* -sumarTiquete: incrementa la cantidad de servicios realizados.
* -reset: reinicia la cantidad de servicios realizados.
* -getArea: retorna el área a la que pertenece el servicio.
* -getPrioridad: retorna la prioridad del servicio.
* -getCantidadServicios: retorna la cantidad de servicios realizados.
* -getDescripcion: retorna la descripción del servicio.
* -operator<<: sobrecarga del operador << para imprimir los datos del servicio.
* 
*
*
*
*/
#pragma once
#include <string>
#include <iostream>


using std::string;
using std::cout;
using std::endl;


class Servicio
{
private: 
	string descripcion;
	int prioridad;
	string Area;
	int cantidadServicios = 0;


public:
	Servicio(string descripcionServicio, int prioridadServicio, string Area)
	{
		descripcion = descripcionServicio;
		prioridad = prioridadServicio;
		this->Area = Area;
	}
	~Servicio()
	{
	}

	void sumarTiquete() {
		cantidadServicios++;
	}

	void reset() {
		cantidadServicios = 0;
	}


	//Metodo para imprimir los datos del servicio
	friend std::ostream& operator<<(std::ostream& os, const Servicio& servicio) {
		os << "Servicio: " << servicio.descripcion << ", Prioridad: " << servicio.prioridad << ", Area: " << servicio.Area << " \n";
		return os;
	}


	string getArea() {
		return Area;
	}

	int getPrioridad() const {
		return prioridad;
	}
	int getCantidadServicios() const {
		return cantidadServicios;
	}

	string getDescripcion() const {
		return descripcion;
	}


};

