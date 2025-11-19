/*Crear copia de una lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void crearCopia(Lista<T> &lista)
{
    Lista<T> temp;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        temp.insertarUltimo(lista.getDato(i));
    }

    cout << "Copia temporal de la lista ingresada: " << endl;
    temp.print();
}

int main()
{

    Lista<int> miLista;
    int cont = 1;
    int num;

    while (true)
    {
        cout << "Ingresar el elemento de la posicion: " << cont << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        miLista.insertarUltimo(num);
        cont++;
    }

    cout << "Lista original: ";
    miLista.print();

    crearCopia(miLista);

    return 0;
}