# Inventario

Si vuole scrivere un programma per gestire l'inventario di un fruttivendolo.

Il commerciante tratta *quattro tipi di frutta*: **arance**, **mele**, **pere** e **pesche**.

Riceve e conserva la frutta in *cassette*. Ogni cassetta contiene **un certo numero** di frutti **di un solo tipo**,
e poiché provengono da diversi fornitori ogni cassetta potrebbe avere un **prezzo unitario** (€/frutto) diverso.

Bisogna:
  1. Modellare una struttura di dati capace di rappresentare l'inventario del fruttivendolo.
  2. Implementare le seguenti funzioni:
      - `box_value`: data una cassetta, calcolarne il valore totale (se fosse venduta intera).
      - `stock_boxes`: dato l'inventario e un tipo di frutta, restituire il numero di cassette contenenti quel tipo di frutta.
      - `stock_value`: dato l'inventario e un tipo di frutta, restituire il valore totale delle cassette contenenti quel tipo
                       di frutta.
      - `stock_total_value`: dato l'inventario, calcolare il valore totale della merce disponibile.
