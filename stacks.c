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
        printf("Pushed an item to top of the stack\n");
    }

    void pop(Stack* stack){
        if (is_empty(stack))
        return;

        stack -> top--;
        printf("Removed item from top of the stack\n");
    }

    int peek(Stack* stack){
        if (is_empty(stack))
        return -1;

        return stack -> array[stack -> top];
    }


    int main(){
        printf("\n");

        Stack* stack = create_stack(5);
        printf("%d\n",is_empty(stack));
        printf("%d\n",is_full(stack));

        push(stack,5);
        push(stack,2);
        push(stack,4);
        push(stack,8);
        push(stack, 12);

        printf("%d\n",is_full(stack));


        printf("%d\n",peek(stack));

        printf("%d\n",is_full(stack));

        pop(stack);

        printf("%d\n",is_full(stack));

        printf("\n");
        return 0;
    }