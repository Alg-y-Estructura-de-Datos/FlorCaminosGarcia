#include <iostream>
#include "Lista/Lista.h"

using namespace std;

// Función principal optimizada - elimina duplicados preservando primera ocurrencia
void eliminarDuplicados(Lista<int> &lista) {
    if (lista.esVacia()) return;
    
    Lista<int> unicos;
    
    for (int i = 0; i < lista.getTamanio(); i++) {
        int actual = lista.getDato(i);
        bool existe = false;
        
        // Buscar si ya existe en únicos
        for (int j = 0; j < unicos.getTamanio(); j++) {
            if (unicos.getDato(j) == actual) {
                existe = true;
                break;
            }
        }
        
        if (!existe) {
            unicos.insertarUltimo(actual);
        }
    }
    
    // Reemplazar lista original
    lista.vaciar();
    for (int i = 0; i < unicos.getTamanio(); i++) {
        lista.insertarUltimo(unicos.getDato(i));
    }
}

// Demostración rápida
int main() {
    Lista<int> lista;
    
    // Lista con duplicados no consecutivos
    lista.insertarUltimo(1);
    lista.insertarUltimo(1);
    lista.insertarUltimo(2);
    lista.insertarUltimo(1);  
    lista.insertarUltimo(3);
    lista.insertarUltimo(2);  
    lista.insertarUltimo(4);
    lista.insertarUltimo(1);  
    
    cout << "Lista con duplicados: ";
    lista.print();  // 1->2->1->3->2->4->1->NULL
    
    eliminarDuplicados(lista);
    
    cout << "Lista sin duplicados: ";
    lista.print();  // 1->2->3->4->NULL
    
    return 0;
}