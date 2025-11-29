/*Encontrar enésimo elemento desde el final*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
T encontrarNesimoDesdeFinal(const Lista<T> &lista, int n)
{
    if (lista.esVacia())
    {
        throw "La lista esta vacia";
    }

    int tamanio = lista.getTamanio();

    if (n <= 0 || n > tamanio)
    {
        throw "Posicion invalida. Debe estar entre 1 y " + to_string(tamanio);
    }

    // Calcular posición desde el inicio
    int posicionDesdeInicio = tamanio - n;

    return lista.getDato(posicionDesdeInicio);
}

template <class T>
T encontrarNesimoDesdeFinalEficiente(const Lista<T> &lista, int n)
{
    if (lista.esVacia())
    {
        throw "La lista esta vacia";
    }

    if (n <= 0)
    {
        throw "La posicion debe ser mayor a 0";
    }

    int principal = 0;
    int referencia = 0;
    int tamanio = lista.getTamanio();

    // Mover referencia n-1 posiciones adelante
    while (referencia < n - 1)
    {
        referencia++;
        if (referencia >= tamanio)
        {
            throw "La posicion esta mas alla del final de la lista";
        }
    }

    // Mover ambos hasta que referencia llegue al final
    while (referencia < tamanio - 1)
    {
        principal++;
        referencia++;
    }

    return lista.getDato(principal);
}

void mostrarVisualizacion(const Lista<int> &lista, int n)
{
    cout << "\n--- VISUALIZACION ---" << endl;
    cout << "Lista: ";
    lista.print();

    int tamanio = lista.getTamanio();
    cout << "Buscando el " << n << " Elemento desde el final..." << endl;

    // Mostrar posiciones desde el final
    cout << "Posiciones desde el final:" << endl;
    for (int i = 1; i <= tamanio; i++)
    {
        int valor = lista.getDato(tamanio - i);
        cout << i << "º desde el final: " << valor;
        if (i == n)
        {
            cout << " ← ENCONTRADO";
        }
        cout << endl;
    }

    // Mostrar equivalencia con posición desde inicio
    int posDesdeInicio = tamanio - n;
    cout << "\nEquivale a la posicion " << posDesdeInicio << " desde el inicio" << endl;
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
    cout << "\n--- EJEMPLOS ---" << endl;

    Lista<int> ejemplo;
    for (int i = 1; i <= 8; i++)
    {
        ejemplo.insertarUltimo(i * 10); // 10, 20, 30, ..., 80
    }

    cout << "Lista ejemplo: ";
    ejemplo.print();

    cout << "Enesimos elementos desde el final:" << endl;
    for (int n = 1; n <= 8; n++)
    {
        try
        {
            int resultado = encontrarNesimoDesdeFinal(ejemplo, n);
            cout << n << "º desde el final: " << resultado << endl;
        }
        catch (const char *mensaje)
        {
            cout << "Error: " << mensaje << endl;
        }
    }
}

int main()
{
    Lista<int> lista;
    int opcion, n;

    cout << "=== ENCONTRADOR DE ENESIMO ELEMENTO DESDE EL FINAL ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Ingresar lista" << endl;
        cout << "2. Mostrar lista actual" << endl;
        cout << "3. Buscar enesimo desde el final" << endl;
        cout << "4. Buscar con metodo eficiente" << endl;
        cout << "5. Mostrar visualizacion" << endl;
        cout << "6. Ver ejemplos" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            lista.vaciar();
            ingresarLista(lista);

            if (lista.esVacia())
            {
                cout << "La lista esta vacia." << endl;
            }
            else
            {
                cout << " Lista ingresada correctamente." << endl;
                cout << "Lista: ";
                lista.print();
            }
            break;
        }

        case 2:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opcion 1)." << endl;
            }
            else
            {
                cout << "Lista actual: ";
                lista.print();
                cout << "Tamaño: " << lista.getTamanio() << " elementos" << endl;
            }
            break;
        }

        case 3:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opcion 1)." << endl;
            }
            else
            {
                cout << "Ingrese n (posicion desde el final): ";
                cin >> n;

                try
                {
                    int resultado = encontrarNesimoDesdeFinal(lista, n);
                    cout << " El " << n << "º elemento desde el final es: " << resultado << endl;

                    // Mostrar explicación
                    int posDesdeInicio = lista.getTamanio() - n;
                    cout << "Explicacion: Posicion " << posDesdeInicio << " desde el inicio" << endl;
                }
                catch (const char *mensaje)
                {
                    cout << " Error: " << mensaje << endl;
                }
            }
            break;
        }

        case 4:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opcion 1)." << endl;
            }
            else
            {
                cout << "Ingrese n (posicion desde el final): ";
                cin >> n;

                try
                {
                    int resultado = encontrarNesimoDesdeFinalEficiente(lista, n);
                    cout << " [EFICIENTE] El " << n << "º elemento desde el final es: " << resultado << endl;
                    cout << "Algoritmo: Dos punteros, una sola pasada" << endl;
                }
                catch (const char *mensaje)
                {
                    cout << " Error: " << mensaje << endl;
                }
            }
            break;
        }

        case 5:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opcion 1)." << endl;
            }
            else
            {
                cout << "Ingrese n para visualizacion: ";
                cin >> n;

                if (n <= 0 || n > lista.getTamanio())
                {
                    cout << "Posicion invalida para visualizacion." << endl;
                }
                else
                {
                    mostrarVisualizacion(lista, n);
                }
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
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 7);

    return 0;
}