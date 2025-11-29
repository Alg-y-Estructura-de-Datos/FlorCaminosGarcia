/*Eliminar elementos alternos*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

Lista<int> sumarNumerosInverso(const Lista<int> &num1, const Lista<int> &num2)
{
    Lista<int> resultado;
    int carry = 0;
    int i = 0, j = 0;
    int size1 = num1.getTamanio();
    int size2 = num2.getTamanio();

    while (i < size1 || j < size2 || carry > 0)
    {
        int digito1 = (i < size1) ? num1.getDato(i) : 0;
        int digito2 = (j < size2) ? num2.getDato(j) : 0;

        int suma = digito1 + digito2 + carry;
        carry = suma / 10;
        int digitoResultado = suma % 10;

        resultado.insertarUltimo(digitoResultado);

        i++;
        j++;
    }

    return resultado;
}

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

int listaANumeroInverso(const Lista<int> &lista)
{
    int numero = 0;
    int multiplicador = 1;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        numero += lista.getDato(i) * multiplicador;
        multiplicador *= 10;
    }

    return numero;
}

int listaANumeroNormal(const Lista<int> &lista)
{
    int numero = 0;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        numero = numero * 10 + lista.getDato(i);
    }

    return numero;
}

void mostrarProcesoSuma(const Lista<int> &num1, const Lista<int> &num2, const Lista<int> &resultado)
{
    cout << "\n--- PROCESO DE SUMA ---" << endl;

    int maxSize = max(num1.getTamanio(), max(num2.getTamanio(), resultado.getTamanio()));

    cout << "  ";
    for (int i = num1.getTamanio() - 1; i >= 0; i--)
    {
        cout << num1.getDato(i);
    }
    cout << endl;

    cout << "+ ";
    for (int i = num2.getTamanio() - 1; i >= 0; i--)
    {
        cout << num2.getDato(i);
    }
    cout << endl;

    cout << "  ";
    for (int i = 0; i < maxSize; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << "  ";
    for (int i = resultado.getTamanio() - 1; i >= 0; i--)
    {
        cout << resultado.getDato(i);
    }
    cout << endl;
}

void ingresarNumeroComoLista(Lista<int> &lista, const string &nombre, bool inverso)
{
    cout << "\n--- INGRESAR " << nombre << " ---" << endl;

    if (inverso)
    {
        cout << "Ingrese digitos en ORDEN INVERSO (unidad, decena, centena...)" << endl;
    }
    else
    {
        cout << "Ingrese digitos en ORDEN NORMAL (centena, decena, unidad...)" << endl;
    }
    cout << "Ingrese digitos (0-9, -1 para terminar):" << endl;

    int digito;
    int contador = 1;

    while (true)
    {
        cout << "Digito " << contador << ": ";
        cin >> digito;

        if (cin.fail())
        {
            cout << "Entrada invalida. Intente again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (digito == -1)
            break;

        if (digito < 0 || digito > 9)
        {
            cout << "Dígito debe estar entre 0 y 9." << endl;
            continue;
        }

        lista.insertarUltimo(digito);
        contador++;
    }

    if (lista.esVacia())
    {
        lista.insertarUltimo(0); // Si está vacía, poner 0
    }
}

void mostrarEjemplos()
{
    cout << "\n--- EJEMPLOS ---" << endl;

    // Ejemplo 1
    Lista<int> ej1, ej2;
    ej1.insertarUltimo(2);
    ej1.insertarUltimo(4);
    ej1.insertarUltimo(3); // 342
    ej2.insertarUltimo(5);
    ej2.insertarUltimo(6);
    ej2.insertarUltimo(4); // 465

    cout << "Ejemplo 1 - Orden inverso:" << endl;
    cout << "Numero 1 (342): ";
    ej1.print();
    cout << "Numero 2 (465): ";
    ej2.print();

    Lista<int> suma = sumarNumerosInverso(ej1, ej2);
    cout << "Suma (807): ";
    suma.print();
    cout << "Verificación: " << listaANumeroInverso(ej1) << " + " << listaANumeroInverso(ej2) << " = " << listaANumeroInverso(suma) << endl;

    // Ejemplo 2
    Lista<int> ej3, ej4;
    ej3.insertarUltimo(9);
    ej3.insertarUltimo(9);
    ej3.insertarUltimo(9); // 999
    ej4.insertarUltimo(1); // 1

    cout << "\nEjemplo 2 - Con acarreo:" << endl;
    cout << "Numero 1 (999): ";
    ej3.print();
    cout << "Numero 2 (1): ";
    ej4.print();

    suma = sumarNumerosInverso(ej3, ej4);
    cout << "Suma (1000): ";
    suma.print();
    cout << "Verificación: " << listaANumeroInverso(ej3) << " + " << listaANumeroInverso(ej4) << " = " << listaANumeroInverso(suma) << endl;
}

int main()
{
    Lista<int> num1, num2;
    int opcion;
    bool ordenInverso = true; // Por defecto usamos orden inverso (más fácil)

    cout << "=== CALCULADORA DE NUMEROS COMO LISTAS ===" << endl;

    // Mostrar ejemplos
    mostrarEjemplos();

    do
    {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Configurar orden (actual: " << (ordenInverso ? "INVERSO" : "NORMAL") << ")" << endl;
        cout << "2. Ingresar numeros" << endl;
        cout << "3. Mostrar numeros actuales" << endl;
        cout << "4. Sumar numeros" << endl;
        cout << "5. Mostrar proceso de suma" << endl;
        cout << "6. Ver ejemplos" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
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
            cout << "Seleccione orden:" << endl;
            cout << "1. Orden INVERSO (unidad primero) - RECOMENDADO" << endl;
            cout << "2. Orden NORMAL (unidad al final)" << endl;
            cout << "Opcion: ";

            int ordenOp;
            cin >> ordenOp;

            if (ordenOp == 1)
            {
                ordenInverso = true;
                cout << " Orden configurado como INVERSO" << endl;
            }
            else if (ordenOp == 2)
            {
                ordenInverso = false;
                cout << " Orden configurado como NORMAL" << endl;
            }
            else
            {
                cout << "Opcion invalida." << endl;
            }
            break;
        }

        case 2:
        {
            num1.vaciar();
            num2.vaciar();

            ingresarNumeroComoLista(num1, "NÚMERO 1", ordenInverso);
            ingresarNumeroComoLista(num2, "NÚMERO 2", ordenInverso);

            cout << " Numeros ingresados correctamente." << endl;
            break;
        }

        case 3:
        {
            if (num1.esVacia() || num2.esVacia())
            {
                cout << "Primero ingrese ambos numeros (opcion 2)." << endl;
            }
            else
            {
                cout << "Numero 1: ";
                num1.print();
                cout << "Valor: " << (ordenInverso ? listaANumeroInverso(num1) : listaANumeroNormal(num1)) << endl;

                cout << "Numero 2: ";
                num2.print();
                cout << "Valor: " << (ordenInverso ? listaANumeroInverso(num2) : listaANumeroNormal(num2)) << endl;
            }
            break;
        }

        case 4:
        {
            if (num1.esVacia() || num2.esVacia())
            {
                cout << "Primero ingrese ambos numeros (opcion 2)." << endl;
            }
            else
            {
                cout << "\n--- REALIZANDO SUMA ---" << endl;
                cout << "Numero 1: ";
                num1.print();
                cout << "Numero 2: ";
                num2.print();

                Lista<int> resultado;
                if (ordenInverso)
                {
                    resultado = sumarNumerosInverso(num1, num2);
                }
                else
                {
                    // Para orden normal, invertir, sumar, y volver a invertir
                    Lista<int> num1Inv = invertirLista(num1);
                    Lista<int> num2Inv = invertirLista(num2);
                    Lista<int> resultadoInv = sumarNumerosInverso(num1Inv, num2Inv);
                    resultado = invertirLista(resultadoInv);
                }

                cout << "Resultado: ";
                resultado.print();

                int valor1 = ordenInverso ? listaANumeroInverso(num1) : listaANumeroNormal(num1);
                int valor2 = ordenInverso ? listaANumeroInverso(num2) : listaANumeroNormal(num2);
                int valorResultado = ordenInverso ? listaANumeroInverso(resultado) : listaANumeroNormal(resultado);

                cout << "Verificación: " << valor1 << " + " << valor2 << " = " << valorResultado << endl;

                if (valor1 + valor2 == valorResultado)
                {
                    cout << " Suma verificada correctamente." << endl;
                }
                else
                {
                    cout << " Error en la suma." << endl;
                }
            }
            break;
        }

        case 5:
        {
            if (num1.esVacia() || num2.esVacia())
            {
                cout << "Primero ingrese ambos numeros (opción 2)." << endl;
            }
            else if (!ordenInverso)
            {
                cout << "La visualización del proceso solo esta disponible para orden inverso." << endl;
            }
            else
            {
                Lista<int> resultado = sumarNumerosInverso(num1, num2);
                mostrarProcesoSuma(num1, num2, resultado);
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