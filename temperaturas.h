#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la clase temperaturas
class temperaturas
{
private:
    vector<pair<int, double>> t;  // Vector que almacena pares de día y temperatura
public:
    // Constructor que inicializa el vector con un tamaño especificado
    temperaturas(int size) : t(size) {}

    // Método para asignar una temperatura a un día específico en el vector
    void implement(int d, double temp, int index)
    {
        t[index] = make_pair(d, temp);
    }

    // Método que devuelve la temperatura mínima en el conjunto de datos
    double tem_min() const
    {
        double tem = 1000;
        for (const auto &temperatura : t)
        {
            if (tem > temperatura.second)
            {
                tem = temperatura.second;
            }
        }
        return tem;
    }

    // Método que devuelve la temperatura máxima en el conjunto de datos
    double tem_max() const
    {
        double tem = 0;
        for (const auto &temperatura : t)
        {
            if (tem < temperatura.second)
            {
                tem = temperatura.second;
            }
        }
        return tem;
    }

    // Método que devuelve la cantidad de días con temperatura superior a un valor dado
    int sup(double temp) const
    {
        int supe = 0;
        for (const auto &temperatura : t)
        {
            if (temp < temperatura.second)
            {
                ++supe;
            }
        }
        return supe;
    }
};