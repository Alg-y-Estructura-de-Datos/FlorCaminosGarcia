/**Convertir infijo a postfijo*/
/**Convertir infijo a postfijo - Versión Simplificada*/
/**Convertir infijo a postfijo - Versión Simplificada y Compatible*/
/**Convertir infijo a postfijo - Versión alternativa sin cima()*/
#include <iostream>
#include <string>
#include <cctype>
#include "Pila/Pila.h"

using namespace std;

bool esOperador(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int prioridad(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infijoAPostfijo(const string &infijo)
{
    Pila<char> pila;
    string postfijo = "";

    for (char c : infijo)
    {
        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            postfijo += c;
            postfijo += ' ';
        }
        else if (c == '(')
        {
            pila.push(c);
        }
        else if (c == ')')
        {
            while (!pila.esVacia())
            {
                char tope = pila.pop();
                if (tope == '(')
                    break;
                postfijo += tope;
                postfijo += ' ';
            }
        }
        else if (esOperador(c))
        {
            // Estrategia simple: desapilar temporalmente y volver a apilar
            Pila<char> temp;

            // Mover operadores de alta prioridad a la salida
            while (!pila.esVacia())
            {
                char tope = pila.pop();
                if (tope == '(' || prioridad(tope) < prioridad(c))
                {
                    temp.push(tope);
                    break;
                }
                postfijo += tope;
                postfijo += ' ';
            }

            // Devolver elementos a la pila
            while (!temp.esVacia())
            {
                pila.push(temp.pop());
            }

            pila.push(c);
        }
    }

    // Vaciar pila final
    while (!pila.esVacia())
    {
        postfijo += pila.pop();
        postfijo += ' ';
    }

    if (!postfijo.empty() && postfijo.back() == ' ')
    {
        postfijo.pop_back();
    }

    return postfijo;
}

int main()
{
    cout << "CONVERSOR INFIJO A POSTFIJA" << endl;

    // Probar algunas expresiones
    string pruebas[] = {"3+4", "3+4*5", "(3+4)*5", "1+2*3-4"};

    for (string prueba : pruebas)
    {
        string resultado = infijoAPostfijo(prueba);
        cout << prueba << " -> " << resultado << endl;
    }

    cout << "\nIngresa tus expresiones (o 'salir'):" << endl;

    string expresion;
    while (true)
    {
        cout << "> ";
        getline(cin, expresion);

        if (expresion == "salir")
            break;
        if (expresion.empty())
            continue;

        string resultado = infijoAPostfijo(expresion);
        cout << "Resultado: " << resultado << endl;
    }

    return 0;
}