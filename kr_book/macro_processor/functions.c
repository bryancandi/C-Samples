/* Table lookup functions for a #define macro processor program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {          // table entry
    struct nlist *next; // next entry in chain
    char *name;         // define name
    char *defn;         // replacement text
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; // pointer to table

// hash: form hash value for string (unsigned ensures non-negative value)
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

// lookup: look for s in hashtab
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
        {
            return np; // found
        }
    }
    return NULL; // not found
}

// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) // not found
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
        {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else // already there
    {
        free((void *) np->defn); // free previous defn
    }
    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

// Exercise 6-5
// undef: remove node from hashtab
void undef(char *name)
{
    struct nlist *np;
    struct nlist *nprev = NULL;
    unsigned hashval = hash(name); // hash index of node to remove

    // loop through each node in the linked list in hashtab at the hashval index
    // nprev tracks the previous node; advance it as np moves forward
    for (np = hashtab[hashval]; np != NULL; nprev = np, np = np->next)
    {
        // found matching name: unlink node
        if (strcmp(name, np->name) == 0) // match
        {
            if (nprev == NULL) // node to remove is the first node in the list (list head)
            {
                // removed head: advance list head to next node
                hashtab[hashval] = np->next; // remove first node
            }
            else
            {
                // remove current node np by skipping over it
                nprev->next = np->next; // unlink
            }
            // free storage for the removed/unlinked node
            free(np->name);
            free(np->defn);
            free(np);
            return;
        }
    }
}
