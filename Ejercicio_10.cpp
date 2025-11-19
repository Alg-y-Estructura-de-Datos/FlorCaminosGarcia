/*Eliminar el primer elemento*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void invertirLista(Lista<T> &lista)
{
    Lista<T> temp;
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
    char respuesta;

    cout << "*** INGRESAR ELEMENTOS EN LA LISTA ***" << endl;
    cout << " Ingrese el 0 cuando termine de ingresar los valores " << endl;

    while (true)
    {
        cout << "Ingrese el elemento " << cont << ": ";
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

        miLista.print();

        if (miLista.getTamanio() > 0)
        {
            miLista.remover(0);
        }

        cout << "Lista invertida con el primer elemento eliminado: " << endl;
        miLista.print();
    }
    else if (respuesta == 'n' || respuesta == 'N')
    {

        if (miLista.getTamanio() > 0)
        {
            miLista.remover(0);
        }

        cout << "Lista original con el primer elemento eliminado: " << endl;
        miLista.print();
    }
    else
    {
        cout << "Respuesta no valida" << endl;
    }

    return 0;
}