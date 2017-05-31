typedef struct SomeStruct {
    char* text;
    struct SomeStruct* next;
} SomeStruct;

SomeStruct s[] = {
    { "Ciao", &s[2] },
    { "pensi", &s[4] },
    { "come", &s[1] },
    { "oggi?", NULL },
    { "di", &s[5] },
    { "stare", &s[3] }
};

// Valore di s?
