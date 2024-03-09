# include<stdio.h> 

void towerOfHanoi(int n, char src, char helper, char dest);

int main()
{

    int n;
    printf("Enter number of disks : ");
    scanf("%d", &n);
    towerOfHanoi(n, 'S', 'H', 'D');
    return 0;
}

void towerOfHanoi(int n, char src, char helper, char dest)
{
    // Base case -> When number of disc is 1 then directly shift disc from source to destination
    if(n == 1)
    {
        printf("Transfer disk %d from %c to %c\n", n, src, dest);
        return;
    }

    // Shifting n-1 discs from source to destination(H) using helper(D)
    towerOfHanoi(n-1, src, dest, helper);
    // Base case
    printf("Transfer disk %d from %c to %c\n", n, src, dest);
    // Shifting of n-1 discs from helper(S) to destination(D) using source(H)
    towerOfHanoi(n-1, helper, src, dest);

}