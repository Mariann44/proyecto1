/*Proyecto realizado por: Gabriel Arguedas Solano y Mariann Marin Barquero
*
* Aquí estan implementados los menus y submenus con los que interactuará el usuario y administradores además de que aquí se hace uso de las clases, estrcutyras y sus metodos
* 
* funciones: 
* menuPrincipal: Muestra el menu principal con las opciones de Estado de Colas, Tiquetes, Atender, Administracion, Estadisticas del Sistema y Salir
* menuTiposDeUsuario: Muestra el menu de Tipos de Usuario con las opciones de Agregar, Eliminar y Regresar
* agregarTipoUsuario: Agrega un tipo de usuario a la lista de tipos de usuario
* eliminarTipoUsuario: Elimina un tipo de usuario de la lista de tipos de usuario
* menuAdministracion: Muestra el menu de Administracion con las opciones de Tipos de Usuario, Areas, Servicios Disponibles, Limpiar Colas Estadisticas y Regresar
* menuAreas: Muestra el menu de Areas con las opciones de Agregar, Eliminar, Modificar Ventanillas, Print de areas y Regresar
* agregarArea: Agrega un area a la lista de areas
* buscarArea: Busca un area en la lista de areas
* modificarVentanillas: Modifica la cantidad de ventanillas de un area
* borrarArea: Borra un area de la lista de areas
* menuServiciosDisponibles: Muestra el menu de Servicios Disponibles con las opciones de Agregar, Eliminar, Reordenar, Regresar y Print de servicios
* agregarServicios: Agrega un servicio a la lista de servicios
* eliminarServicios: Elimina un servicio de la lista de servicios
* eliminarServiciosString: Elimina un servicio de la lista de servicios por medio de un string
* reordenar: Reordena la lista de servicios
* Tiquetes: Muestra el menu de Tiquetes con las opciones de Solicitar Tiquete y Regresar
* prioridadServicio: Obtiene la prioridad de un servicio
* prioridadUsario: Obtiene la prioridad de un usuario
* buscarAreaPorServicio: Busca un area por medio de un servicio
* crearTiquete: Crea un tiquete
* printArrayUsuarios: Imprime la lista de usuarios
* printAreas: Imprime la lista de areas
* Atender: Muestra el menu de Atender con las opciones de Atender Tiquete y Regresar
* atenderAux: Atiende un tiquete
* estadoColas: Muestra el estado de las colas
* consultaEstadisticas: Muestra las estadisticas del sistema
* limpieceLaCola: Limpia las colas
* datosDePrueba: Establece los datos de prueba
* main: Funcion principal
*/
#include <string>
#include <iostream>
#include "LinkedPriorityQueue.h"
#include "LinkedQueue.h"
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
ArrayList<Usuario*> usuariosArray;


//Resulta que c++ toma en cuenta el orden de las funciones, por lo que si se llama una función que no ha sido declarada, se debe declarar antes de llamarla
static int consecutivoGlobal = 100;

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
void Tiquetes();
int prioridadUsario(int usuario);
int prioridadServicio(int servicio);
string buscarAreaPorServicio(int servicio);
Tiquete crearTiquete(int usuario, int servicio);
void eliminarUsuarioPorPrioridad(int prioridad);
void printArrayUsuarios(); // pa imprimir sin la prioridad xd
void datosDePrueba();
void Atender();
void atenderAux(string area, int ventanilla);
void estadoColas();
void consultaEstadisticas();
void limpieceLaCola();






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
	cout << "7. Establecer Datos de Prueba: \n";

	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Estado de Colas: \n";
		estadoColas();
		cout << "Presione cualquier tecla para regresar \n";
		getline(cin, opcion);
		menuPrincipal();

	}
	else if (opcion == "2") {
		Tiquetes();
	}
	else if (opcion == "3") {
		Atender();
	}
	else if (opcion == "4") {
		menuAdministracion();
	}
	else if (opcion == "5") {
		consultaEstadisticas();
	}
	else if (opcion == "6") {
		cout << "Salir: \n";
	}
	else if (opcion == "7") {
		cout << "Establecer Datos de Prueba: \n";
		datosDePrueba();

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
		limpieceLaCola();
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
	
	Usuario* usuarioTemp = new Usuario(nombre, prioridad);
	usuariosArray.append(usuarioTemp);

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
			eliminarUsuarioPorPrioridad(StringtoInt(prioridad));
            cout << "Tipo de usuario eliminado con exito. \n";
            break;
        }
        else {
            cout << "Prioridad no valida. Inserte de nuevo la prioridad \n";
        }
    }

    menuTiposDeUsuario();
}

