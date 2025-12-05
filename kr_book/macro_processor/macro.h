/* macro.h
 * header for #define processor program */

#ifndef MACRO_H
#define MACRO_H

// struct nlist: table entry
struct nlist {
    struct nlist *next; // next entry in chain
    char *name;         // define name
    char *defn;         // replacement text
};

// macro.c: hash table operations
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
void print_hashtab(void);

// getword.c: get word or character from input
int getword(char *, int);

#endif
