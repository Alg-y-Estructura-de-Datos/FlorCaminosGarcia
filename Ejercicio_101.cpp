/*Verificar paréntesis balanceados*/
/*Verificar paréntesis balanceados*/
#include <iostream>
#include <string>
#include "Pila/Pila.h"

using namespace std;

bool verificarParentesisBalanceados(const string &expresion)
{
    Pila<char> pila;
    for (char ch : expresion)
    {
        if (ch == '(')
        {
            pila.push(ch);
        }
        else if (ch == ')')
        {
            if (pila.esVacia())
            {
                return false;
            }
            pila.pop();
        }
    }

    return pila.esVacia();
}

int main()
{
    string expresion;
    char c;

    cout << "Ingrese una expresion con parentesis: ";

    // Leer carácter por carácter hasta salto de línea
    while (cin.get(c) && c != '\n')
    {
        expresion += c;
    }

    if (verificarParentesisBalanceados(expresion))
    {
        cout << "Los parentesis estan balanceados." << endl;
    }
    else
    {
        cout << "Los parentesis no estan balanceados." << endl;
    }

    return 0;
}
