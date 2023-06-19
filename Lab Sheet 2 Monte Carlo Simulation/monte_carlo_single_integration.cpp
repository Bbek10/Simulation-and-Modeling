#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
int N = 10;

using namespace std;
double func(double r);

double sumIntegral()

int main(){
    double a, b;
    //a lower limit 
    //b upper limit 
    double sum = 0;
    srand(time(NULL));

    a = 0;
    b = 2;
    c = 0;
	d = 8;    
    
    int i;
    //dx
    for(i=0;i<N;i++){
    	double dx = (double) rand()/RAND_MAX * (b-a) + a ;
    	double dy = (double) rand()/RAND_MAX * (d-c) + b;
    	
    	sum  += func(dx,dy) * b;
    }
    float result = sum/N;
    cout<<result;
}

double func(double r){
	return sqrt(1+cos(r)*cos(r));
}
