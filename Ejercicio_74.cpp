/*Mover todos los ceros al final*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void moverCerosAlFinal(Lista<T> &lista)
{
    if (lista.esVacia())
        return;

    Lista<T> sinCeros, soloCeros;
    int tamanio = lista.getTamanio();

    // Separar elementos
    for (int i = 0; i < tamanio; i++)
    {
        T elemento = lista.getDato(i);
        if (elemento != 0)
        {
            sinCeros.insertarUltimo(elemento);
        }
        else
        {
            soloCeros.insertarUltimo(elemento);
        }
    }

    // Reconstruir lista
    lista.vaciar();
    for (int i = 0; i < sinCeros.getTamanio(); i++)
    {
        lista.insertarUltimo(sinCeros.getDato(i));
    }
    for (int i = 0; i < soloCeros.getTamanio(); i++)
    {
        lista.insertarUltimo(soloCeros.getDato(i));
    }
}

template <class T>
void moverCerosAlFinalInPlace(Lista<T> &lista)
{
    if (lista.esVacia())
        return;

    int tamanio = lista.getTamanio();
    int indiceNoCero = 0;

    // Mover no-ceros al frente
    for (int i = 0; i < tamanio; i++)
    {
        if (lista.getDato(i) != 0)
        {
            lista.reemplazar(indiceNoCero, lista.getDato(i));
            indiceNoCero++;
        }
    }

    // Llenar con ceros
    for (int i = indiceNoCero; i < tamanio; i++)
    {
        lista.reemplazar(i, 0);
    }
}

void mostrarProceso(const Lista<int> &lista)
{
    cout << "\n--- PROCESO DE MOVIMIENTO ---" << endl;
    cout << "Lista original: ";
    lista.print();

    int ceros = 0, noCeros = 0;
    cout << "Elementos:" << endl;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        int elemento = lista.getDato(i);
        cout << "Posición " << i << ": " << elemento;

        if (elemento == 0)
        {
            cout << " → CERO (irá al final)";
            ceros++;
        }
        else
        {
            cout << " → NO-CERO (mantendrá orden)";
            noCeros++;
        }
        cout << endl;
    }

    cout << "\nResumen:" << endl;
    cout << "Elementos no-cero: " << noCeros << endl;
    cout << "Elementos cero: " << ceros << endl;
    cout << "Orden final: " << noCeros << " no-ceros + " << ceros << " ceros" << endl;
}

void mostrarEstadisticas(const Lista<int> &lista)
{
    cout << "\n--- ESTADÍSTICAS ---" << endl;

    int ceros = 0, noCeros = 0;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        if (lista.getDato(i) == 0)
        {
            ceros++;
        }
        else
        {
            noCeros++;
        }
    }

    cout << "Total elementos: " << tamanio << endl;
    cout << "Elementos no-cero: " << noCeros << " (" << (noCeros * 100.0 / tamanio) << "%)" << endl;
    cout << "Elementos cero: " << ceros << " (" << (ceros * 100.0 / tamanio) << "%)" << endl;

    if (ceros > 0)
    {
        // Verificar si los ceros están al final
        bool cerosAlFinal = true;
        bool encontradoCero = false;

        for (int i = 0; i < tamanio; i++)
        {
            if (lista.getDato(i) == 0)
            {
                encontradoCero = true;
            }
            else if (encontradoCero && lista.getDato(i) != 0)
            {
                cerosAlFinal = false;
                break;
            }
        }

        if (cerosAlFinal)
        {
            cout << " Los ceros están correctamente al final" << endl;
        }
        else
        {
            cout << " Los ceros NO están todos al final" << endl;
        }
    }
}

void ingresarLista(Lista<int> &lista)
{
    cout << "Ingrese elementos (0 para cero, -1 para terminar):" << endl;

    int valor;
    int contador = 1;

    while (true)
    {
        cout << "Elemento " << contador << ": ";
        cin >> valor;

        if (cin.fail())
        {
            cout << "Entrada inválida. Intente again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (valor == -1)
            break;

        lista.insertarUltimo(valor);
        contador++;
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS ---" << endl;

    // Ejemplo 1
    Lista<int> ej1;
    ej1.insertarUltimo(1);
    ej1.insertarUltimo(0);
    ej1.insertarUltimo(3);
    ej1.insertarUltimo(0);
    ej1.insertarUltimo(5);
    ej1.insertarUltimo(6);

    cout << "Ejemplo 1 - Ceros intercalados:" << endl;
    cout << "Original: ";
    ej1.print();

    Lista<int> temp = ej1;
    moverCerosAlFinal(temp);
    cout << "Resultado: ";
    temp.print();

    // Ejemplo 2
    Lista<int> ej2;
    ej2.insertarUltimo(0);
    ej2.insertarUltimo(0);
    ej2.insertarUltimo(2);
    ej2.insertarUltimo(4);
    ej2.insertarUltimo(0);
    ej2.insertarUltimo(6);

    cout << "\nEjemplo 2 - Empieza con ceros:" << endl;
    cout << "Original: ";
    ej2.print();

    temp = ej2;
    moverCerosAlFinalInPlace(temp);
    cout << "Resultado: ";
    temp.print();

    // Ejemplo 3
    Lista<int> ej3;
    ej3.insertarUltimo(7);
    ej3.insertarUltimo(8);
    ej3.insertarUltimo(9);

    cout << "\nEjemplo 3 - Sin ceros:" << endl;
    cout << "Original: ";
    ej3.print();

    temp = ej3;
    moverCerosAlFinal(temp);
    cout << "Resultado: ";
    temp.print();
}

int main()
{
    Lista<int> lista;
    int opcion;

    cout << "=== MOVEDOR DE CEROS AL FINAL ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENÚ PRINCIPAL ===" << endl;
        cout << "1. Ingresar lista" << endl;
        cout << "2. Mostrar lista actual" << endl;
        cout << "3. Mover ceros al final (con lista temporal)" << endl;
        cout << "4. Mover ceros al final (in-place)" << endl;
        cout << "5. Mostrar proceso" << endl;
        cout << "6. Mostrar estadisticas" << endl;
        cout << "7. Ver ejemplos" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: ";
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
                cout << "Tamanio: " << lista.getTamanio() << " elementos" << endl;
            }
            break;
        }

        case 3:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opción 1)." << endl;
            }
            else
            {
                cout << "\n--- METODO CON LISTA TEMPORAL ---" << endl;
                cout << "Lista antes: ";
                lista.print();

                moverCerosAlFinal(lista);

                cout << "Lista despues: ";
                lista.print();
                cout << " Ceros movidos al final." << endl;
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
                cout << "\n--- METODO IN-PLACE ---" << endl;
                cout << "Lista antes: ";
                lista.print();

                moverCerosAlFinalInPlace(lista);

                cout << "Lista despues: ";
                lista.print();
                cout << " Ceros movidos al final (sin lista temporal)." << endl;
            }
            break;
        }

        case 5:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opción 1)." << endl;
            }
            else
            {
                mostrarProceso(lista);
            }
            break;
        }

        case 6:
        {
            if (lista.esVacia())
            {
                cout << "Primero ingrese una lista (opción 1)." << endl;
            }
            else
            {
                mostrarEstadisticas(lista);
            }
            break;
        }

        case 7:
            mostrarEjemplos();
            break;

        case 8:
            cout << "¡Hasta luego!" << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 8);

    return 0;
}