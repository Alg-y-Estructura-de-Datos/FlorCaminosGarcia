/*Dividir lista circular en dos mitades*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int elemento;
    
    cout << "CALCULADORA DE DIVISION DE LISTA CIRCULAR" << endl;
    cout << "Ingrese elementos (0 para terminar): ";
    
    while (cin >> elemento && elemento != 0) {
        lista.insertarUltimo(elemento);
    }
    
    int tamanio = lista.getTamanio();
    int mitad = tamanio / 2;
    
    cout << "\nRESULTADO:" << endl;
    cout << "Lista original: " << tamanio << " elementos" << endl;
    cout << "Primera mitad: " << mitad << " elementos" << endl;
    cout << "Segunda mitad: " << (tamanio - mitad) << " elementos" << endl;
    
    if (tamanio % 2 == 0) {
        cout << "Division exacta - mitades iguales" << endl;
    } else {
        cout << "Division aproximada - segunda mitad tiene 1 elemento mas" << endl;
    }
    
    return 0;
}