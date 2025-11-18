/*Contar cuántos elementos tiene una lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
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

    return 0;
}