#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include "Tasa de prioridad.h"
#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;



void Agregar_prioridad(list<process> & sList ){
    list<process>::iterator pos;
    pos = sList.begin();
    while( pos != sList.end())
    {
        float prioridad_temp= (((float)pos->getTesp()+(float)pos->getTser())/(float)pos->getTser());//formula
        pos->setPrio(prioridad_temp);
        //cout << pos->getPrio() << endl;
        pos++;
    }

    int flag=1;
    pos = sList.begin();
    list<process>::iterator pos2;
    list<process> nueva;

    pos2 = pos++;
    int cont=0;
    while(flag == 1 ){
        flag=0;
        pos = sList.begin();
        pos2 = pos++;
        while( sList.size()!=1 ){
            pos = sList.begin();
            pos2 = pos++;
            if(pos->getPrio() > pos2->getPrio()){
                nueva.push_back(*pos);
                process nuevas(0,0, 0, "hola");
                nuevas=*pos2;
                sList.pop_front();
                sList.pop_front();
                sList.push_back(nuevas);
                flag = 1;
            }

            else{
                nueva.push_back(*pos2);
                sList.pop_front();

            }

        }
        nueva.push_back(*sList.begin());
        sList=nueva;
        nueva.clear();
    }

    pos = sList.begin();
    while( pos != sList.end())
    {

        cout << "Ejecutando:  "<<pos->getAccion() << "   Prioridad: "<< pos->getPrio()<<endl;
        Sleep(1000*pos->getTser());
        pos++;
    }
    sList.clear();

}

int t_espera(time_t now){
    tm *ltm = localtime(&now);
    time_t now2 = time(0);
    tm *ltm2 = localtime(&now2);
    time_t nueva = now2-now;
    tm *ltm3 = localtime(&nueva);


    cout << "Tiempo de Espera: "<< 0 << ":";
    cout << ltm3->tm_min  << ":";
    cout << ltm3->tm_sec  << endl;
    int horas,min,seg;
    horas=  0;
    min= ltm3->tm_min;
    seg= ltm3->tm_sec;
    return (min*60+seg);
}

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Tiempo Actual: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    int  servicio = 0, opcion = 0;
    int espera = 0;
    string accion_p;

    list<process> lista ;
    cout << "Planificacion a la Tasa de Respuesta mas Alta \n" << endl;

    while (opcion != 3) {
        cout << "-------------------------------------------------------------------------------------------- \n" << endl;
        cout << "1. Agregar procesos \n2. Ejecutar Pocesos\n3.Salir del programa \n" << endl;
        cin >> opcion;

        if (opcion == 1) {
            int espera = t_espera(now);
            cout << "Escriba el Tiempo de ejecucion en s:  " << endl;
            cin >> servicio;
            cout << "Escriba el nombre del Proceso a realizar: " << endl;
            cin.ignore();
            getline(cin,accion_p);
            cout << "Proceso agregado exitisamente" << endl;
            process pro(0,espera, servicio, accion_p);
            pro.imprime();
            //lista.insert(new Proceso(){espera, servicio, accion_p});
            lista.push_back(pro);

        }
        else if (opcion == 2) {
            cout << "Ejecutando procesos \n" << endl;
            Agregar_prioridad(lista);

        }
    }
    cout << "Programa finalizado \n" << endl;

}

