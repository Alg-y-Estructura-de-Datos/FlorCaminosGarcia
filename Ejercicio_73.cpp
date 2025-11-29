/*Intercambiar elementos adyacentes*/
/*Intercambiar elementos adyacentes*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

// Método básico: intercambiar elementos adyacentes
template <class T>
void intercambiarAdyacentes(Lista<T> &lista)
{
    if (lista.esVacia() || lista.getTamanio() == 1)
    {
        return; // No hay pares para intercambiar
    }

    int tamanio = lista.getTamanio();

    // Recorrer la lista de 2 en 2
    for (int i = 0; i < tamanio - 1; i += 2)
    {
        // Intercambiar elemento i con elemento i+1
        T temp = lista.getDato(i);
        lista.reemplazar(i, lista.getDato(i + 1));
        lista.reemplazar(i + 1, temp);
    }
}

// Método que intercambia solo si cumple una condición
template <class T>
void intercambiarAdyacentesCondicional(Lista<T> &lista, bool (*condicion)(T, T))
{
    if (lista.esVacia() || lista.getTamanio() == 1)
    {
        return;
    }

    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio - 1; i += 2)
    {
        T actual = lista.getDato(i);
        T siguiente = lista.getDato(i + 1);

        // Solo intercambiar si cumple la condición
        if (condicion(actual, siguiente))
        {
            lista.reemplazar(i, siguiente);
            lista.reemplazar(i + 1, actual);
        }
    }
}

// Función de condición ejemplo: intercambiar si el primero es mayor
bool esMayor(int a, int b)
{
    return a > b;
}

// Función de condición: intercambiar si ambos son pares
bool ambosPares(int a, int b)
{
    return (a % 2 == 0) && (b % 2 == 0);
}

int main()
{
    Lista<int> lista;

    cout << "=== INTERCAMBIAR ELEMENTOS ADYACENTES ===" << endl;

    // Ejemplo 1: Lista con número par de elementos
    cout << "\n--- EJEMPLO 1: Lista con 6 elementos ---" << endl;
    for (int i = 1; i <= 6; i++)
    {
        lista.insertarUltimo(i);
    }

    cout << "Lista original: ";
    lista.print();

    intercambiarAdyacentes(lista);
    cout << "Despues de intercambiar: ";
    lista.print();
    cout << "Resultado esperado: 2->1->4->3->6->5" << endl;

    // Ejemplo 2: Lista con número impar de elementos
    cout << "\n--- EJEMPLO 2: Lista con 5 elementos ---" << endl;
    lista.vaciar();
    for (int i = 1; i <= 5; i++)
    {
        lista.insertarUltimo(i);
    }

    cout << "Lista original: ";
    lista.print();

    intercambiarAdyacentes(lista);
    cout << "Despues de intercambiar: ";
    lista.print();
    cout << "Resultado esperado: 2->1->4->3->5" << endl;
    cout << "Nota: El ultimo elemento (5) no tiene pareja, queda igual" << endl;

    // Ejemplo 3: Lista con strings
    cout << "\n--- EJEMPLO 3: Lista con strings ---" << endl;
    Lista<string> listaStrings;
    listaStrings.insertarUltimo("A");
    listaStrings.insertarUltimo("B");
    listaStrings.insertarUltimo("C");
    listaStrings.insertarUltimo("D");

    cout << "Lista original: ";
    listaStrings.print();

    intercambiarAdyacentes(listaStrings);
    cout << "Despues de intercambiar: ";
    listaStrings.print();

    // Ejemplo 4: Intercambio condicional
    cout << "\n--- EJEMPLO 4: Intercambio condicional ---" << endl;
    lista.vaciar();
    lista.insertarUltimo(5);
    lista.insertarUltimo(3);
    lista.insertarUltimo(8);
    lista.insertarUltimo(2);
    lista.insertarUltimo(7);
    lista.insertarUltimo(1);

    cout << "Lista original: ";
    lista.print();

    // Intercambiar solo si el primero es mayor que el segundo
    intercambiarAdyacentesCondicional(lista, esMayor);
    cout << "Despues de intercambiar condicional (si primero > segundo): ";
    lista.print();

    return 0;
}