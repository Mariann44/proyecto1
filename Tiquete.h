#pragma once
#include <iostream>
#include <string>
#include "chrono"

using std::chrono::system_clock;
using std::string;


class Tiquete
{
private:
	string codigo;
	system_clock::time_point horaDeSolicitud;
	system_clock::time_point horaDeAtencion;
	int prioridad;

public:

    Tiquete(string codigoArea, int prioridadUsuario, int prioridadServicio, int consecutivo)
	{
		codigo = codigoArea + std::to_string(consecutivo + 1);
		horaDeSolicitud = system_clock::now();
        prioridad = prioridadUsuario * 10 + prioridadServicio;	
	}


	Tiquete() {
		codigo = "";
		horaDeSolicitud = system_clock::now();
		prioridad = 0;
	}

	friend std::ostream& operator<<(std::ostream& os, const Tiquete& tiquete)
	{
		os << "Codigo: " << tiquete.codigo << ", Prioridad: " << tiquete.prioridad;
		return os;
	}

};


