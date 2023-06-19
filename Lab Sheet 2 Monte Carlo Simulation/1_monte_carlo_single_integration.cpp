#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
int N = 10;

using namespace std;
double func(double r);

int main(){
    double a, b;
    double sum = 0;
    srand(time(NULL));
	int i;
    a = 0;
    b = 3.1416;
    for(i=0;i<N;i++){
		double r = (double) rand()/RAND_MAX * (b-a) + a ;
		sum  += func(r);
    }
    float result = (b-a)/N * sum;
    cout<<result;
}

double func(double r){
	return sqrt(1+cos(r)*cos(r));
}

