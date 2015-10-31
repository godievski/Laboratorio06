/* 
 * File:   arbolGenerico.h
 * Author: alulab14
 *
 * Created on 30 de octubre de 2015, 08:00 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#ifndef ARBOLGENERICO_H
#define	ARBOLGENERICO_H

#include <fstream>
using namespace std;

void crearArbol (void*&arbol, void* (*leeDatos) (ifstream &),
        ifstream &archEntrada, int (*funCmp) (const void*, const void*));

void impArbol (void *arbol, void (*impDatos) (const void*, ofstream &), ofstream &archSalida);

#endif	/* ARBOLGENERICO_H */

