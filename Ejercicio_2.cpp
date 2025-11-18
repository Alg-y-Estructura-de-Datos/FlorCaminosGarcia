// Imprimir todos los elementos de una lista
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    int num;
    Lista<int> miLista;

    miLista.insertarPrimero(1);
    miLista.insertar(1, 2);
    miLista.insertar(2, 3);
    miLista.insertar(3, 4);
    miLista.insertar(4, 5);
    miLista.insertar(5, 6);
    miLista.insertar(6, 7);
    miLista.insertar(7, 8);
    miLista.insertar(8, 9);
    miLista.insertarUltimo(10);

    cout << "***LISTA INGRESADA***" << endl;
    miLista.print();

    cout << "Escribe el valor de la lista a eliminar: " << endl;
    cin >> num;

    bool encontrado = false;
    int tamanio = miLista.getTamanio();
    for (int i = 0; i < 9; i++)
    {
        if (miLista.getDato(i) == num)
        {
            miLista.remover(i);
            encontrado = true;
            break;
        }
    }

    if (encontrado)
    {
        cout<< "Valor" << num << "Eliminado correctamente." << endl;
        cout<< "***LISTA ACTUALIZADA***" << endl;
        miLista.print();
    }
    else
    {
        cout<< "El valor" << num << "no se encontró en la lista." << endl;
    };    
};