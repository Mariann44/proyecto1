// Proyecto realizado por: Valeria Marín Barquero y Gabriel Arguedas Soloano
//
#include <string>
#include <iostream>
#include "LinkedPriorityQueue.h"
#include "ArrayList.h"
#include "Usuario.h"
#include "Area.h"

using std::cout;
using std::cin;
using std::getline;
using std::string; 

LinkedPriorityQueue<Usuario> usuarios(10);
ArrayList<Area*> areas;


//Resulta que c++ toma en cuenta el orden de las funciones, por lo que si se llama una función que no ha sido declarada, se debe declarar antes de llamarla

void menuTiposDeUsuario();
void agregarTipoUsuario(string nombre, int prioridad);
void eliminarTipoUsuario();
void menuAdministracion();
void menuAreas();
void agregarArea(string descripcion, string codigo, int cantidadVentanillas);




















void menuPrincipal() {
	cout << "Menu Principal: \n";
	cout << "1. Estado de Colas: \n";
	cout << "2. Tiquetes: \n";
	cout << "3. Atender: \n";
	cout << "4. Administracion: \n";
	cout << "5. Estadisticas del Sistema: \n";
	cout << "6. Salir: \n";

	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Estado de Colas: \n";
	}
	else if (opcion == "2") {
		cout << "Tiquetes: \n";
	}
	else if (opcion == "3") {
		cout << "Atender: \n";
	}
	else if (opcion == "4") {
		menuAdministracion();
	}
	else if (opcion == "5") {
		cout << "Estadisticas del Sistema: \n";
	}
	else if (opcion == "6") {
		cout << "Salir: \n";
	}
	else {
		cout << "Opcion no valida. \n";
	}
}

void menuAdministracion() {
	cout << "Menu Administracion: \n";
	cout << "1. Tipos de Usuario: \n";
	cout << "2. Areas \n";
	cout << "3. Servicios Disponibles: \n";
	cout << "4. Limpiar Colas Estadisticas: \n";
	cout << "5. Regresar: \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		menuTiposDeUsuario();
	}
	else if (opcion == "2") {
		menuAreas();
	}
	else if (opcion == "3") {
		//Método para servicios disponibles
	}
	else if (opcion == "4") {
		//Método para limpiar colas limpiece la cola
	}
	else if (opcion == "5") {
		//Regresar
	}
	else {
		cout << "Opcion no valida. \n";
	}
}

void menuTiposDeUsuario() {
	cout << "Menu Tipos de Usuario: \n";
	cout << "1. Agregar \n";
	cout << "2. Eliminar \n";
	cout << "3. Regresar: \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Ingrese la descripción del tipo de usuario: \n";
		string descripcion;
		getline(cin, descripcion);
		cout << "Ingrese la prioridad del tipo de usuario: \n";
		string prioridad;
		getline(cin, prioridad);
		agregarTipoUsuario(descripcion, stoi(prioridad)); //stoi lo convierte a int 

	}
	else if (opcion == "2") {
		eliminarTipoUsuario();


	}
	else if (opcion == "3") {
		menuAdministracion();


	}
	else {
		cout << "Opcion no valida. \n";


	}
}


void agregarTipoUsuario(string nombre, int prioridad) {
	Usuario usuario = Usuario(nombre, prioridad); //***
	usuarios.insert(usuario, prioridad);
	cout << "Tipo de usuario agregado con exito. \n";
	menuTiposDeUsuario();
	
}


//a este metodo le falta agregar una validacion por si nos meten un string en vez de un int
void eliminarTipoUsuario() {
    if (usuarios.isEmpty()) {
        cout << "No hay tipos de usuario para eliminar. \n";
        menuTiposDeUsuario();
        return;
    }

    while (true) {
        cout << "Por favor, inserte la prioridad del tipo de usuario de prioridad \n";
        usuarios.print();
        cout << "Presione -1 para regresar \n";
        string prioridad;
        getline(cin, prioridad);

        if (prioridad == "-1") {
			break;
		}

        if (stoi(prioridad) >= 0 && stoi(prioridad) < usuarios.getSize()) {
            usuarios.removePriority(stoi(prioridad));
            cout << "Tipo de usuario eliminado con exito. \n";
            break;
        }
        else {
            cout << "Prioridad no valida. Inserte de nuevo la prioridad \n";
        }
    }

    menuTiposDeUsuario();
}


void menuAreas() {
	cout << "Menu Areas: \n";
	cout << "1. Agregar \n";
	cout << "2. Eliminar \n";
	cout << "3. Modificar Ventanillas \n";
	cout << "4. Print de areas \n";
	cout << "5. Regresar: \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Ingrese la descripción del area: \n";
		string descripcion;
		getline(cin, descripcion);
		cout << "Ingrese el codigo del area: \n";
		string codigo;
		getline(cin, codigo);
		cout << "Ingrese la cantidad de ventanillas del area: \n";
		string cantidadVentanillas;
		getline(cin, cantidadVentanillas);

		//Agregar Validacion de opciones PENDIENTE
		agregarArea(descripcion, codigo, stoi(cantidadVentanillas)); 
		
		
		

	}
	else if (opcion == "2") {
		


	}
	else if (opcion == "3") {
		



	}
	else if (opcion == "4") {
		cout << "Areas Actuales y su info: \n";
		areas.printPuntero();
		cout << "" << endl;
		menuAreas();


	}
	else if (opcion == "5") {
		menuAdministracion();

	}
	else {
		cout << "Opcion no valida. \n";


	}
}

void agregarArea(string descripcion, string codigo, int cantidadVentanillas) {
	Area* nuevaArea = new Area(descripcion, codigo, cantidadVentanillas);
	areas.insert(nuevaArea);
	cout << "Area agregada con exito. \n";
	menuAreas();
}






static int consecutivoGlobal = 100;

int main()
{


    menuPrincipal();
	return 0;


}