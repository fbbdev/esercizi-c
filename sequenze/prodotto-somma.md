# Prodotto-somma

Data la seguente struttura:
```c
typedef struct IntTriple {
    int n1;
    int n2;
    int n3;
} IntTriple;
```

Implementare la funzione `multiply_add` con il seguente prototipo:
```c
int* multiply_add(IntTriple a[], size_t n);
```

Dato l'array `a` di `IntTriple`, di lunghezza `n`, la funzione dovrà
creare e restituire un array di interi contenente, per ogni elemento `e`
di `a`, il risultato dell'espressione `e.n1 * e.n2 + e.n3`.

Ad esempio dato il seguente array di `IntTriple`:
```c
{
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 3, 7, 15 }
}
```

Il risultato sarà:
```c
{ 5, 26, 36 }
```
