// labsheet 2 stokc market

#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{
    double S[16][1000];
    // initail stock for CBA-AU
    double mu = 0.0518;      // expected annual return
    double sigma = 0.1663;   // expected annual volatility
    double dt = 1.0 / 250.0; // time increment assuming 250 days

    double var_cal[16] = {0};
    double bc = 0, aa,ab;

    int count;
    double mean[16] = {0};
    int i, j;
    ofstream fout("stock_data.csv");
    // save the initial values

    for (i = 0; i < 1000; i++)
    {
        // initialize Random number generator
        default_random_engine generator;
        generator.seed(rand() % 1000);                  // set the seed
        normal_distribution<double> distribution(0, 1); // mean 0, var 1
        S[0][i] = 77.84;
        count = 1;
        fout << "\n"
             << i + 1 << "," << S[0][i] << ",";
        while (count <= 15) // make prediction for 15 days
        {
            double epsilon = distribution(generator);
            S[count][i] = S[count - 1][i] * exp((mu - sigma * sigma / 2) * dt + sigma * epsilon * sqrt(dt));
            fout << S[count][i] << ",";
            mean[count] = mean[count] + S[count][i] / 1000;
            count++;
        }
    }
    fout.close();


    for ( j = 1; j <= 15; j++)
    {
            for ( i = 0; i < 1000; i++)
            {
                ab = pow(abs(S[j][i] - mean[j]), 2);
                bc += ab;

        }
         aa=S[j][i] - mean[j];
        double b= pow(aa,2);
        cout<<bc<<"\t"<<aa<<b<<endl;
        var_cal[j] =  bc/1000;

    }
    // 95% confidence interval

    ofstream fout1("stock_mean.csv");



    double final_result1[16], final_result2[16];
    fout1<<"Upper, Mean, Lower bound\n";
    for ( j = 1; j <= 15; j++)
    {
        final_result1[j] = mean[j] - 1.96 * (var_cal[j] / sqrt(1000));

        final_result2[j] = mean[j] + 1.96 * (var_cal[j] / sqrt(1000));
    }
    for (count = 1; count <= 15; count++)
    {
        fout1<< final_result1[count] << ",";
        fout1<< mean[count] << ",";
        fout1<< final_result2[count]<<"\n";
    }


    fout1.close() ;
    return 0;


}
