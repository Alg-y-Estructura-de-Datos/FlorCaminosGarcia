/*Sumar todos los elementos de una lista de números*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int suma = 0;
    int valor;
    char continuar;

    cout << "*** INGRESO DE ELEMENTOS A LA LISTA ***" << endl;

    do
    {
        cout << "Ingrese un valor para agregar a la lista: ";
        cin >> valor;

        miLista.insertarUltimo(valor);

        cout << "¿Desea agregar otro elemento? (s/n):";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\n*** LISTA INGRESADA ***" << endl;
    miLista.print();

    cout<< "La cantidad de elementos que posee la lista es: "
        << miLista.getTamanio() << endl;


    for (int i = 0; i < miLista.getTamanio() ; i++)
    {
        suma += miLista.getDato(i);
    }
    
    cout << "La suma total de los elementos es: " << suma << endl;

    return 0;
}