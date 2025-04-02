#include <iostream>
#include "OperacionesPolinomios.hpp"
#include "DisenioPolinomio.hpp"

using std::cout;
using std::cin;
using std::endl;





void GestionSuma()
{
    system("cls");
    cout << "Suma";

    cout << endl << endl;
    system("pause");
}
void GestionResta()
{
    system("cls");
    cout << "Resta";

    cout << endl << endl;
    system("pause");
}
void GestionProducto()
{
    system("cls");
    cout << "Producto";

    cout << endl << endl;
    system("pause");
}
void GestionDivision()
{
    system("cls");
    cout << "Division";


    cout << endl << endl;
    system("pause");
}
void GestionDerivada()
{
    system("cls");
    cout << "Derivada";

    cout << endl << endl;
    system("pause");
}
void GestionEvaluar()
{
    system("cls");


    cout << "-------Evaluar un polinomio-------\n\n";
    cout << "Captura del polinomio: \n";

    int grado;
    cout << "Introduzca el grado del polinomio: ";  ////////////////////////////grado entero
    cin >> grado;
    float x;
    cout << "De el valor sobre el que se evaluara el polinomio: ";
    cin >> x;


    float *polinomio = CrearPolinomio(grado);
    cout << "P(x)= ";
    ImprimirPolinomio(polinomio,grado);

    cout << endl;
    cout << "P(" <<x << ") = " << EvaluarPolinomio(polinomio,grado+1,x);





    cout << endl << endl;
    system("pause");
}

