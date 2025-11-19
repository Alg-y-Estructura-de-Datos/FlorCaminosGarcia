/*Contar ocurrencias de un valor*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int cont = 1;
    int num;
    int valor_contar;
    int cant_veces = 0;

    cout << "Ingrese el valor del cual quiera contar las veces que se repite: " << endl;
    cin >> valor_contar;

    while (true)
    {
        cout << " Ingrese el valor del elemento " << cont << " de la lista" << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        if (num == valor_contar)
        {
            cant_veces++;
        }

        miLista.insertarUltimo(num);
        cont++;
    }

    cout << "Lista: " << endl;
    miLista.print();

    cout << "La cantidad de veces que aparece en la lista el valor: " << valor_contar << " es de: " << cant_veces << " veces" << endl;
}