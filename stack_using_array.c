/* Implement a program for stack that performs following operations using array. (a) PUSH
(b) POP (c) PEEP (d) CHANGE (e) DISPLAY */


# include<stdio.h> 
# include<stdlib.h>  
# include<conio.h>  

# define N 5

void push(int *stack, int *top);
int pop(int *stack, int *top);
int peep(int *stack, int *top, int position);
void change(int *stack, int *top, int position, int data);
void display(int *stack, int *top);

int main()
{
   
    int top = -1, data, input, position;
    int *stack = (int *)malloc(N * sizeof(int)); // Dynamic Memory allocation using malloc() 
    

    while(1)
    {
        printf("\nEnter stack operator : \n 1 -> push \n 2 -> pop \n 3 -> peek \n 4 -> Change \n 5 -> Display \n 6 -> Exit");
        printf("\nEnter input : ");
        scanf("%d", &input);

        switch(input)
        {
            // push operation
            case 1:
            {
                push(stack, &top);
                getch();
                break;
            }

            // Pop Operation
            case 2:
            {
                int p = pop(stack, &top);
                if(p != -1)
                {
                    printf("Popped element : %d\n", p);
                    getch();
                }
                break;
            }

            // Peep Operation
            case 3:
            {
                printf("Enter position for viewing data :");
                scanf("%d", &position);
                int p1 = peep(stack, &top, position);
                if(position <= 0 || position > top + 1)
                {
                    printf("\nNot a valid position\n");
                    getch();
                }
                else if(p1 != -1)
                {
                    printf("Value at position %d is : %d\n", position, peep(stack, &top, position));
                    getch();
                }
                break;
            }

            // Change Operation
            case 4:
            {
                printf("\nEnter position for changing data :");
                scanf("%d", &position);
                printf("\nEnter Data :");
                scanf("%d", &data);
                if(position <= 0 || position > top)
                {
                    printf("\nNot a valid position\n");
                }
                change(stack, &top, position, data);
                getch();
                break;
            }
            
            // Display Operation
            case 5:
            {
                printf("\nThe Stack is :\n");
                display(stack, &top);
                getch();
                break;
            }

            // Exit Operation
            case 6:
            {
                return 0;
            }

            // Default case
            default:
            {
                printf("\nInvalid Stack Operation !\n");
                getch();
                break;
            }
        }

    }
    return 0;
}

// Push
void push(int *stack, int *top)
{
    int data;
    while(1)
    {
        if(*top == N - 1)
        {
            printf("\nStack Overflow !\n");
            return;
        }
        *top = *top + 1;
        printf("\nPush data :");
        scanf("%d", &data);
        stack[*top] = data;
    }
}

// Pop
int pop(int *stack, int *top)
{
    if(*top == -1)
    {
        printf("\nStack Underflow ! Cannot pop element\n");
        // getchar();
        return -1;
    }
    int data = stack[*top];
    *top = *top - 1;
    return data;
}

// Peep
int peep(int *stack, int *top, int position)
{
    if(*top - position + 1 < 0)
    {
        printf("\nStack Underflow for peep Operation ! \n");
        return -1;
    }
    return stack[*top - position + 1];
}

// Change
void change(int *stack, int *top, int position, int data)
{
    if(*top - position + 1 < 0)
    {
        printf("\nStack Underflow for change Operation ! \n");
    }
    stack[*top - position + 1] = data;
}

// Display
void display(int *stack, int *top)
{
    if(*top == -1)
    {
        printf("\nStack Underflow !\n");
        return;
    }
    for(int i = *top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}