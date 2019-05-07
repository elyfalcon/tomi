
#include "libros.h"
#include "autores.h"
#include "fechas.h"

#ifndef SOCIOS_H_INCLUDE
#define SOCIOS_H_INCLUDE


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaSocio;

typedef struct
{
    int codigoDeSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    int telefono[16];
    char eMail[31];
    int estado;
    eFechaSocio fechaDeAsociado;
} eSocio;


#endif // SOCIOS_H_INCLUDE

void inicializarSocios(eSocio lista[], int tam);

int menu();

int buscarLibre(eSocio lista[], int tam);

void mostrarUnSocio(eSocio socio);

void mostrarSocios(eSocio lista[], int tam);

int mayorCodigoDeSocios(eSocio lista[], int tam);

void altaSocio(eSocio lista[], int tam);

void bajaSocio(eSocio lista[], int tam,int cant);

void modificarSocio(eSocio lista[], int tam);

int menuM();

void OrdenarSocios(eSocio lista[], int tam);


