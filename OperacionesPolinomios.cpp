#include <iostream>

using std::cout;
using std::endl;

float EvaluarPolinomio(float *coeficientes,int tam,float x)
{
    float evaluacion = coeficientes[0];
    for(int i=1;i<tam;++i){
        evaluacion= evaluacion*x + coeficientes[i];
    }

    return evaluacion;
}
