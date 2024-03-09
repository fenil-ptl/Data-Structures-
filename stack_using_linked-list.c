# include<stdio.h> 
# include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Display
void display(struct node *first)
{
    // If no node is present 
    if(first == NULL)
    {
        printf("\n No Node is present\n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    printf("\n Data : ");
    while(first != NULL)
    {
        printf("%5d", first->info);
        first = first->link;
    }
}

struct node *insert(struct node *first, int x)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    return new;
}
 
// Delete a first node of the Linked List
struct node *delete_first(struct node *first)
{
	if(first == NULL)
	{
		printf("No node present Cannot perform delete_first operation\n");
	}
	
	struct node *save = first;
	first = first->link;
	free(save);
	return first;
}

int main()
{
    struct node *linkedlist1 = NULL;

    linkedlist1 = insert(linkedlist1, 25);
    display(linkedlist1);
    printf("\n-------------\n");

    linkedlist1 = insert(linkedlist1, 50);
    display(linkedlist1);
    printf("\n-------------\n");

    linkedlist1 = insert(linkedlist1, 80);
    display(linkedlist1);
    printf("\n-------------\n");

    linkedlist1 = delete_first(linkedlist1);
    display(linkedlist1);
    printf("\n-------------\n");

    linkedlist1 = delete_first(linkedlist1);
    display(linkedlist1);
    printf("\n-------------\n");

    linkedlist1 = delete_first(linkedlist1);
    display(linkedlist1);
    printf("\n-------------\n");
    return 0;
}