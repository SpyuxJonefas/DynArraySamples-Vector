#include <iostream>
#include "Dynarray.h"

using namespace std;

int main();
void EjerDyna();
void EjerVect();
void Ejer1();
void Ejer2();
void Ejer3();

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
}
