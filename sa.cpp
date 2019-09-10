#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double fx(double x1, double x2) {
  return ((2*pow(x1,2) + pow(x2,4)/3)*pow(x1,2)-(x1*x2)+(4*pow(x2,2))*pow(x2,2));
} //fungsinya

double fRand(double fMin, double fMax){
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
} //random

double delta(double z, double min, double T) /** fungsi untuk menghitung P(deltaE,T) **/
{
    double p = -(z - min) / T; /** rumus delta E / T **/
    return pow(exp(1), p);
}

int main()
{

  srand (time(NULL));
  double x1 = fRand(-1,1);
  double x2 = fRand(-1,1);
  double T0 = 100000; // T awal
  double T1 = 0.000001; // T akhir
  double a = 0.99; // cooling rate
  double x1min = x1;
  double x2min = x2;
  double min = fx(x1,x2);
  double z;

  while (T0 > T1) {
    int i = 1;
    while (i<=100) {
      x1 = x1 + fRand(-1,1);
      x2 = x2 + fRand(-1,1);
      z = fx(x1,x2);
      if (z < min || (delta(z,min,T0) > (fRand(0,1)))) {
        min = z;
        x1min = x1;
        x2min = x2;
      }
      i++;
    }
    T0 = T0 * a;
  }
  cout<<"nilai minimum: "<<min<<" x1: "<<x1min<<" x2: "<<x2min<<endl;
  return 0;
}
