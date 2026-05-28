#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct Ts_Trabajo
{
    int id;
    char usuario[32];
    char documento[32];
    int total_pgs;
    int restante_pgs;
    int prioridad;
    int copias;
    int estado;
    // Ts_Trabajo *siguiente;
} Trabajo;

typedef struct Nodo
{
    Trabajo job;
    struct Nodo *siguiente;
} Nodo;

typedef struct Ts_Lista
{
    Nodo *cabeza;
    Nodo *cola;
    int tamano;
} Ts_Lista;

void menu();
void mensajes();
int qd_enqueue(Ts_Lista *lista, Trabajo job);
void mostrarLista(Ts_Lista *lista);

void q_peak(Ts_Lista *lista);
int q_is_empty(int total);
int qd_dequeue(Ts_Lista *lista);
void qd_destroy(Ts_Lista *lista);

float valida_num(int min, int max, int flotante, const char *texto);
char *valida_char(char *texto, const char *msg);
void qd_init(Ts_Lista *lista);

int main()
{

    menu();
    return 0;
}

void mensajes()
{
    printf("\n=== MENU ===\n");
    printf("[1] Agregar.\n");
    printf("[2] Peak\n");
    printf("[3] Dequeve\n");
    printf("[4] Listar\n");
    printf("[0] Salir\n");
}
void menu()
{
    int opc;
    Ts_Lista lista;
    qd_init(&lista);
    do
    {
        mensajes();
        if (scanf("%d", &opc) != 1)
        {
            while (getchar() != '\n')
            {
                /* code */
            }
            opc = -1;
        }

        switch (opc)
        {
        case 1:{
            system("cls");
            Trabajo impresion;

            valida_char(impresion.usuario, "\nIngresa el usuario quien mando a imprimir: ");
            valida_char(impresion.documento, "\nEscriba el nombre del documento: ");
            strcat(impresion.documento, ".pdf");
            impresion.total_pgs = valida_num(1, 1000, 0, "\nIngrese el numero total de paginas: ");
            impresion.copias = valida_num(1, 50, 0, "\nIntroduzca el numero de copias: ");
            impresion.restante_pgs = impresion.total_pgs * impresion.copias;
            printf("\n1- Normal\n2- Urgente\n");
            impresion.prioridad = valida_num(1, 2, 0, "\nIngresa la prioridad: ");
            impresion.estado = 1;
            impresion.id = lista.tamano + 1;
            qd_enqueue(&lista, impresion);

            break;}

        case 2:{
            system("cls");
            q_peak(&lista);

            break;}

        case 3:{
            system("cls");
            int hecho = qd_dequeue(&lista);
            if (hecho == 1)
            {
                printf("Ya quedo impreso");
            }
            else
            {
                printf("No se pudo imprimir");
            }
            
            break;
        }
            

        case 4:{
            system("cls");
            mostrarLista(&lista);

            break;
}
        case 0:{
            system("cls");
            qd_destroy(&lista);
            printf("Saliendo");
            for (int i = 0; i < 10; i++)
            {
                printf(". ");
                Sleep(50);
            }
            break;}

        default:{
            system("cls");
            printf("Opcion incorrecta.\n");
            system("pause");
            break;}
        }

    } while (opc != 0);
}

int qd_enqueue(Ts_Lista *lista, Trabajo job)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevo == NULL)
    {
        printf("Error: No se pudo agregar.\n");
        return 0;
    }

    nuevo->job = job;
    nuevo->siguiente = NULL;

    if (lista->cabeza == NULL)
    {
        lista->cabeza = nuevo;
        lista->cola = nuevo;
    }
    else
    {
        if (nuevo->job.prioridad == 2)
        {
            nuevo->siguiente = lista->cabeza;
            lista->cabeza = nuevo;
        }
        else
        {
            lista->cola->siguiente = nuevo;
            lista->cola = nuevo;
        }
    }
    lista->tamano++;
    return 1;
}

void mostrarLista(Ts_Lista *lista)
{
    if (lista->cabeza == NULL)
    {
        printf("La lista esta vacia.\n");
        return;
    }

    Nodo *actual = lista->cabeza;
    char estado[12];

    printf("\n%-2s  %-15s  %-20s  %-10s  %-14s  %-6s  %-10s  %-11s",
           "ID", "Usuario", "Documento", "Total_Pag", "Restantes_pag", "Copias", "Prioridad", "Estado");
    while (actual != NULL)
    {
        switch (actual->job.estado)
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
        printf("\n%-2d  %-15s  %-20s  %-10d  %-14d  %-6d  %-10s  %-11s",
               actual->job.id, actual->job.usuario, actual->job.documento, actual->job.total_pgs,
               actual->job.restante_pgs, actual->job.copias, actual->job.prioridad == 1 ? "Normal" : "Urgente", estado);

        actual = actual->siguiente;
    }
}

void q_peak(Ts_Lista *lista)
{
    if (lista->cabeza == NULL)
    {
        printf("Lista vacia");
        return;
    }
    Trabajo t = lista->cabeza->job;
    char estado[12];

    printf("\n%-2s  %-15s  %-20s  %-10s  %-14s  %-6s  %-10s  %-11s",
           "ID", "Usuario", "Documento", "Total_Pag", "Restantes_pag", "Copias", "Prioridad", "Estado");
    switch (t.estado)
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
    printf("\n%-2d  %-15s  %-20s  %-10d  %-14d  %-6d  %-10s  %-11s",
           t.id, t.usuario, t.documento, t.total_pgs, t.restante_pgs, t.copias, t.prioridad == 1 ? "Normal" : "Urgente", estado);
}

int qd_dequeue(Ts_Lista *lista)
{
    if (lista->cabeza == NULL)
    {
        printf("lista vacia.\n");
        return 0;
    }
/*

    Nodo *actual = lista->cabeza;
    int aux = actual->job.total_pgs;
    char estado[12];
    actual->job.estado = 2;
    strcpy(estado, "imprimiendo");

    while (actual->job.copias > 0)
    {
        system("cls");
        printf("\nImprimiendo la siguiente tarea: %s\n", actual->job.documento);
        printf("\nEstado: %s", estado);
        printf("\n----Copias faltantes: %d----\n", actual->job.copias);
        printf("Hojas totales restantes: %d\n", actual->job.restante_pgs);
        while (aux > 0)
        {
            printf("\nHojas faltantes de esta copia: %d\n", aux);
            for (int i = 0; i < 10; i++)
            {
                printf(". ");
                Sleep(50);
            }
            aux -= 1;
        }
        aux = actual->job.total_pgs;
        actual->job.copias -= 1;
        actual->job.restante_pgs -= actual->job.total_pgs;
    }

*/
    Nodo *temp = lista->cabeza;
    lista->cabeza = lista->cabeza->siguiente;

    if (lista->cabeza == NULL)
    {
        lista->cola = NULL;
    }
    free(temp);
    lista->tamano--;
    return 1;
}

void qd_destroy(Ts_Lista *lista)
{
    Nodo *actual = lista->cabeza;
    while (actual != NULL)
    {
        Nodo *temporal = actual;
        actual = actual->siguiente;
        free(temporal);
    }
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->tamano = 0;
}

void qd_init(Ts_Lista *lista)
{
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->tamano = 0;
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
