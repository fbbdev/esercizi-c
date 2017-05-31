#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Film;

typedef struct Result {
    struct Film*   film;
    struct Result* next;
} Result;

typedef struct Result* Search;

typedef struct Genre {
    char          name[32];
    Search        films;
    struct Genre* next;
} Genre;

typedef enum Stars {
    Zero       = 0,
    OneStar    = 1,
    TwoStars   = 2,
    ThreeStars = 3,
    FourStars  = 4,
    FiveStars  = 5
} Stars;

typedef struct Film {
    char   title[128];
    char   director[64];
    char   producer[64];
    Genre* genre;
    char   description[256];
    Stars  rating;
} Film;

typedef struct DBEntry {
    Film film;
    struct DBEntry* next;
} DBEntry;

typedef struct MDB {
    Genre*   genres;
    DBEntry* entries;
} MDB;

typedef struct SearchFields {
    bool title : 1;
    bool director : 1;
    bool producer : 1;
    bool genre : 1;
    bool description : 1;
} SearchFields;


// Search helpers

static bool query_match(Film* film, char const* query, SearchFields fields) {
    return (fields.title && strcasestr(film->title, query)) ||
           (fields.director && strcasestr(film->director, query)) ||
           (fields.producer && strcasestr(film->producer, query)) ||
           (fields.genre && film->genre && strcasestr(film->genre->name, query)) ||
           (fields.description && strcasestr(film->description, query));
}


// Result list methods

Search search_create() {
    return NULL;
}

bool search_empty(Search s) {
    return !s;
}

size_t search_size(Search s) {
    size_t count = 0;

    for (Result* it = s; it; it = it->next)
        ++count;

    return count;
}

Search search_extend(Search s, Film* f) {
    Result* r = malloc(sizeof(Result));

    r->film = f;
    r->next = s;

    return r;
}

Search search_join(Search s, Search o) {
    if (!s)
        return o;

    Result* last = s;
    while (last->next)
        last = last->next;

    last->next = o;

    return s;
}

Search search_intersect(Search s, Search o) {
    if (!s || !o)
        return NULL;

    Search result = search_create();

    for (Result *it = s, *next = NULL; it; it = next) {
        next = it->next;

        for (Result* it_o = o; it_o; it_o = it_o->next) {
            if (it_o->film == it->film) {
                it->next = result;
                result = it;
            } else {
                free(it);
            }
        }
    }

    return result;
}

Search search_filter(Search s, char const* query, SearchFields fields) {
    Search result = search_create();

    for (Result *it = s, *next = NULL; it; it = next) {
        next = it->next;
        
        if (query_match(it->film, query, fields)) {
            it->next = result;
            result = it;
        } else {
            free(it);
        }
    }

    return result;
}


// MDB methods

MDB mdb_create() {
    MDB db = { NULL, NULL };
    return db;
}

MDB mdb_register_genre(MDB db, char const* name) {
    Genre* g = malloc(sizeof(Genre));

    strncpy(g->name, name, 32);
    g->name[31] = '\0';

    g->films = search_create();

    g->next = db.genres;
    db.genres = g;
    
    return db;
}

Genre* mdb_genre(MDB db, char const* name) {
    for (Genre* it = db.genres; it; it = it->next)
        if (!strcmp(it->name, name))
            return it;

    return NULL;
}

size_t mdb_size(MDB db) {
    size_t count = 0;

    for (DBEntry* it = db.entries; it; it = it->next)
        ++count;

    return count;
}

MDB mdb_register_film(MDB db, Film f) {
    DBEntry* e = malloc(sizeof(DBEntry));

    e->film = f;

    if (f.genre)
        f.genre.films = search_extend(f.genre.films, &e->film);

    e->next = db.entries;
    db.entries = e;

    return db;
}

Search mdb_search(MDB db, char const* query, SearchFields fields) {
    Search result = search_create();

    for (DBEntry* it = db.entries; it; it = it->next)
        if (query_match(&it->film, query, fields))
            result = search_extend(result, &it->film);
}

