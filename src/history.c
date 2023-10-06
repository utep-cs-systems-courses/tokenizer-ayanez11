#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "history.h"

List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *item = (Item*)malloc(sizeof(Item));
  item->str = str;
  Item *temp = list->root;
  if(list->root == NULL) {
    item->id = 1;
    list->root = item;
  }
  else{
    while(temp->next != NULL){ 
     temp = temp->next;
    }
    item->id = temp->id + 1;
    temp->next = item;
  }
}

char *get_history(List *list, int id){
  char *p = "empty";
  Item *temp = list->root;
  if(list->root == NULL) {
    return p;
  }
  else{
    while(temp->next != NULL && temp->id != id)
      temp = temp->next;
  }
  if(temp->id == id)
    return temp->str;
  else
    return p;
}

void print_history(List *list){
  int i = 0;
  Item *temp = list->root;
  while(temp != NULL){
    printf("%d. %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list){
  Item *temp;
  List *l = list;
  while(list->root != NULL) {
    temp = list->root->next;
    free(list->root->str);
    free(list->root);
    list->root = temp;
  }
  free(l);
}
