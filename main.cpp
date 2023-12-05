#include <iostream>
#include "Dynarray.h"
#include "personas.h"
#include "calendario.h"
#include "Vector.h"

#include <vector>
#include <string>

using namespace std;

int main();
void EjerDyna();
void EjerVect();
void Ejer1();
void Ejer2();
void Ejer3();
void Ejer4();
void Ejer5();
void Ejer1v();

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
        cout << "[1] - Ejercicios de DynarrayPEL"<< endl;
        cout << "[2] - Ejercicios de vector"<< endl;
        cout << "[0] - Salir del Programa "<< endl;
        cin>> op;
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
        cout << "[1] - Numeros (Insertar, Eliminar, Buscar) "<< endl;
        cout << "[2] - Palabras (Ordenar alfabeticamente, Buscar una precisa) "<< endl;
        cout << "[3] - Numeros(Suma, Promedio, Moda) "<< endl;
        cout << "[4] - Ejercicio 4 "<< endl;
        cout << "[5] - Ejercicio 5 "<< endl;
        cout << "[0] - Salir del Programa "<< endl;

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
    }while (op != 0);
    
}

void Ejer1()
{
    Dynarray <int> myDynarray;

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
    Dynarray<float>myDynarray;

    myDynarray.insert(15);
    myDynarray.insert(11);
    myDynarray.insert(1);
    myDynarray.insert(6);
    myDynarray.insert(19);

    myDynarray.print();

    myDynarray.sum();

    cout <<  myDynarray.promedio() << endl;

    cout << myDynarray.mode() << endl;
}

void Ejer4()
{
    Dynarray <personas> p;

    p.insert(personas("Manolo", 12));
    p.insert(personas("Juan", 13));
    p.insert(personas("Jose", 14));

    cout << "Personas en el array" << endl;

    p.print();

}

void Ejer5()
{
    Dynarray <calendario> c;
    c.insert(calendario(1,2,1000));
    c.insert(calendario(1,4,1000));
    c.insert(calendario(12,2,1000));
    c.insert(calendario(1,32,24));

    cout <<"Calendario"<< endl;
    c.print();

}

void EjerVect()
{
    int op = 1;
    do
    {
        cout << "[1] - Tienda "<< endl;
        cout << "[2] - Ejercicio 2 "<< endl;
        cout << "[3] - Ejercicio 3 "<< endl;
        cout << "[4] - Ejercicio 4 "<< endl;
        cout << "[5] - Ejercicio 5 "<< endl;
        cout << "[0] - Salir del Programa "<< endl;

        cin >> op;

        switch (op)
        {
        case 1:
            Ejer1v();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        
        
        default:
            break;
        }
    }while (op != 0);
}

void Ejer1v()
{
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