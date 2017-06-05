# Da lista ad array

Dato un tipo lista con i nodi strutturati come segue:
```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
```

Implementare la funzione `list_to_array` con il seguente prototipo:
```c
int* list_to_array(Node* l);
```

Data la lista di interi `l`, la funzione dovrà creare e restituire un array
contenente tutti gli elementi di l, nello stesso ordine.
