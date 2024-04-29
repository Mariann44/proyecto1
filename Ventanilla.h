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
	Tiquete tiqueteActual;
	Tiquete tiqueteAnterior;
	int cantidadTiquetesAtendidos = 0;
	bool ocupada;

public:
	
	Ventanilla(string codigoArea, int consecutivo)
	{
		nombre = codigoArea + std::to_string(consecutivo + 1);
		ocupada = false;
		tiqueteActual = Tiquete();
		tiqueteAnterior = Tiquete();
	}

	Ventanilla()
	{
		nombre = "";
		ocupada = false;
		tiqueteActual = Tiquete();
		tiqueteAnterior = Tiquete();
	}

	~Ventanilla()
	{

	}

	string getNombre() const
	{
		return nombre;
	}

	Tiquete getTiqueteActual() const
	{
		return tiqueteActual;
	}


	void print() {
		cout << "Ventanilla: " << nombre << ", Ocupada: " << (ocupada ? "Sí" : "No") << endl;
		cout << "Tiquete actual: " << tiqueteActual.getCodigo() << endl;
	}

	void setTiqueteActual(Tiquete tiquete)
	{
		tiqueteActual = tiquete;
	}

	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla){
		os << "Nombre: " << ventanilla.nombre << ", Ocupada: " << (ventanilla.ocupada ? "Sí" : "No");
		return os;
	}
};





