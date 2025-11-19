/*Reemplazar elemento en posición dada*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int elem_v;
    int elem_n;
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

    cout << "Ingrese el valor que quiere reemplazar: " << endl;
    cin >> elem_v;

    cout << "Ingrese el valor por el cual lo quiere reemplazar: " << endl;
    cin >> elem_n;

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (elem_v == miLista.getDato(i))
        {
            miLista.remover(i);
            miLista.insertar(i, elem_n);
        }
    }

    cout << "Lista actualizada: " << endl;
    miLista.print();
}