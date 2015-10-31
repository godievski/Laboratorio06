/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de octubre de 2015, 08:30 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include "arbolGenerico.h"
#include "funAux.h"
#include <iostream>
#include <fstream>
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archDatos ("in.txt", ios::in);
    
    if (!archDatos){
        cout << "El archivo in.txt no se pudo abrir." << endl;
        exit(1);
    }
    
    ofstream archSalida ("out.txt", ios::out);
    
    if (!archDatos){
        cout << "El archivo out.txt no se pudo abrir/crear." << endl;
        exit(1);
    }
    
    void *arbol;
    
    crearArbol(arbol, leeDatos, archDatos, cmpDatos);
    
    impArbol(arbol, impDatos, archSalida);
   
    return 0;
}

