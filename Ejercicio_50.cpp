/*Dada una lista y un número K, rotar la lista en grupos
de tamaño K. Si el tamaño de la lista no es múltiplo de K,
entonces los elementos finales permanecen como están.*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

void rotarEnGrupos(CircList<int> &lista, int k)
{
    int n = lista.getTamanio();
    for (int i = 0; i < n; i += k)
    {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
        {
            int temp = lista.getDato(left);
            lista.insertar(left, lista.getDato(right));
            lista.insertar(right, temp);
            left++;
            right--;
        }
    }
}

int main()
{
    CircList<int> lista;
    int n, dato, k;

    cout << "Ingrese la cantidad de elementos para la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    cout << "Ingrese el tamaño del grupo K para rotar: ";
    cin >> k;

    rotarEnGrupos(lista, k);

    cout << "Lista rotada en grupos de tamanio " << k << ": ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}