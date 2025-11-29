#include <iostream>
#include "Lista/Lista.h"

using namespace std;

// Función mejorada que muestra todas las posiciones de los duplicados
void encontrarDuplicadosCompleto(Lista<int> &lista)
{
    if (lista.esVacia())
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    int tamanio = lista.getTamanio();
    bool hayDuplicados = false;

    // Usamos una lista auxiliar para marcar elementos ya procesados
    Lista<int> procesados;

    for (int i = 0; i < tamanio; i++)
    {
        int elemento = lista.getDato(i);

        // Saltar si ya procesamos este elemento
        bool yaProcesado = false;
        for (int k = 0; k < procesados.getTamanio(); k++)
        {
            if (procesados.getDato(k) == elemento)
            {
                yaProcesado = true;
                break;
            }
        }
        if (yaProcesado)
            continue;

        // Buscar todas las ocurrencias de este elemento
        Lista<int> posiciones;
        for (int j = i; j < tamanio; j++)
        {
            if (lista.getDato(j) == elemento)
            {
                posiciones.insertarUltimo(j);
            }
        }

        // Si hay más de una ocurrencia, es un duplicado
        if (posiciones.getTamanio() > 1)
        {
            cout << "Elemento " << elemento << " aparece " << posiciones.getTamanio() << " veces en posiciones: ";

            for (int p = 0; p < posiciones.getTamanio(); p++)
            {
                cout << posiciones.getDato(p);
                if (p < posiciones.getTamanio() - 1)
                    cout << ", ";
            }
            cout << endl;

            hayDuplicados = true;
        }

        procesados.insertarUltimo(elemento);
    }

    if (!hayDuplicados)
    {
        cout << "No se encontraron elementos duplicados." << endl;
    }
}

int main()
{
    Lista<int> lista;
    int elemento;

    cout << "INGRESE ELEMENTOS A LA LISTA" << endl;
    cout << "============================" << endl;
    cout << "Ingrese numeros enteros (0 para finalizar):" << endl;

    int contador = 1;
    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> elemento;

        if (elemento == 0)
            break;

        lista.insertarUltimo(elemento);
        contador++;
    }

    // Mostrar resultados
    cout << "\nRESULTADOS:" << endl;
    cout << "===========" << endl;

    if (lista.esVacia())
    {
        cout << "No se ingresaron elementos." << endl;
        return 0;
    }

    cout << "Lista: ";
    lista.print();

    cout << "Tamanio: " << lista.getTamanio() << " elementos" << endl;

    cout << "\nBusqueda de duplicados:" << endl;
    cout << "----------------------" << endl;
    encontrarDuplicadosCompleto(lista);

    return 0;
}