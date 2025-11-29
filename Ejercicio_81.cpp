/*Convertir lista doble a lista simple*/
#include <iostream>
#include "Lista/Lista.h"
#include "Lista/ListaDoble.h"

using namespace std;

// Conversión: Lista Simple → Lista Doble
ListaDoble<int> convertirSimpleADoble(const Lista<int> &listaSimple)
{
    ListaDoble<int> listaDoble;

    if (listaSimple.esVacia())
    {
        return listaDoble;
    }

    int tamanio = listaSimple.getTamanio();
    for (int i = 0; i < tamanio; i++)
    {
        int elemento = listaSimple.getDato(i);
        listaDoble.insertarUltimo(elemento);
    }

    return listaDoble;
}

// 🔄 NUEVA FUNCIÓN: Conversión Lista Doble → Lista Simple
Lista<int> convertirDobleASimple(const ListaDoble<int> &listaDoble)
{
    Lista<int> listaSimple;

    if (listaDoble.esVacia())
    {
        return listaSimple;
    }

    int tamanio = listaDoble.getTamanio();
    for (int i = 0; i < tamanio; i++)
    {
        int elemento = listaDoble.getDato(i);
        listaSimple.insertarUltimo(elemento);
    }

    return listaSimple;
}

void probarCasosEspeciales()
{
    cout << "=== CASOS ESPECIALES ===" << endl;

    // Caso 1: Lista vacía
    Lista<int> vacia;
    ListaDoble<int> dobleVacia = convertirSimpleADoble(vacia);
    cout << "Lista vacia convertida. Tamanio: " << dobleVacia.getTamanio() << endl;

    // Conversión inversa
    Lista<int> simpleDesdeVacia = convertirDobleASimple(dobleVacia);
    cout << "Lista vacia reconvertida a simple. Tamanio: " << simpleDesdeVacia.getTamanio() << endl;

    // Caso 2: Lista con un solo elemento
    Lista<int> unElemento;
    unElemento.insertarUltimo(99);
    ListaDoble<int> dobleUnElemento = convertirSimpleADoble(unElemento);
    cout << "Lista con un elemento (doble): ";
    dobleUnElemento.imprimir();

    // Conversión inversa
    Lista<int> simpleDesdeUno = convertirDobleASimple(dobleUnElemento);
    cout << "Reconvertida a simple: ";
    simpleDesdeUno.print();

    // Caso 3: Lista con elementos repetidos
    Lista<int> repetidos;
    repetidos.insertarUltimo(5);
    repetidos.insertarUltimo(5);
    repetidos.insertarUltimo(5);
    ListaDoble<int> dobleRepetidos = convertirSimpleADoble(repetidos);
    cout << "Lista con repetidos (doble): ";
    dobleRepetidos.imprimir();

    // Conversión inversa
    Lista<int> simpleDesdeRepetidos = convertirDobleASimple(dobleRepetidos);
    cout << "Reconvertida a simple: ";
    simpleDesdeRepetidos.print();
}

// Función para demostrar la conversión bidireccional completa
void demostracionBidireccional()
{
    cout << "\n=== DEMOSTRACIÓN BIDIRECCIONAL ===" << endl;

    // Crear lista simple original
    Lista<int> listaOriginal;
    listaOriginal.insertarUltimo(100);
    listaOriginal.insertarUltimo(200);
    listaOriginal.insertarUltimo(300);
    listaOriginal.insertarUltimo(400);

    cout << "1. Lista original (simple): ";
    listaOriginal.print();

    // Convertir a lista doble
    ListaDoble<int> listaDoble = convertirSimpleADoble(listaOriginal);
    cout << "2. Convertida a lista doble: ";
    listaDoble.imprimir();

    // Convertir de vuelta a lista simple
    Lista<int> listaReconvertida = convertirDobleASimple(listaDoble);
    cout << "3. Reconvertida a lista simple: ";
    listaReconvertida.print();

    // Verificar que son iguales
    cout << "4. Verificación:" << endl;
    cout << "   - Tamaño original: " << listaOriginal.getTamanio() << endl;
    cout << "   - Tamaño reconvertida: " << listaReconvertida.getTamanio() << endl;

    bool sonIguales = true;
    if (listaOriginal.getTamanio() == listaReconvertida.getTamanio())
    {
        for (int i = 0; i < listaOriginal.getTamanio(); i++)
        {
            if (listaOriginal.getDato(i) != listaReconvertida.getDato(i))
            {
                sonIguales = false;
                break;
            }
        }
    }
    else
    {
        sonIguales = false;
    }

    if (sonIguales)
    {
        cout << " Las listas son identicas - conversion correcta" << endl;
    }
    else
    {
        cout << " Error: Las listas son diferentes" << endl;
    }
}

// Función para probar conversión directa de lista doble a simple
void probarConversionDirecta()
{
    cout << "\n=== CONVERSION DIRECTA DOBLE → SIMPLE ===" << endl;

    // Crear una lista doble directamente
    ListaDoble<int> listaDobleOriginal;
    listaDobleOriginal.insertarUltimo(777);
    listaDobleOriginal.insertarUltimo(888);
    listaDobleOriginal.insertarUltimo(999);

    cout << "Lista doble original: ";
    listaDobleOriginal.imprimir();

    // Convertir a lista simple
    Lista<int> listaSimple = convertirDobleASimple(listaDobleOriginal);
    cout << "Convertida a lista simple: ";
    listaSimple.print();

    // Convertir de vuelta para verificar
    ListaDoble<int> listaDobleVerificada = convertirSimpleADoble(listaSimple);
    cout << "Reconvertida a lista doble: ";
    listaDobleVerificada.imprimir();
}

int main()
{
    cout << "DEMOSTRACION COMPLETA DE CONVERSION" << endl;
    cout << "===================================" << endl;

    // Conversión básica simple → doble
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

    // Nueva: conversión de vuelta a simple
    Lista<int> listaReconvertida = convertirDobleASimple(listaConvertida);
    cout << "Lista reconvertida (simple): ";
    listaReconvertida.print();

    // Probar casos especiales
    probarCasosEspeciales();

    // Demostración bidireccional
    demostracionBidireccional();

    // Prueba de conversión directa
    probarConversionDirecta();

    return 0;
}