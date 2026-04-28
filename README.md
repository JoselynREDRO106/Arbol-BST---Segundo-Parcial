# 🌳 Árbol Binario de Búsqueda (BST) Empresarial en C++

> Implementación de un Árbol Binario de Búsqueda para gestionar empleados de una empresa, usando el código numérico como clave de ordenamiento.

**Asignatura:** Estructura de Datos  
**Tema:** Árboles en C++  
**Semestre:** Enero – Junio 2026

---

## 📁 Estructura del proyecto

```
Arbol de busqueda/
├── Nodo.h        # Structs Empleado y Nodo
├── ArbolBST.h    # Clase ArbolBST con todas las operaciones
└── Main.cpp      # Menú interactivo y datos de prueba
```

---

## 🧠 ¿Qué hace el programa?

Organiza empleados en un árbol BST donde cada nodo almacena:

| Campo    | Tipo     | Descripción                              |
|----------|----------|------------------------------------------|
| `codigo` | `int`    | Clave única. Define la posición en el BST |
| `nombre` | `string` | Nombre completo del empleado             |
| `cargo`  | `string` | Puesto dentro de la empresa              |

### Propiedad BST
```
SubÁrbol izquierdo → códigos MENORES que la raíz
SubÁrbol derecho   → códigos MAYORES que la raíz
```

---

## 🗂️ Árbol de ejemplo (datos de prueba)

```
                    [50] Empresa UTA   ← RAÍZ
                   /                 \
      [30] Gerente Ventas        [70] Gerente Finanzas
        /          \               /              \
  [20] Emp1    [40] Emp2     [60] Emp3         [80] Emp4
   (hoja)       (hoja)        (hoja)            (hoja)

  Altura: 3  |  Hojas: 20, 40, 60, 80
```

---

## ⚙️ Funcionalidades

| Opción | Función                        | Complejidad   |
|--------|--------------------------------|---------------|
| 1      | Insertar empleado              | O(log n)      |
| 2      | Buscar empleado por código     | O(log n)      |
| 3      | Mostrar raíz                   | O(1)          |
| 4      | Recorrido inorden              | O(n)          |
| 5      | Recorrido preorden             | O(n)          |
| 6      | Recorrido postorden            | O(n)          |
| 7      | Altura del árbol               | O(n)          |
| 8      | Nodos hoja                     | O(n)          |
| 9      | Cargar datos de prueba         | —             |
| 0      | Salir                          | —             |

---

## 🚀 Compilación y ejecución

### Requisitos
- **MSYS2 MinGW 64-bit** (Windows) o `g++` en Linux/macOS
- C++11 o superior

### Compilar
```bash
g++ Main.cpp -o Main.exe -g
```

### Ejecutar
```bash
# Windows
./Main.exe

# Linux / macOS
./Main
```

---

## 📊 Recorridos con datos de prueba

**Inorden** *(orden ascendente)*
```
20 → 30 → 40 → 50 → 60 → 70 → 80
```

**Preorden** *(raíz primero)*
```
50 → 30 → 20 → 40 → 70 → 60 → 80
```

**Postorden** *(raíz al final)*
```
20 → 40 → 30 → 60 → 80 → 70 → 50
```

---

## 📚 Conceptos aplicados

- Árbol Binario de Búsqueda (BST)
- Recursividad (inserción, búsqueda, recorridos, altura)
- Punteros y memoria dinámica en C++
- Encapsulamiento con clases y headers separados
- Liberación de memoria con destructor recursivo

---

## 👤 Autor

**Joss** — Estudiante de Ingeniería  
Universidad Técnica de Ambato · 2026
