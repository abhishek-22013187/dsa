#include<stdio.h>

typedef struct{
  int status;
  const char *message;
} Error;

Error new_error(int status,const char *message) {
    Error err;
    err.status = status;
    err.message = message;
    return err;
}

void log_err(Error err) {
  printf("%d - An Error Occured!\n%s\n", err.status, err.message);
}
