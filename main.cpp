#include <iostream>
#include "Dynarray.h"
#include "personas.h"
#include "calendario.h"
#include "Vector.h"
#include "vectorinventario.h"
#include "vectorestudiantes.h"
#include "temperaturas.h"
#include "controlcalidad.h"

#include <vector>
#include <string>

using namespace std;

// Declaración de funciones
int main();
void EjerDyna();
void EjerVect();
void Ejer1();
void Ejer2();
void Ejer3();
void Ejer4();
void Ejer5();
void Ejer1v();
void Ejer2v();
void Ejer3v();
void Ejer4v();
void Ejer5v();
void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int op = 1;
    do
    {
        cout << "[1] - Ejercicios de DynarrayPEL" << endl;
        cout << "[2] - Ejercicios de vector" << endl;
        cout << "[0] - Salir del Programa " << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            EjerDyna();
            break;
        case 2:
            EjerVect();
            break;
        default:
            break;
        }

    } while (op != 0);
}

void EjerDyna()
{
    int op = 1;
    do
    {
        cout << "[1] - Numeros (Insertar, Eliminar, Buscar) " << endl;
        cout << "[2] - Palabras (Ordenar alfabeticamente, Buscar una precisa) " << endl;
        cout << "[3] - Numeros(Suma, Promedio, Moda) " << endl;
        cout << "[4] - Ejercicio 4 " << endl;
        cout << "[5] - Ejercicio 5 " << endl;
        cout << "[0] - Salir del Programa " << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            Ejer1();
            break;
        case 2:
            Ejer2();
            break;
        case 3:
            Ejer3();
            break;
        case 4:
            Ejer4();
            break;
        case 5:
            Ejer5();
            break;
        default:
            break;
        }
    } while (op != 0);
}

void Ejer1()
{
    // Ejercicio que utiliza la clase Dynarray con números
    Dynarray<int> myDynarray;

    // Inserción de elementos
    myDynarray.insert(5);
    myDynarray.insert(10);
    myDynarray.insert(15);

    cout << "Dynarray después de la inserción: ";
    myDynarray.print();

    // Eliminación de un elemento
    myDynarray.remove(10);

    cout << "Dynarray después de la eliminación: ";
    myDynarray.print();

    // Búsqueda de elementos
    cout << "El elemento 5 " << (myDynarray.busqueda(5) ? "sí" : "no") << " está en el Dynarray." << endl;
    cout << "El elemento 10 " << (myDynarray.busqueda(10) ? "sí" : "no") << " está en el Dynarray." << endl;
}

void Ejer2()
{
    // Ejercicio que utiliza la clase Dynarray con cadenas (strings)
    Dynarray<string> myDynarray;

    // Insertar elementos
    myDynarray.insert("banana");
    myDynarray.insert("apple");
    myDynarray.insert("orange");

    // Imprimir el Dynarray antes de ordenar
    cout << "Dynarray antes de ordenar: ";
    myDynarray.print();

    // Ordenar el Dynarray alfabéticamente
    myDynarray.sort();

    // Imprimir el Dynarray después de ordenar
    cout << "Dynarray después de ordenar: ";
    myDynarray.print();

    // Buscar una cadena específica
    string searchString = "apple";
    if (myDynarray.containsString(searchString)) {
        cout << "El Dynarray contiene la cadena '" << searchString << "'" << endl;
    } else {
        cout << "El Dynarray no contiene la cadena '" << searchString << "'" << endl;
    }
}

void Ejer3()
{
    // Ejercicio que utiliza la clase Dynarray con números de punto flotante
    Dynarray<float> myDynarray;

    myDynarray.insert(15);
    myDynarray.insert(11);
    myDynarray.insert(1);
    myDynarray.insert(6);
    myDynarray.insert(19);

    myDynarray.print();

    myDynarray.sum();

    cout << myDynarray.promedio() << endl;

    cout << myDynarray.mode() << endl;
}

void Ejer4()
{
    // Ejercicio que utiliza la clase Dynarray con objetos de la clase personas
    Dynarray<personas> p;

    p.insert(personas("Manolo", 12));
    p.insert(personas("Juan", 13));
    p.insert(personas("Jose", 14));

    cout << "Personas en el array" << endl;

    p.print();
}

void Ejer5()
{
    // Ejercicio que utiliza la clase Dynarray con objetos de la clase calendario
    Dynarray<calendario> c;
    c.insert(calendario(1, 2, 1000));
    c.insert(calendario(1, 4, 1000));
    c.insert(calendario(12, 2, 1000));
    c.insert(calendario(1, 32, 24));

    cout << "Calendario" << endl;
    c.print();
}

void EjerVect()
{
    int op = 1;
    do
    {
        cout << "[1] - Tienda " << endl;
        cout << "[2] - Productos " << endl;
        cout << "[3] -  Escuela " << endl;
        cout << "[4] - Temperatura " << endl;
        cout << "[5] - Ejercicio 5 " << endl;
        cout << "[0] - Salir del Programa " << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            Ejer1v();
            break;
        case 2:
            Ejer2v();
            break;
        case 3:
            Ejer3v();
            break;
        case 4:
            Ejer4v();
            break;
        case 5:
            Ejer5v();
            break;
        default:
            break;
        }
    } while (op != 0);
}

