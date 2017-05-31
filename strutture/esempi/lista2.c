#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SomeStruct {
    char* text;
    struct SomeStruct* next;
} SomeStruct;

size_t length(SomeStruct* l) {
    size_t len = l ? strlen(l->text) : 0;

    for (SomeStruct* it = l ? l->next : NULL; it; it = it->next)
        len += 1 + strlen(it->text);

    return len;
}

char* join(SomeStruct* l) {
    size_t size = length(l) + 1;
    char* str = calloc(size, sizeof(char));

    memset(str, 0, size);

    char* str_it = str;

    if (l)
        str_it = strchr(strcpy(str_it, l->text), '\0');

    for (SomeStruct* it = l ? l->next : NULL; it; it = it->next) {
        *str_it++ = ' ';
        str_it = strchr(strcpy(str_it, it->text), '\0');
    }

    return str;
}

int main() {
    SomeStruct s[] = {
        { "Ciao", &s[2] },
        { "pensi", &s[4] },
        { "come", &s[1] },
        { "oggi?", NULL },
        { "di", &s[5] },
        { "stare", &s[3] }
    };
    
    printf("%s\n", join(s));

    return 0;
}

