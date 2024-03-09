# include<stdio.h> 
# include<string.h>
# define SIZE 10

void push(char *stack, int *top, char next);
char pop(char *stack, int *top);

int main()
{
    
    char str[SIZE], stack[SIZE];
    int top = -1, flag = 0;

    printf("Enter string : ");
    scanf("%s", str);

    int len = strlen(str);

    // Pushing first half of the characters in stack
    for(int i=0; i<len/2; i++)
    {
        push(stack, &top, str[i]);
    } 

    // Comparing second half of the stack with the popped character from stack
    for(int i=(len + 1)/2; i<len; i++)
    {
        if(pop(stack, &top) != str[i])
        {
            flag = 1;
            break;
        }   
    }

    if(flag == 0)
    {
        printf("%s is Palindrome\n", str);
    }
    else
    {
        printf("%s is not Palindrome\n", str);
    }

    return 0;
}

// Push Function
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

// Pop Function
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