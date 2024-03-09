# include<stdio.h> 
# include<string.h> 
# define SIZE 5

void push(char S[], int *top, char next);
char pop(char S[], int *top);

int main()
{
    char str[SIZE], stack[SIZE];
    int top = -1;

    printf("Enter String : ");
    scanf("%s", str);

    int len = strlen(str);

    // Pusing all elements in stack
    for(int i = 0; i < len; i++)
    {
        push(stack, &top, str[i]);
    }

    // Popping all elements in str[i] to get the reverse string
    for(int i = 0; i < len; i++)
    {
        str[i] = pop(stack, &top);
    }

    printf("Reverse of string : %s", str);

    return 0;
}

void push(char S[], int *top, char next)
{
    if(*top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    *top = *top + 1;
    S[*top] = next;
}

char pop(char S[], int *top)
{
    if(*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    *top = *top - 1;
    return (S[*top + 1]);
}
