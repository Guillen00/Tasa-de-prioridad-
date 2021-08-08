//
// Created by leona on 06/08/2021.
//

#ifndef PRIORIDAD_TASA_DE_PRIORIDAD_H
#define PRIORIDAD_TASA_DE_PRIORIDAD_H

#include <iostream>

using namespace std;

class process {
    float prioridad;
    int Tespera;
    int Tservicio;
    string accion;
public:
    process(float prioridad ,int Tespera, int Tservicio, string accion) ;
    int getTesp() ;
    void setTesp(int nuevo) ;
    int getTser() ;
    void setTser(int nuevo) ;
    string getAccion();
    void setAccion(string nuevo) ;
    float getPrio() ;
    void setPrio(float nuevo) ;
    void imprime();
};
#endif //PRIORIDAD_TASA_DE_PRIORIDAD_H
