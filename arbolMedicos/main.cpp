/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 30 de octubre de 2015, 08:55 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#include "arbolGenerico.h"
#include "funAux.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {

    char nombArchEnt[100];
    char nombArchSal[100];
    char tipoOrden[20];
    
    if (argc > 1)
        strcpy(nombArchEnt, argv[1]);
    else
        exit(1); //Se corta el programa
    
    ifstream archEntrada (nombArchEnt, ios::in);
    if (!archEntrada){
        cout << "El nombre del archivo es incorrecto o no se pudo abrir.\n";
        exit(1);
    }
    
    if (argc > 2)
        strcpy(nombArchSal, argv[2]);
    else
        exit(1); //Se corta el programa
    ofstream archSalida (nombArchSal, ios::out);
    if (!archSalida){
        cout << "El nombre del archivo es incorrecto o no se pudo abrir/crear.\n";
        exit(1);
    }
    
    if (argc > 3){
        strcpy(tipoOrden, argv[3]);
        if (!(strcmp(tipoOrden, "-n") ==0 || strcmp(tipoOrden, "-s")==0
                || strcmp(tipoOrden, "-e") == 0))
            exit(1); //Se interrumpe el programa porque no es un parametro válido
    } else
        //Si se omite el tercer parametro, por defecto se pone -n
        strcpy(tipoOrden, "-n");
    
    void *arbolMed;
    
    if (strcmp(tipoOrden, "-n") == 0){
        crearArbol(arbolMed, leeDatos,archEntrada,cmpDatosN);
    } else if (strcmp(tipoOrden, "-s") == 0) {
        crearArbol(arbolMed, leeDatos,archEntrada,cmpDatosS);
    } else if (strcmp(tipoOrden, "-e") == 0) {
        crearArbol(arbolMed, leeDatos,archEntrada,cmpDatosE);
    }
    impArbol(arbolMed, impDatos, archSalida);
    
    return 0;
}

