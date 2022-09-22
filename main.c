#include <stdio.h>
#include "list.c"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist = list_alloc();
  //Adding to the Front of the List
  list_add_to_front(mylist, 3);
  list_add_to_front(mylist, 9);
  list_add_to_front(mylist, 12);
  list_add_to_front(mylist, 87);
  list_print(mylist);

  //Adding at an Index
  list_add_at_index(mylist, 24, 1);
  list_add_at_index(mylist, 71, 3);
  list_add_at_index(mylist, 0, 0);
  list_print(mylist);


  //Adding to the Back of the List
  list_add_to_back(mylist, 55);
  list_add_to_back(mylist, 10);
  list_add_to_back(mylist, 7);
  list_print(mylist);

  //Removing from the Back of the List
  int value = list_remove_from_back(mylist);
  list_print(mylist);
  printf("The value removed from the list was %d", value);
  printf("\n");

  //Removing from the Front of the List
  int value2 = list_remove_from_front(mylist);
  list_print(mylist);
  printf("The value removed from the list was %d", value2);
  printf("\n");

  //Removing from a Specific Index
  int value3 = list_remove_at_index(mylist, 2);
  list_print(mylist);
  printf("The value removed from the list was %d", value2);
  printf("\n");

  //Checking if a valid integer is in the list
  if(list_is_in(mylist, 87) == true){
    printf("The value 87 is in the list");
  }
  else{
    printf("The value 87 the list");
  }
  printf("\n");

  //Checking if a valid integer is not in the list
  if(list_is_in(mylist, 99) == true){
    printf("The value 99 is in the list");
  }
  else{
    printf("The value 99 is not in the list");
  }
  printf("\n");

  //Getting the Value at an Index
  int value4 = list_get_elem_at(mylist, 4);
  printf("The value at index 4 is %d", value4);
  printf("\n");

  //Finding the Index of which an integer occurs
  int value5 = list_get_index_of(mylist, 55);
  printf("The value 55 is at index %d", value5);
  printf("\n");

  int value6 = list_length(mylist);
  printf("The length of this list is %d", value6);
  printf("\n");
}
