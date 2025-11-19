/*Insertar elemento en posición específica*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void invertirLista(Lista<T> &lista)
{
    Lista<int> temp;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        temp.insertarPrimero(lista.getDato(i));
    }

    lista.vaciar();

    for (int i = 0; i < tamanio; i++)
    {
        lista.insertarUltimo(temp.getDato(i));
    }
}

int main()
{
    Lista<int> miLista;
    int cont = 1;
    int num;
    int posicion_cambiar;
    int extra;
    char respuesta;

    while (true)
    {
        cout << "Ingrese el elemento " << cont << ": " << endl;
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

    cout << "Desea invertir la lista?(y/n)" << endl;
    cin >> respuesta;

    if (respuesta == 'y' || respuesta == 'Y')
    {
        invertirLista(miLista);

        cout << "Lista invertida: " << endl;
        miLista.print();

        cout << "Ingrese el elemento que desea ingresar: " << endl;
        cin >> extra;

        cout << "Ingrese la posicion en la cual lo desea ingresar: " << endl;
        cin >> posicion_cambiar;

        miLista.insertar(posicion_cambiar - 1, extra);

        cout << "Lista con el elemento agregado: " << endl;
        miLista.print();
    }
    else if (respuesta == 'n' || respuesta == 'N')
    {
        cout << "Ingrese el elemento que desea ingresar: " << endl;
        cin >> extra;

        cout << "Ingrese la posicion en la cual lo desea ingresar: " << endl;
        cin >> posicion_cambiar;

        miLista.insertar(posicion_cambiar - 1, extra);

        cout << "Lista con el elemento agregado: " << endl;
        miLista.print();
    }
    else
    {
        cout << "Respuesta no valida" << endl;
    }

    return 0;
}