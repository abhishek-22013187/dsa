#include <stdio.h>
#include <stdlib.h>


typedef struct Queue{
  int front;
  int rear;
  int size;
  int * array;
  int count;
} Queue;


Queue* create_queue(int size){
    Queue* new_queue = malloc(sizeof(Queue));

    new_queue -> size = size;
    new_queue -> rear = -1;
    new_queue -> front = -1;
    new_queue -> array = malloc(new_queue -> size * sizeof(int));

    return new_queue;
}
int is_empty(Queue* queue){
  return (queue -> front == -1 );
}

int is_full(Queue* queue){
  return (queue -> rear == queue -> size -1);
}

void enqueue(Queue* queue, int value){
  if(is_full(queue)){
    printf("Queue is full\n");
    exit;
  }
  queue -> array[ ++queue -> rear]= value;
}

int dequeue(Queue* queue) {  
    if (is_empty(queue)) {  
        printf("Queue is empty\n");  
        exit;  
    }  
    int element = queue -> array[queue -> front];
    queue -> front++;  
    return element;  
}  

int peek(Queue* queue) {  
    if (is_empty(queue)) {  
        printf("Queue is empty\n");  
        exit;  
    }  
    return queue -> array[queue -> front];
}  

void print_queue(Queue* queue){
  if (is_empty(queue)) {
    printf("Queue is empty\n");
    exit;
  }
  
  for (int i = 0; i <= queue ->rear; i++){
   printf("%d\t", queue -> array[i]);
   }
}

int main(){
  Queue* queue= create_queue(5);
  dequeue(queue);
  enqueue(queue,1);
  enqueue(queue,2);
  enqueue(queue,3);
  enqueue(queue,4);
  enqueue(queue,5);
  enqueue(queue,6);
  print_queue(queue);
  return 0; 
}