// Name : Meet P Jariwala
// Enrollment number : ET22BTCO046

/* Write a program to convert infix notation to postfix notation using stack */

# include<stdio.h> 
# include<stdlib.h>
# include<string.h>

# define SIZE 50

// Function Declarations
void push(char *stack, int *top, char next);
char pop(char *stack, int *top);
int g(char next);
int f(char next);
int r(char next);

int main()
{
    printf("\nCode prepared by -> Meet Jariwala -> ET22BTCO046\n");

    char stack[SIZE], infix[SIZE], polish[SIZE], temp[2], next;
    int t, *top = &t, i = 0, rank, l;

    // Step 1
    *top = -1;
    *top = *top + 1;
    stack[*top] = '('; 

    // Step 2
    strcpy(polish, " ");
    rank = 0;

    printf("\nEnter infix expression padded with ')' : ");
    scanf("%s", infix);
    l = strlen(infix);

    if(infix[l - 1] != ')')
    {
        printf("\nInvalid Infix Expression\n");
        exit(0);
    }

    // Step 3
    next = infix[i];

    // Step 4
    while(next != '\0')
    {
        // Step 5
        if(*top < 0)
        {
            printf("\nINVALID\n");
            exit(0);
        }

        while(g(stack[*top]) > f(next)) 
        {
            temp[0] = pop(stack, top);
            temp[1] = '\0';
            strcat(polish, temp);

            rank = rank + r(temp[0]);

            if(rank < 1)
            {
                printf("\nINVALID\n");
                exit(0);
            }
        }

        // Step 6
        if(g(stack[*top]) != f(next))
        {
            push(stack, top, next);
        }
        else
        {
            pop(stack, top);
        }

        // Step 7
        i++;
        next = infix[i];
        polish[i+1] = '\0';
    }

    // Step 8
    if(*top != -1 || rank != 1)
    {
        printf("Invalid\n");
    }
    else
    {
        printf("Valid\n");
    }

    printf("Postfix Expression is : %s", polish);

    return 0;
}

// Push Operation
void push(char *stack, int *top, char next)
{
    if(*top == SIZE - 1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        *top = *top + 1;
        stack[*top] = next;
    }
}

// Pop Operation
char pop(char *stack, int *top)
{
    if(*top == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        *top = *top - 1;
        return stack[*top + 1];
    }
}

// Input precedence function
int f(char next)
{
    int precedence;

    if(next == '+' || next == '-')
    {
        precedence = 1;
    }
    else if(next == '*' || next == '/')
    {
        precedence = 3;
    }
    else if(next == '^')
    {
        precedence = 6;
    }
    else if(isalpha(next))
    {
        precedence = 7;
    }
    else if(next == '(')
    {
        precedence = 9;
    }
    else if(next == ')')
    {
        precedence = 0;
    }
    return precedence;
}

// Stack precedence function
int g(char next)
{
    int precedence;

    if(next == '+' || next == '-')
    {
        precedence = 2;
    }
    else if(next == '*' || next == '/')
    {
        precedence = 4;
    }
    else if(next == '^')    
    {
        precedence = 5;
    }
    else if(isalpha(next))
    {
        precedence = 8;
    }
    else if(next == '(')
    {
        precedence = 0;
    }
    return precedence;
}

// Rank function
int r(char next)
{
    int rank;

    if(next == '+' || next == '-' || next == '*' || next == '/' || next == '^')
    {
        rank = -1;
    }
    else if(isalpha(next))
    {
        rank = 1;
    }
    return rank;
}