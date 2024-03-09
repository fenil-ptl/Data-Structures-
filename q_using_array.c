# include<stdio.h> 
# include<conio.h> 
# include<stdlib.h> 
# define SIZE 5

void qInsert(int Q[], int *F, int *R, int element);
int qDelete(int Q[], int *F, int *R);
void qDisplay(int Q[], int *F, int *R); 

int main()
{
    
    int queue[SIZE], front = -1, rear = -1, element, choice;

   while(1)
   {
        printf("\nOperations that can be performed :\n 1 -> Insert \n 2 -> Delete \n 3 -> Display \n 4 -> Exit \n");
        printf("\nEnter Operation : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Choice for Insertion
            case 1:
            {
                printf("\nEnter element to be inserted : ");
                scanf("%d", &element);
                qInsert(queue, &front, &rear, element);
                getch();
                break;
            }

            // Choice for Deletion
            case 2:
            {
                int delete = qDelete(queue, &front, &rear);
                if(delete != -1)
                {
                    printf("\nDeleted element is : %d\n", delete);
                    getch();
                }
                break;
            }

            // Choice for Displaying
            case 3:
            {
                qDisplay(queue, &front, &rear);
                getch();
                break;
            }

            // Choice for exit
            case 4:
            {
                exit(0);
            }

            // Default choice
            default:
            {
                printf("\nEnter valid Operation !\n");
                getch();
                break;
            }
        }
    }
    return 0;
}

// Queue Insert
void qInsert(int Q[], int *F, int *R, int element)
{
    if(*R == SIZE - 1)
    {
        printf("\nQueue Overflow !\n");
        return;
    }

    *R = *R + 1;
    Q[*R] = element;

    if(*F == -1)
    {
        *F = 0;
        return;
    }
}

// Queue Delete
int qDelete(int Q[], int *F, int *R)
{
    int element;
    if(*F == -1)
    {
        printf("\nQueue Underflow !\n");
        return -1;
    }
    
    element = Q[*F];

    if(*F == *R)
    {
        *F = *R = -1;
    }
    else
    {
        *F = *F + 1;
    }
    return element;
}

// Queue Display
void qDisplay(int Q[], int *F, int *R)
{
    if(*F == -1)
    {
        printf("\nQueue Empty !\n");
        return;
    }
    printf("\nQueue Contents : \n");
    for(int i = *F; i <= *R; i++)
    {
        printf("%5d", Q[i]);
    }
}