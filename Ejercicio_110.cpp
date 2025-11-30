/*Usar pila para invertir lista*/
#include <iostream>
#include "Lista/Lista.h"
#include "Pila/Pila.h"

using namespace std;

void invertirLista(Lista<int> &lista) {
    Pila<int> pila;
    int tamanio = lista.getTamanio();

    // Apilar todos los elementos de la lista
    for (int i = 0; i < tamanio; i++) {
        pila.push(lista.getDato(i));
    }

    // Desapilar para invertir el orden
    for (int i = 0; i < tamanio; i++) {
        lista.reemplazar(i, pila.pop());
    }
}

void mostrarLista(const Lista<int> &lista) {
    int tamanio = lista.getTamanio();
    cout << "[";
    for (int i = 0; i < tamanio; i++) {
        cout << lista.getDato(i);
        if (i < tamanio - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Lista<int> lista;
    int elemento;
    int opcion;

    cout << "=== INVERTIR LISTA CON PILA ===" << endl;

    while (true) {
        cout << "\nMENU:" << endl;
        cout << "1. Agregar elemento a la lista" << endl;
        cout << "2. Invertir lista" << endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el elemento a agregar: ";
                cin >> elemento;
                // Asumiendo que tu clase Lista tiene un método insertarUltimo
                // Si no, ajusta según los métodos disponibles
                lista.insertarUltimo(elemento);
                cout << "Elemento " << elemento << " agregado." << endl;
                break;
            }
            case 2: {
                if (lista.getTamanio() == 0) {
                    cout << "La lista está vacía. Agregue elementos primero." << endl;
                } else {
                    cout << "Lista original: ";
                    mostrarLista(lista);
                    
                    invertirLista(lista);
                    
                    cout << "Lista invertida: ";
                    mostrarLista(lista);
                }
                break;
            }
            case 3: {
                if (lista.getTamanio() == 0) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    cout << "Lista actual: ";
                    mostrarLista(lista);
                }
                break;
            }
            case 4: {
                cout << "¡Hasta luego!" << endl;
                return 0;
            }
            default: {
                cout << "Opción no valida. Intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}