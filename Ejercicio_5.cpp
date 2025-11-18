/*Buscar si un elemento existe en la lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int numb;
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

    cout << "Ingrese el elemento buscado en la lista: " << endl;
    cin >> numb;

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (numb == miLista.getDato(i))
        {
            cout << "Elemento encontrado en la posicion: " << i + 1 << endl;
        }
        else
        {
            cout << "Elemento NO encontrado" << endl;
        }
    }

    return 0;
}