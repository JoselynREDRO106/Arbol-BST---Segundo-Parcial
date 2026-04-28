#ifndef NODO_H
#define NODO_H
 
#include <string>
using namespace std;
 
// Estructura del empleado 
struct Empleado {
    int    codigo;
    string nombre;
    string cargo;
};
 
// Nodo del árbol BST 
struct Nodo {
    Empleado dato;
    Nodo*    izquierdo;
    Nodo*    derecho;
 
    Nodo(Empleado emp) {
        dato       = emp;
        izquierdo  = nullptr;
        derecho    = nullptr;
    }
};
 
#endif