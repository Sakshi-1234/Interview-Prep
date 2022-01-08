#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
} node;

node *create();
void insert(node *, node *);
void preorder(node *);
void smallest(node *);
void inorder(node *);
void largest(node *);
int countnodes(node *);
void inorderstore(int arr[], node *);
int main()
{
	char ch;
	int num = 0;
	node *root = NULL, *temp;
	int numberofnodes = 0;
	do
	{
		temp = create();
		if (root == NULL)
			root = temp;
		else
			insert(root, temp);

		printf("nDo you want to enter more(y/n)?");
		getchar();
		scanf("%c", &ch);
	} while (ch == 'y' | ch == 'Y');

	printf("Preorder Traversal: \n");
	preorder(root);
	smallest(root);
	largest(root);
	inorder(root);
	printf("\n....................");
	inorder(root);
	//printf("\nNumber of nodes in tree  = %d", countnodes(root));
	numberofnodes = countnodes(root);
	printf("\nNumber of nodes in a tree: %d", numberofnodes);
	int arr[numberofnodes];
	inorderstore(arr, root);
	printf("\n.........%d.....", arr[2]);
	return 0;
}
node *inordersucc(node *root)
{
	node *curr = root;
	while (curr && curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}
node *deleteinBST(node *root, int key)
{
	if (root->data < key)
	{
		root->right = deleteinBST(root->right, key);
	}
	else if (root->data > key)
	{
		root->left = deleteinBST(root->left, key);
	}
	else
	{
		if (root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		if (root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		//case 3
		else
		{
			node *temp = inordersucc(root->right);
			root->data = temp->data;
			root->right = deleteinBST(root->right, temp->data);
		}
	}
	return root;
}
void inorder(node *t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%d ", t->data);
		inorder(t->right);
	}
}
static int k = 0;
void inorderstore(int arr[], node *root)
{
	if (root != NULL)
	{
		inorderstore(arr, root->left);
		arr[k] = root->data;
		k++;
		inorderstore(arr, root->right);
	}
}
static int count = 0;
int countnodes(node *root)
{
	if (root != NULL)
	{
		count++;
		countnodes(root->left);
		countnodes(root->right);
	}
	return count;
}

node *create()
{
	node *temp;
	printf("nEnter data:");
	temp = (node *)malloc(sizeof(node));
	scanf("%d", &temp->data);
	temp->left = temp->right = NULL;
	return temp;
}

void insert(node *root, node *temp)
{
	if (temp->data < root->data)
	{
		if (root->left != NULL)
			insert(root->left, temp);
		else
			root->left = temp;
	}

	if (temp->data > root->data)
	{
		if (root->right != NULL)
			insert(root->right, temp);
		else
			root->right = temp;
	}
}

void preorder(node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void smallest(node *root)
{
	node *temp1 = root;
	while (temp1->left != NULL)
	{
		temp1 = temp1->left;
	}
	printf("\nminimum is %d\n", temp1->data);
	//return (temp1->data);
}
void largest(node *root)
{
	node *temp2 = root;
	while (temp2->right != NULL)
	{
		temp2 = temp2->right;
	}
	printf("largest element is %d\n", temp2->data);
}
