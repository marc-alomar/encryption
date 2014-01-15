#ifndef __keyword_cypher_h__
#define __keyword_cypher_h__
#include "list.h"

typedef struct {
        Node *list;
        char *password;
} Keyword;

Keyword *create_keyword(char *key);
/* Creates a new Keyword cypher with the given key
It normalizes the password and 
creates the list of pairs storing the alphabets
returns a pointer to the created structure */

void destroy_keyword(Keyword *);
/*Frees all the memory of the pointed structure */

char encrypt_char(Keyword *k, char c);
/*Returns the encrypted char associated to c*/

char decrypt_char(Keyword *k, char c);
/*Returns the decrypted char associated to c*/

char *normalize(char *s1);
/*Auxiliary function: Given a pointer to a string, s1,
it gives another pointer to a string without repeated
letters */

#endif
