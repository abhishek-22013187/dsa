#include <stdio.h>

int fact(int n){
  if (1==n){
    return 1;
  }else if(1>n){
    return 0;
  }
 return( n*fact(n-1));
}

int fibonacci(int n) {
   
    if (0 == n)
        return 0;
    else if (1 == n)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
  int product = fact(4);
  printf("\n%d\n",product);

  for (int i = 0; i < 12; ++i) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");
  return 0;
}

