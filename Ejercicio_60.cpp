#include <iostream>
#include "Lista/Lista.h"
#include "Algoritmos Ordenamiento/bubbleSort.h"

using namespace std;

template <class T>
Lista<T> fusionarListasOrdenadas(const Lista<T> &lista1, const Lista<T> &lista2)
{
    Lista<T> listaFusionada;
    int i = 0, j = 0;
    int tamanio1 = lista1.getTamanio();
    int tamanio2 = lista2.getTamanio();

    // Algoritmo de fusión (merge) de dos listas ordenadas
    while (i < tamanio1 && j < tamanio2)
    {
        if (lista1.getDato(i) <= lista2.getDato(j))
        {
            listaFusionada.insertarUltimo(lista1.getDato(i++));
        }
        else
        {
            listaFusionada.insertarUltimo(lista2.getDato(j++));
        }
    }

    // Agregar elementos restantes de lista1
    while (i < tamanio1)
    {
        listaFusionada.insertarUltimo(lista1.getDato(i++));
    }

    // Agregar elementos restantes de lista2
    while (j < tamanio2)
    {
        listaFusionada.insertarUltimo(lista2.getDato(j++));
    }

    return listaFusionada;
}

template <class T>
void ordenarLista(Lista<T> &lista)
{
    if (lista.esVacia() || lista.getTamanio() == 1)
        return;

    int tamanio = lista.getTamanio();
    T *arreglo = new T[tamanio];

    // Copiar lista a arreglo
    for (int i = 0; i < tamanio; i++)
    {
        arreglo[i] = lista.getDato(i);
    }

    // Ordenar arreglo
    bubbleSort(arreglo, tamanio);

    // Copiar arreglo ordenado de vuelta a la lista
    for (int i = 0; i < tamanio; i++)
    {
        lista.reemplazar(i, arreglo[i]);
    }

    delete[] arreglo;
}

void ingresarLista(Lista<int> &lista, const string &nombre)
{
    cout << "\n--- " << nombre << " LISTA ---" << endl;
    cout << "Ingrese numeros (-1 para terminar):" << endl;

    int valor;
    int contador = 1;

    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> valor;

        if (cin.fail())
        {
            cout << "Error: Entrada invalida. Ingrese un numero entero." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (valor == -1)
            break;

        lista.insertarUltimo(valor);
        contador++;
    }
}

int main()
{
    Lista<int> lista1, lista2;

    cout << "=== FUSIONADOR DE LISTAS ORDENADAS ===" << endl;

    // Ingresar ambas listas
    ingresarLista(lista1, "PRIMERA");
    ingresarLista(lista2, "SEGUNDA");

    // Verificar si hay datos para procesar
    if (lista1.esVacia() && lista2.esVacia())
    {
        cout << "\n❌ Ambas listas estan vacias. No hay nada que fusionar." << endl;
        return 0;
    }

    // Mostrar listas originales
    cout << "\n--- LISTAS ORIGINALES ---" << endl;
    cout << "Lista 1 (" << lista1.getTamanio() << " elementos): ";
    lista1.print();
    cout << "Lista 2 (" << lista2.getTamanio() << " elementos): ";
    lista2.print();

    // Ordenar listas
    cout << "\n--- ORDENANDO LISTAS ---" << endl;
    if (!lista1.esVacia())
    {
        ordenarLista(lista1);
        cout << "✅ Lista 1 ordenada: ";
        lista1.print();
    }

    if (!lista2.esVacia())
    {
        ordenarLista(lista2);
        cout << "✅ Lista 2 ordenada: ";
        lista2.print();
    }

    // Fusionar listas
    cout << "\n--- FUSIONANDO LISTAS ---" << endl;
    Lista<int> listaFusionada = fusionarListasOrdenadas(lista1, lista2);

    cout << "🎯 Lista fusionada: ";
    listaFusionada.print();

    // Mostrar estadísticas
    cout << "\n--- ESTADISTICAS ---" << endl;
    cout << "• Tamaño lista 1: " << lista1.getTamanio() << " elementos" << endl;
    cout << "• Tamaño lista 2: " << lista2.getTamanio() << " elementos" << endl;
    cout << "• Tamaño lista fusionada: " << listaFusionada.getTamanio() << " elementos" << endl;

    if (!listaFusionada.esVacia())
    {
        cout << "• Rango: [" << listaFusionada.getDato(0)
             << " - " << listaFusionada.getDato(listaFusionada.getTamanio() - 1) << "]" << endl;
    }

    // Verificación de la fusión
    if (listaFusionada.getTamanio() == lista1.getTamanio() + lista2.getTamanio())
    {
        cout << "✅ Fusion completada correctamente." << endl;
    }
    else
    {
        cout << "⚠️  Advertencia: El tamaño de la lista fusionada no coincide con la suma." << endl;
    }

    return 0;
}