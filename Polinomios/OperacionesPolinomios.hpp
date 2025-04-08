#ifndef OPERACIONESPOLINOMIOS_HPP_INCLUDED
#define OPERACIONESPOLINOMIOS_HPP_INCLUDED

double EvaluarPolinomio(double *coeficientes,int tam,float x);
double* DerivarPolinomio(double *polinomio, int tam);
void DivisionPolinomios(const double *P, int TamP, const double *Q, int TamQ, double *&C, int &TamC, double *&R, int &TamR);


double *SumaPolinomios(double *P,int gradoP, double *Q, int gradoQ,int &gradoR);
double *RestaPolinomios(double *P,int gradoP, double *Q, int gradoQ,int &gradoR);

double* Multiplicacion(double* P, int TamP, double* Q, int TamQ, int& TamR);


#endif // OPERACIONESPOLINOMIOS_HPP_INCLUDED
