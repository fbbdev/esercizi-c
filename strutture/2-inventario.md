# Inventario - Seconda parte

A partire dal sistema di inventario sviluppato nell'esercizio precedente,
si vuole sviluppare un sistema di gestione delle vendite.

Definiamo la seguente struttura:
```c
typedef struct Order {
    Fruit object;
    size_t count;
    float max_unit_price;
} Order;
```
Questa struttura rappresenta *l'ordine* di un cliente per il fruttivendolo:
il campo `object` rappresenta il frutto desiderato (arancia, mela, pera, pesca);
il tipo `Fruit` sarà stato definito adeguatamente nell'esercizio precedente.
Il campo `count` rappresenta il numero di frutti desiderato; il campo `max_unit_price`
rappresenta il massimo prezzo che il cliente è disposto a pagare per ogni singolo frutto.

Si deve scrivere una funzione `handle_order` con il seguente prototipo:
```c
Action* handle_order(Stock s, Order o);
```
Dove `s` è l'inventario (si sostituisca `Stock` con il tipo definito nell'esercizio
precedente per rappresentare l'inventario), `o` è un ordine da evadere. La funzione
deve restituire una lista di azioni da compiere per soddisfare l'ordine, così composta:
```c
typedef struct Action {
    size_t box;
    size_t count;
    struct Action* next_action;
} Action;
```
Il campo `box` è l'indice di una cassetta nell'inventario da cui prelevare la frutta;
il campo `count` è il numero di frutti da prelevare dalla cassetta; il campo `next_action`
è un puntatore all'azione successiva, o `NULL` se questa è l'ultima.

Il fruttivendolo vuole soddisfare, se possibile, le richieste del cliente, ma vuole anche massimizzare
i guadagni. Perciò, se il cliente desiderasse 10 mele ad un massimo di 1€ l'una, e l'inventario
fosse così composto:
  - cassetta di 10 mele a 0,50€ l'una
  - cassetta di 4 mele a 0,80€ l'una
  - cassetta di 8 mele a 1,20€ l'una

Il fruttivendolo preleverà 4 mele dalla seconda cassetta e 6 mele dalla prima. La terza è esclusa perché
eccede il tetto di spesa del cliente. Pertanto la lista di azioni sarà:
```c
(box = 1, count = 4) -> (box = 0, count = 6) -> NULL
```

Se l'ordine non può essere evaso (non ci sono abbastanza frutti del tipo desiderato, o non è possibile
rispettare il tetto di spesa) la funzione deve restituire una lista vuota (`NULL`);
