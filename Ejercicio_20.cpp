/*Insertar después de un valor específico - Todas las ocurrencias*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;
    int nuevoElemento;
    int elementoAnterior;
    int inserciones = 0;

    cout << "*** INSERTAR DESPUES DE ELEMENTO ***" << endl;
    cout << "Ingrese el nuevo elemento a insertar: ";
    cin >> nuevoElemento;

    cout << "Ingrese el elemento despues del cual insertar: ";
    cin >> elementoAnterior;

    cout << "\nIngrese elementos a la lista (0 para terminar):" << endl;
    
    int cont = 1;
    while (true)
    {
        cout << "Elemento " << cont << ": ";
        cin >> num;
        if (num == 0) break;
        miLista.insertarUltimo(num);
        cont++;
    }

    cout << "\nLista original: ";
    miLista.print();

    for (int i = miLista.getTamanio() - 1; i >= 0; i--)
    {
        if (miLista.getDato(i) == elementoAnterior)
        {
            miLista.insertar(i + 1, nuevoElemento);
            cout << "Insertado despues de posicion " << i << endl;
            inserciones++;
        }
    }

    if (inserciones > 0)
    {
        cout << "Se inserto " << nuevoElemento << " despues de " << elementoAnterior << " en " << inserciones << " ubicaciones." << endl;
    }
    else
    {
        cout << "El elemento " << elementoAnterior << " no se encuentra en la lista." << endl;
    }

    cout << "Lista final: ";
    miLista.print();

    return 0;
}