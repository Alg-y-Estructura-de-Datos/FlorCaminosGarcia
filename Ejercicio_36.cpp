/*Intercambiar primer y último elemento*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;
    int primerElemento;
    int ultimoElemento;

    while (true)
    {
        cout << "Ingrese el siguiente valor de la lista: " << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        miLista.insertarUltimo(num);
    }

    cout << "Lista original: " << endl;
    miLista.print();

    primerElemento = miLista.getDato(0);
    ultimoElemento = miLista.getDato(miLista.getTamanio() - 1);

    miLista.reemplazar(0, ultimoElemento);
    miLista.reemplazar(miLista.getTamanio() - 1, primerElemento);

    cout << "Lista con primer y ultimo elemento intercambiados: " << endl;
    miLista.print();

    return 0;
}