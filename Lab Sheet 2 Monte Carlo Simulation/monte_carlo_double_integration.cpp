#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
int N = 50000;

using namespace std;
double func(double x, double y);

int main(){
    double a, b, c, d;
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
    	double dy = (double) rand()/RAND_MAX * (d-c) + c;
    	
    	sum  += func(dx,dy);
    }
    float result = (b-a)*(d-c)*sum/N;
    cout<<result;
}

double func(double x, double y){
	return sqrt(pow(x,4)+y);
}
