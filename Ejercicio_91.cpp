#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

template <class T>
void convertirCircularASimple(CircList<T> &listaCircular, Lista<T> &listaSimple)
{
    listaSimple.vaciar();

    if (listaCircular.esVacia())
    {
        cout << "La lista circular esta vacia." << endl;
        return;
    }

    cout << "La lista circular no esta vacía." << endl;

    T primerElemento = listaCircular.getDato(0);
    cout << "Primer elemento: " << primerElemento << endl;

    listaSimple.insertarUltimo(primerElemento);
    cout << "Insertado el primer elemento." << endl;

    int i = 1;
    while (true)
    {
        cout << "Intentando obtener el elemento en posicion " << i << endl;
        T elementoActual = listaCircular.getDato(i);
        cout << "Elemento actual: " << elementoActual << endl;

        if (elementoActual == primerElemento)
        {
            cout << "Encontrado el primer elemento again, terminando." << endl;
            break;
        }

        cout << "Insertando elemento: " << elementoActual << endl;
        listaSimple.insertarUltimo(elementoActual);
        i++;

        // Para evitar un bucle infinito en caso de error, ponemos un límite
        if (i > 100)
        {
            cout << "Advertencia Demasiadas iteraciones. Saliendo." << endl;
            break;
        }
    }

    cout << "Conversion completada. Total de elementos: " << i << endl;
    listaSimple.print();
}

int main()
{
    CircList<int> circular;
    Lista<int> simple;

    cout << "Insertando elementos en la lista circular..." << endl;
    circular.insertarUltimo(10);
    cout << "Insertado 10" << endl;
    circular.insertarUltimo(20);
    cout << "Insertado 20" << endl;
    circular.insertarUltimo(30);
    cout << "Insertado 30" << endl;
    circular.insertarUltimo(40);
    cout << "Insertado 40" << endl;

    circular.imprimir();
    
    cout << "Llamando a la funcion de conversion..." << endl;
    convertirCircularASimple(circular, simple);    

    return 0;
}