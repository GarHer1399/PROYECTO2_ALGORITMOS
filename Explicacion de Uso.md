# Gestión de Productos en C++

Este es un programa simple de gestión de productos en C++. Permite agregar, buscar y modificar productos, así como guardar los datos en un archivo de texto.

## Clases

### `Producto`

La clase `Producto` representa un producto con los siguientes atributos:
- `codigo`: Código único del producto.
- `nombre`: Nombre del producto.
- `precio`: Precio del producto.
- `existencia`: Cantidad en existencia.
- `estado`: Estado del producto (Aprobado o Reprobado).
- `descuento`: Descuento aplicable al producto.

### Funciones

El programa consta de las siguientes funciones:

- `void agregar_producto(vector<Producto>& productos)`: Agrega un nuevo producto a la lista de productos después de verificar que el código sea único y el estado sea válido.

- `void buscar_producto(const vector<Producto>& productos)`: Permite buscar un producto por código o nombre e imprime los detalles si se encuentra.

- `void modificar_producto(vector<Producto>& productos)`: Permite editar los datos de un producto existente.

- `void guardar_productos(const vector<Producto>& productos)`: Guarda la lista de productos en un archivo de texto llamado "productos.txt".

- `vector<Producto> cargar_productos()`: Carga los productos desde el archivo "productos.txt" y los devuelve como un vector de `Producto`.

## Uso

El programa tiene un menú simple que permite al usuario realizar las siguientes acciones:
1. Agregar un producto.
2. Buscar un producto por código o nombre.
3. Modificar datos de un producto.
4. Salir del programa.

Los datos de los productos se guardan y cargan desde un archivo de texto para mantener la persistencia de los datos.

## Ejecución

Para compilar y ejecutar el programa en C++, puedes utilizar un compilador de C++ como g++.

```bash
g++ -o gestion_productos gestion_productos.cpp
./gestion_productos
