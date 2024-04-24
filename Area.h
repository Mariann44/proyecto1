#pragma once
#include <string>
#include <vector>
#include <queue>
#include "Ventanilla.h"
#include "ArrayList.h"
#include "LinkedPriorityQueue.h"



using std::string;
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


    /*
    //Constructor de copia
    Area(const Area& other)
        : descripcion(other.descripcion), codigo(other.codigo), cantidadVentanillas(other.cantidadVentanillas), ventanillas(other.ventanillas), tiquetes(other.tiquetes)
    {}


    */

    //Para poder imprimir area
    friend std::ostream& operator<<(std::ostream& os, const Area& area) {
        os << "Area: " << area.descripcion << ",  Codigo: " << area.codigo << ", Cantidad de Ventanillas: " << area.cantidadVentanillas;
        return os;


    }
    
    

    
};