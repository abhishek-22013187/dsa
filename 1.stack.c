#include <stdio.h>
    #include <stdlib.h>
    
    typedef struct Stack{
        int top;
        int size;
        int* array;
    } Stack;

    Stack* create_stack(int size){
        Stack* new_stack = malloc(sizeof(Stack));
        new_stack -> size = size;
        new_stack -> top = -1;
        new_stack -> array = malloc(new_stack -> size * sizeof(int));

        return new_stack;
    }

    int is_full(Stack* stack){
        return stack -> top == stack -> size - 1;
    }

    int is_empty(Stack* stack){
        return stack -> top == -1;
    }

    void push(Stack* stack, int item){
        if (is_full(stack)) 
            return;
        stack -> array[++stack -> top] = item;
    }

    int pop(Stack* stack){
        if (is_empty(stack))
        return -1;

        return stack -> array[stack -> top--];
    }

    int peek(Stack* stack){
        if (is_empty(stack))
        return -1;

        return stack -> array[stack -> top];
    }


    int main(){
        printf("\n");

        Stack* stack = create_stack(4);
        push(stack,1);

        printf("Original Order: %d\t",peek(stack));
        push(stack,2);
        printf("%d\t",peek(stack));
        push(stack,3);
        printf("%d\t",peek(stack));
        push(stack,4);
        printf("%d\t",peek(stack));

        printf("\nReversed Order: ");
        for (int i = 0; i < 4;i++){
            int num = pop(stack);
            printf("%d\t",num);
        }

        printf("\n");
        return 0;
    }