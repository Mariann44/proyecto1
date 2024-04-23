#pragma once
#include <string>
#include "Tiquete.h"

using std::string;
class Ventanilla
{
private:
	string nombre;
	Tiquete* tiqueteActual;
	Tiquete* tiqueteAnterior;
	bool ocupada;

public:
	
	Ventanilla(string codigoArea, int consecutivo)
	{
		nombre = codigoArea + std::to_string(consecutivo + 1);
		ocupada = false;
		tiqueteActual = nullptr;
		tiqueteAnterior = nullptr;
	}

	Ventanilla()
	{
		nombre = "";
		ocupada = false;
		tiqueteActual = nullptr;
		tiqueteAnterior = nullptr;
	}



	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla){
		os << "Nombre: " << ventanilla.nombre << ", Ocupada: " << (ventanilla.ocupada ? "Sí" : "No");
		return os;
	}
};





