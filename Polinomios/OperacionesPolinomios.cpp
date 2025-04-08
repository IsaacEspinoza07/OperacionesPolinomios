#include <iostream>

using std::cout;
using std::endl;


double *SumaPolinomios(double *P,int gradoP, double *Q, int gradoQ,int &gradoR)
{
    double *R;
    if(gradoP > gradoQ){
        gradoR = gradoP;

    }else{
        gradoR = gradoQ;
    }

    R = new double [gradoR]{0};


    for(int i=0;i<gradoR;++i){
        if(i < gradoP){
            R[gradoR-gradoP+i] += P[i];
        }
        if(i < gradoQ){
            R[gradoR-gradoQ+i] += Q[i];
        }
    }


    return R;
}


double *RestaPolinomios(double *P,int gradoP, double *Q, int gradoQ,int &gradoR)
{
    double *R;
    if(gradoP > gradoQ){
        gradoR = gradoP;

    }else{
        gradoR = gradoQ;
    }

    R = new double [gradoR]{0};

    for(int i=0;i<gradoR;++i){
        if(i < gradoP){
            R[gradoR-gradoP+i] += P[i];
        }
        if(i < gradoQ){
            R[gradoR-gradoQ+i] -= Q[i];
        }
    }

    return R;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double EvaluarPolinomio(double *coeficientes,int tam,float x)
{
    float evaluacion = coeficientes[0];
    for(int i=1;i<tam;++i){
        evaluacion= evaluacion*x + coeficientes[i];
    }

    return evaluacion;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double *DerivarPolinomio(double *polinomio, int tam)
{

    double *R = new double [tam]{0};

    for(int i=0;i<tam-1;++i){
        R[i] = polinomio[i]*(tam-i-1);
    }


    return R;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DivisionPolinomios(const double *P, int TamP, const double *Q, int TamQ, double *&C, int &TamC, double *&R, int &TamR) {
    if (TamQ == 0 || Q[0] == 0) throw "Division por 0";

    // Caso especial: Si el divisor (Q) tiene mayor grado que el dividendo (P)
    if (TamQ > TamP) {
        TamC = 0;
        C = new double[1];
        C[0] = 0.0; // Cociente = 0

        TamR = TamP;
        R = new double[TamR];
        for (int i = 0; i < TamR; ++i) {
            R[i] = P[i]; // Residuo = P (copia exacta)
        }
        return;
    }

    TamC = TamP - TamQ; // Grado del cociente = Grado(P) - Grado(Q)
    TamR = TamQ - 1;    // Grado del residuo = Grado(Q) - 1 (máximo posible)

    C = new double[TamC + 1]; // +1 porque un polinomio de grado n tiene n+1 coeficientes
    R = new double[TamR + 1];

    // Copiamos P a un arreglo auxiliar D (para no modificar P directamente)
    double *D = new double[TamP];
    for (int i = 0; i < TamP; ++i) {
        D[i] = P[i];
    }

    // Algoritmo de división de polinomios
    for (int i = 0; i <= TamC; ++i) {
        C[i] = D[i] / Q[0]; // Coeficiente líder del cociente
        for (int j = 0; j <= TamR; ++j) {
            if (i + j < TamP) {
                D[i + j] -= C[i] * Q[j]; // Restamos el término correspondiente
            }
        }
    }

    // Copiamos el residuo desde D (los últimos TamR términos)
    for (int i = 0; i <= TamR; ++i) {
        R[i] = D[TamC + 1 + i];
    }

    delete[] D; // Liberamos memoria auxiliar
}


double* Multiplicacion(double* P, int TamP, double* Q, int TamQ, int& TamR){
    TamR = TamP + TamQ - 1; //El polinomio resultante será de un grado igual a las sumas de los grados de los polinomios multiplicados (el menos uno es por cosas de arreglos)
    double* R = new double[TamR]{0}; //Creacion del arreglo resultante, {0} para designar los valores como 0

    //Multiplicando y designando los valores en el arreglo
    for(int i = TamP-1; i>=0; i--){
        for(int j = TamQ-1; j>=0; j--){
            R[i+j] += P[i] * Q[j];
        }
    }

    return R;
}
