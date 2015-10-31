/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cctype>
#include "funAux.h"
using namespace std;

void* leeDatos (ifstream &archEntrada)
{
    char linea[200];
    char *palabras[20];
    int cantPal;
    
    if (!archEntrada.getline(linea, 200)) return NULL;
    
    separaPalabras(linea, palabras, cantPal);
    
    char* especialidad = new char[strlen(palabras[cantPal-1]) + 1];
    strcpy(especialidad, palabras[cantPal-1]);
    double* tarifa = new double;
    *tarifa = atof(palabras[cantPal-2]);
    
    char buffNombre[100];
    strcpy(buffNombre, palabras[0]);
    for (int i = 1; i < cantPal - 2; i++){
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    char* nombre = new char[strlen(buffNombre) + 1];
    strcpy(nombre, buffNombre);
    
    void** reg = new void*[3];
    reg[0] = nombre;
    reg[1] = tarifa;
    reg[2] = especialidad;
    return reg;
}

int cmpDatosN (const void* dato1, const void*dato2)
{
    void **reg1 = (void **) dato1, **reg2 = (void**) dato2;
    char *nombre1 = (char *) reg1[0];
    char *nombre2 = (char *) reg2[0];
    return strcmp(nombre1, nombre2);
}

int cmpDatosS (const void* dato1, const void*dato2)
{
    void **reg1 = (void **) dato1, **reg2 = (void**) dato2;
    double* tar1 = (double*) reg1[1];
    double* tar2 = (double*) reg2[1];
    return *tar2 - *tar1;
}

int cmpDatosE (const void* dato1, const void*dato2)
{
    void **reg1 = (void **) dato1, **reg2 = (void**) dato2;
    char *esp1 = (char*) reg1[2];
    char *esp2 = (char*) reg2[2];
    int varCmp;
    varCmp = strcmp(esp2, esp1);
    if (varCmp == 0){
        //Compara por el nombre si son de la misma especialidad
        char *nombre1 = (char *) reg1[0];
        char *nombre2 = (char *) reg2[0];
        return strcmp(nombre2, nombre1);
    } else
        return varCmp;
}

void impDatos (const void* dato, ofstream &archSalida)
{
    void **reg = (void **) dato;
    char *nombre = (char *) reg[0];
    double* tar = (double*) reg[1];
    char *esp = (char*) reg[2];
    archSalida << "Nombre: " << nombre << endl;
    archSalida << "Sueldo: " << *tar << endl;
    archSalida << "Especialidad: " << esp << endl;
    archSalida << "-----------------------------------------------------" << endl;
}


void separaPalabras(char* linea, char**palabras, int &cantPal)
{
    cantPal = 0;
    
    if (!isblank(linea[0])){
        palabras[0] = linea;
        cantPal++;
    }
    
    for (int i = 1; linea[i]; i++){
        if (!isblank(linea[i]) && (isblank(linea[i-1]) || linea[i-1] == NULL)){
            palabras[cantPal] = &(linea[i]);
            cantPal++;
        }
        
        if (!isblank(linea[i]) && isblank(linea[i+1])){
            linea[i+1] = NULL;
            i++;
        }
    }
}