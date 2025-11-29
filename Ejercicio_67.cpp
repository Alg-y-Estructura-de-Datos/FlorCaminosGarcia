/*Rotar lista K posiciones*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void rotarListaDerecha(Lista<T> &lista, int k)
{
    if (lista.esVacia() || k == 0)
        return;

    int n = lista.getTamanio();
    k = k % n;
    if (k == 0)
        return;

    Lista<T> temp;

    for (int i = n - k; i < n; i++)
    {
        temp.insertarUltimo(lista.getDato(i));
    }

    for (int i = 0; i < n - k; i++)
    {
        temp.insertarUltimo(lista.getDato(i));
    }

    lista.vaciar();
    for (int i = 0; i < n; i++)
    {
        lista.insertarUltimo(temp.getDato(i));
    }
}

template <class T>
void rotarListaIzquierda(Lista<T> &lista, int k)
{
    if (lista.esVacia() || k == 0)
        return;

    int n = lista.getTamanio();
    k = k % n;
    if (k == 0)
        return;

    Lista<T> temp;

    for (int i = k; i < n; i++)
    {
        temp.insertarUltimo(lista.getDato(i));
    }

    for (int i = 0; i < k; i++)
    {
        temp.insertarUltimo(lista.getDato(i));
    }

    lista.vaciar();
    for (int i = 0; i < n; i++)
    {
        lista.insertarUltimo(temp.getDato(i));
    }
}

void ingresarLista(Lista<int> &lista)
{
    cout << "Ingrese elementos (0 para terminar):" << endl;
    int valor;
    int contador = 1;

    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> valor;

        if (valor == 0)
            break;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Intente again." << endl;
            continue;
        }

        lista.insertarUltimo(valor);
        contador++;
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS DE ROTACION ---" << endl;

    Lista<int> ejemplo;
    for (int i = 1; i <= 5; i++)
    {
        ejemplo.insertarUltimo(i);
    }

    cout << "Lista original: ";
    ejemplo.print();

    cout << "\nRotaciones a la DERECHA:" << endl;
    Lista<int> temp;

    for (int k = 1; k <= 3; k++)
    {
        temp.vaciar();
        for (int i = 0; i < ejemplo.getTamanio(); i++)
        {
            temp.insertarUltimo(ejemplo.getDato(i));
        }
        rotarListaDerecha(temp, k);
        cout << "Rotar " << k << " posicion(es): ";
        temp.print();
    }

    cout << "\nRotaciones a la IZQUIERDA:" << endl;
    for (int k = 1; k <= 3; k++)
    {
        temp.vaciar();
        for (int i = 0; i < ejemplo.getTamanio(); i++)
        {
            temp.insertarUltimo(ejemplo.getDato(i));
        }
        rotarListaIzquierda(temp, k);
        cout << "Rotar " << k << " posicion(es): ";
        temp.print();
    }
}

int main()
{
    Lista<int> lista;
    int opcion, k;

    cout << "=== ROTADOR INTERACTIVO DE LISTAS ===" << endl;

    mostrarEjemplos();

    cout << "\n--- INGRESE SU LISTA ---" << endl;
    ingresarLista(lista);

    if (lista.esVacia())
    {
        cout << "Lista vacía. Saliendo..." << endl;
        return 0;
    }

    do
    {
        cout << "\n=== MENU ROTACION ===" << endl;
        cout << "Lista actual: ";
        lista.print();
        cout << "1. Rotar a la DERECHA" << endl;
        cout << "2. Rotar a la IZQUIERDA" << endl;
        cout << "3. Ingresar nueva lista" << endl;
        cout << "4. Ver ejemplos again" << endl;
        cout << "5. Salir" << endl;
        cout << "OpciOn: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "OpciOn invAlida." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            cout << "Posiciones a rotar a la DERECHA: ";
            cin >> k;
            if (cin.fail() || k < 0)
            {
                cout << "Valor invalido." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                rotarListaDerecha(lista, k);
                cout << " Lista rotada " << k << " posiciones a la derecha." << endl;
            }
            break;
        }

        case 2:
        {
            cout << "Posiciones a rotar a la IZQUIERDA: ";
            cin >> k;
            if (cin.fail() || k < 0)
            {
                cout << "Valor invalido." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                rotarListaIzquierda(lista, k);
                cout << " Lista rotada " << k << " posiciones a la izquierda." << endl;
            }
            break;
        }

        case 3:
            lista.vaciar();
            ingresarLista(lista);
            break;

        case 4:
            mostrarEjemplos();
            break;

        case 5:
            cout << "¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 5);

    return 0;
}