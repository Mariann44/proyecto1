#pragma once
#include <string>
#include "Tiquete.h"

using std::string;
using std::cout;
using std::endl;
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

	~Ventanilla()
	{
		delete tiqueteActual;
		delete tiqueteAnterior;
	}

	string getNombre() const
	{
		return nombre;
	}

	Tiquete* getTiqueteActual() const
	{
		return tiqueteActual;
	}


	void print() {
		cout << "Ventanilla: " << nombre << ", Ocupada: " << (ocupada ? "Sí" : "No") << endl;
		if (tiqueteActual != nullptr) {
			cout << "Tiquete actual: " << tiqueteActual->getCodigo() << endl;
		}
		else {
			cout << "Tiquete actual: No hay tiquete actual" << endl;
		}

	}

	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla){
		os << "Nombre: " << ventanilla.nombre << ", Ocupada: " << (ventanilla.ocupada ? "Sí" : "No");
		return os;
	}
};





