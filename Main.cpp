#include <iostream>
#include <string>
#include <limits>
#include "ArbolBST.h"

using namespace std;

// ─── Cargar datos de prueba según la guía ─────────────────────
void cargarDatosPrueba(ArbolBST& arbol) {
    Empleado datos[] = {
        {50, "Empresa UTA",      "Raiz"},
        {30, "Gerente Ventas",   "Nodo interno"},
        {70, "Gerente Finanzas", "Nodo interno"},
        {20, "Emp 1",            "Hoja"},
        {40, "Emp 2",            "Hoja"},
        {60, "Emp 3",            "Hoja"},
        {80, "Emp 4",            "Hoja"}
    };
    for (auto& e : datos)
        arbol.insertarEmpleado(e);
    cout << "  [OK] Datos de prueba cargados (7 empleados).\n";
}

// ─── Main ──────────────────────────────────────────────────────
int main() {
    ArbolBST arbol;
    int opcion;

    do {
        cout << "\n========================================\n";
        cout << "   MENU - ARBOL BST EMPRESARIAL\n";
        cout << "========================================\n";
        cout << " 1. Insertar empleado\n";
        cout << " 2. Buscar empleado por codigo\n";
        cout << " 3. Mostrar raiz\n";
        cout << " 4. Recorrido inorden\n";
        cout << " 5. Recorrido preorden\n";
        cout << " 6. Recorrido postorden\n";
        cout << " 7. Mostrar altura del arbol\n";
        cout << " 8. Mostrar nodos hoja\n";
        cout << " 9. Cargar datos de prueba\n";
        cout << " 0. Salir\n";
        cout << "----------------------------------------\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
        }

        switch (opcion) {
            case 1: {
                Empleado emp;
                cout << "\n  Codigo  : "; cin >> emp.codigo;
                cin.ignore();
                cout << "  Nombre  : "; getline(cin, emp.nombre);
                cout << "  Cargo   : "; getline(cin, emp.cargo);
                arbol.insertarEmpleado(emp);
                cout << "  [OK] Empleado insertado.\n";
                break;
            }
            case 2: {
                int cod;
                cout << "\n  Codigo a buscar: "; cin >> cod;
                arbol.buscarEmpleado(cod);
                break;
            }
            case 3:  arbol.mostrarRaiz();      break;
            case 4:  arbol.mostrarInorden();   break;
            case 5:  arbol.mostrarPreorden();  break;
            case 6:  arbol.mostrarPostorden(); break;
            case 7:  arbol.mostrarAltura();    break;
            case 8:  arbol.mostrarNodosHoja(); break;
            case 9:  cargarDatosPrueba(arbol); break;
            case 0:  cout << "\n  Saliendo...\n"; break;
            default: cout << "\n  [!] Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}