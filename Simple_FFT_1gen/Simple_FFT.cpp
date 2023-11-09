#include "Simple_FFT.h"

const double T=2*M_PI; // length of the selection
double* f_t; // values of t[k]
complex<double> i(0,1.0);
FILE* spectrum;

double H_window(int step)
{
    return 1.0/2.0*(1-cos(2*M_PI*step/(n-1)));   
}

double O_window(int step)
{
    return 1.0;
}


complex<double>* FFT( double* f_t, double (* window) (int), complex<double>* f_w,FILE* out)
{
    static double C=1.0/pow(n,0.5);
    for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
                {
                    f_w[j]+=f_t[k]*window(k)*exp(2*M_PI/n*j*k*i);
                }
            f_w[j]*=C;
            fprintf(out,"%d % .3lf % .3e % .3e % .3e\n",j,f_t[j],real(f_w[j]),f_w[j].imag(),abs(f_w[j]));
        }
    return f_w;
}


double* f_generation(double (*f) (double),double time, int sapmles)
{
    double* f_out=(double*)malloc(n*sizeof(double));
    double h=time/n;                                            //step for time 
    for (int j=0; j<n;j++)
        {
                f_out[j]=f(h*j);
        }
    return f_out;
}



double function(double time)

    {
        return sin(time);
    }

/*int main()
{
    spectrum=fopen("func_samples.txt","w");
    //complex<double>* f_w=(complex<double>*)malloc(n*sizeof(complex<double>));
    complex<double>* f_w=FFT(f_generation(function));
    complex<double> z(1.0,1.0);
    //for(int j=0;j<n;j++)
    //    cout<<abs(f_w[j])<<"\n";

    //cout<<exp(z).real()<<"\n";
    //cout<<exp(3.0/4.0*M_PI*i)<<"\n";
    //system("pause");

}*/