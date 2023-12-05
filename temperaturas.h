#include <iostream>
#include <string>
#include <vector>

using namespace std;

class temperaturas
{
private:
    vector<pair<int, double>> t;
public:
    temperaturas(int size ) : t(size){}

    void implement( int d, double temp, int index )
    {
        t[index] = make_pair(d,temp);
    }

    double tem_min() const{
        double tem = 1000;
        for(const auto& temperatura : t)
        {
            if(tem < temperatura.second)
            {
                tem = temperatura.second;
            }
        }

        return tem;
    }

    double tem_max() const{
        double tem = 0;
        for(const auto& temperatura : t)
        {
            if(tem > temperatura.second)
            {
                tem = temperatura.second;
            }
        }

        return tem;
    }

    int sup(double temp) const{
        int supe = 0;
        for(const auto& temperatura : t)
        {
            if(temp < temperatura.second)
            {
                ++supe;
            }
        }

        return supe;
    }


};

