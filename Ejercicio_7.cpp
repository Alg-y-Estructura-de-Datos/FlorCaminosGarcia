/*Encontrar el elemento mayor en una lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int mayor;
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

    if (miLista.getTamanio() == 0)
    {
        cout << "La lista está vacía. No hay elementos para evaluar." << endl;
        return 0;
    }

    mayor = miLista.getDato(0);

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (miLista.getDato(i) > mayor)
        {
            mayor = miLista.getDato(i);
        }
    }

    cout << "El mayor de los elementos ingresados es: " << mayor << endl;

    return 0;
}