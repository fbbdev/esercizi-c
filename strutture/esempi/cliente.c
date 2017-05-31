#include <stdint.h>

typedef struct Indirizzo {
    char* localita;
    char* specifica;
    char  cap[6];
    char* citta[10];
    char  provincia[3];
} Indirizzo;

typedef enum Circuito {
    AmericanExpress,
    MasterCard,
    Visa
} Circuito;

typedef struct Scadenza {
    int mese;
    int anno;
} Scadenza;

typedef struct Carta {
    Circuito circuito;
    char     numero[16];
    Scadenza scadenza;
    uint16_t cvv;
} Carta;

typedef struct Cliente {
    char*     nome;
    char*     cognome;
    Indirizzo indirizzo;
    Carta     carta_di_credito;
} Cliente;

Cliente c = {
    "Giuseppe", "Verdi",
    { "Via Antonio Vivaldi, 7", "", "00156", "Roma", "RM" },
    { MasterCard, "0542" "1202" "0471" "6264", { 4, 2019 }, 587 }
};

// Valore di
//     c.cognome
//     c.indirizzo.cap
//     c.carta_di_credito.scadenza.mese
//     c.carta_di_credito.numero[6]

