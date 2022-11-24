#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10000
#define EMPTY 0

struct queue
{
    int datos[MAX];
    int frente;
    int ultimo;
    int tam;
};

int dequeue(struct queue *q);
void enqueue(struct queue *q, int dato);
bool is_empty(const struct queue *q);
bool is_full(const struct queue *q);
int next(int indice);
int size(const struct queue *q);
void clear(struct queue *q);
int front(const struct queue *q);
void prueba_cola(int n, struct queue *q);

int main()
{
    struct queue q;
    clear(&q);
    int n;
    printf("Tam de la cola: ");
    scanf("%d", &n);
    prueba_cola(n, &q);
    return 0;
}
void prueba_cola(int n, struct queue *q)
{
    int x;

    printf("nums a meter: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(q, x);
    }
    puts("");

    printf("Datos: ");
    for (int i = 0; i < q->tam; i++)
    {
        printf("%d ", q->datos[i]);
    }
    printf("\n");

    printf("Cant a sacar: ");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int num = dequeue(q);
    }

    printf("Datos: ");
    for (int i = q->frente; i < q->ultimo; i++)
    {
        printf("%d ", q->datos[i]);
    }
}

int dequeue(struct queue *q)
{
    if (!is_empty(q))
    {
        int valor = q->datos[q->frente];
        (q->frente)++;
        q->tam = q->tam - 1;
        return valor;
    }
    return 0;
}

void enqueue(struct queue *q, int dato)
{
    if (!is_full(q))
    {
        q->datos[q->ultimo] = dato;
        q->ultimo = next(q->ultimo);
        q->tam = q->tam + 1;
    }
}

bool is_empty(const struct queue *q)
{
    return q->tam <= 0;
}

bool is_full(const struct queue *q)
{
    return q->tam >= MAX;
}

int next(int indice){
    return(indice+1)%MAX;
}

int tam(const struct queue *q){
    return (q->tam);
}

void clear(struct queue *q){
    q->frente=0;
    q->ultimo=0;
    q->tam=0;
}
