/*Eliminar todos los elementos*/
/*Verificar si lista está vacía*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;

    int cont = 1;
    int num;

    cout << "*** INGRESAR ELEMENTOS EN LA LISTA ***" << endl;
    cout << " Ingrese el 0 cuando termine de ingresar los valores " << endl;

    while (true)
    {
        cout << "Ingrese el elemento " << cont << ": ";
        cin >> num;

        if (num == 0)
        {
            break;
        }

        miLista.insertarUltimo(num);
        cont++;
    }

    miLista.print();

    miLista.vaciar();

    miLista.print();

    cout << "Lista vacia" << endl;
}