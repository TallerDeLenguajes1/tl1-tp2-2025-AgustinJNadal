#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct 
{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef Compu;

void listarPCs(Compu *pcs, int num_pcs);
void mostrarMasVieja(Compu *pcs, int num_pcs);
void mostrarMasVeloz(Compu *pcs, int num_pcs);

int main(){
    int num_pcs = 5;
    Compu *pcs = (Compu *)malloc(num_pcs*sizeof(Compu));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};    

    srand(time(NULL));
    for (int i = 1; i <= num_pcs; i++)
    {
       pcs[i].velocidad = 1 + rand() % 3;
       pcs[i].anio = 2015 + rand() % (2024 - 2015 + 1);
       pcs[i].cantidad_nucleos = 1 + rand() % 8;
       pcs[i].tipo_cpu = tipos[rand() % 6];
    }
    
    listarPCs(pcs, num_pcs);

    free(pcs);
    return 0;
}

void listarPCs(Compu *pcs, int num_pcs){
    printf("Lista completa de las Pcs:\n");
    for (int i = 1; i <= num_pcs; i++)
    {
        printf("PC %d:\n", i);
        printf("Velocidad de procesamiento: %d GHz\n", pcs[i].velocidad);
        printf("Anio de fabricacion: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo de procesador: %s\n", pcs[i].tipo_cpu);
        puts("-----------------------------------");
    }
    
}
