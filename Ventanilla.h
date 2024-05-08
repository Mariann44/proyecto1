/*Proyecto realizado por : Gabriel Arguedas Solano y Valeria Marín Barquero
*
*
* implementación de una ventanilla de servicio en un sistema de colas. 
Esta clase utiliza la clase Tiquete para representar los tiquetes que se atienden en la ventanilla. 
*
*funciones:
* void seTtiempoEspera() : calcula el tiempo de espera de la ventanilla
* std::chrono::duration<double> getTiempoEsperaVentanilla() : retorna el tiempo de espera de la ventanilla
* string getNombre() const : retorna el nombre de la ventanilla
* Tiquete getTiqueteActual() const : retorna el tiquete actual de la ventanilla
* int getCantidadTiquetesAtendidos() const : retorna la cantidad de tiquetes atendidos por la ventanilla
* void setTiqueteActual(Tiquete tiquete) : asigna un tiquete a la ventanilla
* void print() : imprime la información de la ventanilla
* void limpiarVentanilla() : limpia la ventanilla
* void cantidadTiquetesAtendidosIncrementar() : incrementa la cantidad de tiquetes atendidos por la ventanilla
* friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla) : sobrecarga del operador << para imprimir la información de la ventanilla
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

	int getcantidadTiquetesAtendidos()
	{
		return cantidadTiquetesAtendidos;
	}

	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla){
		os << "Nombre: " << ventanilla.nombre << ", Ocupada: " << (ventanilla.ocupada ? "Sí" : "No");
		return os;
	}
};





