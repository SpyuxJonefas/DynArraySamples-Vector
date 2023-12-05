#include <iostream>

using namespace std;

class calendario
{
private:
    int dia;
    int mes;
    int ano;
public:
    calendario() : dia(0), mes(0), ano(0)    {}

    calendario(int d, int m, int a) : dia(d), mes(m), ano(a){}

    friend std :: ostream& operator<<(std :: ostream& os, const calendario& cal)
    {
        os << cal.dia <<"/"<< cal.mes<<"/"<< cal.ano;
        return os;
    }
    
};


