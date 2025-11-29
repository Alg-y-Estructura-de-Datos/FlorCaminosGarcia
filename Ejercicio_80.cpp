#include <iostream>
#include "Lista/Lista.h"
#include "Lista/ListaDoble.h"

using namespace std;

ListaDoble<int> convertirSimpleADoble(const Lista<int>& listaSimple) {
    ListaDoble<int> listaDoble;
    
    // Si la lista simple está vacía, retornar lista doble vacía
    if (listaSimple.esVacia()) {
        return listaDoble;
    }
    
    // Recorrer la lista simple y agregar cada elemento a la lista doble
    int tamanio = listaSimple.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        int elemento = listaSimple.getDato(i);
        listaDoble.insertarUltimo(elemento);
    }
    
    return listaDoble;
}

void probarCasosEspeciales() {
    cout << "=== CASOS ESPECIALES ===" << endl;

    // Caso 1: Lista vacía
    Lista<int> vacia;
    ListaDoble<int> dobleVacia = convertirSimpleADoble(vacia);
    cout << "Lista vacia convertida. Tamanio: " << dobleVacia.getTamanio() << endl;

    // Caso 2: Lista con un solo elemento
    Lista<int> unElemento;
    unElemento.insertarUltimo(99);
    ListaDoble<int> dobleUnElemento = convertirSimpleADoble(unElemento);
    cout << "Lista con un elemento: ";
    dobleUnElemento.imprimir();

    // Caso 3: Lista con elementos repetidos
    Lista<int> repetidos;
    repetidos.insertarUltimo(5);
    repetidos.insertarUltimo(5);
    repetidos.insertarUltimo(5);
    ListaDoble<int> dobleRepetidos = convertirSimpleADoble(repetidos);
    cout << "Lista con repetidos: ";
    dobleRepetidos.imprimir();
}

int main() {
    cout << "DEMOSTRACION COMPLETA DE CONVERSION" << endl;
    cout << "===================================" << endl;

    // Conversión básica
    Lista<int> miLista;
    miLista.insertarUltimo(10);
    miLista.insertarUltimo(25);
    miLista.insertarUltimo(40);
    miLista.insertarUltimo(55);

    cout << "Lista original (simple): ";
    miLista.print();

    ListaDoble<int> listaConvertida = convertirSimpleADoble(miLista);

    cout << "Lista convertida (doble): ";
    listaConvertida.imprimir();

    // Probar casos especiales
    probarCasosEspeciales();

    return 0;
}