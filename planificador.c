#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2000

/*void f(char *file1){

    char buffer[SIZE];
    FILE *archivo1 = fopen(file1,"r");
    int encontre = 0;
    char ch;
    char cadena[SIZE];
    int i = 0;
    int entero = 0;
    if(!archivo1){
        printf("Error al abrir el archivo\n");
    }

    else{



        fclose(archivo1);
    }

}*/
typedef struct ciudad {
char * nombre;
float pos_x;
float pos_y;
} * TCiudad;

typedef struct usuario {
float pos_x;
float pos_y;
} * TUsuario;

void vaciar(char temp[]){
    for (int i = 0; i < 50; i++){
        temp[i] = '\0';
    }
}

void cargarNombre(char temp[], int contador, TCiudad arreglo ){
    int k = strlen(temp) + 1;
    arreglo[contador].nombre = (char*) malloc (k * sizeof(char));
    strcpy(arreglo[contador].nombre, temp);
}
void cargarPosX(int temp, int contador, TCiudad arreglo){
    arreglo[contador].pos_x = temp;
}
void cargarPosY(int temp, int contador, TCiudad arreglo){
    arreglo[contador].pos_y = temp;
}

void cargarXUsuario(int temp, TUsuario usuario){
    usuario->pos_x = temp;
}

void cargarYUsuario(int temp, TUsuario usuario){
    usuario->pos_y = temp;
}

int main(int argc,char *args[]){
    /*if (argc != 2){
        printf("error en args");
        exit(1);
    }
    FILE *archivo = fopen(args[1],"r");*/

    TCiudad ciudades;
    TUsuario persona;
    FILE *archivo = fopen("mapa.txt","r");
    if (archivo == NULL){
        printf("no se pudo abrir el archivo. \n");
        exit(1);
    }

    char temporal[100];
    int cont = 0; 
    char aux = '0';
    int auxInt = 0;

    while(!feof(archivo)){
        fgets(temporal,50,archivo);
        cont++;
    }

    rewind(archivo);

    ciudades = (TCiudad) malloc(cont * sizeof(struct ciudad));
    persona = (TUsuario) malloc (sizeof(struct usuario));
    if (ciudades == NULL){
        printf("no pudimos reservar memoria.");
    }

          
    auxInt = fgetc(archivo);
    cargarXUsuario(auxInt, persona);      
    aux = fgetc(archivo);
    if (aux != ';'){
        printf("archivo con mal formato");
        exit(1);
    }
    auxInt = fgetc(archivo);
    cargarYUsuario(auxInt, persona);
    fgetc(archivo);
    
    for (int i = 0; aux != EOF; i++){ // contador de numero de ciudad (para cada ciudad se ejecuta este codigo)
        vaciar(temporal);
        aux = '0';
        for(int j = 0; aux != ';'; j++){
            aux = fgetc(archivo);
            if (aux != ';'){
                temporal[j] = aux;
            }
        }
        cargarNombre(temporal, i, ciudades);
        
        auxInt = fgetc(archivo);
        cargarPosX(auxInt,i, ciudades);

        aux = fgetc(archivo);
        if (aux != ';'){
            printf("archivo con mal formato.\n");
            exit(1);
        }
        auxInt = fgetc(archivo);
        cargarPosY(auxInt, i, ciudades);
        aux = fgetc(archivo);
    }
    fclose(archivo);
    for (int iterador = 0; iterador <= 3; iterador++){
        printf("ciudad 1: %s, posicion: %d %d \n", ciudades[iterador].nombre, ciudades[iterador].pos_x, ciudades[iterador].pos_y);
    }
    return 0;
}