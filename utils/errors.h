typedef struct{
  int status;
  const char *message;
} Error;
Error new_error(int status,const char *message);
void log_err(Error err);