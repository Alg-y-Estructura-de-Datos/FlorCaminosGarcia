/*Encontrar posición de un elemento*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int cont = 1;
    int num;
    int elem;
    bool encontrado = false;

    cout << "Ingrese el elemento del que quiere averiguar la posicion: ";
    cin >> elem;

    cout << "\n**INGRESAR ELEMENTOS A LA LISTA**" << endl;
    cout << "Ingrese 0 para terminar" << endl;

    while (true)
    {
        cout << "Ingrese el valor del elemento " << cont << ": ";
        cin >> num;

        if (num == 0)
        {
            break;
        }
        miLista.insertarUltimo(num);
        cont++;
    }

    cout << "\nBuscando el elemento " << elem << " en la lista..." << endl;

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (miLista.getDato(i) == elem)
        {
            cout << "El elemento " << elem << " se encuentra en la posicion: " << i << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "El elemento " << elem << " no se encuentra en la lista." << endl;
    }

    cout << "\nLista completa: ";
    miLista.print();

    return 0;
}