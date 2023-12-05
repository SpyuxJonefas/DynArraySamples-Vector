
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vector {
public:
    // Constructor que inicializa el vector de pares
    Vector(int size);

    // Métodos para operar sobre el vector de pares
    void setElement(int index, const string& productName, int sales);
    int calculateTotalSum() const;
    string findMostSoldProduct() const;
    string findDayWithLeastSales() const;

private:
    vector<pair<string, int>> salesVector;
};

// Constructor que inicializa el vector de pares
Vector::Vector(int size) : salesVector(size) {}

// Establece el nombre del producto y la cantidad de ventas para un día específico
void Vector::setElement(int index, const string& productName, int sales) {
    salesVector[index] = make_pair(productName, sales);
}

// Calcula la suma total de las ventas
int Vector::calculateTotalSum() const {
    int sum = 0;
    for (const auto& product : salesVector) {
        sum += product.second;
    }
    return sum;
}

// Encuentra el producto más vendido
string Vector::findMostSoldProduct() const {
    string mostSoldProduct = "";
    int maxSales = 0;

    for (const auto& product : salesVector) {
        if (product.second > maxSales) {
            maxSales = product.second;
            mostSoldProduct = product.first;
        }
    }

    return mostSoldProduct;
}

// Encuentra el día con menos ventas
string Vector::findDayWithLeastSales() const {
    string dayWithLeastSales = salesVector[0].first;
    int minSales = salesVector[0].second;

    for (const auto& product : salesVector) {
        if (product.second < minSales) {
            minSales = product.second;
            dayWithLeastSales = product.first;
        }
    }

    return dayWithLeastSales;
}