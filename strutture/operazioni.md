# Operazioni

Data la seguente enumerazione:
```c
typedef enum Operator {
    Add, // +
    Sub, // -
    Mul, // *
    Div  // /
} Operator;
```

E la seguente struttura:
```c
typedef struct Operation {
    Operator operator;
    float rhs;
} Operation;
```

Implementare la funzione `run_ops` con il seguente prototipo:
```c
float run_ops(float lhs, Operation ops[], size_t n);
```

La funzione dovrà, per ogni elemento dell'array `ops` (costituito da `n` elementi), svolgere
l'operazione, indicata dal campo `operator`, fra il risultato dell'operazione precedente e
il valore del campo `rhs`. Per il primo elemento non c'è un risultato precedente,
perciò si deve operare sul valore dell'argomento `lhs` della funzione.

Ad esempio, se la sequenza in `ops` fosse:
```c
{
    { Add, 10 },
    { Mul,  4 },
    { Sub,  8 },
    { Div,  3 }
}
```
Il risultato dovrebbe essere calcolato così:
```c
(((lhs + 10) * 4) - 8) / 3
```
Perciò, con `lhs` uguale - per esempio - a `2`, il risultato sarebbe `13.333333`:
```c
2 + 10 -> 12
12 * 4 -> 48
48 - 8 -> 40
40 / 3 -> 13.333333
```
