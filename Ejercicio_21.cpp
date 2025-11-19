/*Eliminar por valor (primera ocurrencia)*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int cont = 1;
    int num;
    int elem;
    int posicion = -1; 
    bool encontrado = false;

    cout << "Ingrese el elemento que desea eliminar: "; 
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

    cout << "\nLista original: ";
    miLista.print();

    cout << "Buscando el elemento " << elem << " en la lista..." << endl;

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (miLista.getDato(i) == elem)
        {
            cout << "El elemento " << elem << " se encuentra en la posicion: " << i << endl;
            encontrado = true;
            posicion = i;
            break; 
        }
    }

    if (!encontrado)
    {
        cout << "El elemento " << elem << " no se encuentra en la lista." << endl;
    }
    else
    {
        miLista.remover(posicion);
        cout << "Elemento eliminado exitosamente." << endl;
    }

    cout << "\nLista resultante: ";
    miLista.print();

    return 0;
}