/*Sumar dos números representados como listas*/
/*Sumar dos números representados como listas*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

// Suma con dígitos en orden inverso (más fácil)
Lista<int> sumarNumerosInverso(const Lista<int> &num1, const Lista<int> &num2)
{
    Lista<int> resultado;
    int carry = 0; // Acarreo
    int i = 0, j = 0;
    int size1 = num1.getTamanio();
    int size2 = num2.getTamanio();

    // Sumar dígito por dígito
    while (i < size1 || j < size2 || carry > 0)
    {
        int digito1 = (i < size1) ? num1.getDato(i) : 0;
        int digito2 = (j < size2) ? num2.getDato(j) : 0;

        int suma = digito1 + digito2 + carry;
        carry = suma / 10;               // Nuevo acarreo
        int digitoResultado = suma % 10; // Dígito del resultado

        resultado.insertarUltimo(digitoResultado);

        i++;
        j++;
    }

    return resultado;
}

// Función auxiliar para invertir una lista
Lista<int> invertirLista(const Lista<int> &lista)
{
    Lista<int> invertida;
    int tamanio = lista.getTamanio();

    for (int i = tamanio - 1; i >= 0; i--)
    {
        invertida.insertarUltimo(lista.getDato(i));
    }

    return invertida;
}

// Suma con dígitos en orden normal (más complejo)
Lista<int> sumarNumerosNormal(const Lista<int> &num1, const Lista<int> &num2)
{
    // Invertir ambas listas, sumar, y volver a invertir el resultado
    Lista<int> num1Inv = invertirLista(num1);
    Lista<int> num2Inv = invertirLista(num2);

    Lista<int> resultadoInv = sumarNumerosInverso(num1Inv, num2Inv);

    return invertirLista(resultadoInv);
}

// Función para convertir lista a número (para verificación)
int listaANumeroInverso(const Lista<int> &lista)
{
    int numero = 0;
    int multiplicador = 1;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        numero += lista.getDato(i) * multiplicador;
        multiplicador *= 10;
    }

    return numero;
}

int listaANumeroNormal(const Lista<int> &lista)
{
    int numero = 0;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        numero = numero * 10 + lista.getDato(i);
    }

    return numero;
}

// Función para crear lista desde número (orden inverso)
Lista<int> numeroAListaInverso(int numero)
{
    Lista<int> lista;

    if (numero == 0)
    {
        lista.insertarUltimo(0);
        return lista;
    }

    while (numero > 0)
    {
        lista.insertarUltimo(numero % 10);
        numero /= 10;
    }

    return lista;
}

// Función para crear lista desde número (orden normal)
Lista<int> numeroAListaNormal(int numero)
{
    Lista<int> lista;

    if (numero == 0)
    {
        lista.insertarUltimo(0);
        return lista;
    }

    // Contar dígitos
    int temp = numero;
    int digitos = 0;
    while (temp > 0)
    {
        digitos++;
        temp /= 10;
    }

    // Extraer dígitos en orden normal
    temp = numero;
    for (int i = digitos - 1; i >= 0; i--)
    {
        int divisor = 1;
        for (int j = 0; j < i; j++)
        {
            divisor *= 10;
        }
        lista.insertarUltimo(temp / divisor);
        temp %= divisor;
    }

    return lista;
}

int main()
{
    cout << "=== SUMAR NÚMEROS REPRESENTADOS COMO LISTAS ===" << endl;

    // Ejemplo 1: Suma en orden inverso (342 + 465 = 807)
    cout << "\n--- EJEMPLO 1: Orden Inverso (342 + 465 = 807) ---" << endl;

    Lista<int> num1_inv, num2_inv;
    // 342 en orden inverso: 2->4->3
    num1_inv.insertarUltimo(2);
    num1_inv.insertarUltimo(4);
    num1_inv.insertarUltimo(3);

    // 465 en orden inverso: 5->6->4
    num2_inv.insertarUltimo(5);
    num2_inv.insertarUltimo(6);
    num2_inv.insertarUltimo(4);

    cout << "Número 1 (inverso): ";
    num1_inv.print();
    cout << "Número 2 (inverso): ";
    num2_inv.print();

    Lista<int> suma_inv = sumarNumerosInverso(num1_inv, num2_inv);
    cout << "Suma (inverso): ";
    suma_inv.print();

    // Verificación
    cout << "Verificación: " << listaANumeroInverso(num1_inv) << " + " << listaANumeroInverso(num2_inv) << " = " << listaANumeroInverso(suma_inv) << endl;

    // Ejemplo 2: Suma en orden normal (342 + 465 = 807)
    cout << "\n--- EJEMPLO 2: Orden Normal (342 + 465 = 807) ---" << endl;

    Lista<int> num1_norm, num2_norm;
    // 342 en orden normal: 3->4->2
    num1_norm.insertarUltimo(3);
    num1_norm.insertarUltimo(4);
    num1_norm.insertarUltimo(2);

    // 465 en orden normal: 4->6->5
    num2_norm.insertarUltimo(4);
    num2_norm.insertarUltimo(6);
    num2_norm.insertarUltimo(5);

    cout << "Número 1 (normal): ";
    num1_norm.print();
    cout << "Número 2 (normal): ";
    num2_norm.print();

    Lista<int> suma_norm = sumarNumerosNormal(num1_norm, num2_norm);
    cout << "Suma (normal): ";
    suma_norm.print();

    // Verificación
    cout << "Verificación: " << listaANumeroNormal(num1_norm) << " + " << listaANumeroNormal(num2_norm) << " = " << listaANumeroNormal(suma_norm) << endl;

    // Ejemplo 3: Números de diferente longitud
    cout << "\n--- EJEMPLO 3: Diferente longitud (999 + 1 = 1000) ---" << endl;

    Lista<int> num3, num4;
    // 999 en orden inverso: 9->9->9
    num3.insertarUltimo(9);
    num3.insertarUltimo(9);
    num3.insertarUltimo(9);

    // 1 en orden inverso: 1
    num4.insertarUltimo(1);

    cout << "Número 1 (999): ";
    num3.print();
    cout << "Número 2 (1): ";
    num4.print();

    Lista<int> suma3 = sumarNumerosInverso(num3, num4);
    cout << "Suma (1000): ";
    suma3.print();

    cout << "Verificación: " << listaANumeroInverso(num3) << " + " << listaANumeroInverso(num4) << " = " << listaANumeroInverso(suma3) << endl;

    return 0;
}