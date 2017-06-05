# Range (array)

Definita la seguente struttura:
```c
typedef struct IntArray {
    int* array;
    size_t len;
} IntArray;
```

Implementare la funzione `range` con il seguente prototipo:
```c
IntArray range(int i, int j, int k);
```

La funzione dovrà creare un array di interi composto dagli elementi della
progressione aritmetica generata dai tre interi `(i, j, k)`, e cioè:

  - Con `k > 0`:

        i, i+k, i+2k, ... , i+tk

    dove `t` è il massimo intero per cui `i+tk < j`. Ad esempio,
    con `i = 1, j = 8, k = 2`, la progressione sarà `[1, 3, 5, 7]`.

  - Con `k < 0`:

        i, i+k, i+2k, ... , i+tk

    dove `t` è il massimo intero per cui `i+tk > j`. Ad esempio,
    con `i = 8, j = 1, k = -2`, la progressione sarà `[8, 6, 4, 2]`.

  - Con `k = 0`, la progressione è vuota.

La funzione dovrà restituire un valore di tipo `IntArray`, con il campo `array`
uguale al puntatore al primo elemento dell'array da restituire, e il campo
`len` uguale alla lunghezza dell'array restituito.
