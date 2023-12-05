#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
class VectorEstudiantes
{
private:
    vector<T> data;

public:
    VectorEstudiantes() {}

    // Agregar un elemento al vector
    void push_back(const T &element)
    {
        data.push_back(element);
    }

    // Obtener el tamaño del vector
    int size() const
    {
        return data.size();
    }

    // Obtener el elemento en una posición dada
    T &operator[](int index)
    {
        return data[index];
    }

    // Obtener el elemento en una posición dada (versión constante)
    const T &operator[](int index) const
    {
        return data[index];
    }

    // Iterador de inicio (begin)
    typename vector<T>::iterator begin()
    {
        return data.begin();
    }

    // Iterador de fin (end)
    typename vector<T>::iterator end()
    {
        return data.end();
    }

    // Iterador de inicio (begin) constante
    typename vector<T>::const_iterator begin() const
    {
        return data.begin();
    }

    // Iterador de fin (end) constante
    typename vector<T>::const_iterator end() const
    {
        return data.end();
    }
};

// Función para calcular el promedio de calificaciones por asignatura
double calcularPromedioAsignatura(const VectorEstudiantes<pair<string, pair<string, double>>> &vectEstudiantes, const string &asignatura)
{
    double sumaCalificaciones = 0.0;
    int cantidadEstudiantes = 0;

    for (const auto &estudiante : vectEstudiantes)
    {
        if (estudiante.second.first == asignatura)
        {
            sumaCalificaciones += estudiante.second.second;
            cantidadEstudiantes++;
        }
    }

    return cantidadEstudiantes > 0 ? sumaCalificaciones / cantidadEstudiantes : 0.0;
}

// Función para encontrar al estudiante con el mejor desempeño
pair<string, double> encontrarMejorEstudiante(const VectorEstudiantes<pair<string, pair<string, double>>> &vectEstudiantes)
{
    pair<string, double> mejorEstudiante = {"", 0.0};

    for (const auto &estudiante : vectEstudiantes)
    {
        if (estudiante.second.second > mejorEstudiante.second)
        {
            mejorEstudiante = {estudiante.first, estudiante.second.second};
        }
    }

    return mejorEstudiante;
}

// Función para encontrar la asignatura con la mayor dispersión de calificaciones
string encontrarAsignaturaMayorDispersion(const VectorEstudiantes<pair<string, pair<string, double>>> &vectEstudiantes)
{
    string asignaturaMayorDispersion = "";
    double mayorDispersion = 0.0;

    for (const auto &estudiante : vectEstudiantes)
    {
        double promedioAsignatura = calcularPromedioAsignatura(vectEstudiantes, estudiante.second.first);
        double dispersion = abs(estudiante.second.second - promedioAsignatura);

        if (dispersion > mayorDispersion)
        {
            mayorDispersion = dispersion;
            asignaturaMayorDispersion = estudiante.second.first;
        }
    }

    return asignaturaMayorDispersion;
}
