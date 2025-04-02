#include <iostream>

using std::cout;
using std::cin;


//////////////////////////////////////////////////////////////////////////////////////////
float *CrearPolinomio(int tam)
{
    ++tam;
    float *p;

    p = new float[tam];

    for(int i=0;i<tam;++i){
        if(i != tam-1){
            cout << "Introduce coeficiente de x^" << tam-i-1 << ": ";
            cin >> *(p+i);
        }else{
            cout << "Introduce el termino constante: ";
            cin >> *(p+i);
        }
    }
    return p;

}
//////////////////////////////////////////////////////////////////////////////////////////
void ImprimirPolinomio(float *pol, int tam)
{

    cout << pol[0] << "x^" << tam;

    for(int i=1;i<tam;++i){
        /*
        Arreglar problema cuando se introduce que el tamaño = 0,
        arroja p(x) nx^0. Quitar el x^0.
        */



        if(pol[i] < 0){// este 'if' es para imprimir los numeros negativos de forma correcta
            if(pol[i] == 1 || pol[i] == -1){// Estos 'if' y 'else' son para ignorar los unos del lado negativo

                tam-i == 1 ? cout << " - " << "x" : cout <<" - " << "x^" << tam-i;

                //cout <<" - " << "x^" << tam-i;
            }else{

                tam-i == 1 ? cout << " - " << -pol[i] << "x" : cout <<" - " << -pol[i] << "x^" << tam-i;


                //cout <<" - " << -pol[i] << "x^" << tam-i;
            }
        }else if(pol[i] > 0){// Este 'else if' es para imprimir los numeros positivos de forma correcta
            if(pol[i] == 1 || pol[i] == -1){// Estos 'if' y 'else' son para ignorar los unos del lado positivo.

                tam-i == 1 ? cout << " + " << "x" : cout <<" + " << "x^" << tam-i;


                //cout <<" + " << "x^" << tam-i;
            }else{
                tam-i == 1 ? cout << " + " << "x" : cout <<" + " << pol[i] << "x^" << tam-i;

                //cout <<" + " << pol[i] << "x^" << tam-i;
            }

            //cout << " + "<< pol[i] << "x^" << tam-i;
        }
        if(i == tam-1 && pol[tam] != 0){//este 'if' es para imprimir el termino constante.
            pol[tam] < 0 ? cout << " - " << -pol[tam] : cout << " + " << pol[tam];
        }
    }
}
