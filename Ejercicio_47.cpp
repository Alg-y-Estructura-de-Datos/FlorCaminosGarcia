/*Dadas dos listas ordenadas, encontrar su intersección 
(elementos comunes) y retornar una nueva lista ordenada 
con los elementos comunes.*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

void ordenarLista(CircList<int>& lista) {
    int n = lista.getTamanio();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista.getDato(j) > lista.getDato(j + 1)) {
                int temp = lista.getDato(j);
                lista.insertar(j, lista.getDato(j + 1));
                lista.insertar(j + 1, temp);
            }
        }
    }
}

void encontrarInterseccion(CircList<int>& lista1, CircList<int>& lista2, CircList<int>& interseccion) {
    int n1 = lista1.getTamanio();
    int n2 = lista2.getTamanio();

    for (int i = 0; i < n1; i++) {
        int dato1 = lista1.getDato(i);
        for (int j = 0; j < n2; j++) {
            int dato2 = lista2.getDato(j);
            if (dato1 == dato2) {
                interseccion.insertarUltimo(dato1);
                break; // Evitar duplicados en la intersección
            }
        }
    }
}

int main()
{
    CircList<int> lista1;
    CircList<int> lista2;
    CircList<int> interseccion;
    int n, dato;

    cout << "Ingrese la cantidad de elementos para la primera lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista1.insertarUltimo(dato);
    }

    cout << "Ingrese la cantidad de elementos para la segunda lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista2.insertarUltimo(dato);
    }

    ordenarLista(lista1);
    ordenarLista(lista2);

    encontrarInterseccion(lista1, lista2, interseccion);

    cout << "Elementos comunes en ambas listas (intersección): ";
    interseccion.imprimir();

    return 0;
}