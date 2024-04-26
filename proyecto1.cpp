// Proyecto realizado por: Valeria Marín Barquero y Gabriel Arguedas Soloano
//
#include <string>
#include <iostream>
#include "LinkedPriorityQueue.h"
#include "ArrayList.h"
#include "Usuario.h"
#include "Area.h"
#include "Servicio.h"

using std::cout;
using std::cin;
using std::getline;
using std::string; 

LinkedPriorityQueue<Usuario> usuarios(10); //pa saber los tipos de usuario
ArrayList<Area*> areas;
ArrayList<Servicio*> servicios;


//Resulta que c++ toma en cuenta el orden de las funciones, por lo que si se llama una función que no ha sido declarada, se debe declarar antes de llamarla
void menuPrincipal();
void menuTiposDeUsuario();
void agregarTipoUsuario(string nombre, int prioridad);
void eliminarTipoUsuario();
void menuAdministracion();
void menuAreas();
void agregarArea(string descripcion, string codigo, int cantidadVentanillas);
Area* buscarArea(string nombre);
void modificarVentanillas(Area* area, int cantidadVentanillas);
void borrarArea(string nombre);
void menuServiciosDisponibles();
void agregarServicios(string descripcion, int prioridad, string area);
void eliminarServicios(int servicio);
void eliminarServiciosString(string servicio);
void reordenar(int servicio, int nuevaPosicion);


// Gabriel: Este método convierte un string a un int, si el string no es un número, se manejan las excepciones. por eso cuando se llama para convirtir se llama como stoi(string) xd
//Es decir, es lo mismo pero modificao shico
int StringtoInt(string str)
 { 
	try {
		int num = stoi(str);
		return num;
	}
	catch (const std::invalid_argument& ia) {
		cout << "Usted no digito un número. \n";
		menuAdministracion();
		
	}
	catch (const std::out_of_range& oor) {
		cout << "El numero esta fuera de rango. \n";
		menuAdministracion();
	
	}
	catch (const std::exception& e) {
		cout << "Error desconocido. \n";
		menuAdministracion();
		
	}
	
}

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
		menuPrincipal();
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
		menuServiciosDisponibles();
	}
	else if (opcion == "4") {
		//Método para limpiar colas limpiece la cola
	}
	else if (opcion == "5") {
		menuPrincipal();
	}
	else {
		cout << "Opcion no valida. \n";
		menuAdministracion();
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
		agregarTipoUsuario(descripcion, StringtoInt(prioridad));

	}
	else if (opcion == "2") {
		eliminarTipoUsuario();


	}
	else if (opcion == "3") {
		menuAdministracion();


	}
	else {
		cout << "Opcion no valida. \n";
		menuTiposDeUsuario();
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

        if (StringtoInt(prioridad) >= 0 && StringtoInt(prioridad) < usuarios.getSize()) {
            usuarios.removePriority(StringtoInt(prioridad));
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
		agregarArea(descripcion, codigo, StringtoInt(cantidadVentanillas)); 
			

	}
	else if (opcion == "2") {
		cout << "Inserte el nombre del area: \n";
		string nombreArea;
		getline(cin, nombreArea);
		


		if(buscarArea(nombreArea) == nullptr) {
			cout << "Area no encontrada. \n";
			menuAreas();
			return;
		}
		else {
			cout << "Esta es la informacion del area: \n";
			buscarArea(nombreArea)->print();
		}


		cout << "Esta seguro que desea borrar el area? Coloque s para confirmar, de lo contrario no se borrará \n";
		string confirmacion;
		getline(cin, confirmacion);
		if (confirmacion == "s") {
			borrarArea(nombreArea);
			menuAreas();
		}
		else {
			cout << "Area no borrada. \n";
			menuAreas();
		}
		

	}
	else if (opcion == "3") {
		cout << "Inserte el nombre del area: \n";
		string nombreArea;
		getline(cin, nombreArea);
		Area* area = buscarArea(nombreArea);

		if (area == nullptr) {
			cout << "Area no encontrada. \n";
			menuAreas();
			return;
		}
		else {
			cout << "Estas son las ventanillas de dicha area: \n";
			area->imprimirVentanillas();
			cout << "\n";
			cout << "Inserte el nuevo numero de ventanillas: \n";
			string cantidadVentanillas;
			getline(cin, cantidadVentanillas);
			modificarVentanillas(area, StringtoInt(cantidadVentanillas));
			menuAreas();
			

		}

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
		menuAreas();


	}
}

