/*Simular proceso round-robin*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<string> procesos;
    
    // Agregar procesos a la lista circular
    procesos.insertarUltimo("Proceso 1");
    procesos.insertarUltimo("Proceso 2");
    procesos.insertarUltimo("Proceso 3");
    procesos.insertarUltimo("Proceso 4");

    int quantum = 2; // Tiempo asignado a cada proceso
    int tiempoTotal = 10; // Tiempo total de simulación

    cout << "Simulación de proceso round-robin:" << endl;

    for (int tiempo = 0; tiempo < tiempoTotal; tiempo += quantum)
    {
        int indice = (tiempo / quantum) % procesos.getTamanio(); // Calcular el índice del proceso actual
        cout << "Tiempo " << tiempo << " - Ejecutando: " << procesos.getDato(indice) << endl;
    }

    return 0;
}