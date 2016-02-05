/*
	República Bolivariana de Venezuela.
	Valle de Sartenejas, Miranda.	
	Universidad Simón Bolívar.
	Sistemas de Operación III.
	Profesora: Yudith Cardinale.
	Asunto: Proyecto III.
	Integrantes:
		González Betzabeth 08-10462.
		Villamizar Jhon    09-11221.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"

typedef int bool;
enum { false, true };

/* Verificación horizontal normal de las palabras */

int horizontal(int Dim, char **form, char word[]) {

	int j, fin, x, z, w, f, rep;
	int valor = 0;
	int N = Dim;
    int V = Dim-1;
	bool termino = false;
	bool invalido = false;
	int longt = strlen(word);
	int i = 0;

	while( (i < N) && !termino) {
		j = 0;
		fin = longt-1;
				
		while( j <  N && !(termino) && !(invalido)) {
			
			if(word[0] == form[i][j]) {

				x = 1; z = (j+1) % N;
				w = 0; f = N+1;
				rep = j;
				
				while (w < N) {
					
					if ( (word[x] == form[i][z]) && (z!=rep)) {
						
						if( z != rep) {						
							fin--;
													
							if( fin <= 0) {
								valor = 1;
								termino = true;
								break;
							} else {
								f--; w++;
								z = (z+1) % N;
								x++;
							}
						} else {
							invalido = true;
							break;
						}						

					} else {
						f--; w++;
						
						if (f >= longt) {
							z = (z+1) % N;
						} else {
							
							if(j != (N-1)) {
								fin = longt-1;								
								break;
							} else {
								invalido = true;
								break;
							}
						}
					}
				}
			}
			j++;
		}
		i++;	
	}
	return valor;
}

/* Verificación horizontal inversa de las palabras */

int horizontal_inv(int Dim, char **form, char word[]) {

	int j, fin, x, z, w, f, rep;
	int valor = 0;
	int N = Dim;
    int V = Dim-1;
	int longt = strlen(word);
	bool termino = false;
	bool invalido = false;
	int i = 0;

	while( (i < N) && !termino) {
		j = N-1;
		fin = longt-1;
		
		
		while( j > 0 && !(termino) && !(invalido)) {
				
			if(word[0] == form[i][j]) {

				x = 1; z = (j-1) % N;
				w = 0; f = N+1;
				rep = j;
				
				while (w < N) {
					
					if ( (word[x] == form[i][z]) && (z!=rep)) {
						
						if( z != rep) {						
							fin--;
												
							if( fin <= 0) {
								valor = 1;
								termino = true;
								break;
							} else {
								f--; w++;
								z =  (z != 0) ? (z-1) % N : N-1;
								x++;
							}
						} else {
							invalido = true;
							break;
						}

					} else {
						f--; w++;
												
						if (f >= longt) {
							z =  (z != 0) ? (z-1) % N : N-1;
						} else {
							
							if(j != 0) {
								fin = longt-1;	
								break;
							} else {
								invalido = true;
								break;
							}
						}
					}
				}
			}
			j--;
		}
		i++;	
	}
	return valor;
}

/* Verificación vertical normal de las palabras */

int vertical(int Dim, char **form, char word[]) {

	int i, fin, x, z, w, f, rep;
	int valor = 0;
	int N = Dim;
    int V = Dim-1;
	bool termino = false;
	bool invalido = false;
	int longt = strlen(word);
	int j = 0;

	while( (j < N) && !termino) {
		i = 0;
		fin = longt-1;
				
		while( i <  N && !(termino) && !(invalido)) {
			
			if(word[0] == form[i][j]) {

				x = 1; z = (i+1) % N;
				w = 0; f = N+1;
				rep = i;
				
				while (w < N) {
					
					if ( (word[x] == form[z][j]) && (rep != z) ) {
						
						if( z != rep) {						
							fin--;
						
							if( fin <= 0) {
								valor = 1;
								termino = true;
								break;
							} else {
								f--; w++;
								z = (z+1) % N;
								x++;
							}

						} else {
							invalido = true;
							break;
						}

					} else {
						f--; w++;
						
						if (f >= longt) {
							z = (z+1) % N;
						} else {

							if(i != (N-1)) {
								fin = longt-1;									
								break;
							} else {
								invalido = true;
								break;
							}
						}
					}
				}
			}
			i++;
		}
		j++;	
	}
	return valor;
} 

/* Verificación vertical inversa de las palabras */

int vertical_inv(int Dim, char **form, char word[]) {

	int i, fin, x, z, w, f, rep;
	int valor = 0;
	int N = Dim;
    int V = Dim-1;
	int longt = strlen(word);
	bool termino = false;
	bool invalido = false;
	int j = 0;

	while( (j < N) && !termino) {
		i = N-1;
		fin = longt-1;
		
		
		while( i > 0 && !(termino) && !(invalido)) {
			
			if(word[0] == form[i][j]) {

				x = 1; z = (i-1) % N;
				w = 0; f = N+1;
				rep = i;
				
				while (w < N) {
					
					if ( (word[x] == form[z][j]) && (rep != z) ) {
						
						if( z != rep) {						
							fin--;
												
							if( fin <= 0) {
								valor = 1;
								termino = true;
								break;
							} else {
								f--; w++;
								z =  (z != 0) ? (z-1) % N : N-1;
								x++;
							}
						} else {
							invalido = true;
							break;
						}

					} else {
						f--; w++;
												
						if (f >= longt) {
							z =  (z != 0) ? (z-1) % N : N-1;
						} else {
							
							if(i != 0) {
								fin = longt-1;
								break;
							} else {
								invalido = true;
								break;
							}
						}
					}
				}
			}
			i--;
		}
		j++;	
	}
	return valor;
} 

