#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
typedef struct ts_trabajo
{
    int id;
    char usuario[50];
    char documento[50];
    int total_pags;
    int restant_pags;
    int copias;
    int priordad;
    int estado;
} trabajo;

void menu();

void q_init(trabajo *lista, int total);
void q_print(trabajo *lista, int total);
void q_peak(trabajo *lista, int total);
int q_is_empty(int total);
void q_dequeue(trabajo *lista, int *total);

float valida_num(int min, int max, int flotante, const char *texto);
char *valida_char(char *texto, const char *msg);
void imprimir(trabajo *lista, int indice);
void eliminar(trabajo *lista, int indice, int *total);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
void menu()
{
    trabajo lista[3];
    int total = 0;
    int op = 0;
    while (op != 5)
    {
        printf("\n------- MENU -------\n");
        printf("---- INVENTARIO ----\n");
        printf("1- Agregar\n");
        printf("2- Peak\n");
        printf("3- Dequeue\n");
        printf("4- Listar\n");
        printf("5- Salir\n");

        op = valida_num(1, 5, 0, "\nIngresa tu opcion: ");
        switch (op)
        {
        case 1:
            system("cls");
            if (total !=3 )
            {
                q_init(lista, total);
                total++;
            }
            else
            {
                printf("\nLa lista esta llena\n");
            }
            break;
        case 2:
            system("cls");
            if (q_is_empty(total))
            {
                printf("\nLa lista esta vacia\n");
            }
            else
            {
                q_peak(lista,total);
            }

            break;
        case 3:
            system("cls");
            if (q_is_empty(total))
            {
                printf("\nLa lista esta vacia\n");
            }
            else
            {
                q_dequeue(lista, &total);
            }

            break;
        case 4:
            system("cls");
            if (q_is_empty(total))
            {
                printf("\nLa lista esta vacia\n");
            }
            else
            {
                q_print(lista, total);
            }
            break;
        case 5:
            printf("\nSaliendo...");
            break;
        }
    }
}

void q_init(trabajo *lista, int total)
{
    lista[total].id = total + 1;
    valida_char(lista[total].usuario, "\nIngresa el usuario quien mando a imprimir: ");
    valida_char(lista[total].documento, "\nIngresa el nombre del decumento: ");
    strcat(lista[total].documento, ".pdf");
    lista[total].total_pags = valida_num(1, 999, 0, "\nIngresa el numero total de paginas: ");
    lista[total].copias = valida_num(1, 999, 0, "\nIngresa el numero total de copias: ");
    lista[total].restant_pags = lista[total].total_pags * lista[total].copias;
    printf("\n1- Normal\n2- Urgente\n");
    lista[total].priordad = valida_num(1, 2, 0, "\nIngresa la prioridad: ");
    lista[total].estado = 1;
}

void q_print(trabajo *lista, int total)
{
    printf("\n%-2s  %-15s  %-20s  %-10s  %-14s  %-6s  %-10s  %-11s",
           "ID", "Usuario", "Documento", "Total_Pag", "Restantes_pag", "Copias", "Prioridad", "Estado");
    for (int i = 0; i < total; i++)
    {
        imprimir(lista, i);
        printf("\n------------------------------------------------------");
        printf("-------------------------------------------");
    }
}

void q_dequeue(trabajo *lista, int *total)
{
    int bandera = 0;
    for (int i = 0; i < *total; i++)
    {
        if (bandera == 0)
        {
            if (lista[i].estado == 1)
            {
                char estado[12];
                lista[i].estado = 2;
                strcpy(estado, "Imprimiendo");
                int aux;
                aux = lista[i].total_pags;
                int auxCopia = lista[i].copias;
                while (lista[i].copias > 0)
                {
                    /*system("cls");
                    printf("\nImprmiendo la siguiente tarea: %s\n", lista[i].documento);
                    printf("\nEstado: %s", estado);
                    printf("\n----Copias faltantes: %d----\n", lista[i].copias);
                    printf("Hojas totales restantes: %d\n", lista[i].restant_pags);
                    while (aux > 0)
                    {

                        printf("\nHojas faltantes de esta copia: %d\n", aux);
                        for (int i = 0; i < 10; i++)
                        {
                            printf(". ");
                            Sleep(50);
                        }
                        aux -= 1;
                    }*/
                    aux = lista[i].total_pags;
                    lista[i].copias -= 1;
                    lista[i].restant_pags -= lista[i].total_pags;
                }
                lista[i].copias = auxCopia;
                lista[i].restant_pags = 0;

                lista[i].estado = 3;
                strcpy(estado, "\nCompletado");
                printf("%-11s", estado);
                bandera = 1;
                
                
                eliminar(lista, i, total);
                return;
            }
        }
    }
    if (bandera == 0)
    {
        printf("\nNo hay nada en la lista para imprimir\n");
    }
}
void eliminar(trabajo *lista, int indice, int *total){
    
    for (int i = indice; i < *total-1; i++)
    {
        lista[i] = lista[i+1];
    }
    
    (*total)--;
}

