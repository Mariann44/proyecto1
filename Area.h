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

    //Constructor de copia
    Area(const Area& other)
        : descripcion(other.descripcion), codigo(other.codigo), cantidadVentanillas(other.cantidadVentanillas), ventanillas(other.ventanillas), tiquetes(other.tiquetes)
    {}


    /*

    //Para poder imprimir area
    friend std::ostream& operator<<(std::ostream& os, const Area& area) {
        os << "Area: " << area.descripcion << ", " << area.codigo << ", " << area.cantidadVentanillas;
        return os;


    }
    */
    

    
};