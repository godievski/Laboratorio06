/* 
 * File:   funAux.h
 * Author: alulab14
 *
 * Created on 30 de octubre de 2015, 08:33 AM
 */

/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */


#ifndef FUNAUX_H
#define	FUNAUX_H

/*FUNCIONES PARA LA LECTURA, COMPARACIÓN Y ESCRITURA DE DATOS
 *(CARACTERES EN ESTE CASO)
 */
#include <fstream>
using namespace std;

void* leeDatos (ifstream &archEntrada);

int cmpDatos (const void* dato1, const void*dato2);

void impDatos (const void* dato, ofstream &archSalida);


#endif	/* FUNAUX_H */

