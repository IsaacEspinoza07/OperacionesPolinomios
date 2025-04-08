#include <iostream>
#include <cstdlib>
#include <cmath>
#include "GestionOperaciones.hpp"

using namespace std;

enum {SALIR,SUMA,RESTA,PRODUCTO,DIVISION,DERIVAR,EVALUAR};

int main()
{

    int opcion=1;
    do{
        system("cls");

        ///////////////////////////////////////////////////////////////////////

        cout << "Programa que hace operaciones con dos polinomios.\n\n";

        cout << "----Opciones----\n\n";
        cout << SUMA<<"- Suma de polinomios.\n";
        cout << RESTA<<"- Resta de polinomios.\n";
        cout << PRODUCTO<<"- Producto de polinomios.\n";
        cout << DIVISION<<"- Divisi\242n de polinomios.\n";
        cout << DERIVAR<<"- Derivar un polinomio\n";
        cout << EVALUAR<<"- Evaluar un polinomio.\n";
        cout << SALIR << "- Salir del programa\n\n";

        do{
            if(opcion >= SUMA && opcion <= EVALUAR){
                cout << "Introduzca su opci\242n:";
                cin >> opcion;
            }else{
                cout << "Error: No es una opcion valida.\nIntroduzca su opci\242n: ";
                cin >> opcion;
            }
        }while(opcion < SALIR || opcion > EVALUAR);

        ///////////////////////////////////////////////////////////////////////



        switch(opcion){
            case SUMA:
                GestionSuma();
                break;
            case RESTA:
                GestionResta();
                break;
            case PRODUCTO:
                GestionProducto();
                break;
            case DIVISION:
                GestionDivision();
                break;
            case DERIVAR:
                GestionDerivada();
                break;
            case EVALUAR:
                GestionEvaluar();
                break;
            case SALIR:
                break;
        }



    }while(opcion !=SALIR);
    cout << endl << endl;
    system("pause");

    return 0;
}


