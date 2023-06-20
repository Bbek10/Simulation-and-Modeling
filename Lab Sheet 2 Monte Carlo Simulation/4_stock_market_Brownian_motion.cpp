//PREDICTING STOCK MARKET PRICE LAB SHEET 2

#include<iostream>
#include<cstdlib>
#include<random>
#include<fstream>
#include<cmath>
#include<ctime>

using namespace std;

int main(){
	double S = 77.84;	//initail stock for CBA-AU
	double mu = 0.0518;	//expected annual return
	double sigma = 0.1663;	//expected annual volatility
	double dt  = 1.0/250.0;	//time increment assuming 250 days
	
	//initialize Random number generator
	default_random_engine generator;
	generator.seed(123);	//set the seed
	normal_distribution<double> distribution(0,1);	//mean 0, var 1 
	ofstream fout("Stock.csv");
	//save the initial values
	fout<<"Trading Dat, stock price\n";
	fout<<0<<","<<S<<"\n";
	//make prediction for 15 days
	int count = 1;
	while(count <= 15){
		double epsilon = distribution(generator);
		S = S * exp((mu-sigma*sigma/2)*dt+sigma * epsilon * sqrt(dt));
		fout<<count<<","<<S<<"\n";
		count++;
	}
	fout.close();
	return 0;
	
}
