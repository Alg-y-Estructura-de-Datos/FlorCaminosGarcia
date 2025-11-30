/*Usar lista para implementar pila*/
#include <iostream>
#include "Lista/Lista.h"
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<int> pila;
    Lista<int> lista;
    int elemento;
    int opcion;

    cout << "=== IMPLEMENTAR PILA CON LISTA ===" << endl;

    while (true)
    {
        cout << "\nMENU:" << endl;
        cout << "1. Apilar elemento" << endl;
        cout << "2. Desapilar elemento" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el elemento a apilar: ";
            cin >> elemento;
            pila.push(elemento);
            lista.insertarUltimo(elemento); // Mantener sincronizado con la pila
            cout << "Elemento " << elemento << " apilado." << endl;
            break;
        }
        case 2:
        {
            try
            {
                int desapilado = pila.pop();
                lista.remover(lista.getTamanio()); // Mantener sincronizado con la pila
                cout << "Elemento " << desapilado << " desapilado." << endl;
            }
            catch (int e)
            {
                if (e == 400)
                {
                    cout << "Error: La pila esta vacia." << endl;
                }
            }
            break;
        }
        case 3:
        {
            if (lista.getTamanio() == 0)
            {
                cout << "La pila esta vacia." << endl;
            }
            else
            {
                cout << "Pila actual (de tope a base): ";
                for (int i = lista.getTamanio() - 1; i >= 0; i--)
                {
                    cout << lista.getDato(i);
                    if (i > 0)
                    {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout << "Opcion no valida. Intente nuevamente." << endl;
            break;
        }
        }
    }

    return 0;
}