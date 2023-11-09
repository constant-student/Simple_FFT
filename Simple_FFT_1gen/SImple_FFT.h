
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex>
#include <cmath>
#include <iostream>

#define n 100 // amount of sapmles for time

using namespace std;

extern const double T; // length of the selection
extern double* f_t; // values of t[k]
extern complex<double> i;
extern FILE* spectrum;

double H_window(int step);

double O_window(int step);

complex<double>* FFT( double* f_t, double (*window) (int)=O_window, complex<double>* f_w=(complex<double>*)malloc(n*sizeof(complex<double>)),FILE* out=spectrum);

double* f_generation(double (*f) (double)=sin,double time=T, int sapmles=n);

double function(double time);