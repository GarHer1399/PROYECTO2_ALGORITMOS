#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Producto {
public:
    string codigo;
    string nombre;
    double precio;
    int existencia;
    char estado;
    double descuento;

    Producto(string codigo, string nombre, double precio, int existencia, char estado, double descuento)
        : codigo(codigo), nombre(nombre), precio(precio), existencia(existencia), estado(estado), descuento(descuento) {}
};

void agregar_producto(vector<Producto>& productos) {
    string codigo, nombre;
    double precio, descuento;
    int existencia;
    char estado;

    cout << "Codigo: ";
    cin >> codigo;

    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].codigo == codigo) {
            cout << "El codigo ya existe. No es valido." << endl;
            return;
        }
    }

    cout << "Nombre: ";
    cin >> nombre;

    cout << "Precio: ";
    string precioStr;
    cin >> precioStr;
    precio = atof(precioStr.c_str());

    cout << "Existencia: ";
    cin >> existencia;

    cout << "Estado (A = Aprobado, R = Reprobado): ";
    cin >> estado;

    if (estado != 'A' && estado != 'R') {
        cout << "El estado debe ser 'A' o 'R'. No se ha modificado el producto." << endl;
        return;
    }

    cout << "Descuento: ";
    cin >> descuento;

    productos.push_back(Producto(codigo, nombre, precio, existencia, estado, descuento));
    cout << "Producto agregado." << endl;
}

void buscar_producto(const vector<Producto>& productos) {
    string consulta;
    cout << "Ingrese el codigo o nombre del producto a buscar: ";
    cin >> consulta;

    cout << "Resultado:" << endl;

    for (int i = 0; i < productos.size(); i++) {
        const Producto& producto = productos[i];
        if (consulta == producto.codigo || consulta == producto.nombre) {
            cout << "Codigo: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Existencia: " << producto.existencia << endl;
            cout << "Estado: " << producto.estado << endl;
            cout << "Descuento: " << producto.descuento << endl;
            cout << "-------------------" << endl;
        }
    }
}

void modificar_producto(vector<Producto>& productos) {
    string codigo;
    cout << "Ingrese el codigo del producto que desea editar: ";
    cin >> codigo;

    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].codigo == codigo) {
            cout << "Producto encontrado. Edite los datos:" << endl;

            cout << "Nombre: ";
            cin >> productos[i].nombre;

            cout << "Precio: ";
            string precioStr;
            cin >> precioStr;
            productos[i].precio = atof(precioStr.c_str());

            cout << "Existencia: ";
            cin >> productos[i].existencia;

            cout << "Estado (A = Aprobado, R = Reprobado): ";
            cin >> productos[i].estado;

            if (productos[i].estado != 'A' && productos[i].estado != 'R') {
                cout << "El estado debe ser 'A' o 'R'. No se ha modificado el producto." << endl;
                return;
            }

            cout << "Descuento: ";
            cin >> productos[i].descuento;

            cout << "Producto modificado con exito." << endl;
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

void guardar_productos(const vector<Producto>& productos) {
    ofstream file("productos.txt");

    for (int i = 0; i < productos.size(); i++) {
        const Producto& producto = productos[i];
        file << producto.codigo << "," << producto.nombre << "," << producto.precio << ","
             << producto.existencia << "," << producto.estado << "," << producto.descuento << "\n";
    }
}

vector<Producto> cargar_productos() {
    vector<Producto> productos;
    ifstream file("productos.txt");

    if (file.is_open()) {
        string codigo, nombre, precioStr, estado, descuentoStr, existenciaStr;
        double precio, descuento;
        int existencia;

        while (getline(file, codigo, ',') &&
               getline(file, nombre, ',') &&
               getline(file, precioStr, ',') &&
               getline(file, existenciaStr, ',') &&
               getline(file, estado, ',') &&
               getline(file, descuentoStr)) {
            precio = atof(precioStr.c_str());
            descuento = atof(descuentoStr.c_str());
            existencia = atoi(existenciaStr.c_str());
            productos.push_back(Producto(codigo, nombre, precio, existencia, estado[0], descuento));
        }
    }

    return productos;
}

int main() {
    vector<Producto> productos = cargar_productos();

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar producto" << endl;
        cout << "3. Modificar datos de un producto" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            agregar_producto(productos);
            guardar_productos(productos);
        } else if (opcion == 2) {
            buscar_producto(productos);
        } else if (opcion == 3) {
            modificar_producto(productos);
            guardar_productos(productos);
        } else if (opcion == 4) {
            cout << "Saliendo del programa." << endl;
            break;
        } else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
