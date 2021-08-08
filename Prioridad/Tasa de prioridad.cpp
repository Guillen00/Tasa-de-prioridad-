//
// Created by leona on 06/08/2021.
//


#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include "Tasa de prioridad.h"


process::process(float prio,int Te, int Ts, string a) {
    Tespera = Te;
    Tservicio = Ts;
    accion = a;
    prioridad=prio;
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
    cout << "------>" << prioridad << "|" <<Tespera << "|" << Tservicio << "|" << accion << "\n" << endl;
}
float process::getPrio() {
    return prioridad;
}
void process::setPrio(float nuevo) {
    prioridad = nuevo;
}