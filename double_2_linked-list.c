// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

# include<stdio.h>
# include<stdlib.h> 

struct node
{
    int info;
    struct node *link;
};

// DONE
struct node *create()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));

    int data;
    printf("Enter data for first node : ");
    scanf("%d", &data);

    first->info = data;
    // Setting link of first node to NULL
    first->link = NULL;

    printf("Linked List is Created\n");

    return first;
}

// DONE
void display(struct node *first)
{
    // If no node is present 
    if(first == NULL)
    {
        printf("No Node is present\n");
    }

    // Traversal in linked list while link of node is not equal to NULL
    while(first != NULL)
    {
        printf("Data : %d \n", first->info);
        first = first->link;
    }
}

// DONE
// Count the number of nodes
int count_nodes(struct node *first)
{
    int count;
    if(first == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = first;

    while(save->link != NULL)
    {
        save = save->link;
        count++;
    }

    return count;
}


// DONE
struct node *insert(struct node *first, int x)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    return new;
}

// DONE
struct node *insend(struct node *first, int x)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = x;
    new->link = NULL;

    if(first == NULL)
    {
        return new;
    }

    struct node *save = first;

    while(save->link != NULL)
    {
        save = save->link;
    }
    save->link = new;

    return first;
}

// struct node *inserAtIndex(struct node* first, int x, int index)
// {
//     struct node *new = (struct node*)malloc(sizeof(struct node));
//     struct node *p = new;
//     int i = 0;

//     while(i != index - 1)
//     {
//         p = p->link;
//         i++;
//     }
//     new->info = x;
//     new->link = p->link;
//     p->link = new;
//     return first; 
// }

// DONE
struct node *insord(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    
    // If no node is present
    if(first == NULL)
    {
        new->link = NULL;
        return new;
    }

    // if the new node is smaller than first node 
    if(new->info <= first->info)
    {
        new->link = first;
        return new;
    }

    struct node *save = first;
    while(save->link != NULL && new->info >= save->link->info)
    {
        save = save->link;
    }

    new->link = save->link;
    save->link = new;
       
    return first;
}

// DONE
struct node *delete(struct node *first, int x)
{
    if(first == NULL)
    {
        printf("No node present Cannot perform delete operation\n");
    }

    struct node *save = first;
    struct node *pred = NULL;

    while(save->info != x && save != NULL)
    {
        pred = save;
        save = save->link;
    } 

    if(save == NULL)
    {
        printf("Node not found\n");
        return first;
    }

    if(x == first->info)
    {
        first = first->link;
    }
    else
    {
        pred->link = save->link;
    }

    free(save);
    return first;
}

// DONE
// Deleting first node
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

// DONE
// Delete a node before a particular node (using info)
struct node *delete_before(struct node *first, int x)
{
	if(first == NULL)
	{
		printf("No node present Cannot perform delete_before operation\n");
	}
	
	struct node *save = first;
	struct node *pred = NULL;
	
	while(save->link->info != x)
	{
		pred = save;
		save = save->link;

        if(save->link == NULL)
        {
            printf("Node not found Cannot delete : %d \n", x);
            return first;
        }
	}
    
    if(save->link->info == x)
    {
        pred->link = save->link;
    }
	free(save);
	return first;
}

// DONE
// Delete a node after a particular node (using info)
struct node *delete_after(struct node *first, int x)
{
	if(first == NULL)
	{
		printf("No node present Cannot perform delete_after operation\n");
	}
	
	struct node *save = first;
	struct node *pred = NULL;
	
	while(save->info != x && save->link != NULL)
	{
		pred = save;
		save = save->link;

        if(save->link == NULL)
        {
            printf("Node not found Cannot delete : %d \n", x);
            return first;
        }
	}
    if(save->info == x)
    {
        pred = save;
        save = save->link;
        pred->link = save->link;
    }

    free(save);

	return first;
}


// Delete a node before specified position
struct node *del_before_position(struct node *first, int pos)
{
    if(first == NULL)
	{
		printf("No node present Cannot perform del_before_position operation\n");
	}

    struct node *save = first;
    struct node *pred = NULL;
    int i;
    
    if(pos == 2) /* If first node is to be deleted */
    {
        first = first->link;
        free(save);
        return first;
    }
    for(i = 1; i <= pos - 2; i++)
    {
        pred = save;
        save = save->link;

        if(save->link == NULL)
        {
            printf("Position %d is invalid\n", pos);
            return first;
        }
    }
    
    pred->link = save->link;
    free(save);
    return first;
}

// Delete a node after specified position
struct node *del_after_position(struct node *first, int pos)
{
    if(first == NULL)
	{
		printf("No node present Cannot perform del_before_position operation\n");
	}

    struct node *save = first;
    struct node *pred = NULL;
    int i;
    
    for(i = 1; i < pos + 1; i++)
    {
        pred = save;
        save = save->link;

        /* NOT CHECKED: If position is greater than number of nodes */
        if(save->link == NULL)
        {
            pred->link = NULL;
            free(save);
            return first;
        }
    }
    
    pred->link = save->link;
    free(save);
    return first;
}


int main()
{
    struct node *linkedList1 = NULL;

    // Verified
    linkedList1 = create();
    display(linkedList1);
    printf("---------------\n");
    
    // Verified
    linkedList1 = insert(linkedList1, 55);
    display(linkedList1);
    printf("---------------\n");


    // Verified
    linkedList1 = insend(linkedList1, 88);
    display(linkedList1);
    printf("---------------\n");

    linkedList1 = insend(linkedList1, 99);
    display(linkedList1);
    printf("---------------\n");


    linkedList1 = insord(linkedList1, 90);
    display(linkedList1);
    printf("---------------\n");

    // linkedList1 = delete(linkedList1, 88);
    // display(linkedList1);
    // printf("---------------\n");

    linkedList1 = delete_after(linkedList1, 88);
    display(linkedList1);
    printf("---------------\n");

    linkedList1 = insend(linkedList1, 85);
    display(linkedList1);
    printf("---------------\n");

    linkedList1 = delete_before(linkedList1, 85);
    display(linkedList1);
    printf("---------------\n");



    // For delete Operation -> set of values 

    // linkedList1 = insert(linkedList1, 55);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = insert(linkedList1, 80);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = insert(linkedList1, 100);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = delete(linkedList1, 80);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = delete(linkedList1, 55);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = del_before_position(linkedList1, 3);
    // display(linkedList1);
    // printf("---------------\n");

    // linkedList1 = del_before_position(linkedList1, 2);
    // display(linkedList1);
    // printf("---------------\n");

    linkedList1 = del_after_position(linkedList1, 2);
    display(linkedList1);
    printf("---------------\n");

    int num_of_nodes = count_nodes(linkedList1);
    printf("Number of nodes in Linked List are : %d\n", num_of_nodes);
    printf("---------------\n");

    return 0;
}