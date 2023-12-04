#include <iostream>

using namespace std;

class personas
{
private:
    string nombre;
    int edad;
public:
    personas(): nombre(" "), edad(0){}

    personas(const string& n,  int e) : nombre(n), edad(e){}

    friend std::ostream& operator<<(std::ostream& os, const personas& persona) {
        os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad;
        return os;
    }


};