void Ejer1v()
{
    // Ejercicio que simula una tienda utilizando la clase Vector
    const int daysInMonth = 30; // Cambia esto según la cantidad de días en el mes
    Vector salesVector(daysInMonth);

    // Simula la entrada de datos (nombre del producto y cantidad de ventas para cada día)
    for (int i = 0; i < daysInMonth; ++i) {
        string productName;
        int sales;

        cout << "Ingrese el nombre del producto para el día " << i + 1 << ": ";
        cin >> productName;

        cout << "Ingrese la cantidad de ventas para el día " << i + 1 << ": ";
        cin >> sales;

        salesVector.setElement(i, productName, sales);
    }

    // Calcula e imprime los resultados
    cout << "Suma total de ventas: " << salesVector.calculateTotalSum() << endl;
    cout << "Producto más vendido: " << salesVector.findMostSoldProduct() << endl;
    cout << "Día con menos ventas: " << salesVector.findDayWithLeastSales() << endl;
}

void Ejer2v()
{
    // Ejercicio que utiliza la clase vectorinventario
    const int numero_objetos = 10;
    vectorinventario invetario(numero_objetos);

    for (int i = 0; i < numero_objetos; i++) {
        string name;
        double precio;
        int numero;

        cout << "Ingrese el nombre del producto " << i + 1 << " : ";
        cin >> name;
        cout << "Ingrese el precio del " << name << " : ";
        cin >> precio;
        cout << "Ingrese la cantidad del " << name << " : ";
        cin >> numero;

        invetario.setelement(i, name, numero, precio);
    }

    // Calcula e imprime los resultados
    cout << "Valor total del inventario: " << invetario.valor_inv() << endl;
    cout << "Elemento con el precio mas alto: " << invetario.mas_alto() << endl;
    cout << "Promedio de unidades vendidas por producto: " << invetario.valor_inv() / numero_objetos << endl;
}

void Ejer3v()
{
    // Ejercicio que utiliza la clase VectorEstudiantes
    VectorEstudiantes<pair<string, pair<string, double>>> vectEstudiantes;

    // Agregar estudiantes con sus calificaciones y asignaturas
    vectEstudiantes.push_back({"Estudiante1", {"Asignatura1", 85.0}});
    vectEstudiantes.push_back({"Estudiante2", {"Asignatura1", 90.0}});
    vectEstudiantes.push_back({"Estudiante3", {"Asignatura2", 78.0}});
    vectEstudiantes.push_back({"Estudiante4", {"Asignatura2", 92.0}});
    vectEstudiantes.push_back({"Estudiante5", {"Asignatura3", 88.0}});
    vectEstudiantes.push_back({"Estudiante6", {"Asignatura3", 95.0}});

    // Calcular el promedio de calificaciones por asignatura
    cout << "Promedio Asignatura1: " << calcularPromedioAsignatura(vectEstudiantes, "Asignatura1") << endl;
    cout << "Promedio Asignatura2: " << calcularPromedioAsignatura(vectEstudiantes, "Asignatura2") << endl;
    cout << "Promedio Asignatura3: " << calcularPromedioAsignatura(vectEstudiantes, "Asignatura3") << endl;

    // Encontrar al estudiante con el mejor desempeño
    auto mejorEstudiante = encontrarMejorEstudiante(vectEstudiantes);
    cout << "Mejor Estudiante: " << mejorEstudiante.first << " - Calificación: " << mejorEstudiante.second << endl;

    // Encontrar la asignatura con la mayor dispersión de calificaciones
    string asignaturaMayorDispersion = encontrarAsignaturaMayorDispersion(vectEstudiantes);
    cout << "Asignatura con Mayor Dispersión: " << asignaturaMayorDispersion << endl;
}

void Ejer4v()
{
    // Ejercicio que utiliza la clase temperaturas
    const int numero_dias = 10;
    temperaturas temps(numero_dias);

    temps.implement(1, 25.0, 0);
    temps.implement(2, 20.0, 1);
    temps.implement(3, 28.0, 2);
    temps.implement(4, 18.0, 3);
    temps.implement(5, 22.0, 4);

    cout << "Min Temperature: " << temps.tem_min() << endl;
    cout << "Max Temperature: " << temps.tem_max() << endl;
    cout << "Number of temperatures above 20: " << temps.sup(20.0) << endl;
}

void Ejer5v()
{
    // Crear un ControlCalidad de medidas de tipo double
    ControlCalidad<double> controlcalidad(5);

    // Establecer medidas en posiciones específicas
    controlcalidad.setMeasure(0, 10.5);
    controlcalidad.setMeasure(1, 12.3);
    controlcalidad.setMeasure(2, 11.8);
    controlcalidad.setMeasure(3, 10.0);
    controlcalidad.setMeasure(4, 13.2);

    // Calcular y mostrar la media de las medidas
    cout << "Media de las medidas: " << controlcalidad.calculateMean() << endl;

    // Calcular y mostrar el rango de variación de las medidas
    cout << "Rango de variacion: " << controlcalidad.calculateRange() << endl;

    // Calcular y mostrar la proporción de productos que cumplen con ciertas especificaciones
    double lowerBound = 10.0;
    double upperBound = 12.0;
    cout << "Proporcion de productos dentro del rango [" << lowerBound << ", " << upperBound << "]: "
         << controlcalidad.calculateProportion(lowerBound, upperBound) << endl;

}