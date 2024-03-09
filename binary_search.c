# include<stdio.h> 
# include<stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

// Creating node
struct node *create_node(int data)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inserting a node
struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
    }
    else if(data <= root->info)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Searching a node
int search(struct node *root, int data)
{
    if(root == NULL)
    {
        return -1;
    }

    while(root)
    {
        if(root->info == data)
        {
            return 1;
        }
        else if(data > root->info)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
} 

// Recursive Preorder Traversal
void preorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    printf("\n Data : %d", root->info);

    if(root->left != NULL)
    {
        preorder_recursive(root->left);
    }

    if(root->right != NULL)
    {
        preorder_recursive(root->right);
    }
}

// Recursive Inorder Traversal
void inorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    if(root->left != NULL)
    {
        inorder_recursive(root->left);
    }

    printf("\n Data : %d", root->info);

    if(root->right != NULL)
    {
        inorder_recursive(root->right);
    }
}

// Recursive Postorder Traversal
void postorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    if(root->left != NULL)
    {
        postorder_recursive(root->left);
    }

    if(root->right != NULL)
    {
        postorder_recursive(root->right);
    }

    printf("\n Data : %5d", root->info);
}

int main()
{

    struct node *root = NULL;

    int data, choice;

    printf("\n 1 -> Create node \n 2 -> Insert node \n 3 -> Inorder Traversal \n 4 -> Preorder Traversal \n 5 -> Postorder Traversal \n 6 -> Search a node \n 7 -> Exit \n");

    while(1)
    {
        printf("\n Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Create a node
            case 1:
            {
                printf("\n Enter Data: ");
                scanf("%d", &data);

                root = create_node(data);
                break;
            }

            // Inserting a node
            case 2:
            {
                printf("\n Enter Data: ");
                scanf("%d", &data);

                root = insert(root, data);
                break;
            }

            // Inorder Traversal
            case 3:
            {
                inorder_recursive(root);
                break;
            }

            // Preorder Traversal
            case 4:
            {
                preorder_recursive(root);
                break;
            }

            // Postorder Traversal
            case 5:
            {
                postorder_recursive(root);
                break;
            }

            // Searching a node
            case 6:
            {
                printf("\n Enter Data to search in BST (Binary Search Tree): ");
                scanf("%d", &data);

                if(search(root, data))
                {
                    printf("\n %d is found in binary search tree", data);
                }
                else
                {
                    printf("\n %d is not found in binary search tree", data);  
                }
                break;
            }
            case 7:
            {
                exit(0);
            }
        }
    }
    return 0;
}