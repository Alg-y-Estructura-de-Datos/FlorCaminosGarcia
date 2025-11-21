/*Dadas dos listas ordenadas, encontrar su intersección
(elementos comunes) y retornar una nueva lista ordenada
con los elementos comunes.*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

void ordenarLista(CircList<int> &lista)
{
    int n = lista.getTamanio();
    if (n <= 1)
        return;

    bool intercambiado;

    for (int i = 0; i < n - 1; i++)
    {
        intercambiado = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (lista.getDato(j) > lista.getDato(j + 1))
            {
                int temp = lista.getDato(j);
                lista.insertar(j, lista.getDato(j + 1));
                lista.insertar(j + 1, temp);
                intercambiado = true;
            }
        }

        if (!intercambiado)
        {
            break;
        }
    }
}

CircList<int> encontrarInterseccion(CircList<int> &lista1, CircList<int> &lista2)
{
    CircList<int> interseccion;

    if (lista1.esVacia() || lista2.esVacia())
    {
        return interseccion;
    }

    int i = 0, j = 0;
    int n1 = lista1.getTamanio();
    int n2 = lista2.getTamanio();

    while (i < n1 && j < n2)
    {
        int dato1 = lista1.getDato(i);
        int dato2 = lista2.getDato(j);

        if (dato1 == dato2)
        {
            if (interseccion.esVacia() || interseccion.getDato(interseccion.getTamanio() - 1) != dato1)
            {
                interseccion.insertarUltimo(dato1);
            }
            i++;
            j++;
        }
        else if (dato1 < dato2)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return interseccion;
}

void imprimirLista(CircList<int> &lista, const string &nombre)
{
    cout << nombre << ": [";
    int n = lista.getTamanio();
    for (int i = 0; i < n; i++)
    {
        cout << lista.getDato(i);
        if (i < n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    CircList<int> lista1, lista2;
    int n1, n2, dato;

    cout << "=== ENCUENTRO DE INTERSECCION ENTRE LISTAS ===" << endl;
    cout << "\nIngrese la cantidad de elementos para la primera lista: ";
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        cout << "Lista 1 - Elemento " << i + 1 << ": ";
        cin >> dato;
        lista1.insertarUltimo(dato);
    }

    cout << "\nIngrese la cantidad de elementos para la segunda lista: ";
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        cout << "Lista 2 - Elemento " << i + 1 << ": ";
        cin >> dato;
        lista2.insertarUltimo(dato);
    }

    cout << "\n--- LISTAS ORIGINALES ---" << endl;
    imprimirLista(lista1, "Lista 1");
    imprimirLista(lista2, "Lista 2");

    ordenarLista(lista1);
    ordenarLista(lista2);

    cout << "\n--- LISTAS ORDENADAS ---" << endl;
    imprimirLista(lista1, "Lista 1 ordenada");
    imprimirLista(lista2, "Lista 2 ordenada");

    CircList<int> interseccion = encontrarInterseccion(lista1, lista2);

    cout << "\n--- RESULTADO ---" << endl;
    imprimirLista(interseccion, "Intersección");

    if (interseccion.esVacia())
    {
        cout << "No hay elementos comunes entre las listas." << endl;
    }
    else
    {
        cout << "Se encontraron " << interseccion.getTamanio() << " elementos comunes." << endl;
    }

    return 0;
}