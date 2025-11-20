/*Crear lista doble con 5 elementos*/
#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

int main()
{
    ListaDoble<int> miLista;
    int num;

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese el elemento de la posicion: " << i + 1 << endl;
        cin >> num;

        miLista.insertarUltimo(num);
    }

    cout << "Lista Ingresada: " << endl;
    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        cout << miLista.getDato(i) << " ";
    }
    cout << endl;

    return 0;
}