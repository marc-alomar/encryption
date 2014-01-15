#include <stdlib.h>
#include <string.h>
#include "keyword_cypher.h"
#include "list.h"

Keyword *create_keyword(char *key)
{
        int i=0, j;
        int length;
        int aux[26] = {0};

/* Create a new Keyword dynamically.The password key passed 
is normalized and associated to k1 */
        
        Keyword *k1 = malloc(sizeof(Keyword));
        
        k1->list = NULL;
        k1->password = normalize(key);

/*Letters contained in the password must be removed afterwards.
Aux array keeps track of the alphabet: index 0 -> 'a', etc. 
Aux[i] = 1 if 'a'+i is contained in the password */
        
        while(k1->password[i] != '\0')
        {
                 aux[(int)k1->password[i]-'a'] = 1;
                 i++;
        }
/* First part of the alphabet: codes the password */       
        length = strlen(k1->password);
        
        for(i=0; i<length; i++)
        {
                 k1->list = add_pair(k1->list, 'a'+i,
                            k1->password[i]);
        }   
        
/* Second part: codes the remaining letters */

        for(i=length, j=0; i<26; i++, j++)
        {
                 while(aux[j] == 1)
                 {
                      j++;
                 }      
                 k1->list = add_pair(k1->list, 'a'+i,
                            'a'+j);
        }        
       
	    return k1;
}

void destroy_keyword(Keyword *key)
{
     destroy_list(key->list);
     free(key->password);
     free(key);
}

char encrypt_char(Keyword *k, char c)
{
     Keyword node; 
     
     if((node.list = find_car(k->list, c)) == NULL)
		 return c;
	 else
    	 return node.list->b;
}

char decrypt_char(Keyword *k, char c)
{
     Keyword node;
     
     if((node.list = find_cdr(k->list, c)) == NULL)
		 return c;
	 else
   	     return node.list->a;
}

char *normalize(char *s1)
{
     int length = strlen(s1);
     int *aux = malloc(length*sizeof(int));
     char *s_norm = malloc((length+1)*sizeof(char));
     int i, j;
     
/* Initialize to zero the aux array. This array keeps 
track of the repeated letters: it has value 1 at 
the position of the repeated letters */
     
     for (i=0; i<length; i++)
     {
         aux[i] = 0;
     }
        
     for(i=0; i<(length-1); i++)
     {
              if(aux[i] == 0)
              {
                  for(j=i+1; j<length; j++)
                  {
                             if(s1[i] == s1[j])
                             {
                                      aux[j] = 1;
                             }
                  }
              }
     } 
/* The characters that correspond to aux = 0 are placed
in the string s_norm. Thus, s_norm doesn't have repeated
values */
     
     j=0;
     
     for(i=0; i<length; i++)
     {
              if(aux[i] == 0)
              {
                          s_norm[j] = s1[i];
                          j++;
              }
     }   
     s_norm[j] = '\0';
     free(aux);
     
     return s_norm;
} 
