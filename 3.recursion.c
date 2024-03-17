#include <stdio.h>

int iterative_sum(int n){
  int sum = 0;
  for(int i = 1; i <= n; i++){
    sum += i;
  }
  return sum;
}

int recursive_sum(int n) {
    if (n <= 0) {
      return 0;
    } 
    return n + recursive_sum(n - 1);
}

int main(){
  printf("****************************\n");

  printf("Iterative Sum: %d\n",iterative_sum(10));

  printf("Recursive Sum: %d\n",recursive_sum(10));
  printf("****************************\n");
  return 0;
}