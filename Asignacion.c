#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>


void ejecutar_proceso();
void listado_procesos();
void Kill_bill();
void ejecutar_en_segundo_plano(const char *comando);


void ejecutar_en_segundo_plano(const char *comando) {
    pid_t pid = fork(); 
    if (pid == 0) {
        char *args[] = {"/bin/sh", "-c", (char *)comando, NULL};
        execvp(args[0], args);
        perror("Hubo un error al ejecutar el comando!");
        _exit(1);
    }
} 


void ejecutar_proceso()
{
    char comando[256];
    printf("Porfavor escriba los comandos que quiera ejecutar , si quiere salir de esta operacion escriba exit:\n");
    while (1) {
        printf("> ");
        if (!fgets(comando, sizeof(comando), stdin)) break;
        comando[strcspn(comando, "\n")] = '\0';  
        if (strcmp(comando, "exit") == 0) break;
        ejecutar_en_segundo_plano(comando);
    }
}

int main()
{

    int opcion;

    do
    {
        system("clear");
        printf("Menu \n\n");
        printf("1.- Ejecutar un nuevo proceso \n");
        printf("2.-Listado de procesos \n");
        printf("3.-Matar un proceso \n");
        printf("4.-Salir \n\n");
        printf(" Que desea escoger?: ");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion)
        {

        case 1:
            printf("Hola 1 \n");
            ejecutar_proceso();
            break;
        case 2:
            printf("Hola 2 \n");
            listado_procesos();
            break;
        case 3:
            printf("Hola 3 \n");
            Kill_bill();
            break;
        case 4:
            printf("Saliendo del programa.. \n");

            break;
        default:
            printf("Hola default \n");
            break;
        }
    } while (opcion != 4);
    printf("\n");
    return 0;
}