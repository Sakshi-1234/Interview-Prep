#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

node *buildTree(int preorder[], int inorder[], int start, int end);
int search(int inorder[], int start, int end, int curr);
void inorder(node *t);

node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = curr;
    int pos = search(inorder, start, end, curr);
    newnode->left = buildTree(preorder, inorder, start, pos - 1);
    newnode->right = buildTree(preorder, inorder, pos + 1, end);
    return newnode;
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
}

void inorde(node *t)
{
    if (t != NULL)
    {
        inorde(t->left);
        printf("\n%d", t->data);
        inorde(t->right);
    }
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node *root = buildTree(preorder, inorder, 0, 4);
    inorde(root);
    return 0;
}

//-----------------------------BINARY TREE FROM POSTORDER AND INORDER--------------------------------------

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     struct node *left;
//     struct node *right;
//     int data;
// } node;
// node *buildtree(int postorder[], int inorder[], int start, int end);
// int search(int inorder[], int curr, int start, int end);
// void inorde(node*t);
// void inorde(node *t)
// {
//     if (t != NULL)
//     {
//         inorde(t->left);
//         printf("\n%d", t->data);
//         inorde(t->right);
//     }
// }
// int search(int inorder[], int curr, int start, int end)
// {
//     for (int i = start; i <= end; i++)
//     {
//         if (inorder[i] == curr)
//         {
//             return i;
//         }
//     }
// }
// node *buildtree(int postorder[], int inorder[], int start, int end)
// {
//     static int idx = 4;
//     if (start > end)
//     {
//         return NULL;
//     }
//     int curr = postorder[idx];
//     idx--;

//     node *newnode = (node *)malloc(sizeof(node));
//     newnode->data = curr;
//     if (start == end)
//     {
//         return newnode;
//     }
//     int pos = search(inorder, curr, start, end);
//     newnode->right = buildtree(postorder, inorder, pos + 1, end);
//     newnode->left = buildtree(postorder, inorder, start, pos - 1);
//     return newnode;
// }
// int main()
// {
//     int postorder[] = {4, 2, 5, 3, 1};
//     int inorder[] = {4, 2, 1, 5, 3};
//     node *root = buildtree(postorder, inorder, 0, 4);
//     inorde(root);

//     return 0;
// }
