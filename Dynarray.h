#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>  // Para std::sort
#include <unordered_map>

using namespace std;

// Declaración de la plantilla de clase Dynarray
template <typename T>
class Dynarray
{
private:
    T* Array;        // Puntero al array dinámico
    size_t size;     // Tamaño actual del array
    size_t cap;      // Capacidad máxima del array

public:
    // Constructor por defecto
    Dynarray() : Array(nullptr), size(0), cap(0) {}

    // Destructor
    ~Dynarray()
    {
        delete[] Array; // Libera la memoria asignada al array dinámico
    }

    // Método para insertar un elemento en el array
    void insert(const T& value)
    {
        if (size == cap)
        {
            cap = (cap == 0) ? 1 : cap * 2; // Duplica la capacidad o establece en 1 si es la primera inserción

            T* newArray = new T[cap]; // Crea un nuevo array con la nueva capacidad

            for (size_t i = 0; i < size; i++)
            {
                newArray[i] = Array[i]; // Copia los elementos del array anterior al nuevo array
            }
            delete[] Array; // Libera la memoria del array anterior

            Array = newArray; // Actualiza el puntero al nuevo array
        }
        Array[size++] = value; // Inserta el nuevo elemento y actualiza el tamaño
    }

    // Método para eliminar un elemento del array
    void remove(const T& value)
    {
        size_t index = 0;

        // Busca el índice del elemento a eliminar
        while (index < size && Array[index] != value)
        {
            ++index;
        }

        if (index == size)
        {
            throw std::out_of_range("No ha sido encontrado"); // Lanza una excepción si el elemento no se encuentra
        }

        // Desplaza los elementos hacia la izquierda para llenar el espacio del elemento eliminado
        for (size_t i = index; i < size; i++)
        {
            Array[i] = Array[i + 1];
        }

        --size; // Reduce el tamaño del array
    }

    // Método para buscar un elemento en el array
    bool busqueda(const T& value) const
    {
        for (size_t i = 0; i < size; i++)
        {
            if (Array[i] == value)
            {
                return true; // Devuelve true si encuentra el elemento
            }
        }
        return false; // Devuelve false si no encuentra el elemento
    }

    // Método para imprimir los elementos del array
    void print() const
    {
        cout << "Estos son los elementos del array: " << endl;
        for (size_t i = 0; i < size; i++)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }
    // Ordena el Dynarray alfabéticamente
    void sort()
    {
        std :: sort(Array, Array + size);
    }

    // Busca una cadena específica en el arreglo
    bool containsString(const string& str) const {
        for (size_t i = 0; i < size; ++i) {
            if (Array[i] == str) {
                return true;
            }
        }
        return false;
    }

    //Suma de toda la cadena de numeros dentro del Array uno a uno
    T sum() const {
        T result = 0;
        for (size_t i = 0; i < size; ++i) {
            result += Array[i];
        }
        cout << result << endl;
        return result;
    }

    // Promedio sería mencionar a la suma de todo y dividirlo entre dos

    T promedio() const
    {
        if (size == 0) {
            throw std::logic_error("Cannot calculate average of an empty Dynarray");
        }

        return static_cast<double>(sum()) / size;
    }


};

