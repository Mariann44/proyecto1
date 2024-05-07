/*Proyecto realizado por : Valeria Marín Barquero y Gabriel Arguedas Soloano
*
*
* implementación de un tiquete en un sistema de colas.
* Esta clase contiene información sobre el código del tiquete, la hora de solicitud, la hora de atención y la prioridad del tiquete.
* funciones:
* -tiempoEspera: calcula el tiempo de espera del tiquete.
* -getCodigo: retorna el código del tiquete.
* -getPrioridad: retorna la prioridad del tiquete.
* -print: imprime el código y la prioridad del tiquete.
* -printConHora: imprime el código, la prioridad y la hora de solicitud del tiquete.
* -setHoraDeAtencion: establece la hora de atención del tiquete.
* -operator<<: sobrecarga del operador << para imprimir el código y la prioridad del tiquete.
*
*
*
*
*/


#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>

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


	std::chrono::duration<double> tiempoEspera() {
		std::chrono::duration<double> tiempo = horaDeAtencion - horaDeSolicitud;
		return tiempo;
	}

	string getCodigo() const
	{
		return codigo;
	}

	int getPrioridad() const
	{
		return prioridad;
	}

	void print() const
	{
		std::cout << "Codigo: " << codigo << ", Prioridad: " << prioridad << std::endl;
	}

	void printConHora() const
	{
		auto tp = std::chrono::system_clock::to_time_t(horaDeSolicitud);
		std::tm bt;
		localtime_s(&bt, &tp);
		std::ostringstream oss;

		oss << std::put_time(&bt, "%H:%M:%S");

		std::cout << "Codigo: " << codigo << ", Prioridad: " << prioridad << ", Hora de solicitud: " << oss.str() << std::endl;
	}

	void setHoraDeAtencion()
	{
		horaDeAtencion = system_clock::now();
	}



	friend std::ostream& operator<<(std::ostream& os, const Tiquete& tiquete)
	{
		os << "Codigo: " << tiquete.codigo << ", Prioridad: " << tiquete.prioridad;
		return os;
	}

};


