/*Unir dos listas ordenadas*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
Lista<T> unirListasOrdenadas(const Lista<T> &lista1, const Lista<T> &lista2)
{
    Lista<T> resultado;
    int i = 0, j = 0;
    int size1 = lista1.getTamanio();
    int size2 = lista2.getTamanio();

    // Algoritmo de mezcla (merge)
    while (i < size1 && j < size2)
    {
        if (lista1.getDato(i) <= lista2.getDato(j))
        {
            resultado.insertarUltimo(lista1.getDato(i++));
        }
        else
        {
            resultado.insertarUltimo(lista2.getDato(j++));
        }
    }

    // Elementos restantes de lista1
    while (i < size1)
    {
        resultado.insertarUltimo(lista1.getDato(i++));
    }

    // Elementos restantes de lista2
    while (j < size2)
    {
        resultado.insertarUltimo(lista2.getDato(j++));
    }

    return resultado;
}

template <class T>
void ordenarLista(Lista<T> &lista)
{
    int n = lista.getTamanio();
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lista.getDato(j) > lista.getDato(j + 1))
            {
                T temp = lista.getDato(j);
                lista.reemplazar(j, lista.getDato(j + 1));
                lista.reemplazar(j + 1, temp);
            }
        }
    }
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
            cout << "Entrada inválida. Intente again." << endl;
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

void mostrarEstadisticas(const Lista<int> &lista1, const Lista<int> &lista2, const Lista<int> &listaUnida)
{
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "Tamaño lista 1: " << lista1.getTamanio() << " elementos" << endl;
    cout << "Tamaño lista 2: " << lista2.getTamanio() << " elementos" << endl;
    cout << "Tamaño lista unida: " << listaUnida.getTamanio() << " elementos" << endl;

    if (!listaUnida.esVacia())
    {
        cout << "Rango final: [" << listaUnida.getDato(0) << " - " << listaUnida.getDato(listaUnida.getTamanio() - 1) << "]" << endl;
    }

    // Verificar que la unión es correcta
    if (listaUnida.getTamanio() == lista1.getTamanio() + lista2.getTamanio())
    {
        cout << "✅ Unión completada correctamente." << endl;
    }
    else
    {
        cout << "❌ Error en la unión." << endl;
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS DE UNIÓN ---" << endl;

    // Ejemplo 1
    Lista<int> ej1a, ej1b;
    ej1a.insertarUltimo(1);
    ej1a.insertarUltimo(3);
    ej1a.insertarUltimo(5);
    ej1b.insertarUltimo(2);
    ej1b.insertarUltimo(4);
    ej1b.insertarUltimo(6);

    cout << "Ejemplo 1 - Listas ordenadas:" << endl;
    cout << "Lista A: ";
    ej1a.print();
    cout << "Lista B: ";
    ej1b.print();
    cout << "Unión: ";
    unirListasOrdenadas(ej1a, ej1b).print();

    // Ejemplo 2
    Lista<int> ej2a, ej2b;
    ej2a.insertarUltimo(10);
    ej2a.insertarUltimo(20);
    ej2b.insertarUltimo(5);
    ej2b.insertarUltimo(15);
    ej2b.insertarUltimo(25);

    cout << "\nEjemplo 2 - Listas desordenadas:" << endl;
    cout << "Lista A: ";
    ej2a.print();
    cout << "Lista B: ";
    ej2b.print();

    // Ordenar primero
    ordenarLista(ej2a);
    ordenarLista(ej2b);
    cout << "Lista A ordenada: ";
    ej2a.print();
    cout << "Lista B ordenada: ";
    ej2b.print();
    cout << "Unión: ";
    unirListasOrdenadas(ej2a, ej2b).print();
}

int main()
{
    Lista<int> lista1, lista2;
    int opcion;

    cout << "=== UNIÓN DE LISTAS ORDENADAS ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Ingresar listas" << endl;
        cout << "2. Mostrar listas actuales" << endl;
        cout << "3. Ordenar listas" << endl;
        cout << "4. Unir listas" << endl;
        cout << "5. Ver ejemplos" << endl;
        cout << "6. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opción inválida." << endl;
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
                cout << "Primero ingrese ambas listas (opción 1)." << endl;
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
                cout << "Primero ingrese ambas listas (opción 1)." << endl;
            }
            else
            {
                cout << "\n--- ORDENANDO LISTAS ---" << endl;
                cout << "Lista 1 antes: ";
                lista1.print();
                ordenarLista(lista1);
                cout << "Lista 1 despues: ";
                lista1.print();

                cout << "Lista 2 antes: ";
                lista2.print();
                ordenarLista(lista2);
                cout << "Lista 2 despues: ";
                lista2.print();

                cout << "✅ Listas ordenadas correctamente." << endl;
            }
            break;
        }

        case 4:
        {
            if (lista1.esVacia() || lista2.esVacia())
            {
                cout << "Primero ingrese ambas listas (opción 1)." << endl;
            }
            else
            {
                cout << "\n--- UNIENDO LISTAS ---" << endl;
                cout << "Lista 1: ";
                lista1.print();
                cout << "Lista 2: ";
                lista2.print();

                // Verificar si están ordenadas
                bool ordenada1 = true, ordenada2 = true;
                for (int i = 0; i < lista1.getTamanio() - 1; i++)
                {
                    if (lista1.getDato(i) > lista1.getDato(i + 1))
                    {
                        ordenada1 = false;
                        break;
                    }
                }
                for (int i = 0; i < lista2.getTamanio() - 1; i++)
                {
                    if (lista2.getDato(i) > lista2.getDato(i + 1))
                    {
                        ordenada2 = false;
                        break;
                    }
                }

                if (!ordenada1 || !ordenada2)
                {
                    cout << " Las listas no están ordenadas. Se ordenarán automáticamente." << endl;
                    ordenarLista(lista1);
                    ordenarLista(lista2);
                    cout << "Listas ordenadas:" << endl;
                    cout << "Lista 1: ";
                    lista1.print();
                    cout << "Lista 2: ";
                    lista2.print();
                }

                Lista<int> listaUnida = unirListasOrdenadas(lista1, lista2);

                cout << " Lista unida: ";
                listaUnida.print();

                mostrarEstadisticas(lista1, lista2, listaUnida);

                // Mostrar proceso paso a paso
                cout << "\n--- PROCESO DE UNION ---" << endl;
                cout << "Se comparan elementos de ambas listas y se inserta el menor." << endl;
                cout << "Cuando una lista se vacia, se agregan todos los elementos restantes de la otra." << endl;
            }
            break;
        }

        case 5:
            mostrarEjemplos();
            break;

        case 6:
            cout << "¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opcoin no valida." << endl;
        }

    } while (opcion != 6);

    return 0;
}