// list/list.c
//
// Implementation for linked list.
//
// <Author> Darryle Mensah

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {
  list_t* list = (list_t* )malloc (sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_free(list_t *l) {
  while(l->head != NULL) {
    node_t* temp = l->head;
    l->head = l->head->next;
    free(temp);
  }
}

void node_free(node_t *n){
  free(n);
}

void list_print(list_t *l){
  node_t* cur = l->head;
  while(cur != NULL){
    printf("%d ", cur->value);
    cur = cur->next;
  }
  printf("\n");
}

int list_length(list_t *l){
  int count = 0;
  node_t* cur = l->head;
  while(cur != NULL){
    count++;
    cur = cur->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value){
  node_t* cur = l->head;
  while(cur->next != NULL){
    cur = cur->next;
  }
  node_t* new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  cur->next = new_node;
}

void list_add_to_front(list_t *l, elem value){
  node_t* cur = malloc(sizeof(node_t));
  cur->value = value;
  cur->next = l->head;
  l->head = cur;
}

void list_add_at_index(list_t *l, elem value, int index){
  int length = list_length(l);
  if(index == 0){
    list_add_to_front(l, value);
  }
  else if(index == length-1){
    list_add_to_back(l, value);
  }

  else if(index < length){
    node_t* cur = l->head->next;
    node_t* prev = l->head;
    int count = 1;
    while(count != index){
      count++;
      prev = cur;
      cur = cur->next;
    }
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = cur;
    prev->next = new_node;
  }
}

elem list_remove_from_back(list_t *l){
  if(l->head != NULL){
    node_t* cur = l->head->next;
    node_t* prev = l->head;
    int value;
    while(cur->next != NULL){
      prev = cur;
      cur = cur->next;
    value = cur->value;
    }
    node_free(cur);
    prev->next = NULL;
    return value;
  }
}

elem list_remove_from_front(list_t *l){
  if(l->head != NULL){
    node_t* cur = l->head->next;
    node_t* prev = l->head;
    int value = l->head->value;
    l->head = cur;
    node_free(prev);
    return value;
  }
}

elem list_remove_at_index(list_t *l, int index){
  int length = list_length(l);
  if(index == 0){
    list_remove_from_front(l);
  }
  else if(index == length-1){
    list_remove_from_back(l);
  }
  else if(index < length){
    node_t* cur = l->head->next;
    node_t* prev = l->head;
    int count = 1;
    while(count != index){
      count++;
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
    int value = cur->value;
    node_free(cur);
    return value;
  }
}

bool list_is_in(list_t *l, elem value){
  node_t* cur = l->head;
  while(cur != NULL){
    if(cur->value == value){
      return true;
    }
    cur = cur->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index){
  node_t* cur = l->head;
  int length = list_length(l);
  if(index < length){
    int count = 0;
    while(true){
      if(count == index){
        return cur->value;
      }
      count++;
      cur = cur->next;
    }
  }
  return -1;
}

int list_get_index_of(list_t *l, elem value){
  node_t* cur = l->head;
  int index = 0;
  while(cur != NULL){
    if(cur->value == value){
      return index;
    }
    index++;
    cur = cur->next;
  }
  return -1;
}
