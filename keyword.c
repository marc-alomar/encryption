#include "list.h"
#include "keyword_cypher.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Function prototypes:

	interface -> executes the desired option. Takes a pointer to a function, 
				 in order to use the same scheme to encrypt and decrypt. Reads
	 			 also the input/output mode
				 
				 Execution is finished when program reaches EOF character (Ctrl+D 
				 for stdin)

	openfile -> opens a file with the given name and mode (r or w). Returns a 
				pointer to FILE. If there is an error, exits the program and 
				warns the user

	help -> contains the documentation of this program */


void interface(FILE *in_stream, FILE *out_stream, char (*mode) (Keyword *, char));
FILE* openfile(char *name, char *mode);
void help(void);

int main(int argc, char **argv)
{
	char c;
	FILE *f_in, *f_out;
	
/* Use getopt to read the options given on the command line.
   Possible options: -h, -e, -d
   As getopt can only read one argument associated to each option,
   we still use argv to save the name of the files given on the command line */
	
	if((c = getopt (argc, argv, "hed")) != -1)
	{
		
/* Open files only if we write their names */
		
		if(argc == 4)
		{
		 	f_in = openfile(argv[2], "r");
		 	f_out = openfile(argv[3], "w");
		}
		
/* Option loop: consider all the possible cases 
according to the option given */
		switch (c)
		{
			case 'h':
				help();
				break;
				
			case 'e':
				if(argc == 4)		 
   				 	interface(f_in, f_out, encrypt_char);
				else if(argc == 2)
						 interface(stdin, stdout, encrypt_char);
					 else
						 help();
				break;
				
			case 'd':
				if(argc == 4)
					interface(f_in, f_out, decrypt_char);
				else if(argc == 2)
						interface(stdin, stdout, decrypt_char);
					else
						help();
				break;
				
			default:
				help();
				break;
		
		}
	}
	else
		help();
         
    return 0;
}

void help(void)
{
     printf("keyword [-e|-d|-h] <input> <output>\n"
     		"Mandatory:\n"
     	   	"\t-e : encrypt\n\t-d : decrypt\n\t-h : help\n"
     		"Optional:\n"
     	   	"\tinput : text file to read (default stdin)\n"
     	    "\toutput: text file to write(default stdout)\n");
}

void interface(FILE *in_stream, FILE *out_stream, char (*mode) (Keyword *, char))
{
     Keyword *key;
     char pwd[27], *p, c;

/* Asks for the password, using fgets to avoid
overflow problems (max size: 27) */
     
     printf("Password: ");
     fgets(pwd, 27, stdin);

/* fgets saves the character '\n'. strchr
searchs for the first occurrence of '\n' 
and replaces it with '\0' */

     if((p = strchr(pwd,'\n')) != NULL)
         *p = '\0';
     
     key = create_keyword(pwd);
	 
/* Prints characters one by one. We pass to fprintf 
the dereferenced pointer to a function: encrypt, or decrypt */

     while((c = getc(in_stream)) != EOF)
     {       
           	fprintf(out_stream, "%c", (*mode)(key, c));
     }

}

FILE* openfile(char *name, char *mode)
{
	FILE *p_file;
	
    if((p_file = fopen(name, mode)) == NULL)
	{
		printf("Error opening file %s\n", name);
		exit(EXIT_FAILURE);
	}
	else
		return p_file;    
}


