#pragma once
#include <string>
#include <vector>
#include <queue>
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
    LinkedPriorityQueue<Tiquete> tiquetes;

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





    /*
    //Constructor de copia
    Area(const Area& other)
        : descripcion(other.descripcion), codigo(other.codigo), cantidadVentanillas(other.cantidadVentanillas), ventanillas(other.ventanillas), tiquetes(other.tiquetes)
    {}


    */
    //Getters y Setters
    string getDescripcion() const
	{
		return descripcion;
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
            cout <<"llega al while y crea el objeto"<<endl;
			ventanillas.insert(ventanilla);
			cantidadVentanillas++;
		}
    }





    //Para poder imprimir area
    friend std::ostream& operator<<(std::ostream& os, const Area& area) {
        os << "Area: " << area.descripcion << ",  Codigo: " << area.codigo << ", Cantidad de Ventanillas: " << area.cantidadVentanillas << " \n";
        return os;


    }
    
    

    
};