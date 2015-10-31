/*
 * Nombre: Diego Alonso Guardia Ayala
 * Codigo: 20125849
 */

#include <cstdlib>
#include <fstream>
using namespace std;

void insertarDato(void *&arbol, void* dato, int (*funCmp) (const void*, const void*));

void* crearNodo (void);

void crearArbol (void*&arbol, void* (*leeDatos) (ifstream &),
        ifstream &archEntrada, int (*funCmp) (const void*, const void*))
{
    if (!arbol) delete (void**)arbol;
    arbol = NULL;
    while (1){
        void* dato = leeDatos(archEntrada);
        if (dato == NULL) break;
        insertarDato(arbol, dato, funCmp);
    }
}


void impArbol (void *arbol, void (*impDatos) (const void*, ofstream &), ofstream &archSalida)
{
    if (!arbol) return;
    void **nodo = (void **) arbol;
    if (nodo[0] == NULL)  return;
    if (nodo[1] != NULL) impArbol(nodo[1], impDatos, archSalida);
    impDatos(nodo[0],archSalida);
    if (nodo[2] != NULL) impArbol(nodo[2], impDatos, archSalida);
}


void* crearNodo (void)
{
    void **nodo = new void*[3];
    nodo[0] = nodo[1] = nodo[2] = NULL;
    return nodo;
}

void insertarDato(void *&arbol, void* dato, int (*funCmp) (const void*, const void*))
{
    if (!arbol)
        arbol = crearNodo();
    
    void **nodo = (void**) arbol;
    if (nodo[0] == NULL) nodo[0] = dato; 
    else{
        //Compara los datos del nodo y del dato leído
        int varCmp = funCmp(nodo[0], dato);
        //Inserta el dato en el nodo derecho
        if (varCmp <= 0) 
            insertarDato(nodo[2], dato, funCmp);
        else
        //Inserta el dato en el nodo izquierdo
            insertarDato(nodo[1], dato, funCmp);
    }
}