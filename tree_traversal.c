# include<stdio.h> 
# include<stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct StackNode
{
    struct node *node;
    struct StackNode *next;
};


struct node *create_node(int data)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct StackNode *createStackNode(struct node *node)
{
    struct StackNode *stackNode = (struct StackNode *) malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

void push(struct StackNode** root, struct node* node) 
{
    struct StackNode* stackNode = createStackNode(node);
    stackNode->next = *root;
    *root = stackNode;
}

struct node* pop(struct StackNode** root) 
{
    if (*root == NULL) 
    {
        return NULL;
    }

    struct node* popped = (*root)->node;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    free(temp);
    return popped;
}

void inorder_non_recursive(struct node* root) 
{
    struct node* curr = root;
    struct StackNode* s = NULL;

    while (1) 
    {
        if (curr != NULL) 
        {
            push(&s, curr);
            curr = curr->left;
        } 
        else 
        {
            if (s == NULL) break;
            curr = pop(&s);
            printf("\n Data : %d ", curr->info);
            curr = curr->right;
        }
    }
}

void preorder_non_recursive(struct node* root) 
{
    struct node* curr = root;
    struct StackNode* s = NULL;

    while (1) 
    {
        if (curr != NULL) 
        {
            printf("\n Data : %d ", curr->info);
            push(&s, curr->right);
            curr = curr->left;
        } 
        else 
        {
            if (s == NULL) break;
            curr = pop(&s);
        }
    }
}

void postorder_non_recursive(struct node* root) 
{
    if (root == NULL) 
    {
        return;
    }

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, root);

    while (stack1 != NULL) 
    {
        struct node* current = pop(&stack1);
        push(&stack2, current);

        if (current->left)
        {
            push(&stack1, current->left);
        }
        if (current->right)
        {
            push(&stack1, current->right);
        }
    }

    while (stack2 != NULL) 
    {
        struct node* current = pop(&stack2);
        printf("\n Data : %d ", current->info);
        
    }
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

    printf("\n Data : %d", root->info);
}

int main()
{
    

    struct node *root = NULL;

    int data, choice;

    printf("\n 1 -> Create node \n 2 -> Insert node \n 3 -> Inorder Traversal \n 4 -> Preorder Traversal \n 5 -> Postorder Traversal \n 6 -> Inorder non recursive \n 7 -> Preorder non recursive \n 8 -> Postorder non recursive \n 9 -> Exit \n");

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

            // Inorder non recursive
            case 6:
            {
                inorder_non_recursive(root);
                break;
            }

            // Preorder non recursive
            case 7:
            {
                preorder_non_recursive(root);
                break;
            }

            // Postorder non recursive
            case 8:
            {
                postorder_non_recursive(root);
                break;
            }

            // Exit
            case 9:
            {
                exit(0);
            }
        }
    }
    return 0;
}