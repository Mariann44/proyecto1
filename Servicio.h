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



	//Metodo para imprimir los datos del servicio
	friend std::ostream& operator<<(std::ostream& os, const Servicio& servicio) {
		os << "Servicio: " << servicio.descripcion << ", Prioridad: " << servicio.prioridad << ", Area: " << servicio.Area << " \n";
		return os;
	}


	string getArea() {
		return Area;
	}
};

