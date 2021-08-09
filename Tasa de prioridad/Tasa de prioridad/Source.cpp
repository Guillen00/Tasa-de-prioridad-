#include "Tasa de prioridad.h"
#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <pthread.h>

int main() {

    int  servicio = 0, opcion = 0;
    int espera = 0;
    string accion_p;
    list<process> lista;
    cout << "Planificacion a la Tasa de Respuesta mas Alta \n" << endl;

    while (opcion != 3) {
        cout << "-------------------------------------------------------------------------------------------- \n" << endl;
        cout << "1. Agregar procesos \n2. Ejecutar Pocesos\n3.Salir del programa \n" << endl;
        cin >> opcion;
        if (opcion == 1) {
            cout << "Escriba el Tiempo de ejecucion en s:  " << endl;
            cin >> servicio;
            cout << "Escriba el nombre del Proceso a realizar: " << endl;
            cin.ignore();
            getline(cin,accion_p);
            cout << "Proceso agregado exitisamente" << endl;
            process pro(espera, servicio, accion_p);
            pro.imprime();
            //lista.insert(new Proceso(){espera, servicio, accion_p});
            lista.push_back(pro);

        }
        else if (opcion == 2) {
            cout << "Ejecutando procesos\n" << endl;
            pthread_t thread1, thread2;

        }
    }
    cout << "Programa finalizado \n" << endl;
}