/*Proyecto realizado por : Gabriel Arguedas Solano y Valeria Mar�n Barquero
*
*
*
*
*
*
*
*
*/
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
	std::chrono::duration<double> tiempoEsperaVentanilla{};

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

	void seTtiempoEspera() {
		tiempoEsperaVentanilla = tiqueteActual.tiempoEspera();

	}

	std::chrono::duration<double> getTiempoEsperaVentanilla() {
		return tiempoEsperaVentanilla;
	}


	string getNombre() const
	{
		return nombre;
	}

	Tiquete getTiqueteActual() const
	{
		return tiqueteActual;
	}

	int getCantidadTiquetesAtendidos() const
	{
		return cantidadTiquetesAtendidos;
	}

	void setTiqueteActual(Tiquete tiquete)
	{
		tiqueteAnterior = tiqueteActual;
		tiqueteActual = tiquete;

	}

	void print() {
		cout << "Ventanilla: " << nombre <<  endl;
		if (tiqueteActual.getCodigo() != "") {
			cout << "Tiquete actual: " << tiqueteActual.getCodigo() << endl;
		}
		else cout << "Tiquete actual: No hay tiquete actual" << endl;
	}

	void limpiarVentanilla()
	{
		tiqueteAnterior = Tiquete();
		tiqueteActual = Tiquete();
		cout << "Ventanilla LIMPIADA" << endl;
		cout << "Tiquete: " << tiqueteActual.getCodigo() << endl;
		cantidadTiquetesAtendidos = 0;
	}
	


	void cantidadTiquetesAtendidosIncrementar()
	{
		cantidadTiquetesAtendidos++;
	}

	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla){
		os << "Nombre: " << ventanilla.nombre << ", Ocupada: " << (ventanilla.ocupada ? "S�" : "No");
		return os;
	}
};





