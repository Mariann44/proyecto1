/*Proyecto realizado por : Valeria Marín Barquero y Gabriel Arguedas Soloano
*
*
*implementación de un área de servicio en un sistema de colas. 
Esta clase utiliza una ArrayList para almacenar las ventanillas de servicio y una LinkedPriorityQueue para almacenar los tiquetes de los clientes.
*
* funciones:
* agregarVentanilla: agrega una ventanilla a la lista de ventanillas.
* agregarTiquete: agrega un tiquete a la cola de tiquetes.
* atenderTiquete: atiende un tiquete de la cola de tiquetes.
* setTiempoEspera: calcula el tiempo de espera promedio de los tiquetes en la cola.
* tiempoEsperaPromedio: imprime el tiempo de espera promedio de los tiquetes en la cola.
* agregarAventanillas: agrega un tiquete a una ventanilla específica.
* print: imprime la información del área.
* printEstadoCola: imprime el estado de la cola de tiquetes y de las ventanillas.
* limpiarCola: limpia la cola de tiquetes y las ventanillas.
* getDescripcion: retorna la descripción del área.
* getCodigo: retorna el código del área.
* getCantidadTiquetes: retorna la cantidad de tiquetes en la cola.
* operator<<: sobrecarga del operador << para imprimir el área.
*
*
*
*
*/
#pragma once
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "Ventanilla.h"
#include "ArrayList.h"
#include "LinkedPriorityQueue.h"



using std::string;
using std::cout;
using std::endl;

class Area      
{
private:
    string descripcion;
    string codigo;
    ArrayList<Ventanilla> ventanillas;
    int cantidadVentanillas;
    int cantidadTiquetes = 0;
    LinkedPriorityQueue<Tiquete> tiquetes;
    std::chrono::duration<double> tiempoEspera{};


public: 
    Area(string descripcionArea, string codigoArea, int cantidadVentanillasArea)
        : descripcion(descripcionArea), codigo(codigoArea), cantidadVentanillas(cantidadVentanillasArea), ventanillas(cantidadVentanillasArea)
    {
        for (int i = 0; i < cantidadVentanillas; i++)
        {
            Ventanilla ventanilla = Ventanilla(codigoArea, i);
            ventanillas.insert(ventanilla);
        }
    }

    ~Area()
    {
        //ArrayList y LinkedPriorityQueue se eliminan automaticamente por lo que no es necesario hacerlo ¿?
      
    }

    void imprimirVentanillas(){
        ventanillas.goToStart();
		for (int i = 0; i < cantidadVentanillas; i++)
		{
            ventanillas.getElement().print();
            cout<<endl;
            ventanillas.next();

		}
	}
    
    void printVentanillas() {
        ventanillas.goToStart();
        for (int i = 0; i < cantidadVentanillas; i++)
        {
			cout << i << ". ";
            cout << ventanillas.getElement().getNombre();
            cout << " Tiquetes dispensados: " << ventanillas.getElement().getcantidadTiquetesAtendidos();
			cout << endl;
			ventanillas.next();
		}
    }




    void setVentanillas(int nuevaCantidadVentanillas)
	{
        if(nuevaCantidadVentanillas == cantidadVentanillas){
			return;
		}
        /*
        if (nuevaCantidadVentanillas > cantidadVentanillas) {
            cout << "llega al if" << endl;
            agregarVentanilla(nuevaCantidadVentanillas);
            return;
        }
        */
        ventanillas.clear();
        cantidadVentanillas = nuevaCantidadVentanillas;

        for (int i = 0; i < cantidadVentanillas; i++)
		{
            Ventanilla ventanilla = Ventanilla(codigo, i);
			ventanillas.insert(ventanilla);
		}
		
	}


    void agregarVentanilla(int nuevaCantidadVentanillas) {
        while(cantidadVentanillas < nuevaCantidadVentanillas){
			Ventanilla ventanilla = Ventanilla(codigo, cantidadVentanillas);
            
			ventanillas.insert(ventanilla);
			cantidadVentanillas++;
            
		}
    }

    void agregarTiquete(Tiquete tiquete) {
        int prioridad = tiquete.getPrioridad();
		tiquetes.insert(tiquete, prioridad);
        cantidadTiquetes++;
	}



    void DeleteTodo (){
		ventanillas.clear();
		tiquetes.clear();
	}

    Tiquete atenderTiquete() {
        if (tiquetes.isEmpty()) {
			cout << "No hay tiquetes en la cola" << endl;
			return Tiquete();
		}
        Tiquete tiquete = tiquetes.removeMin();
        tiquete.setHoraDeAtencion();
        return tiquete;

		
	}

    void setTiempoEspera() {
		ventanillas.goToStart();
		for (int i = 0; i < cantidadVentanillas; i++)
		{
			Ventanilla ventanilla = ventanillas.getElement();
			tiempoEspera += ventanilla.getTiempoEsperaVentanilla();
			ventanillas.next();
		}
	}

    void tiempoEsperaPromedio() {
		if (cantidadTiquetes == 0) {
			cout << "No hay tiquetes en la cola" << endl;
			return;
		}
		setTiempoEspera();
		cout << "Tiempo de espera promedio: " << tiempoEspera.count() / cantidadTiquetes << " segundos" << endl;
	}




    void agregarAventanillas(int ventanilla, Tiquete tiquete) {
        if (ventanilla >= cantidadVentanillas) {
            cout << "No existe la ventanilla" << endl;
            return;
        }
        if (tiquete.getCodigo() == "") {
			return;
		}
        else {
            ventanillas.goToPos(ventanilla);
            Ventanilla ventanillaActual = ventanillas.getElement();
            ventanillaActual.setTiqueteActual(tiquete);
            ventanillaActual.seTtiempoEspera();
            ventanillaActual.cantidadTiquetesAtendidosIncrementar();
            ventanillas.remove();
            ventanillas.insert(ventanillaActual);
        }
    }


    void print(){
		cout << "Area: " << descripcion << ",  Codigo: " << codigo << ", Cantidad de Ventanillas: " << cantidadVentanillas << " \n";
        cout << "Tiquetes: " << endl;
        tiquetes.print();
	}

    void printEstadoCola() {
        cout << "Area: " << descripcion <<  ", Cantidad de Ventanillas: " << cantidadVentanillas << " \n";
        cout << "Tiquetes en cola: " << endl;
        tiquetes.print();
        ventanillas.goToStart();
        for (int i = 0; i < cantidadVentanillas; i++)
        {
            ventanillas.getElement().print();
			cout << endl;
			ventanillas.next();
		}
    }

    void limpiarCola() {
        tiquetes.clear();
        cantidadTiquetes = 0;
        tiempoEspera = std::chrono::duration<double>{}; // tiempoEspera a 0

        ventanillas.goToStart();
        for (int i = 0; i < cantidadVentanillas; i++)
        {
            Ventanilla ventanillaTemp = ventanillas.getElement();
            ventanillaTemp.limpiarVentanilla();
            ventanillas.remove();
            ventanillas.insert(ventanillaTemp);

            ventanillas.next();
        }
    }


    //Getters y Setters
    string getDescripcion() const
    {
        return descripcion;
    }

    string getCodigo() const
    {
		return codigo;
	}

    int getCantidadTiquetes() const
    {
		return cantidadTiquetes;
	}
	


    //Para poder imprimir area
    friend std::ostream& operator<<(std::ostream& os, const Area& area) {
        os << "Area: " << area.descripcion << ",  Codigo: " << area.codigo << ", Cantidad de Ventanillas: " << area.cantidadVentanillas << " \n";
        return os;


    }

};