/* Búsqueda de la palabra en la sopa de letras */

int procesar_palabra(int Dim, char **form, char word[]) {

	int res = 0;
	res  = horizontal(Dim,form,word);
	
	if (!res)
		res = horizontal_inv(Dim,form,word);
	if (!res)
		res = vertical(Dim,form,word);
	if (!res)
		res = vertical_inv(Dim,form,word);

	return res;

}

/* Función Principal */

void main(int argc, char* argv[]) {

	int N = 0, W = 0;
	int tam = 0;
	char * p = NULL;
	FILE *fp;
	fp = fopen(argv[1],"r");
	int rank, size;

	if (fp==NULL){
		printf("Error de apertura de Archivo \n");
		exit(0);

	} else {	
		fscanf (fp, "%d", &N);
		char **matriz;
		int i, j, asci;
		char c;

		/* Matriz Asignación Memoria Dinámica */

		matriz = (char **) malloc(N*sizeof(char*));
		for (i = 0; i < N; i++)
			matriz[i] = (char*) malloc(N*sizeof(char));	
		

		/* Inicialización de la Sopa de Letras */
		for ( i = 0; i< N ; i++) {
			for (j =0; j < N ; j++) {
				matriz[i][j] = 0;
			}
		}

		/* Lectura de la Sopa de Letras */
		i = 0;
		while ( i< N ) {
			j = 0;		
			while ( j < N ) {
				c = fgetc(fp);
				asci = 0;
				asci = (int) c;
				if (asci == 10) {
					continue;
				} else {
					matriz[i][j] = c;
					j++;
				}
			}
			i++;
		}

		fscanf (fp, "%d", &W);

		MPI_Init(&argc,&argv);
		
		int rank, size;
		int Id, numeroProcesos;
		MPI_Status Stat;

		/* Inicialización de los procesos MPI */
		
		MPI_Comm_size(MPI_COMM_WORLD, &numeroProcesos);
		MPI_Comm_rank(MPI_COMM_WORLD, &Id);

		char word[1000];
		int x, rfinal = 0;
		int r = 0;
		int numPal, resPal, Inicio, Fin;

		int k = Id;

		/* Calculo el número de palabras a procesar por cada
		   procesador y el resto de palabras a procesar   */

		numPal = W/numeroProcesos;
		resPal = W % numeroProcesos;
		
		/* Calculo el Inicio y Final del # de Palabras a pro
		   cesar                                          */

		Inicio = Id*numPal;
		if ((resPal != 0) && (Id < resPal) && (Id !=0))
			Inicio++;

		Fin = Inicio + (numPal-1);
		if(Id < resPal)
			Fin++;

		if(Id >= resPal) {
			Inicio += resPal;
			Fin += resPal;
		}

		char* palabras[W];
		int   respuestas[numeroProcesos];

		for ( i = 0; i < numeroProcesos; i++)
			respuestas[i] = 0;

		/* Guardo en un arreglo las palabras a buscar */

		for (x= 0; x < W; x++) {
			p = NULL;
			fscanf(fp,"%s", word);
			tam = strlen(word);
			p = (char *) malloc((tam+1)*sizeof(char));
			strcpy(p,word);
			palabras[x] = p;
		} 

		/* Resultado de las palabras a procesar por un procesador */
		
			int valor = 0;
			x = Inicio;
			while (x <= Fin) {
				valor = valor + procesar_palabra(N,matriz,palabras[x]);
				x++;
			}

			respuestas[Id] = valor;
						
		/* Datos a enviar y recibir */

		int tam_a_enviar = (Fin - Inicio + 1)*N;

		/* Caso ID = 0 */
		
		if (Id == 0) {

			for (i = 1; i < numeroProcesos ; i++) {
			
			MPI_Probe(MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,&Stat);
			MPI_Recv(&(respuestas[i]),tam_a_enviar,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

			}

			for ( x= 0; x < numeroProcesos; x++) {
				rfinal += respuestas[x];
			}	

			printf("\n\nEsta es la Sopa de letras: \n\n");

			i = 0;
			printf("\t");
			while ( i < N ) {
				j = 0;
				while ( j < N ) {
					printf("%c ",matriz[i][j]);
					j++;
				}
			printf("\n");printf("\t");
			i++;
			}

			printf("\nN° de palabras presentes: \n\n");
			printf("\t    %d \n", rfinal);
			printf("\n");
	        fclose(fp);	
		
		} else {

		/* Envío la respuesta */

			MPI_Send(&(respuestas[Id]),tam_a_enviar,MPI_INT,0,0,MPI_COMM_WORLD);
		}
	}

	MPI_Finalize();
		
}
//FINAL
