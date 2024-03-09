# include<stdio.h> 
# include<stdlib.h>
# include<string.h>
# include<ctype.h>

# define SIZE 50

void push(char *stack, int *top, char next);
char pop(char *stack, int *top);
 
int main()
{
   
    char exp[SIZE], stack[SIZE];
    int top = -1, i = 0;
    printf("Enter string : ");
    scanf("%s", exp);

    // Only condition changes for evalution of postfix
    while(exp[i] != '\0')
    {
        // if there is operand push into stack
        if(isdigit(exp[i]))
        {
            push(stack, &top, exp[i] - '0');
        }
        else
        {
            // If there is operator then pop two operands from stack and perform the operation between them
            int val1 = pop(stack, &top);  
            int val2 = pop(stack, &top);  

            switch(exp[i])
            {
                case '+':
                    push(stack, &top, val2 + val1);
                    break;

                case '-':
                    push(stack, &top, val2 - val1);
                    break;

                case '*':
                    push(stack, &top, val2 * val1);
                    break;

                case '/':
                    push(stack, &top, val2 / val1);
                    break;
            }
        }
        i++;
    }

    int ans = pop(stack, &top);
    printf("Evaluation of Postfix expression is : %d", ans);
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