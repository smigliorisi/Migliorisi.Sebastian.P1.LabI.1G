/*
 ============================================================================
 Name        : 1er.c
 Author      : Sebastian Migliorisi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_SebaLib.h"
#include "Mascotas.h"
#include "Trabajo.h"

#define CANTHARDCODE 10
#define TAM 15
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTRABAJO 15

int main(void)
{
	setbuf(stdout, NULL);
	char opcion;
	char salida='n';
	int proximoId=1000;
	int proximoIdT=2000;
	eTipo tipo[TAMT] = {{1,"Ave"}, {2,"Perro"}, {3,"Roedor"}, {4,"Gato"}, {5,"Pez"}};
	eColor color[TAMC] = {{1,"Negro"}, {2,"Blanco"}, {3,"Rojo"},{4,"Gris"}, {5,"Azul"}};
	eServicio servicio[TAMS] = {{1,"Corte", 450}, {2,"Desparasitado", 800}, {3,"Castrado", 600}};
	eMascota lista[TAM];
	eTrabajo trabajos[TAMTRABAJO];


	inicializarMascotas(lista,TAM);
	inicializarTrabajos(trabajos,TAMTRABAJO);

	hardCodearMascotas(lista, CANTHARDCODE);
	proximoIdT+=CANTHARDCODE+1;

	do
	{
		if(utn_getCharacter(&opcion, "\n***** Gestion de Mascotas *****\n\n"
				"A.	ALTA MASCOTA\n"
				"B.	MODIFICAR MASCOTA\n"
				"C.	BAJA MASCOTA\n"
				"D.	LISTAR MASCOTAS\n"
				"E.	LISTAR TIPOS \n"
				"F.	LISTAR COLORES\n"
				"G.	LISTAR SERVICIOS\n"
				"H.	ALTA TRABAJO\n"
				"I.	LISTAR TRABAJOS\n"
				"J.	SALIR\n",
				"\nReingrese Opcion (1 a 9)\n",'A','J',2)==0)
		{
			switch(opcion)
			{
				case 'A':
					if(altaMascota(proximoId,lista,TAM,tipo,TAMT,color,TAMC)==1)
					{
						proximoId+=1;
					}
					else
						printf("No se pudo dar de alta");
					break;
				case 'B':
					if(checkEmpty(lista, TAM)==1)
					{
						modificarMascota(lista,TAM,tipo,TAMT,color,TAMC);
					}
					else
						printf("\n******* No hay mascotas que modificar *******\n\n");

					break;
				case 'C':
					if(checkEmpty(lista, TAM)==1)
					{
						bajaMascota(lista,TAM,tipo,TAMT,color,TAMC);
					}
					else
						printf("\n******* No hay mascotas que dar de baja *******\n\n");

					break;
				case 'D':
					mostrarMascotas(lista,TAM,tipo,TAMT,color,TAMC);
					break;
				case 'E':
					listarTipos(tipo,TAMT);
					break;
				case 'F':
					listarColor(color,TAMC);
					break;
				case 'G':
					listarServicios(servicio,TAMS);
					break;
				case 'H':
					if(altaTrabajo(proximoIdT,trabajos,TAMTRABAJO,lista,TAM,tipo,TAMT,color,TAMC,servicio,TAMS)==1)
					{
						proximoIdT+=1;
					}
					else
						printf("No se pudo dar de alta");
					break;
				case 'I':
					mostrarTrabajos(trabajos,TAMTRABAJO,lista,TAM,servicio,TAMS);
					break;
				case 'J':
					printf("¿Confirma Salida? (ingrese 's' para salir)\n");
					fflush(stdin);
					scanf("%c", &salida);
					break;
			}
		}
	}while(salida!='s');

	return 0;
}
