#include<stdio.h>
#include<stdlib.h>
struct Nodo{
    int dato;
    struct Nodo *siguiente; 
};


struct Nodo *AgregarAlInicio(struct Nodo *nodo, int dato)
{
    struct Nodo *nodonuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodonuevo!=NULL)
    {
        nodonuevo->dato=dato;
        if(nodo!=NULL)
        {
            nodonuevo->siguiente=nodo;
        }
        return nodonuevo;
    }
    return nodo;
}

struct Nodo *AgregarAlFinal(struct Nodo *nodo, int dato)
{
    struct Nodo *temporal=NULL;
    struct Nodo *nodonuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodonuevo!=NULL)
    {
        nodonuevo->dato=dato;
        temporal=nodo;
        while(temporal->siguiente!=NULL)
        {
            temporal=temporal->siguiente;
        }
        temporal->siguiente=nodonuevo;
    }
    return nodo;
}

struct Nodo *MostrarLista(struct Nodo *nodo)
{
    if(nodo!=NULL)
    {
        while(nodo!=NULL)
        {
            printf(" | %d | ",nodo->dato);
            nodo=nodo->siguiente;
        }
    }
    else
    {
        printf("\n No existen datos en la lista \n ");
    }
    printf("\n");
}

int main()
{
    struct Nodo *nodo=NULL;
    nodo=AgregarAlInicio(nodo,1);
    MostrarLista(nodo);
    nodo=AgregarAlInicio(nodo,4);
    nodo=AgregarAlFinal(nodo,10);
    nodo=AgregarAlFinal(nodo,9);
    nodo=AgregarAlFinal(nodo,8);
    MostrarLista(nodo);
    return 0;
}