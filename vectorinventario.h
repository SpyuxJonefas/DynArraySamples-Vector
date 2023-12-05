#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vectorinventario
{
private:
    vector<pair<string, pair<double, int>>> vectorInven;
public:

    vectorinventario(int size) : vectorInven(size){}

    void setelement(int index, const string& name, int numero, double precio)
    {
        vectorInven[index] = make_pair(name,make_pair(precio, numero));
    }

    double valor_inv() const
    {
        double inv = 0;
        for(const auto& product : vectorInven)
        {
            inv += product.second.first * product.second.second;
        }
        return inv;
    }

    string mas_alto() const{

        string n;
        int aux = 0;
        for(const auto& product : vectorInven)
        {
            if(product.second.second > aux)
            {
                n = product.first;
            }
        }

        return n;
    }


};




