#ifndef DISENIOPOLINOMIO_HPP_INCLUDED
#define DISENIOPOLINOMIO_HPP_INCLUDED


/** \brief Permite almacenar los coeficientes de el polinomio.
 *
 * \param tam int Grado del polinomio. Se guardan los coeficientes en el arreglo + el termino constante.
 * \return float* Devuelve la dirección de el arreglo
 *
 */
double *CrearPolinomio(int &tam);

void ImprimirPolinomio(double* pol, int tam);

bool PolinomiosIguales(double *P, int tamP, double *Q, int tamQ);
#endif // DISENIOPOLINOMIO_HPP_INCLUDED
