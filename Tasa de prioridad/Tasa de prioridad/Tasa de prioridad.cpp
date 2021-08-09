

#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include "Tasa de prioridad.h"


process::process(int Te, int Ts, string a) {
    Tespera = Te;
    Tservicio = Ts;
    accion = a;
};

int process::getTesp() {
    return Tespera;
}
void process::setTesp(int nuevo) {
    Tespera = nuevo;
}
int process::getTser() {
    return Tservicio;
}
void process::setTser(int nuevo) {
    Tservicio = nuevo;
}

string process::getAccion() {
    return accion;
}
void process::setAccion(string nuevo) {
    accion = nuevo;
}
void process::imprime() {
    cout << "------>" << Tespera << "|" << Tservicio << "|" << accion << "\n" << endl;
}




