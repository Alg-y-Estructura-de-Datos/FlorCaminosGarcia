/*Verificar si lista es palíndromo usando pila*/
#include <iostream>
#include <string>
#include "Lista/Lista.h"
#include "Pila/Pila.h"

using namespace std;

bool esPalindromo(const Lista<char> &lista)
{
    Pila<char> pila;
    int tamanio = lista.getTamanio();

    // Apilar todos los elementos de la lista
    for (int i = 0; i < tamanio; i++)
    {
        pila.push(lista.getDato(i));
    }
    // Comparar elementos desapilados con los de la lista
    for (int i = 0; i < tamanio; i++)
    {
        if (lista.getDato(i) != pila.pop())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Lista<char> lista;
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    // Llenar la lista con los caracteres de la palabra
    for (char c : palabra)
    {
        lista.insertarUltimo(c);
    }

    if (esPalindromo(lista))
    {
        cout << "La palabra '" << palabra << "' es un palindromo." << endl;
    }
    else
    {
        cout << "La palabra '" << palabra << "' no es un palindromo." << endl;
    }

    return 0;
}