void eliminarUsuarioPorPrioridad(int prioridad) {
	usuariosArray.goToStart();
	for (int i = 0; i < usuariosArray.getSize(); i++) {
		if (usuariosArray.getElement()->getPrioridad() == prioridad) {
			usuariosArray.remove();
			return;
		}
		usuariosArray.next();
	}

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
	if(buscarArea(area) == nullptr) {
		cout << "Area asociada al servicio no encontrada. \n";
		menuServiciosDisponibles();
		return;
	}
	else {
		Servicio* servicio = new Servicio(descripcion, prioridad, area);
		servicios.insert(servicio);
		cout << "Servicio agregado con exito. \n";
		menuServiciosDisponibles();
	}
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



void Tiquetes() {
	cout << "Menu Tiquetes: \n";
	cout << "1. Solicitar Tiquete: \n";
	cout << "2. Regresar: \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		cout << "Observe los tipos de usuario disponibles: \n";
		printArrayUsuarios();
		cout << "Inserte el numero del tipo de usuario: \n";
		string tipoUsuario;
		getline(cin, tipoUsuario);
		cout << "Observe los servicios disponibles: \n";
		servicios.printPunteroConIndice();
		cout << "Inserte el numero del servicio: \n";
		string servicio;
		getline(cin, servicio);

		Tiquete tiquete = crearTiquete(StringtoInt(tipoUsuario), StringtoInt(servicio));

		tiquete.printConHora();
		Tiquetes(); 
		
	}
	else if (opcion == "2") {
		menuPrincipal();
	}
	else {
		cout << "Opcion no valida. \n";
		Tiquetes();
	}
}


int prioridadServicio(int servicio) {
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		if (i == servicio) {
			
			servicios.getElement()->sumarTiquete(); //sumar tiquete al servicio
			return servicios.getElement()->getPrioridad();
		}
		servicios.next();
	}
}

int prioridadUsario(int usuario) {
	usuariosArray.goToPos(usuario);
	usuariosArray.getElement()->sumarTiquete(); //sumar tiquete al usuario
	int prioridad = usuariosArray.getElement()->getPrioridad();
	return prioridad;
	
}

string buscarAreaPorServicio(int servicio) {
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		if (i == servicio) {
			
			return servicios.getElement()->getArea();
		}
		servicios.next();

	}
}

Tiquete crearTiquete(int usuario, int servicio) {
	int prioridadServicioNum = prioridadServicio(servicio);
	int prioridadUsuario = prioridadUsario(usuario);
	string areaCodigo = buscarArea(buscarAreaPorServicio(servicio))->getCodigo();
	Tiquete tiqueteTemp = Tiquete(areaCodigo, prioridadUsuario, prioridadServicioNum, consecutivoGlobal);

	buscarArea(buscarAreaPorServicio(servicio))->agregarTiquete(tiqueteTemp);
	//buscarArea(buscarAreaPorServicio(servicio))->print(); pa ver si se agrega el tiquete

	consecutivoGlobal++;
	return tiqueteTemp;

}

void printArrayUsuarios() {
	usuariosArray.goToStart();
	for (int i = 0; i < usuariosArray.getSize(); i++) {
		cout << i << ". ";
		usuariosArray.getElement()->printSinPrioridad();
		
		usuariosArray.next();

	}
}


void printAreas() {
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		cout << areas.getElement()->getDescripcion() << " \n";
		areas.next();

	}
}

void Atender() {
	cout << "Menu Atender: \n";
	cout << "1. Atender Tiquete: \n";
	cout << "2. Regresar: \n";
	string opcion;
	getline(cin, opcion);

	if (opcion == "1") {
		printAreas();
		cout << "Inserte el nombre del area que le corresponde: \n";
		string area;
		getline(cin, area);
	    buscarArea(area)->printVentanillas();
		cout << "Inserte el numero de ventanilla: \n";
		string numeroVentanilla;
		getline(cin, numeroVentanilla);
		atenderAux(area, StringtoInt(numeroVentanilla));
		Atender();



	}
	else if (opcion == "2") {
		menuPrincipal();
	}
	else {
		cout << "Opcion no valida. \n";
		Tiquetes();
	}
}







