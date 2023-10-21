# Mi Programa de Gestión de Productos en C++ y Phyton.

Este es un programa que he desarrollado en C++ y Phyton para gestionar productos. Con él, puedo agregar, buscar y modificar productos, y también guardar los datos en un archivo de texto.

## Clases

### `Producto`

Dentro de mi programa, he definido una clase llamada `Producto`. Cada instancia de esta clase representa un producto y tiene los siguientes atributos:
- `codigo`: El código único del producto.
- `nombre`: El nombre del producto.
- `precio`: El precio del producto.
- `existencia`: La cantidad en existencia.
- `estado`: El estado del producto (Aprobado o Reprobado).
- `descuento`: El descuento aplicable al producto.

## Funciones

Mi programa incluye las siguientes funciones:

- `void agregar_producto(vector<Producto>& productos)`: Esta función me permite agregar un nuevo producto a la lista de productos, después de verificar que el código sea único y el estado sea válido.

- `void buscar_producto(const vector<Producto>& productos)`: La función permite buscar un producto por código o nombre y muestra los detalles si se encuentra.

- `void modificar_producto(vector<Producto>& productos)`: Con esta función, puedo editar los datos de un producto existente.

- `void guardar_productos(const vector<Producto>& productos)`: Me permite guardar la lista de productos en un archivo de texto llamado "productos.txt".

- `vector<Producto> cargar_productos()`: Utilizo esta función para cargar los productos desde el archivo "productos.txt" y almacenarlos en un vector de `Producto`.

## Uso

Mi programa cuenta con un menú simple que me permite realizar las siguientes acciones:
1. Agregar un producto.
2. Buscar un producto por código o nombre.
3. Modificar datos de un producto.
4. Salir del programa.

Los datos de los productos se guardan y cargan desde un archivo de texto para mantener la persistencia de los datos.

## Ejecución

Para compilar y ejecutar el programa en C++, simplemente utilizo un compilador de C++ como g++.

```bash
g++ -o gestion_productos gestion_productos.cpp
./gestion_productos
