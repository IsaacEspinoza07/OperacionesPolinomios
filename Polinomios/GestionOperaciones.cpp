#include <iostream>
#include "OperacionesPolinomios.hpp"
#include "DisenioPolinomio.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;




void GestionSuma()
{
    system("cls");

    cout << "-------Suma de polinomios-------\n\n";

    cout << "Captura del polinomio P: \n";
    int gradoP;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> gradoP;
    double *polinomioP = CrearPolinomio(gradoP);


    cout << "\nCaptura del polinomio Q: \n";
    int gradoQ;
    cout << "Introduzca el grado del polinomio Q: ";  ////////////////////////////grado entero
    cin >> gradoQ;
    double *polinomioQ = CrearPolinomio(gradoQ);



    int gradoR;
    double *Resultante = SumaPolinomios(polinomioP,gradoP,polinomioQ,gradoQ,gradoR);

    cout << endl << "P(x)= ";
    ImprimirPolinomio(polinomioP,gradoP);

    cout << endl << "Q(x)= ";
    ImprimirPolinomio(polinomioQ,gradoQ);

    cout << endl << "P(x) + Q(x)= ";
    ImprimirPolinomio(Resultante,gradoR);




    cout << endl << endl;

    delete []polinomioP;
    delete []polinomioQ;
    delete []Resultante;
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestionResta()
{
    system("cls");

    cout << "-------Resta de polinomios-------\n\n";
    cout << "Captura del polinomio P: \n";

    int gradoP;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> gradoP;
    double *polinomioP = CrearPolinomio(gradoP);


    cout << "\nCaptura del polinomio Q: \n";
    int gradoQ;
    cout << "Introduzca el grado del polinomio Q: ";  ////////////////////////////grado entero
    cin >> gradoQ;
    double *polinomioQ = CrearPolinomio(gradoQ);



    int gradoR;
    double *Resultante = RestaPolinomios(polinomioP,gradoP,polinomioQ,gradoQ,gradoR);

    cout << endl << "P(x)= ";
    ImprimirPolinomio(polinomioP,gradoP);

    cout << endl << "Q(x)= ";
    ImprimirPolinomio(polinomioQ,gradoQ);

    if(!PolinomiosIguales(polinomioP,gradoP,polinomioQ,gradoQ)){
        cout << endl << endl<< "P(x) - Q(x)= ";
        ImprimirPolinomio(Resultante,gradoR);
    }else{
        cout << endl << endl << "P(x) - Q(x)= 0";
    }



    cout << endl << endl;

    delete []polinomioP;
    delete []polinomioQ;
    delete []Resultante;
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestionProducto()
{
    system("cls");

    cout << "-------Producto de polinomios-------\n\n";

    cout << "Captura del polinomio P: \n";
    int gradoP;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> gradoP;
    double *polinomioP = CrearPolinomio(gradoP);


    cout << "\nCaptura del polinomio Q: \n";
    int gradoQ;
    cout << "Introduzca el grado del polinomio Q: ";  ////////////////////////////grado entero
    cin >> gradoQ;
    double *polinomioQ = CrearPolinomio(gradoQ);



    int gradoR;
    double *Resultante = Multiplicacion(polinomioP,gradoP,polinomioQ,gradoQ,gradoR);

    cout << endl << "P(x)= ";
    ImprimirPolinomio(polinomioP,gradoP);
    cout << endl << "Q(x)= ";
    ImprimirPolinomio(polinomioQ,gradoQ);

    if((gradoP == 1 && polinomioP[0] == 0) || (gradoQ == 1 && polinomioQ[0] == 0) ) cout << endl << "P(x)*Q(x)= 0";
    else{
        cout << endl << "P(x)*Q(x)= ";
        ImprimirPolinomio(Resultante,gradoR);
    }

    cout << endl << endl;

    delete []polinomioP;
    delete []polinomioQ;
    delete []Resultante;
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////

void GestionDivision()
{


    system("cls");


    cout << "-------Divisi\242n de polinomios-------\n\n";

    cout << "Captura del polinomio P: \n";
    int gradoP;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> gradoP;
    double *polinomioP = CrearPolinomio(gradoP);


    cout << "\nCaptura del polinomio Q: \n";
    int gradoQ;
    cout << "Introduzca el grado del polinomio Q: ";  ////////////////////////////grado entero
    cin >> gradoQ;
    double *polinomioQ = CrearPolinomio(gradoQ);


    int gradoC=0;
    double *polinomioC = nullptr;

    int gradoR=0;
    double *polResiduo = nullptr;
    try{
        DivisionPolinomios(polinomioP,gradoP,polinomioQ,gradoQ,polinomioC,gradoC,polResiduo,gradoR);

        cout << endl << "P(x)= ";
        ImprimirPolinomio(polinomioP,gradoP);
        cout << endl << "Q(x)= ";
        ImprimirPolinomio(polinomioQ,gradoQ);

        cout << endl << endl << "P(x)/Q(x)= ";
        ImprimirPolinomio(polinomioC,gradoC+1);


        cout << endl <<"Residuo= ";
        ImprimirPolinomio(polResiduo,gradoR);
    }catch(const char *mensaje){
        cerr << "Error: " << mensaje << endl;
    }

    cout << endl << endl;

    delete []polinomioP;
    delete []polinomioQ;
    delete []polResiduo;
    delete []polinomioC;

    system("pause");

}


////////////////////////////////////////////////////////////////////////////////////////////////

void GestionDerivada()
{
    system("cls");
    cout << "-------Derivar un polinomio-------\n\n";
    cout << "Captura del polinomio P: \n";

    int grado;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> grado;
    if(grado > 0){
        double *polinomio = CrearPolinomio(grado);
        cout << endl << "P(x)= ";
        ImprimirPolinomio(polinomio,grado);

        cout << endl;


        double *R = DerivarPolinomio(polinomio, grado); ///////////////////////////

        cout << "P'(x) = ";
        ImprimirPolinomio(R, grado-1);

        delete[] polinomio;
        delete[] R;
    }else{
        double *polinomio = CrearPolinomio(grado); // Para que introduzca un polinomio aunque no haga nada.
        cout << "P'(x) = 0";
        delete[] polinomio;
    }

    cout << endl << endl;
    system("pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GestionEvaluar()
{
    system("cls");

    cout << "-------Evaluar un polinomio-------\n\n";

    cout << "Captura del polinomio P: \n";
    int grado;
    cout << "Introduzca el grado del polinomio P: ";  ////////////////////////////grado entero
    cin >> grado;

    float x;
    do{
        if(x<0){
            cout << "Error: No se puede tener un polinomio de grado negativo.\n";
            cout << "De el valor sobre el que se evaluara el polinomio: ";
            cin >> x;
        }else{
            cout << "De el valor sobre el que se evaluara el polinomio: ";
            cin >> x;
        }
    }while(x < 0);

    double *polinomio = CrearPolinomio(grado);
    cout << endl << "P(x)= ";
    ImprimirPolinomio(polinomio,grado);

    cout << endl;
    cout << "P(" << x << ") = " << EvaluarPolinomio(polinomio,grado,x);


    cout << endl << endl;

    delete []polinomio;
    system("pause");
}

