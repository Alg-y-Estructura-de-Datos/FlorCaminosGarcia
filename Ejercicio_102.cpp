/*Evaluar expresión postfija*/
/*Evaluar expresión postfija*/
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "Pila/Pila.h"

using namespace std;

int evaluarPostfija(const string &expresion)
{
    Pila<int> pila;
    stringstream ss(expresion);
    string token;

    while (ss >> token) // Lee tokens separados por espacios
    {
        // Si es un número (puede tener múltiples dígitos)
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1])))
        {
            pila.push(stoi(token)); // Convertir string a entero
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            // Verificar que hay suficientes operandos
            if (pila.esVacia())
            {
                throw invalid_argument("Faltan operandos");
            }
            int operando2 = pila.pop();
            
            if (pila.esVacia())
            {
                throw invalid_argument("Faltan operandos");
            }
            int operando1 = pila.pop();
            int resultado;

            if (token == "+")
            {
                resultado = operando1 + operando2;
            }
            else if (token == "-")
            {
                resultado = operando1 - operando2; // ¡ORDEN IMPORTANTE!
            }
            else if (token == "*")
            {
                resultado = operando1 * operando2;
            }
            else if (token == "/")
            {
                if (operando2 == 0)
                {
                    throw invalid_argument("Division por cero");
                }
                resultado = operando1 / operando2; // ¡ORDEN IMPORTANTE!
            }

            pila.push(resultado);
        }
        else
        {
            throw invalid_argument("Caracter no valido: " + token);
        }
    }

    // Al final debe quedar solo un elemento en la pila
    if (pila.esVacia())
    {
        throw invalid_argument("Expresion vacia");
    }

    int resultadoFinal = pila.pop();
    
    if (!pila.esVacia())
    {
        throw invalid_argument("Sobran operandos");
    }

    return resultadoFinal;
}

int main()
{
    string expresion;

    cout << "Ingrese una expresion postfija (ejemplo: '5 3 + 4 2 - *'): ";
    getline(cin, expresion);

    try
    {
        int resultado = evaluarPostfija(expresion);
        cout << "El resultado de la expresion postfija es: " << resultado << endl;
    }
    catch (const exception &e)
    {
        cout << "Error al evaluar la expresion: " << e.what() << endl;
    }

    return 0;
}