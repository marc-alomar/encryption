#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Node *add_pair(Node *l, char x, char y)
{
	
/* Create dynamically a new node, and insert data */
      Node *new = malloc(sizeof(Node));
      Node *current_cell;
      
      new->a = x;
      new->b = y;
      new->next = NULL;
      
/* Verify if the list is empty.If it's not,
look for the last element of the list, and 
link it to the new node*/
      if(l == NULL)
      {
          return new;
      }
      else
      {
          current_cell = l;         
          while(current_cell->next != NULL)
          {
                current_cell = current_cell->next;
          }
          
          current_cell->next = new;
            
          return l;
      }
}

void destroy_list(Node *l)
{
/* Go through all the nodes
and free them, until we reach
the last one*/
     Node *aux;
     
     while(l != NULL)
     {
             aux = l->next;
             free(l);
             l = aux;
     }
}

Node *find_car(Node *l, char x)
{
/* Look for a cell with this value, from the
beginning of the list. If we reach the end, 
we exit the function with a NULL pointer.*/
      
      while(l->a != x)
      {
/* This block is only executed if we reach the last 
cell of the list and we have not found a coincidence */

          if(l->next == NULL)
          {
              return NULL;
          }
          l = l->next;
      }
	  
/* This line is executed only if we find a coincidence */
      return l;
}

Node *find_cdr(Node *l, char y)
{
/* Look for a cell with this value, from the
beginning of the list. If we reach the end, 
we exit the function with a NULL pointer.*/
      
      while(l->b != y)
      {
/* This block is only executed if we reach the last 
cell of the list and we have not found a coincidence */

          if(l->next == NULL)
          {
              return NULL;
          }
          l = l->next;
      }
      return l;
}

Node *remove_car(Node *l, char x)
{
     Node *cell = find_car(l, x);

/* If the node is not in the list, we exit 
the function, and return l */

    if(cell != NULL)
    {
/* If the cell is the first of the list, we have to follow a 
different procedure */

         if(cell != l)
         {
             Node *previous = l;
        
/* Find the cell previous to the one
we want to delete */
             
             while(previous->next != cell)
             {
                 previous = previous->next;
             }
/* Link the previous cell to the following one,
and delete the cell */   
       
             previous->next = cell->next;
             
             free(cell);
             
             return l;
         }
         else

         {
/* Executed only if the node is the first
The pointer returned corresponds to the second element
of the list */
             l = l->next;
             free(cell);
             return l;
         }
    }
    else
    {
/* Executed only if we don't find
the character in the list */
        return l;
    }
}

Node *remove_cdr(Node *l, char y)
{
     Node *cell = find_cdr(l, y);

/* If the node is not in the list, we exit 
the function, and return l */

    if(cell != NULL)
    {
/* If the cell is the first of the list, we have to follow a 
different procedure */

         if(cell != l)
         {
             Node *previous = l;
        
/* Find the cell previous to the one
we want to delete */
             
             while(previous->next != cell)
             {
                 previous = previous->next;
             }
/* Link the previous cell to the following one,
and delete the cell */   
       
             previous->next = cell->next;
             
             free(cell);
             
             return l;
         }
         else
         {
/* The pointer returned corresponds to the second element
of the list */
             l = l->next;
             free(cell);
             return l;
         }
    }
    else
    {
        return l;
    }
}
   
void dump(Node *l)
{
/* Go through all the nodes and print its contents */
     while(l != NULL)
     {
             printf("%c   %c\n", l->a, l->b);
             l = l->next;
     }   
}