void agregarArea(string descripcion, string codigo, int cantidadVentanillas) {
	Area* nuevaArea = new Area(descripcion, codigo, cantidadVentanillas);
	areas.insert(nuevaArea);
	cout << "Area agregada con exito. \n";
	menuAreas();
}

Area* buscarArea(string nombre) {
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		if (areas.getElement()->getDescripcion() == nombre) {
			return areas.getElement();
		}
		areas.next();
		
	}
	return nullptr;
}

void modificarVentanillas(Area* area, int cantidadVentanillas) {
	area->setVentanillas(cantidadVentanillas);
	cout << "Ventanillas modificadas con exito. \n";
	area->imprimirVentanillas();
	cout << "\n";
}

void borrarArea(string nombre) {
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		if (areas.getElement()->getDescripcion() == nombre) {
			Area* area = areas.getElement();
			eliminarServiciosString(area->getDescripcion());
			areas.remove();
			delete area;
			cout << "Area eliminada con exito. \n";
			return;
		}
		areas.next();
	}
	cout << "Area no encontrada. \n";
}

void menuServiciosDisponibles() {
	cout << "de Servicios Opciones : \n";
	cout << "1. Agregar \n";
	cout << "2. Eliminar \n";
	cout << "3. Reordenar \n";
	cout << "4. Regresar: \n";
	cout << "5. Print de servicios \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Ingrese la descripción del servicio: \n";
		string descripcion;
		getline(cin, descripcion);
		cout << "Ingrese la prioridad del servicio: \n";
		string prioridad;
		getline(cin, prioridad);
		cout << "Ingrese el area del servicio: \n";
		string area;
		getline(cin, area);
		agregarServicios(descripcion, StringtoInt(prioridad), area);
		
	}
	else if (opcion == "2") {
		cout << "Observe los servicios disponibles a borrar:  \n";
		servicios.printPunteroConIndice();
		cout << "Inserte el numero del servicio que desea borrar: \n";
		string servicio;
		getline(cin, servicio);
		eliminarServicios(StringtoInt(servicio));
	}
	else if (opcion == "3") {
		cout << "Observe los servicios disponibles a reordenar:  \n";
		servicios.printPunteroConIndice();
		cout << "Inserte el numero del servicio que desea reordenar: \n";
		string servicio;
		getline(cin, servicio);
		cout << "Inserte la nueva posicion del servicio: \n";
		string nuevaPosicion;
		getline(cin, nuevaPosicion);
		reordenar(StringtoInt(servicio), StringtoInt(nuevaPosicion));
	}
	else if (opcion == "4") {
		menuAdministracion();
	}
	else if (opcion == "5") {
		servicios.printPunteroConIndice();
		menuServiciosDisponibles();
	}
	else {
		cout << "Opcion no valida. \n";
		menuServiciosDisponibles();
	}
}


void agregarServicios(string descripcion, int prioridad, string area) {
	Servicio* servicio = new Servicio(descripcion, prioridad, area);
	servicios.insert(servicio);
	cout << "Servicio agregado con exito. \n";
	menuServiciosDisponibles();
}

void eliminarServicios(int servicio) {
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		if (i == servicio) {
			Servicio* servicio = servicios.getElement();
			servicios.remove();
			delete servicio;
			cout << "Servicio eliminado con exito. \n";
			menuServiciosDisponibles();
		}
		servicios.next();
	}
	cout << "Servicio no encontrado. \n";
	menuServiciosDisponibles();
	
}

void eliminarServiciosString(string servicio) {
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		
			Servicio* servicioTemp = servicios.getElement();
			if (servicio == servicioTemp->getArea()) {
			servicios.remove();
			delete servicioTemp;
			return;
		     }
		servicios.next();
	}
	return;
	

}

void reordenar(int servicio, int nuevaPosicion) {
		if (servicio < 0 || nuevaPosicion < 0 || servicio >= servicios.getSize() || nuevaPosicion >= servicios.getSize()) {
			cout << "Posicion no valida. \n";
			menuServiciosDisponibles();
		}
		servicios.goToPos(servicio);
		Servicio* servicioTemp = servicios.getElement();
		servicios.remove(); 
		servicios.goToPos(nuevaPosicion);
		servicios.insert(servicioTemp);
		

	cout << "Servicio reordenado con exito. \n";
	menuServiciosDisponibles();
}


static int consecutivoGlobal = 100;

int main()
{


    menuPrincipal();
	return 0;


}