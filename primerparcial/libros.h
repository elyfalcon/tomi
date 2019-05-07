#ifndef LIBROS_H_INCLUDE
#define LIBROS_H_INCLUDE

typedef struct
{
    int codigoDeLibro;
    char titulo[51];
    int codigoDeAutor;
}eLibro;


void AltaLibro(eLibro libro[],int cantidad);
int obtenerEspacioLibre(eLibro lista_libro[],int cantidad);
void MostrarUno(eLibro libro);

#endif // LIBROS_H_INCLUDE
