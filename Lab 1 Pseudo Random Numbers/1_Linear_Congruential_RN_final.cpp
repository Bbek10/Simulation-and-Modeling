#include <iostream>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

int main()
{

    long a, c, m, Z, nSample;
    long print;
    float rand;

    nSample = 10000; // no. of random numbers
    Z = 1234;       // seed


    a = 1664525, c = 1013904223, m = 256  ;

    ofstream fout("linearRN1.csv");
    fout<<"Random Numbers"<<"\n";

    for (int i = 0; i < nSample; i++)
    {
        Z = (a * Z + c) % m;
        print = Z;
        rand = static_cast<float>(print) / m;
        fout<<rand<< "\n";

    }

        // cout << Z;


    fout.close();
    return 0;
}
