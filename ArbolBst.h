#ifndef ARBOLBST_H
#define ARBOLBST_H

#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

//  Clase Árbol Binario de Búsqueda 
class ArbolBST {
private:
    Nodo* raiz;

    //  Insertar recursivo 
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr)
            return new Nodo(emp);

        if (emp.codigo < nodo->dato.codigo)
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        else if (emp.codigo > nodo->dato.codigo)
            nodo->derecho = insertar(nodo->derecho, emp);
        else
            cout << "  [!] El codigo " << emp.codigo << " ya existe.\n";

        return nodo;
    }

    //  Buscar recursivo 
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo)
            return nodo;
        if (codigo < nodo->dato.codigo)
            return buscar(nodo->izquierdo, codigo);
        else
            return buscar(nodo->derecho, codigo);
    }

    //  Recorridos 
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    //  Altura 
    int altura(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int altIzq = altura(nodo->izquierdo);
        int altDer = altura(nodo->derecho);
        return 1 + max(altIzq, altDer);
    }

    //  Nodos hoja 
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr)
                mostrarEmpleado(nodo);
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    //  Mostrar un empleado 
    void mostrarEmpleado(Nodo* nodo) {
        cout << "  Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: "  << nodo->dato.cargo << "\n";
    }

    //  Destructor recursivo 
    void destruir(Nodo* nodo) {
        if (nodo == nullptr) return;
        destruir(nodo->izquierdo);
        destruir(nodo->derecho);
        delete nodo;
    }

public:
    ArbolBST() : raiz(nullptr) {}
    ~ArbolBST() { destruir(raiz); }

    //  Métodos públicos 
    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* res = buscar(raiz, codigo);
        if (res != nullptr) {
            cout << "\n  Empleado encontrado:\n";
            mostrarEmpleado(res);
        } else {
            cout << "\n  [!] Empleado con codigo " << codigo << " no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n  Raiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "  El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\n  Recorrido Inorden (orden ascendente por codigo):\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\n  Recorrido Preorden (raiz, izquierdo, derecho):\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\n  Recorrido Postorden (izquierdo, derecho, raiz):\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\n  Altura del arbol: " << altura(raiz) << "\n";
    }

    void mostrarNodosHoja() {
        cout << "\n  Nodos hoja (sin hijos):\n";
        mostrarHojas(raiz);
    }
};

#endif