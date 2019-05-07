
#include "libros.h"
#include "autores.h"
#include "fechas.h"

#ifndef PRESTAMOS_H_INCLUDE
#define PRESTAMOS_H_INCLUDE

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaPrestamo;

typedef struct
{
    int codigoDePrestamo;
    int codigoDeLibro;
    int codigoDeSocio;
    eFechaPrestamo fechaDePrestamo;
} ePrestamo;





#endif // PRESTAMOS_H_INCLUDE
