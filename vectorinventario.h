#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la clase vectorinventario
class vectorinventario
{
private:
    vector<pair<string, pair<double, int>>> vectorInven;  // Vector que almacena pares de nombre, precio, y cantidad
public:

    // Constructor que inicializa el vector con un tamaño especificado
    vectorinventario(int size) : vectorInven(size) {}

    // Método para establecer un elemento en el vector con nombre, número y precio dados
    void setelement(int index, const string& name, int numero, double precio)
    {
        vectorInven[index] = make_pair(name, make_pair(precio, numero));
    }

    // Método que devuelve el valor total del inventario
    double valor_inv() const
    {
        double inv = 0;
        for(const auto& product : vectorInven)
        {
            inv += product.second.first * product.second.second;
        }
        return inv;
    }

    string mas_alto() const
    {
        string n;
        int aux = 0;
        for(const auto& product : vectorInven)
        {
            if(product.second.second > aux)
            {
                n = product.first;
                aux = product.second.second;  // Actualizar el valor máximo
            }
        }
        return n;
    }
};