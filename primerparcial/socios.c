#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "prestamos.h"
#include "input.h"
#include "fechas.h"
#include "libros.h"
#include "autores.h"
#include "socios.h"
#define T 3
#define OCUPADO 1
#define LIBRE 0
void inicializarSocios(eSocio lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta de socios\n");
    printf("2- Modificacion de socios\n");
    printf("3- Baja de socios\n");
    printf("4- Listar los socios, autores y libros\n");
    printf("5- Prestamos\n");
    printf("6- Salir\n");
    printf("\nIngrese opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eSocio lista[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
void mostrarUnSocio(eSocio socio)
{
        printf("  %d   %s   %s    %c    %d     %s     %d    %d    %d\n", socio.codigoDeSocio, socio.apellido, socio.nombre, socio.sexo, socio.telefono, socio.eMail, socio.fechaDeAsociado.dia, socio.fechaDeAsociado.mes, socio.fechaDeAsociado.anio);

}

void mostrarSocios(eSocio lista[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            mostrarUnSocio(lista[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay socios que mostrar\n\n");
    }
}

int mayorCodigoDeSocios(eSocio lista[], int tam)
{
    int i;
    int flag = 0;
    int aux = 0;
    for(i=0; i < tam; i++)
    {
        if(flag==0 || lista[i].codigoDeSocio > aux)
        {
            aux = lista[i].codigoDeSocio;
            flag = 1;
        }
    }
    return aux;
}

void altaSocio(eSocio lista[], int tam)
{
    eFechaSocio fecha[8];
    int i;
    i = buscarLibre(lista,tam);

    if(i != -1)
    {
        lista[i].codigoDeSocio = mayorCodigoDeSocios(lista, T) + 1;
        getChar("ingrese apellido: ");
        gets(lista[i].apellido);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese telefono: ");
        scanf("%d", &lista[i].telefono);
        printf("Ingrese eMail: ");
        fflush(stdin);
        gets(lista[i].eMail);
        printf("Ingrese dia del asociados: ");
        scanf("%d", &fecha[i].dia);
        printf("Ingrese mes del asociados: ");
        scanf("%d", &fecha[i].mes);
        printf("Ingrese anio del asociados: ");
        scanf("%d", &fecha[i].anio);
      //  strcpy(lista[i].fechaDeAsociado, fecha[i]);
        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("no hay espacio");
    }
}

void bajaSocio(eSocio lista[], int tam, int codigoDeSocio)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese codigo de socio a dar de baja: ");
    scanf("%d", &codigoDeSocio);

    for(i=0; i<tam; i++)
    {
        if(codigoDeSocio == lista[i].codigoDeSocio)
        {
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void modificarSocio(eSocio lista[], int tam)
{
    int i;
    char seguir='N';
    int loEncontro = 0;
    int codigoDeSocio;
    mostrarSocios(lista,tam);
    system("pause");
    printf("Ingrese codigo de socio a modificar: ");
    scanf("%d", &codigoDeSocio);
    system("pause");

    for(i=0; i<tam; i++)
    {
        if(codigoDeSocio == lista[i].codigoDeSocio && lista[i].estado == OCUPADO)
        {
            do
            {
                switch(menuM())
                {
                case 1:
                    printf("Ingrese un nuevo apellido: ");
                    fflush(stdin);
                    gets(lista[i].apellido);
                    break;
                case 2:
                    printf("Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(lista[i].nombre);
                    break;
                case 3:
                    printf("Ingrese un nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &lista[i].sexo);
                    break;
                case 4:
                    printf("Ingrese telefono: ");
                    scanf("%d", &lista[i].telefono);
                    break;
                case 5:
                    printf("Ingrese eMail: ");
                    fflush(stdin);
                    gets(lista[i].eMail);
                    break;
                case 6:
                    seguir = 'n';
                    break;
                }
            }
            while(seguir == 's');
            loEncontro = 1;
            break;
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}
int menuM()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones de Modificar***\n\n");
    printf("1- modificar apellido\n");
    printf("2- modificar nombre\n");
    printf("3- modificar sexo\n");
    printf("4- modificar telefono\n");
    printf("5- modificar eMail\n");
    printf("6- Salir\n");
    printf("\nIngrese opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &opcion);

    return opcion;
}

void OrdenarSocios(eSocio lista[], int tam)
{
    eSocio auxLista;
    int i;
    int j;

    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j < tam; j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido) && strcmp(lista[i].nombre,lista[j].nombre) > 0)
            {
                auxLista = lista[i];
                lista[i] = lista[j];
                lista[j] = auxLista;
            }
        }
    }
}
