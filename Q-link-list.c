# include<stdio.h> 
# include<stdlib.h> 

struct node
{
    int info;
    struct node *link;
};

void display(struct node *front);
struct node *enqueue(struct node **front, struct node **rear, int x);
struct node *dequeue(struct node **front);

int main()
{

    int choice, data;
    struct node *front = NULL, *rear = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Insert \n 2 -> Delete \n 3 -> Display \n 4 -> Exit \n");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Insert
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                front = enqueue(&front, &rear, data);
                break;
            }

            // Delete a first node of the Linked List
            case 2:
            {
                front = dequeue(&front);
                break;
            }

            // Display
            case 3:
            {
                display(front);
                break;
            }

            // Exit
            case 4:
            {
                exit(0);
            }

            default:
            {
                printf("\n Enter proper choice \n");
                break;
            }
        }
    }
    return 0;
}

// Display
void display(struct node *front)
{
    // If no node is present
    if (front == NULL)
    {
        printf("\n Queue is empty\n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    printf("\n Data : ");
    while (front != NULL)
    {
        printf("%5d", front->info);
        front = front->link;
    }
}

// Insert at last 
struct node *enqueue(struct node **front, struct node **rear, int x)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\n Queue Overflow\n");
        return (*front);
    }
    else
    {
        new->info = x;
        new->link = NULL;
        
        if(*front == NULL)
        {
            *front = *rear = new;
            return (*front);
        }
        else
        {
            (*rear)->link = new;
            *rear = new;
            return (*front);
        }
    }
}

// Delete from front
struct node *dequeue(struct node **front)
{
    if(*front == NULL)
    {
        printf("\n Queue Underflow\n");
        return (*front);
    }

    struct node *save = *front;
    *front = (*front)->link;
    free(save);
    return (*front);
}