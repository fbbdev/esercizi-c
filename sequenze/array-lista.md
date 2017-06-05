# Da array a lista

Dato un tipo lista con i nodi strutturati come segue:
```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
```

Implementare la funzione `array_to_list` con il seguente prototipo:
```c
Node* array_to_list(int a[], size_t n);
```

Dato l'array di interi `a` di lunghezza `n`, la funzione dovrà creare e
restituire una lista contenente tutti gli elementi di a, nello stesso ordine.

## Suggerimenti

Per creare un nodo, dopo aver incluso `stdlib.h` utilizzare le seguenti
istruzioni:
```c
Nodo* n = malloc(sizeof(Nodo));
n->data = /* ... */;
n->next = /* ... */;
n->prev = /* ... */;
```
