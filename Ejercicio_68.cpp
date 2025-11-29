/*Encontrar intersecci
n de dos listas*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
Lista<T> encontrarInterseccion(const Lista<T> &lista1, const Lista<T> &lista2)
{
    Lista<T> interseccion;
    int tamanio1 = lista1.getTamanio();
    int tamanio2 = lista2.getTamanio();

    for (int i = 0; i < tamanio1; i++)
    {
        T elemento = lista1.getDato(i);
        bool enLista2 = false;

        // Buscar en lista2
        for (int j = 0; j < tamanio2; j++)
        {
            if (elemento == lista2.getDato(j))
            {
                enLista2 = true;
                break;
            }
        }

        // Si está en ambas listas y no está duplicado
        if (enLista2)
        {
            bool duplicado = false;
            for (int k = 0; k < interseccion.getTamanio(); k++)
            {
                if (elemento == interseccion.getDato(k))
                {
                    duplicado = true;
                    break;
                }
            }

            if (!duplicado)
            {
                interseccion.insertarUltimo(elemento);
            }
        }
    }

    return interseccion;
}

void ingresarLista(Lista<int> &lista, const string &nombre)
{
    cout << "\n--- INGRESAR " << nombre << " LISTA ---" << endl;
    cout << "Ingrese numeros (0 para terminar):" << endl;

    int valor;
    int contador = 1;

    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> valor;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (valor == 0)
            break;

        lista.insertarUltimo(valor);
        contador++;
    }
}

void mostrarEstadisticas(const Lista<int> &lista1, const Lista<int> &lista2, const Lista<int> &interseccion)
{
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Tamanio lista 1: " << lista1.getTamanio() << " elementos" << endl;
    cout << "Tamanio lista 2: " << lista2.getTamanio() << " elementos" << endl;
    cout << "Elementos en interseccion: " << interseccion.getTamanio() << endl;

    if (!interseccion.esVacia())
    {
        cout << "Porcentaje de elementos comunes: "
             << (interseccion.getTamanio() * 100.0 / lista1.getTamanio()) << "% de la lista 1" << endl;
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS DE INTERSECCION ---" << endl;

    Lista<int> ej1a, ej1b;
    ej1a.insertarUltimo(1);
    ej1a.insertarUltimo(2);
    ej1a.insertarUltimo(3);
    ej1b.insertarUltimo(2);
    ej1b.insertarUltimo(3);
    ej1b.insertarUltimo(4);

    cout << "Ejemplo 1:" << endl;
    cout << "Lista A: ";
    ej1a.print();
    cout << "Lista B: ";
    ej1b.print();
    cout << "Interseccion: ";
    encontrarInterseccion(ej1a, ej1b).print();

    Lista<int> ej2a, ej2b;
    ej2a.insertarUltimo(5);
    ej2a.insertarUltimo(10);
    ej2a.insertarUltimo(15);
    ej2b.insertarUltimo(10);
    ej2b.insertarUltimo(20);
    ej2b.insertarUltimo(30);

    cout << "\nEjemplo 2:" << endl;
    cout << "Lista A: ";
    ej2a.print();
    cout << "Lista B: ";
    ej2b.print();
    cout << "Interseccion: ";
    encontrarInterseccion(ej2a, ej2b).print();
}

int main()
{
    Lista<int> lista1, lista2;
    int opcion;

    cout << "=== ENCONTRADOR DE INTERSECCION DE LISTAS ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Ingresar listas" << endl;
        cout << "2. Mostrar listas actuales" << endl;
        cout << "3. Encontrar interseccion" << endl;
        cout << "4. Ver ejemplos" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            lista1.vaciar();
            lista2.vaciar();
            ingresarLista(lista1, "PRIMERA");
            ingresarLista(lista2, "SEGUNDA");

            if (lista1.esVacia() || lista2.esVacia())
            {
                cout << "Ambas listas deben tener elementos." << endl;
            }
            else
            {
                cout << " Listas ingresadas correctamente." << endl;
            }
            break;
        }

        case 2:
        {
            if (lista1.esVacia() || lista2.esVacia())
            {
                cout << "Primero ingrese ambas listas (opcion 1)." << endl;
            }
            else
            {
                cout << "Lista 1: ";
                lista1.print();
                cout << "Lista 2: ";
                lista2.print();
            }
            break;
        }

        case 3:
        {
            if (lista1.esVacia() || lista2.esVacia())
            {
                cout << "Primero ingrese ambas listas (opcion 1)." << endl;
            }
            else
            {
                cout << "\n--- CALCULANDO INTERSECCION ---" << endl;
                cout << "Lista 1: ";
                lista1.print();
                cout << "Lista 2: ";
                lista2.print();

                Lista<int> interseccion = encontrarInterseccion(lista1, lista2);

                cout << "Interseccion: ";
                if (interseccion.esVacia())
                {
                    cout << "VACIA (no hay elementos comunes)" << endl;
                }
                else
                {
                    interseccion.print();
                }

                mostrarEstadisticas(lista1, lista2, interseccion);

                if (!interseccion.esVacia())
                {
                    cout << "\nElementos comunes:" << endl;
                    for (int i = 0; i < interseccion.getTamanio(); i++)
                    {
                        cout << "• " << interseccion.getDato(i) << endl;
                    }
                }
            }
            break;
        }

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