/* 
 * File:   funAux.h
 * Author: alulab14
 *
 * Created on 30 de octubre de 2015, 08:56 AM
 */


/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#ifndef FUNAUX_H
#define	FUNAUX_H

#include <fstream>
using namespace std;

void* leeDatos (ifstream &archEntrada);

int cmpDatosN (const void* dato1, const void*dato2);

int cmpDatosS (const void* dato1, const void*dato2);

int cmpDatosE (const void* dato1, const void*dato2);

void impDatos (const void* dato, ofstream &archSalida);

void separaPalabras(char* linea, char**palabras, int &cantPal);

#endif	/* FUNAUX_H */

