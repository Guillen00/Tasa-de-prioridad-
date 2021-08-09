#ifndef  TASA_DE_PRIORIDAD.H



#include <iostream>

using namespace std;

class process {
    int Tespera;
    int Tservicio;
    string accion;
public:
    process(int Tespera, int Tservicio, string accion) ;
    int getTesp() ;
    void setTesp(int nuevo) ;
    int getTser() ;
    void setTser(int nuevo) ;
    string getAccion();
    void setAccion(string nuevo) ;
    void imprime();
};

#endif // ! TASA_DE_PRIORIDAD.H
