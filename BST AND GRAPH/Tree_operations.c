#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    p = (node *)malloc(sizeof(node));
    p->data = x;

    printf("Enter left child of %d:\n", x);
    p->left = create();

    printf("Enter right child of %d:\n", x);
    p->right = create();

    return p;
}

void preorder(node *t) //address of root node is passed in t
{
    if (t != NULL)
    {
        printf("\n%d", t->data); //visit the root
        preorder(t->left);       //preorder traversal on left subtree
        preorder(t->right);      //preorder traversal on right subtree
    }
}

void inorder(node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("\n%d", t->data);
        inorder(t->right);
    }
}

void postorder(node *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("\n%d", t->data);
    }
}

static int count = 0;
int countnodes(struct node *root)
{
    if (root != NULL)
    {
        count++;
        countnodes(root->left);
        countnodes(root->right);
    }
    return count;
}

static int sum = 0;
int sumofnodes(struct node *root)
{
    if (root != NULL)
    {
        sum = sum + (root->data);
        sumofnodes(root->left);
        sumofnodes(root->right);
    }
    return sum;
}

static int k = 0;
int leftsum(struct node *root)
{
    if (root != NULL)
    {
        k = k + (root->data);
        leftsum(root->left);
    }
    return k;
}

static int j = 0;
int rightsum(struct node *root)
{
    if (root != NULL)
    {
        j = j + (root->data);
        rightsum(root->right);
    }
    return j;
}

int maxHeightTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lh;
        int rh;
        lh = maxHeightTree(root->left);
        rh = maxHeightTree(root->right);
        if (lh > rh)
        {
            return lh + 1;
        }
        else
        {
            return rh + 1;
        }
    }
}

void printLeafNodes(node *root)
{

    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        printf("\n%d", root->data);
        return;
    }

    else
        printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void print_level(node *root, int level)
{
    if (level == 0)
    {
        printf("\n %d", root->data);
    }
    else
    {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void levelorder(node *root, int maxhei)
{
    for (int i = 0; i < maxhei; i++)
    {
        print_level(root, i);
        printf("\n");
    }
}

static int sum1 = 0;
int sumofnodes_klevel(node *root, int level)
{
    if (level == 0)
    {
        sum1 = sum1 + root->data;
    }
    else
    {
        sumofnodes_klevel(root->left, level - 1);
        sumofnodes_klevel(root->right, level - 1);
    }
    return sum1;
}

//static int sum2 = 0;
void sumreplace(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);

    if (root->left != NULL)
    {
        root->data = root->data + root->left->data;
    }

    if (root->right != NULL)
    {
        root->data = root->data + root->right->data;
    }
}

void rightViewUtil(node *root, int level, int *max_level)
{
    if (root == NULL)
        return;

    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
void rightView(node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

node* LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL)
    {
        return (root->left);
    }
    if (right != NULL)
    {
        return (root->right);
    }
}
int distance(node *root, int n1, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n1)
    {
        return dist;
    }
    int left = distance(root->left, n1, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return distance(root->right, n1, dist + 1);
}
int finddistance(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);
    int d1 = distance(lca, n1, 0);
    int d2 = distance(lca, n2, 0);
    return d1+d2;
}
int main()
{
    node *root;
    int count = 0;
    int sum = 0;
    int k = 0;
    int l;
    root = create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nThe inorder traversal of tree is : \n");
    inorder(root);
    printf("\nThe postorder traversal of tree is: \n");
    postorder(root);
   printf("\n........");
    printf("DISTANCE= %d ",finddistance(root,7,6));
    printf("\nNumber of nodes in tree  = %d", countnodes(root));
    printf("\nSum of nodes of binary tree is = %d", sumofnodes(root));
    printf("\nSum of all left nodes of binary tree is = %d", leftsum(root) - (root->data));
    printf("\nSum of all right nodes of binary tree is = %d", rightsum(root) - (root->data));
    printf("\nMaximum height of tree is = %d", maxHeightTree(root));
    int maxhei = maxHeightTree(root);
    printf("\nMaximum Height of Tree is: %d", maxhei);
    rightView(root);

    printf("\nLeaf nodes are:");
    printLeafNodes(root);
    printf("\nLEVEL ORDER TRAVERSAL........");
    levelorder(root, maxhei);
    printf("\nEnter k level at which sum of nodes is to be found: ");
    scanf("%d", &l);
    printf("\n%d", sumofnodes_klevel(root, 1));
    sumreplace(root);
    inorder(root);
    return 0;
}
