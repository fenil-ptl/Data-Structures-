#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *first, struct node *last);
int count_nodes(struct node *first, struct node *last);
struct node *insend(struct node **first, struct node **last, int x);
struct node *insert_before_pos(struct node *first, struct node *last, int data, int pos);
struct node *delete_first(struct node *first, struct node *last);
struct node *del_after_position(struct node *first, struct node **last, int pos);

int main()
{
    
    int choice, data, position;
    struct node *first = NULL, *last = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Insend \n 2 -> Insert before position \n 3 -> Delete first node \n 4 -> Delete a node after specified position \n 5 -> Display \n 6 -> Exit \n");

    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            // Insend
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                first = insend(&first, &last, data);
                break;
            }

            // Insert before position
            case 2:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                printf("\n Enter Position : ");
                scanf("%d", &position);

                if(position < 1 || position > count_nodes(first, last))
                {
                    printf("\n INVALID POSITION \n");
                    break;
                }

                first = insert_before_pos(first, last, data, position);
                break;
            }

            // Delete a first node of the Linked List
            case 3:
            {
                first = delete_first(first, last);
                break;
            }

            // Delete a node after specified position
            case 4:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                if(first == NULL)
                {
                    printf("\n No node present \n");
                    break;
                }
                if(position < 1 || position >= count_nodes(first, last))
                {
                    printf("\n INVALID POSITION \n");
                    break;
                }

                first = del_after_position(first, &last, position);
                break;
            }

            // Display
            case 5:
            {
                display(first, last);
                printf("\n %d",  count_nodes(first, last));
               
                break;
            }

            // Exit
            case 6:
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
void display(struct node *first, struct node *last)
{
    // If no node is present
    if (first == NULL)
    {
        printf("\n No Node present \n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    struct node *temp = first;

    printf("\n Data : ");
    do
    {
        printf("%5d", temp->info);
        temp = temp->link;
    } while (temp != first);
}

// Count number of nodes
int count_nodes(struct node *first, struct node *last)
{
    int count;
    if (first == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = first;

    while (save != last)
    {
        save = save->link;
        count++;
    }
    return count;
}

// Insert a node at the end of the Linked List
struct node *insend(struct node **first, struct node **last, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;

    if (*first == NULL) /* If no node is present */
    {
        new->link = new;
        *first = *last = new;
    }
    else
    {
        new->link = *first;
        (*last)->link = new;
        *last = new;
    }
    return *first;
}

// Insert a node before specified position
struct node *insert_before_pos(struct node *first, struct node *last, int data, int pos)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = data;

    if (first == NULL)
    {
        printf("\n No node present \n");
        return first;
    }

    struct node *save = first;
    struct node *pred = NULL;
    int i;

    if (pos == 1)
    {
        new->link = first;
        first = new;
        last->link = first;
        return first;
    }
    else
    {
        for (i = 1; i < pos; i++)
        {
            pred = save;
            save = save->link;
        }
        pred->link = new;
        new->link = save;
        return first;
    }
}

// Delete a first node of the Linked List
struct node *delete_first(struct node *first, struct node *last)
{
    if (first == NULL)
    {
        printf("\n No node present \n");
        return first;
    }
    else if (first == last) /* If only one node is present */
    {
        first = last = NULL;
        return NULL;
    }
    else
    {
        struct node *save = first;
        first = first->link;
        last->link = first;
        free(save);
        return first;
    }
}

// Delete a node after specified position
struct node *del_after_position(struct node *first, struct node **last, int pos)
{
    if (first == NULL)
    {
        printf("\n No node present \n");
        return first;
    }
    else
    {
        struct node *save = first;
        struct node *pred = NULL;

        for (int i = 1; i < pos + 1; i++)
        {
            pred = save;
            save = save->link;
        
            // If last node is to be deleted
            if (save == *last)
            {
                pred->link = first;
                free(save);
                *last = pred;
                return first;
            }
        }

        pred->link = save->link;
        free(save);
        return first;
    }
}
