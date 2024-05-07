/*Proyecto realizado por : Valeria Mar�n Barquero y Gabriel Arguedas Soloano
*
* implementaci�n de un usuario en un colas. 
* Esta clase contiene informaci�n sobre la descripci�n del usuario, su prioridad y la cantidad de tiquetes que ha obtenido
* 
* Funciones:
* sumarTiquete: incrementa la cantidad de tiquetes que tiene el usuario
* reset: reinicia la cantidad de tiquetes a 0
* getDescripcion: retorna la descripci�n del usuario
* getPrioridad: retorna la prioridad del usuario
* setDescripcion: modifica la descripci�n del usuario
* setPrioridad: modifica la prioridad del usuario
* getCantidadTiquete: retorna la cantidad de tiquetes que tiene el usuario
* printSinPrioridad: imprime la descripci�n del usuario
* Sobrecarga del operador <<: imprime la descripci�n y la prioridad del usuario
* 
*
*
*
*
*
*/




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
