#include <iostream>
#include <vector>
#include <numeric>     // Para std::accumulate
#include <algorithm>   // Para std::min_element y std::max_element
#include <functional>  // Para std::count_if

using namespace std;

template <typename T>
class ControlCalidad
{
private:
    vector<T> controlcalidad;

public:
    ControlCalidad(int size) : controlcalidad(size) {}

    // Función para establecer una medida en una posición específica
    void setMeasure(int index, T measure)
    {
        controlcalidad[index] = measure;
    }

    // Función para calcular la media de las medidas
    double calculateMean() const
    {
        if (controlcalidad.empty())
            return 0.0;

        double sum = accumulate(controlcalidad.begin(), controlcalidad.end(), 0.0);
        return sum / controlcalidad.size();
    }

    // Función para calcular el rango de variación de las medidas
    T calculateRange() const
    {
        if (controlcalidad.empty())
            return 0;

        T minMeasure = *min_element(controlcalidad.begin(), controlcalidad.end());
        T maxMeasure = *max_element(controlcalidad.begin(), controlcalidad.end());

        return maxMeasure - minMeasure;
    }

    // Función para calcular la proporción de productos que cumplen con ciertas especificaciones
    double calculateProportion(T lowerBound, T upperBound) const
    {
        if (controlcalidad.empty())
            return 0.0;

        int countWithinBounds = count_if(controlcalidad.begin(), controlcalidad.end(), [&](const T &measure) {
            return measure >= lowerBound && measure <= upperBound;
        });

        return static_cast<double>(countWithinBounds) / controlcalidad.size();
    }
};

