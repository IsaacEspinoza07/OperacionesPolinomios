#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;


//////////////////////////////////////////////////////////////////////////////////////////
double *CrearPolinomio(int &tam)
{
    ++tam;
    double *p;

    p = new double[tam];
    bool primero=true;
    for(int i=0;i<tam;++i){
        if(i != tam-1){
            do{
                cout << "Introduce coeficiente de x^" << tam-i-1 << ": ";
                cin >> *(p+i);
                primero = false;
            }while(primero == true || *(p+0) == 0);

        }else{
            cout << "Introduce el termino constante: ";
            cin >> *(p+i);
        }
    }
    return p;

}

//////////////////////////////////////////////////////////////////////////////////////////

void ImprimirPolinomio(double *pol, int tam){
    --tam;
    if(tam > 1){
        pol[0] == 1 ? cout << "x^" << tam : cout << pol[0] << "x^" << tam;


        for(int i=1;i<tam;++i){

            if(pol[i] < 0){// este 'if' es para imprimir los numeros negativos de forma correcta
                if(pol[i] == 1 || pol[i] == -1){// Estos 'if' y 'else' son para ignorar los unos del lado negativo

                    tam-i == 1 ? cout << " - " << "x" : cout <<" - " << "x^" << tam-i;

                }else{

                    tam-i == 1 ? cout << " - " << -pol[i] << "x" : cout <<" - " << -pol[i] << "x^" << tam-i;

                }
            }else if(pol[i] > 0){// Este 'else if' es para imprimir los numeros positivos de forma correcta
                if(pol[i] == 1 || pol[i] == -1){// Estos 'if' y 'else' son para ignorar los unos del lado positivo.

                    tam-i == 1 ? cout << " + " << "x" : cout <<" + " << "x^" << tam-i;

                }else{

                    tam-i == 1 ? cout << " + " << pol[i] << "x" : cout <<" + " << pol[i] << "x^" << tam-i;

                }
            }
            if(i == tam-1 && pol[tam] != 0){//este 'if' es para imprimir el termino constante.
                pol[tam] < 0 ? cout << " - " << -pol[tam] : cout << " + " << pol[tam];
            }
        }

    }else if(tam == 1){
        pol[0] == 1 ? cout << "x": cout << pol[0] << "x";
        pol[1] < 0 ? cout << " - " << -pol[tam] : cout << " + " << pol[tam];
        return;
    }else{
        cout << pol[0];
        return;
    }


}

//////////////////////////////////////////////////////////////////////////////////////////

bool PolinomiosIguales(double *P, int tamP, double *Q, int tamQ)
{
    if(tamP != tamQ){
        return false;
    }else{
        for(int i=0;i<tamP;++i){
            if(P[i] != Q[i]){
                return false;
            }
        }
        return true;
    }
}
