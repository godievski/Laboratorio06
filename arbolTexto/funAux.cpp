/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include <fstream>
using namespace std;

void* leeDatos (ifstream &archEntrada)
{
    char c;
    if (!archEntrada.get(c)) return NULL;
    char* dato = new char;
    *dato = c;
    return dato;
}

int cmpDatos (const void* dato1, const void*dato2)
{
    char *c1 = (char*) dato1, *c2 = (char*) dato2;
    return *c1 - *c2;
}

void impDatos (const void* dato, ofstream &archSalida)
{
    char *c = (char *) dato;
    archSalida << *c << endl;
}