void imprimir(trabajo *lista, int i)
{
    printf("\n%-2d  %-15s  %-20s  %-10d  %-14d  %-6d  %-10s",
           lista[i].id, lista[i].usuario, lista[i].documento,
           lista[i].total_pags, lista[i].restant_pags, lista[i].copias,
           lista[i].priordad == 1 ? "Normal" : "Urgente");
    char estado[12];
    switch (lista[i].estado)
    {
    case 1:
        strcpy(estado, "En Cola");
        break;
    case 2:
        strcpy(estado, "Imprimiendo");
        break;
    case 3:
        strcpy(estado, "Completado");
        break;
    case 4:
        strcpy(estado, "Cancelado");
        break;
    }
    printf("%-11s", estado);
}

void q_peak(trabajo *lista, int total)
{
    for (int i = 0; i < total; i++)
    {
        if (lista[i].estado == 1)
        {
            printf("\n%-2s  %-15s  %-20s  %-10s  %-14s  %-6s  %-10s  %-11s",
                   "ID", "Usuario", "Documento", "Total_Pag", "Restantes_pag", "Copias", "Prioridad", "Estado");
            imprimir(lista, i);
        }
    }
}

int q_is_empty(int total)
{
    if (total == 0)
    {
        return 1;
    }
    return 0;
}

float valida_num(int min, int max, int flotante, const char *texto)
{
    int n;
    float n2;
    int ciclo = 0;
    char comprobar[50];
    while (ciclo == 0)
    {
        printf("%s", texto);
        int i = 0;
        char temp;
        do
        {
            temp = getch();
            if (temp >= 48)
            {
                if (temp <= 57)
                {
                    comprobar[i] = temp;
                    printf("%c", temp);
                    i++;
                }
            }
            if (temp == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            if (temp == 46)
            {
                if (flotante)
                {
                    if (i > 0)
                    {
                        comprobar[i] = temp;
                        printf("%c", temp);
                        i++;
                    }
                }
            }
        } while ((temp != 13) || i == 0);
        comprobar[i] = '\0';
        // printf("\n\n%s\n", comprobar);
        if (flotante)
        {
            n2 = atof(comprobar);
        }
        else
        {
            n = atoi(comprobar);
        }
        if (n >= min)
        {
            if (n <= max)
            {
                // printf("\nLa opcion fue: %d\n", n);
                ciclo = 1;
            }
            else
            {
                printf("\nValor invalido\n");
            }
        }
        else
        {
            printf("\nValor invalido\n");
        }
    }
    if (flotante)
    {
        return n2;
    }
    else
    {
        return n;
    }
}

char *valida_char(char *texto, const char *msg)
{
    char palabra[75];
    int i = 0;
    char temp;
    strcpy(palabra, "");
    strcpy(texto, "");
    /*
    printf("\n%s\n", texto);
    printf("%s\n", palabra);*/
    printf("%s", msg);
    do
    {
        // printf("\nPalabra- %s\n", palabra);
        temp = getch();

        if (i == 48)
        {
            palabra[49] = '\0';
        }
        else
        {
            if (temp <= 122 && temp >= 97)
            {
                palabra[i] = temp - 32;
                printf("%c", palabra[i]);
                i++;
                continue;
            }
            if (temp <= 90 && temp >= 65)
            {
                palabra[i] = temp;
                printf("%c", palabra[i]);
                i++;
                continue;
            }
            if (temp >= 48 && temp <= 57)
            {
                palabra[i] = temp;
                printf("%c", palabra[i]);
                i++;
                continue;
            }
            if (temp == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                    continue;
                }
            }
            if (i > 0)
            {
                if (temp == 32)
                {
                    if (palabra[i - 1] != 32)
                    {
                        palabra[i] = 32;
                        printf("%c", palabra[i]);
                        i++;
                        continue;
                    }
                }
                if (temp == 46)
                {
                    if (i > 0)
                    {
                        palabra[i] = 46;
                        printf("%c", palabra[i]);
                        i++;
                        continue;
                    }
                }
                if (temp == 61)
                {
                    palabra[i] = 46;
                    printf("%c", palabra[i]);
                    i++;
                    continue;
                }
            }
        }
    } while ((temp != 13) || i == 0);
    // printf("%d", i);
    palabra[i] = '\0';
    strcpy(texto, palabra);
    return texto;
}
