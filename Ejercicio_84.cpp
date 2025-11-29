/*Encontrar pares con suma dada*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void encontrarParesConSuma(const Lista<T> &lista, T suma_dada)
{
    bool encontrado = false;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        for (int j = i + 1; j < tamanio; j++)
        {
            if (lista.getDato(i) + lista.getDato(j) == suma_dada)
            {
                cout << "Par encontrado: (" << lista.getDato(i) << ", " << lista.getDato(j) << ")" << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado)
    {
        cout << "No se encontraron pares con la suma dada." << endl;
    }
}

int main()
{
    Lista<int> lista;
    int elementos, suma_dada;

    cout << "Ingrese los elementos de la lista (termina con 0): " << endl;
    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista.insertarUltimo(elementos);
    }

    cout << "Lista ingresada: ";
    lista.print();

    cout << "Ingrese la suma dada: ";
    cin >> suma_dada;

    encontrarParesConSuma(lista, suma_dada);

    return 0;
}