void datosDePrueba() {
	Usuario usuario1 = Usuario("Usuario1", 1);
	Usuario usuario2 = Usuario("Usuario2", 2);
	Usuario usuario3 = Usuario("Usuario3", 3);

	usuarios.insert(usuario1, 1);
	usuarios.insert(usuario2, 2);
	usuarios.insert(usuario3, 3);


	Usuario* usuarioTemp1 = new Usuario("Usuario1", 1);
	Usuario* usuarioTemp2 = new Usuario("Usuario2", 2);
	Usuario* usuarioTemp3 = new Usuario("Usuario3", 3);
	usuariosArray.append(usuarioTemp1);
	usuariosArray.append(usuarioTemp2);
	usuariosArray.append(usuarioTemp3);


	Area* area1 = new Area("Area1", "A1", 1);
	Area* area2 = new Area("Area2", "A2", 2);
	Area* area3 = new Area("Area3", "A3", 3);
	areas.insert(area1);
	areas.insert(area2);
	areas.insert(area3);

	Servicio* servicio1 = new Servicio("Servicio1", 1, "Area1");
	Servicio* servicio2 = new Servicio("Servicio2", 2, "Area2");
	Servicio* servicio3 = new Servicio("Servicio3", 3, "Area3");
	
	servicios.append(servicio1);
	servicios.append(servicio2);
	servicios.append(servicio3);
	menuPrincipal();	
}

void atenderAux(string area, int ventanilla) {
	if (buscarArea(area) == nullptr) {
		cout << "Area no encontrada. \n";
		Atender();
		return;
	}
	buscarArea(area)->agregarAventanillas(ventanilla, buscarArea(area)->atenderTiquete());
}

void estadoColas() {
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		areas.getElement()->printEstadoCola();
		cout << "\n";
		areas.next();
	}
	menuPrincipal();
}

void consultaEstadisticas() {
	cout << "Estadisticas del Sistema: \n";
	cout << "Cantidad tiquetes dispensandos por area: \n";
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		cout << "Area: " << areas.getElement()->getDescripcion() << " Cantidad de tiquetes dispensados: " << areas.getElement()->getCantidadTiquetes() << " \n";
		cout << "Tiempo: ";
		areas.getElement()->tiempoEsperaPromedio();


		areas.next();
	}
	cout << "Cantidad de tiquetes dispensados por servicio: \n";
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		cout << "Servicio: " << servicios.getElement()->getDescripcion() << " Cantidad de tiquetes dispensados: " << servicios.getElement()->getCantidadServicios() << " \n";
		servicios.next();
	}
	cout << "Cantidad de tiquetes dispensados por usuario: \n";
	usuariosArray.goToStart();
	for (int i = 0; i < usuariosArray.getSize(); i++) {
		cout << "Usuario: " << usuariosArray.getElement()->getDescripcion() << " Cantidad de tiquetes dispensados: " << usuariosArray.getElement()->getCantidadTiquete() << " \n";
		usuariosArray.next();
	}

	
	cout << "Presione cualquier tecla para regresar \n";
	string opcion;
	getline(cin, opcion);
	menuPrincipal();
}


void limpieceLaCola() {
	areas.goToStart();
	for (int i = 0; i < areas.getSize(); i++) {
		areas.getElement()->limpiarCola();
		areas.next();
	}
	servicios.goToStart();
	for (int i = 0; i < servicios.getSize(); i++) {
		servicios.getElement()->reset();
		servicios.next();
	}
	usuariosArray.goToStart();
	for (int i = 0; i < usuariosArray.getSize(); i++) {
		usuariosArray.getElement()->reset();
		usuariosArray.next();
	}

	consecutivoGlobal = 100;

	cout << "Colas limpiadas con exito. \n";
	menuAdministracion();
}




int main()
{


    menuPrincipal();
	return 0;


}