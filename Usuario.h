#pragma once
#include <iostream>
#include <string>

using std::string;

class Usuario
{
private:
	string descripcion;
	int prioridad;
	int cantidadTiquete = 0;

public:
	Usuario(string descripcionUsuario, int prioridadUsuario){
	descripcion = descripcionUsuario;
	prioridad = prioridadUsuario;
}

//Constructor por defecto
	Usuario() {
		descripcion = "";
		prioridad = 0;
	}

	void sumarTiquete() {
		cantidadTiquete++;

	}

	void reset() {
		cantidadTiquete = 0;
	}


//Getters y Setters
	string getDescripcion() {
		return descripcion;
	}
	int getPrioridad() {
		return prioridad;
	}
	void setDescripcion(string descripcionUsuario) {
		descripcion = descripcionUsuario;
	}
	void setPrioridad(int prioridadUsuario) {
		prioridad = prioridadUsuario;
	}
	int getCantidadTiquete() {
		return cantidadTiquete;
	}

	void printSinPrioridad() const
	{
		std::cout << "Descripcion: " << descripcion << std::endl;
	}



	// Sobrecarga del operador <<
	friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario) {
		os << "Descripcion: " << usuario.descripcion << " Prioridad: " << usuario.prioridad;
		return os;
	}



};
