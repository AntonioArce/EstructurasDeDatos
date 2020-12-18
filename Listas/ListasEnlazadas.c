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

void MostrarLista(struct Nodo *nodo)
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

struct Nodo *AgregarEnmedio(struct Nodo *nodo,int dato)
{
    struct Nodo *temporal=NULL;
    struct Nodo *nodonuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    int buscar;


    if(nodonuevo!=NULL)
    {
        nodonuevo->dato=dato;
        temporal=nodo;
        puts("Despues de que dato quiere insertar el nuevo nodo");
        scanf("%d",&buscar);

        while(temporal!=NULL)
        {
            if(temporal->dato==buscar)
            {
                nodonuevo->siguiente=temporal->siguiente;
                temporal->siguiente=nodonuevo;
                break;
            }
            else
                temporal=temporal->siguiente;
        }
    }
    return nodo;
}

struct Nodo *EliminarAlInicio(struct Nodo *nodo)
{
    struct Nodo *aux=NULL;

    aux=nodo;

    nodo=aux->siguiente;
    
    free(aux);
    return nodo;
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
    nodo=AgregarEnmedio(nodo,111);
    MostrarLista(nodo);
    nodo=EliminarAlInicio(nodo);
    MostrarLista(nodo);
    nodo=AgregarAlFinal(nodo,99);
    MostrarLista(nodo);

    return 0;
}