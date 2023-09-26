#include <stdio.h>
#include <stdlib.h>
#include "colaCircular.h"

int colaLlena()
{
    if (a == maximo)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int colaVacia()
{
    if (a == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int calcuUbic()
{
    return (frente + a) % maximo;
}
int calcuFren()
{
    return (frente + 1) % maximo;
}
void enCola(int b)
{
    if (colaLlena() == 1)
    {
        fin = calcuUbic();
        elemento[fin] = b;
        printf("El valor: %d esta en la posicion %d\n", b, fin);
        a++;
        printf("La cantidad de elementos es: %d\n", a);
    }
    else
    {
        printf("La cola esta llena\n");
    }
}
int desenCola()
{
    int n = NULL;
    if (colaVacia() == 1)
    {
        n = elemento[frente];
        printf("Eliminando el valor %d de la posicion %d", elemento[frente], frente);
        frente = calcuFren();
        a--;
        printf("La cantidad de elementos es: %d\n", a);
    }
    else
    {
        printf("La cola esta vacia\n");
    }
    return n;
}
void mostrarCola()
{
    if (colaVacia() == 0)
    {
        printf("La cola esta vacia\n");
    }
    else if (colaLlena() == 0)
    {
        printf("Cola circular: \n");
        for (int i = 0; i < maximo; i++)
        {
            printf("\telemento[%d]: %d \n", i, elemento[i]);
        }
        printf("\n");
    }
    else
    {
        if (fin == frente)
        {
            printf("Cola circular: \n");
            printf("\telemento[%d]: %d \n", fin, elemento[fin]);
        }
        else if (fin > frente)
        {
            printf("Cola circular:\n");
            for (int i = frente; i <= fin; i++)
            {
                printf("\telemento[%d] = %d\n", i, elemento[i]);
            }
            printf("\n");
        }
        else if (fin < frente)
        {
            printf("\nCola circular:\n");
            for (int i = 0; i <= fin; i++)
            {
                printf("\telemento[%d]: %d", i, elemento[i]);
            }
            for (int i = frente; i < maximo; i++)
            {
                printf("\telemento[%d]: %d\n", i, elemento[i]);
            }
            printf("\n");
        }
    }
}

void vaciaCola()
{
    if (colaVacia() == 0)
    {
        printf("\nLacola esta vacia\n");
    }
    else
    {
        frente = 0;
        a = 0;
    }
}
int main()
{
    int opcion, valor, eliminar;
    do
    {
        printf("Menu\n");
        printf("1- Agregar un elemento\n");
        printf("2- Comprobar si esta llena\n");
        printf("3- Listar elementos\n");
        printf("4- Eliminar un elemento\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\nIngrese valor a agregar\n");
            scanf("%d", &valor);
            enCola(valor);
            break;
        case 2:
            if (colaLlena() == 0)
            {
                printf("\nLa cola esta llena\n");
            }
            else
            {
                printf("\nLa cola no esta llena\n");
            }
            break;
        case 3:
            mostrarCola();
            break;
        case 4:
            eliminar = desenCola();
            break;
        default:
            printf("Opcion incorrecta\n");
        }
    } while (opcion != 0);
    return 0;
}
