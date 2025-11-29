#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void insertarOrdenado(Lista<int> &lista, int valor) {
    if (lista.esVacia()) {
        lista.insertarPrimero(valor);
        return;
    }
    
    int i = 0;
    int tamanio = lista.getTamanio();
    
    // Encontrar la posición de inserción
    while (i < tamanio && lista.getDato(i) < valor) {
        i++;
    }
    
    lista.insertar(i, valor);
}

void mostrarMenu() {
    cout << "\n=== MENU DE OPCIONES ===" << endl;
    cout << "1. Insertar numero ordenado" << endl;
    cout << "2. Mostrar lista" << endl;
    cout << "3. Buscar numero" << endl;
    cout << "4. Eliminar numero" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void buscarNumero(const Lista<int> &lista, int valor) {
    bool encontrado = false;
    int posicion = -1;
    
    for (int i = 0; i < lista.getTamanio(); i++) {
        if (lista.getDato(i) == valor) {
            encontrado = true;
            posicion = i;
            break;
        }
    }
    
    if (encontrado) {
        cout << " Numero " << valor << " encontrado en posicion " << posicion << endl;
    } else {
        cout << " Numero " << valor << " no encontrado" << endl;
    }
}

int main() {
    Lista<int> lista;
    int opcion, numero;
    
    cout << "=== SISTEMA DE LISTA ORDENADA ===" << endl;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese numero a insertar: ";
                cin >> numero;
                insertarOrdenado(lista, numero);
                cout << " Numero insertado. Lista actual: ";
                lista.print();
                break;
                
            case 2:
                if (lista.esVacia()) {
                    cout << "La lista esta vacia" << endl;
                } else {
                    cout << "Lista ordenada (" << lista.getTamanio() << " elementos): ";
                    lista.print();
                }
                break;
                
            case 3:
                if (lista.esVacia()) {
                    cout << "La lista esta vacia" << endl;
                } else {
                    cout << "Ingrese numero a buscar: ";
                    cin >> numero;
                    buscarNumero(lista, numero);
                }
                break;
                
            case 4:
                if (lista.esVacia()) {
                    cout << "La lista esta vacia" << endl;
                } else {
                    cout << "Ingrese numero a eliminar: ";
                    cin >> numero;
                    // Buscar y eliminar (implementación básica)
                    bool eliminado = false;
                    for (int i = 0; i < lista.getTamanio(); i++) {
                        if (lista.getDato(i) == numero) {
                            lista.remover(i);
                            cout << " Numero eliminado. Lista actual: ";
                            lista.print();
                            eliminado = true;
                            break;
                        }
                    }
                    if (!eliminado) {
                        cout << " Numero no encontrado" << endl;
                    }
                }
                break;
                
            case 5:
                cout << "Saliendo..." << endl;
                break;
                
            default:
                cout << "Opción invalida" << endl;
        }
    } while (opcion != 5);

    return 0;
}