/*Invertir cadena usando pila*/
#include <iostream>
#include <string>
#include "Pila/Pila.h"

using namespace std;

// Versión 1: Modifica la cadena original (como tu versión)
void invertirCadena(string &cadena)
{
    Pila<char> pila;

    // Apilar todos los caracteres
    for (char c : cadena)
    {
        pila.push(c);
    }

    // Desapilar para formar la cadena invertida
    for (size_t i = 0; i < cadena.length(); ++i)
    {
        cadena[i] = pila.pop();
    }
}

// Versión 2: Retorna una nueva cadena invertida (más funcional)
string invertirCadena2(const string &cadena)
{
    Pila<char> pila;
    string resultado;

    // Apilar todos los caracteres
    for (char c : cadena)
    {
        pila.push(c);
    }

    // Desapilar para formar la cadena invertida
    while (!pila.esVacia())
    {
        resultado += pila.pop();
    }

    return resultado;
}

// Versión 3: Invertir palabras manteniendo el orden (más avanzado)
string invertirPalabras(const string &texto)
{
    Pila<char> pila;
    string resultado;
    string palabra;

    for (char c : texto)
    {
        if (c == ' ')
        {
            // Invertir la palabra acumulada
            while (!pila.esVacia())
            {
                palabra += pila.pop();
            }
            resultado += palabra + " ";
            palabra = "";
        }
        else
        {
            pila.push(c);
        }
    }

    // Invertir la última palabra
    while (!pila.esVacia())
    {
        palabra += pila.pop();
    }
    resultado += palabra;

    return resultado;
}

// Función para mostrar ejemplos
void mostrarEjemplos()
{
    cout << "=== EJEMPLOS ===" << endl;
    string ejemplos[] = {"Hola", "12345", "a b c", "C++", ""};

    for (string ejemplo : ejemplos)
    {
        string original = ejemplo;
        cout << "Original: \"" << ejemplo << "\"";

        if (!ejemplo.empty())
        {
            invertirCadena(ejemplo);
            cout << " -> Invertida: \"" << ejemplo << "\"";
        }
        cout << endl;
    }
    cout << "================" << endl << endl;
}

// Función para probar diferentes opciones
void menuInversion()
{
    cout << "OPCIONES DE INVERSION:" << endl;
    cout << "1. Invertir cadena (modifica original)" << endl;
    cout << "2. Invertir cadena (nueva cadena)" << endl;
    cout << "3. Invertir palabras individualmente" << endl;
    cout << "4. Ver ejemplos" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    string cadena;
    int opcion;

    cout << "=== INVERSOR DE CADENAS CON PILA ===" << endl;
    mostrarEjemplos();

    while (true)
    {
        menuInversion();
        cout << endl
             << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer

        if (opcion == 0)
        {
            cout << "¡Hasta luego!" << endl;
            break;
        }

        if (opcion == 4)
        {
            mostrarEjemplos();
            continue;
        }

        cout << "Ingresa una cadena: ";
        getline(cin, cadena);

        if (cadena.empty())
        {
            cout << "Cadena vacia. Intenta de nuevo." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            string temp = cadena; // Guardar original
            invertirCadena(cadena);
            cout << "Original: \"" << temp << "\"" << endl;
            cout << "Invertida: \"" << cadena << "\"" << endl;
            break;
        }
        case 2:
        {
            string invertida = invertirCadena2(cadena);
            cout << "Original: \"" << cadena << "\"" << endl;
            cout << "Invertida: \"" << invertida << "\"" << endl;
            break;
        }
        case 3:
        {
            string invertida = invertirPalabras(cadena);
            cout << "Original: \"" << cadena << "\"" << endl;
            cout << "Palabras invertidas: \"" << invertida << "\"" << endl;
            break;
        }
        default:
            cout << "Opcion no valida!" << endl;
        }
        cout << endl;
    }

    return 0;
}