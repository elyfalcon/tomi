#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "socios.h"
#include "prestamos.h"
#include "input.h"
#include "fechas.h"
#include "autores.h"


void AltaLibro(eLibro libro[],int cantidad)

{
   int indice;
   int flag=-1;
   char resp='S';

        while(resp=='S')
        {
            indice=obtenerEspacioLibre(libro,cantidad);
            if(indice!=-1)
            {
            printf("\n-----------ALTA DE LIBROS-------\n");
            libro[indice].idlibro=indice+1;
            printf("Ingrese el nombre del libro: ");
            fflush(stdin);
            gets(libro[indice].nombre_prop);
            printf("Ingrese el autor del libro: ");
            fflush(stdin);
            gets(libro[indice].ape_prop);
     //       printf("Ingrese codigo: ");
      //      gets(libro[indice].direccion);
           /* do{
                printf("\nIngrese id del libro: ");
                fflush(stdin);
                }while (scanf("%d",&libro[indice].idlibro)==0);*/
            printf("\nIngrese el codigo de autor:");
            fflush(stdin);
            gets(libro[indice].codigoDeAutor);
            libro[indice].estado=1;
            flag=1;
            resp=Responder("\nContinua ingresando otro libro?: (S/N)");
        }
        else
        {
            printf("\n--------No hay mas lugar, no se pudo ingresar:");

        }
        }

        }
int obtenerEspacioLibre(eLibro lista_libro[],int cantidad)
{
int i;
int posicion=-1;

if(cantidad>0 && lista_libro !=NULL)
{
    for(i=0;i<cantidad;i++)
    {
        if(lista_libro[i].codigoDeLibro==0)
        {
            posicion=i;
            break;
        }
    }
}
void MostrarUno(eLibro libro)
{
    printf("\nCodigo: %d  Titulo: %s Codigo del autor: %d  \n",libro.codigoDeLibro,libro.titulo,libro.codigoDeAutor);
}

/*void MostrarPropietarios(ePropietario lista_propietario[],int cant_prop)
{
    int i;
    printf("LISTADO DE LIBROS\n");

    for(i=0;i<cant_prop;i++)
    {
        if(lista_propietario[i].idPropietario!=0)
        {
        printf("%d  %s   %s\n",lista_propietario[i].idPropietario,lista_propietario[i].nombre_prop,lista_propietario[i].direccion);
        }

    }
}*/
void MostrarLibros(eLibro lista[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {
            MostrarUnLibro(lista[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay socios que mostrar\n\n");
    }
}
void ModificarUnaPersona(eLibro lista_libro[],int cantidad)
{
  int i;
  int index;
  char resp='N';
  ePropietario aux[10];

  MostrarLibros(lista_libro,cantidad);
  i=PedirEntero("Ingrese el id del libro");
  index= buscarPorId(lista_propietario,i,cantidad);
  if(index!=-1)
    {
        lista_libro[index].idPropietario = index+1;
        fflush(stdin);
        aux[index]=lista_libro[index];
        printf("\nIngrese el nuevo Titulo:  ");
        fflush(stdin);
        gets(lista_libro[index].tarjeta);//CORREGI Y PONE PARA QUE TOME STRING
        resp=Responder("\nConfirma la modificion?(S/N)");
        if(resp=='S')
        {
            printf("\nLibro  modificado:");
        }
        else
        {
            printf("\nModificacion cancelada:");
            lista_libro[index]=aux[index];
        }




    }
    else
    {
        printf("Usuario no encontrado!!!");
    }
}
int buscarPorId(eLibro lista_propietario[], int id,int cantidad)
{
    int i;
    int flag=-1;
    if(lista_propietario!=NULL)
  {
        for(i=0;i<cantidad;i++)
        {
            if(id==lista_propietario[i].codigoDeLibro)
            {
                printf("El libro  buscada es:\n");
                printf("\nCodigo: %d  Titulo: %s Codigo del autor: %d  \n",lista_propietario[i].codigoDeLibro,lista_propietario[i].titulo,lista_propietario[i].codigoDeAutor);
               // system("pause");
                flag=i;
                break;
            }
        }
  }
  return flag;
}
/*void BajaPropietario(ePropietario lista_prop[],int indice,int cant_prop,eIngresos list_ingre[],int cant_ingre,eEgreso lista_egreso[],int cant_egreso)
{
    int j,i;
    int cuenta=0;
    float marca1;
    float Total_pagar;
    char resp='N';
    int estadia=0;
    int PropAux;
    int primeravez=0;
    int id;


    MostrarPropietarios(lista_prop,cant_prop);
    id=PedirEntero("\nIngrese el id a dar de baja: ");
    indice=buscarPorId(lista_prop,id,cant_prop);

        if(indice!=-1)
        {

            resp=Responder("\nEsta seguro que desea egresar al propietario?: S/N ");

            resp=Responder("\nEsta seguro que desea dar de baja al propietario?: S/N ");

            if(resp=='S')
                {
                    lista_prop[indice].estado=-1;
                   Total_pagar=Liquidacion(list_ingre,lista_egreso,indice,cant_ingre);
                   if(Total_pagar!=0)
                    printf("\nEl total a pagar: %2.f\n",Total_pagar);

                   // AltaEgreso(lista_egreso,list_ingres[i].marca,Total_pagar,cant_egreso);


                   else
                    printf("\nEl propietario no tiene deuda\n");


                }
                 else{
                        printf("\nBaja Cancelada");}
}

            else
            printf("\nNo existe el propietario ingresado: \n");

       system("pause");

    }
*/
void ordenarPorCriterios(eLibro vec[], int tam){
    int i, j;
    eLibro aux;
    for(i=0; i<tam; i++){
        for(j=i+1; j<tam; j++){
            if(vec[i].sueldo<vec[j].sueldo){
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else{
                    if(vec[i].sueldo==vec[j].sueldo){
                        if(strcmp(vec[i].nombre,vec[j].nombre)){
                            aux=vec[i];
                            vec[i]=vec[j];
                            vec[j]=aux;
                        }
                    }
                }
        }
    }
}
