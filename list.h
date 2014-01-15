# ifndef __list_h__
# define __list_h__

typedef struct node {
        char a;
        char b;
        struct node *next ;
} Node;

Node *add_pair(Node *l, char x, char y);
/* adds the pair (x,y) in the list l
returns the new list pointer */

void destroy_list(Node *);
/* destroy the list ( free ALL the nodes of the list ) */

Node *find_car(Node *l, char x);
/* finds the first node of the list l
where the first value of the pair is x
returns a pointer to the node or NULL otherwise */

Node *find_cdr(Node *l, char y);
/* finds the first node of the list l
where the second value of the pair is y
returns a pointer to the node or NULL otherwise */

Node *remove_car(Node *l, char x);
/* removes the first node of the list l
where the first value of the pair is x
returns the new list pointer */

Node *remove_cdr(Node *l, char y);
/*removes the first node of the list l
where the second value of the pair is y
returns the new list pointer */

void dump(Node *l);
/* prints the list l (the nodes contents ) */

# endif
