/*Dos números están representados como listas enlazadas
donde cada nodo contiene un dígito. Los dígitos están
almacenados en orden inverso. Sumar los dos números y
retornar el resultado como una lista.*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

void sumarListas(CircList<int> &lista1, CircList<int> &lista2)
{
    CircList<int> resultado;
    int carry = 0;
    int n1 = lista1.getTamanio();
    int n2 = lista2.getTamanio();
    int maxSize = (n1 > n2) ? n1 : n2;

    for (int i = 0; i < maxSize; i++)
    {
        int digit1 = (i < n1) ? lista1.getDato(i) : 0;
        int digit2 = (i < n2) ? lista2.getDato(i) : 0;

        int sum = digit1 + digit2 + carry;
        resultado.insertarUltimo(sum % 10);
        carry = sum / 10;
    }

    if (carry > 0)
    {
        resultado.insertarUltimo(carry);
    }

    cout << "Resultado de la suma: ";

    for (int i = 0; i < resultado.getTamanio(); i++)
    {
        cout << resultado.getDato(i) << " ";
    }
}

int main()
{
    CircList<int> lista1;
    CircList<int> lista2;
    int n, dato;

    cout << "Ingrese la cantidad de digitos para el primer numero: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el dígito " << i + 1 << ": ";
        cin >> dato;
        lista1.insertarUltimo(dato);
    }

    cout << "Ingrese la cantidad de digitos para el segundo numero: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el dígito " << i + 1 << ": ";
        cin >> dato;
        lista2.insertarUltimo(dato);
    }

    sumarListas(lista1, lista2);

    return 0;
}