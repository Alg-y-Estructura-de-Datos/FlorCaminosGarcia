/*Concatenar dos listas*/
#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"

using namespace std;

int main()
{
    ListaDoble<string> lista;
    string frase1;
    string frase2;

    cout << "Ingrese la cadena de caracteres perteneciente a la primera lista: " << endl;
    getline(cin, frase1);

    cout << "Ingrese la cadena de caracteres perteneciente a la segunda lista: " << endl;
    getline(cin, frase2);

    lista.insertarPrimero(frase1);
    lista.insertarUltimo(frase2);

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i);
        if (i < lista.getTamanio() - 1)
        {
            cout << " ";
        }
    }

    return 0;
}