#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

int main()
{
  int exit = 1;
  List *list = init_history();
  do{
    printf("Make your selection\n 1. Tokenize 2. Print History 3. Get History 4. Quit (Enter 1, 2, 3 or 4)\n");
    char sel[10];
    printf("> ");
    fgets(sel, 10, stdin);
    char *end;
    int x = strtol(sel, &end, 10);
    switch(x){
      case 1:{
	char *tokens = (char*)malloc(30*sizeof(char));
	printf("> ");
	fgets(tokens, 30, stdin);
	char **t = tokenize(tokens);
	add_history(list, tokens);
	print_tokens(t);
	free_tokens(t);
      }	break;
      case 2:
	print_history(list);
	break;
      case 3:{
	char id[10];
	printf("Enter ID:\n> ");
	fgets(id, 10, stdin);
        int i = strtol(id, &end, 10);
	char *h = get_history(list, i);
	printf("%d. %s\n", i, h);
      }	break;
      case 4:
	exit = 0;
	break;
    default:
        break;
    }
    
  }while(exit);
  free_history;
  return 0;
}
