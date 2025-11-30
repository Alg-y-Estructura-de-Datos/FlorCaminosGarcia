/*Implementar algoritmo de ordenamiento merge sort para listas*/
#include <iostream>
#include <vector>
#include "Lista/Lista.h"
#include "Algoritmos Ordenamiento/quickSort.h"

using namespace std;

void ordenarLista(Lista<int> &lista) {
    int n = lista.getTamanio();
    if (n <= 1) return;
    
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(lista.getDato(i));
    }
    
    quickSort(temp, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        lista.reemplazar(i, temp[i]);
    }
}

void mostrarLista(const Lista<int> &lista) {
    int n = lista.getTamanio();
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << lista.getDato(i);
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Lista<int> lista;
    int opcion, valor;
    
    cout << "ORDENADOR DE LISTAS - QUICKSORT" << endl;
    
    while (true) {
        cout << "\n1. Agregar 2. Ordenar 3. Mostrar 4. Salir\nOpción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                lista.insertarUltimo(valor);
                break;
            case 2:
                if (lista.getTamanio() > 0) {
                    ordenarLista(lista);
                    cout << "Lista ordenada." << endl;
                } else {
                    cout << "Lista vacía." << endl;
                }
                break;
            case 3:
                mostrarLista(lista);
                break;
            case 4:
                return 0;
            default:
                cout << "Opción inválida." << endl;
        }
    }
}