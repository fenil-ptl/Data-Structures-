# include<stdio.h> 

void callByValue(int a, int b);
void callByReference(int *a, int *b);

int main()
{

    int a = 18, b = 45;

    printf("Before swapping a = %d and b = %d\n", a, b);

    callByValue(a, b);
    printf("In call by value function a = %d and b = %d\n", a, b);

    callByReference(&a, &b);
    printf("In call by reference function a = %d and b = %d\n", a, b);

    return 0;
}

void callByValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void callByReference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}