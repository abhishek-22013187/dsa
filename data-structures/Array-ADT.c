#include <stdio.h>
#include <stdlib.h>

#include "../utils/errors.h"

typedef struct{
  int cap;
  int len;
  int *first;
}Array;

Error new_array(Array *arr, int cap) {
    Error err={0};
    arr->cap = cap;
    arr->len = 0;
    arr->first = (int*)calloc(cap, sizeof(int));

    if (arr->first == NULL) {
        err = new_error(12, "Error Creating ADT Array");
    }

    return err;
}

void main(){
  Array arr;
   Error err = new_array(&arr, 10);
   if (err.status){
    log_err(err);
    return;
   }

  return;
}