#pragma once
#include <string>

using std::string;

class Servicio
{
private: 
	string descripcion;
	int prioridad;
	string Area;


public:
	Servicio(string descripcionServicio, int prioridadServicio)
	{
		descripcion = descripcionServicio;
		prioridad = prioridadServicio;
	}
	~Servicio()
	{
	}
};

