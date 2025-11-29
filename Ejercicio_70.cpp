/*Dividir lista en dos mitades*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void dividirListaMitades(const Lista<T> &listaOriginal, Lista<T> &mitad1, Lista<T> &mitad2)
{
    mitad1.vaciar();
    mitad2.vaciar();

    if (listaOriginal.esVacia())
    {
        return;
    }

    int tamanio = listaOriginal.getTamanio();
    int puntoDivision = tamanio / 2;

    // Primera mitad
    for (int i = 0; i < puntoDivision; i++)
    {
        mitad1.insertarUltimo(listaOriginal.getDato(i));
    }

    // Segunda mitad
    for (int i = puntoDivision; i < tamanio; i++)
    {
        mitad2.insertarUltimo(listaOriginal.getDato(i));
    }
}

// Función para verificar si la división es balanceada
void verificarBalance(const Lista<int> &mitad1, const Lista<int> &mitad2)
{
    int diff = abs(mitad1.getTamanio() - mitad2.getTamanio());

    cout << "\n--- VERIFICACION DE BALANCE ---" << endl;
    cout << "Tamanio mitad 1: " << mitad1.getTamanio() << " elementos" << endl;
    cout << "Tamanio mitad 2: " << mitad2.getTamanio() << " elementos" << endl;
    cout << "Diferencia: " << diff << " elementos" << endl;

    if (diff <= 1)
    {
        cout << " Division balanceada" << endl;
    }
    else
    {
        cout << " Division desbalanceada" << endl;
    }
}

// Función para mostrar estadísticas de las mitades
void mostrarEstadisticasMitades(const Lista<int> &mitad1, const Lista<int> &mitad2)
{
    cout << "\n--- ESTADISTICAS DE LAS MITADES ---" << endl;

    if (!mitad1.esVacia())
    {
        cout << "Mitad 1 - Rango: [" << mitad1.getDato(0) << " - " << mitad1.getDato(mitad1.getTamanio() - 1) << "]" << endl;
    }
    else
    {
        cout << "Mitad 1 - Vacia" << endl;
    }

    if (!mitad2.esVacia())
    {
        cout << "Mitad 2 - Rango: [" << mitad2.getDato(0) << " - " << mitad2.getDato(mitad2.getTamanio() - 1) << "]" << endl;
    }
    else
    {
        cout << "Mitad 2 - Vacia" << endl;
    }
}

void ingresarLista(Lista<int> &lista)
{
    cout << "Ingrese elementos (0 para terminar):" << endl;

    int valor;
    int contador = 1;

    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> valor;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (valor == 0)
            break;

        lista.insertarUltimo(valor);
        contador++;
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS DE DIVISION ---" << endl;

    // Ejemplo 1: Lista par
    Lista<int> ej1;
    for (int i = 1; i <= 6; i++)
        ej1.insertarUltimo(i);

    cout << "Ejemplo 1 - Lista con 6 elementos:" << endl;
    cout << "Original: ";
    ej1.print();

    Lista<int> m1, m2;
    dividirListaMitades(ej1, m1, m2);
    cout << "Mitad 1: ";
    m1.print();
    cout << "Mitad 2: ";
    m2.print();

    // Ejemplo 2: Lista impar
    Lista<int> ej2;
    for (int i = 1; i <= 5; i++)
        ej2.insertarUltimo(i);

    cout << "\nEjemplo 2 - Lista con 5 elementos:" << endl;
    cout << "Original: ";
    ej2.print();

    dividirListaMitades(ej2, m1, m2);
    cout << "Mitad 1: ";
    m1.print();
    cout << "Mitad 2: ";
    m2.print();
}

int main()
{
    Lista<int> listaOriginal, mitad1, mitad2;
    int opcion;

    cout << "=== DIVISOR DE LISTAS EN MITADES ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Ingresar lista" << endl;
        cout << "2. Mostrar lista actual" << endl;
        cout << "3. Dividir lista en mitades" << endl;
        cout << "4. Verificar balance" << endl;
        cout << "5. Mostrar estadisticas" << endl;
        cout << "6. Ver ejemplos" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opción invalida." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            listaOriginal.vaciar();
            ingresarLista(listaOriginal);

            if (listaOriginal.esVacia())
            {
                cout << "La lista esta vacia." << endl;
            }
            else
            {
                cout << " Lista ingresada correctamente." << endl;
                cout << "Lista: ";
                listaOriginal.print();
            }
            break;
        }

        case 2:
        {
            if (listaOriginal.esVacia())
            {
                cout << "Primero ingrese una lista (opcion 1)." << endl;
            }
            else
            {
                cout << "Lista actual: ";
                listaOriginal.print();
                cout << "Tamaño: " << listaOriginal.getTamanio() << " elementos" << endl;
            }
            break;
        }

        case 3:
        {
            if (listaOriginal.esVacia())
            {
                cout << "Primero ingrese una lista (opción 1)." << endl;
            }
            else
            {
                cout << "\n--- DIVIDIENDO LISTA ---" << endl;
                cout << "Lista original: ";
                listaOriginal.print();

                dividirListaMitades(listaOriginal, mitad1, mitad2);

                cout << " Lista dividida correctamente." << endl;
                cout << "Mitad 1: ";
                mitad1.print();
                cout << "Mitad 2: ";
                mitad2.print();

                verificarBalance(mitad1, mitad2);
            }
            break;
        }

        case 4:
        {
            if (mitad1.esVacia() && mitad2.esVacia())
            {
                cout << "Primero divida una lista (opción 3)." << endl;
            }
            else
            {
                verificarBalance(mitad1, mitad2);
            }
            break;
        }

        case 5:
        {
            if (mitad1.esVacia() && mitad2.esVacia())
            {
                cout << "Primero divida una lista (opción 3)." << endl;
            }
            else
            {
                mostrarEstadisticasMitades(mitad1, mitad2);
            }
            break;
        }

        case 6:
            mostrarEjemplos();
            break;

        case 7:
            cout << "¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opción no valida." << endl;
        }

    } while (opcion != 7);

    return 0;
}