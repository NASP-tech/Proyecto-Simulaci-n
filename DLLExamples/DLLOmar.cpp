#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;
struct nodoasig {
    string codigo, descripcion;
    int cantidad;
    struct nodoasig *siguiente;
};
nodoasig *primero,*ultimo;
void iniciar()
{
    primero=NULL;
    ultimo=NULL;
}
int vacia()
{
    if (primero==NULL)
        return 1;
    else
        return 0;
}
void insertar_delante ( string cod, string nomb, int cant)
{
    nodoasig *nodo;
    nodo= new nodoasig;
    nodo->siguiente=NULL;
    nodo->codigo=cod;
    nodo->descripcion=nomb;
    nodo->cantidad=cant;
    if (vacia())
    {
        primero=nodo;
 
        ultimo=nodo;
    }
    else
    {
        nodo->siguiente=primero;
        primero=nodo;
    }
    return;
}
void mostrar ()
{
    nodoasig *p;
    if (vacia())
        cout<<"Lista vacia";
    else
    {
        p = primero ;
        while (p != NULL){
            cout<< p->codigo<<endl;
            cout<< p->descripcion<<endl;
            cout<< p->cantidad<<endl;
            p = p->siguiente;
            getchar();
        }
    }
    return;
}
void eliminar(string valor)
{
    nodoasig *p,*q;
    q=primero;
    p=primero;
    while ((p!= NULL) && (p->codigo!=valor))
    {
        q=p;
        p = p->siguiente;
 
    }
    if (p==NULL)
        cout<<"No existe ese elemento en la lista";
    else
    {
        if (primero==ultimo)
        {
            primero=NULL;
            ultimo=NULL;
        }
        else
        {
            q->siguiente=p->siguiente;
            if (p==primero)
                primero=p->siguiente;
            else
                if (p==ultimo)
                    ultimo=q;
        }
    }
    return;
}
int main(int argc, char *argv[])
{
    int cant;
    string cod, nombre, c;
    int opc;
    iniciar();
    do
    {
        system("cls");
        cout<<" LISTA DE ASIGNATURAS"<<endl;
        cout<<" Seleccione la opcion a realizar\n\n";
        cout<<" 1.- Insertar una asignatura\n";
        cout<<" 2.- Eliminar una asignatura\n";
        cout<<" 3.- Mostrar toda la lista de asignaturas\n";
        cout<<" 4.- Salir";
        cout<<" \n\n\nOpcion(1-4): ";
        cin>>opc;
        switch(opc)
        {
            case 1:
                cod="";
                nombre="";
                cant=0;
                cout<<"Entre los Datos de la Asignatura:\n ";
                cout<<"Codigo o siglas de la Asignatura: \n";
                cin>>cod;
                cout<<"Nombre de la Asignatura: \n";
                cin>>nombre;
                cout<<"Cantidad de Horas:\n ";
                cin>>cant;
                insertar_delante(cod,nombre,cant);
                break;
                case 2:
                    cout<<"codigo de la Asignatura a eliminar: \n";
                    cin>>c;
                    eliminar(c);
                    getchar();
                    break;
                    case 3:
                        mostrar();
                        cout<<"Oprima una tecla para salir";
                        getchar();
                        break;
                        case 4:
                            exit(0);
                            break;
        }
    }
    while ((opc!=4));
    return 0;
}