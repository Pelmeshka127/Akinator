#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *pleft;
	struct node *pright;
};

void insert(struct node **pproot, int value);
void inorder(struct node *proot);
int Min_Tree_Elem(struct node *proot);
int Height(struct node *proot);

int main()
{
	struct node *proot = NULL;
	insert(&proot, 10);
	insert(&proot, 5);
	insert(&proot, 15);
	insert(&proot, 3);
	insert(&proot, 11);
	inorder(proot);
	printf("%d", Min_Tree_Elem(proot));
	system("pause");
	return 0;
}

void insert(struct node **pproot, int value)
{
	if (*pproot == NULL)
{
		*pproot = (struct node *)malloc(sizeof(struct node));
		if (*pproot == NULL)
{
			printf("%d not insert. No memory available.\n", value);
			system("pause");
			exit(1);
		}
		(*pproot)->data = value;
		(*pproot)->pleft = NULL;
		(*pproot)->pright = NULL; 
	}
	else if (value < (*pproot)->data)
		insert(&((*pproot)->pleft), value);
	else if (value > (*pproot)->data)
		insert(&((*pproot)->pright), value);
}

void inorder(struct node *proot)
{
	if (proot != NULL) {
		inorder(proot->pleft);
		printf("%d ", proot->data);
		inorder(proot->pright);
	}
}


int Min_Tree_Elem(struct node *proot)
{
	while ((proot->pleft) != NULL)
		proot = (proot->pleft);

	return proot->data;
}


int Height(node *proot)
{
    if(proot == NULL)
        return 0;
    int left = 0, right = 0;
    if (proot->pleft != NULL) {
        left = Height(proot->pleft);
    }else 
        left = -1;
    if (proot->pright != NULL) {
        right = Height(proot->pright);
    }else 
        right = -1;
    int max = left > right ? left : right;
    return max+1;

}


#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *pleft;
	struct node *pright;
};

void insertTree(struct node **pproot, int value);
void inOrder(struct node *proot);
void minTree(struct node *proot);
int treeHeight(struct node *proot);
int AVL(node* root);
int height(node* node);
int max(int x, int y);
void tree_remove (node *&p);
int numOfLists(node* root);
int numOfElem(node* root);

int main()
{
	struct node *proot = NULL;
	insertTree(&proot, 10);
	insertTree(&proot, 5);
	insertTree(&proot, 15);
	insertTree(&proot, 3);
	insertTree(&proot, 11);
	//insertTree(&proot, 17);
	//inOrder(proot);
    //minTree(proot);
    //printf("%d", treeHeight(proot));
	//printf("%d %d",AVL(proot), height(proot));
	//tree_remove (proot);
	//printf("%d", numOfLists(proot));
	printf("%d", numOfElem(proot));
	return 0;
}

void insertTree(struct node **pproot, int value)
{
	if (*pproot == NULL)
{
		*pproot = (struct node *)malloc(sizeof(struct node));
		if (*pproot == NULL)
		{
			printf("%d not insertTree. No memory available.\n", value);
			exit(1);
		}
		(*pproot)->data = value;
		(*pproot)->pleft = NULL;
		(*pproot)->pright = NULL; 
}
	else if (value < (*pproot)->data)
		insertTree(&((*pproot)->pleft), value);
	else if (value > (*pproot)->data)
		insertTree(&((*pproot)->pright), value);
	else
		printf("duplicate\n");
}

void inOrder(struct node *proot)
{
	if (proot != NULL) {
		inOrder(proot->pleft);
		printf("%d ", proot->data);
		inOrder(proot->pright);
	}
}
void minTree(struct node *proot)
{
    while( (proot -> pleft) != NULL)
    {
        proot = (proot -> pleft);
    }
    printf("%d ",(proot -> data));

}

int treeHeight(struct node *proot)
{ 
    if (proot == NULL)
        return 0;
    else if ((proot -> pleft == NULL) && (proot -> pright == NULL))
        return 0;
    else if (treeHeight (proot-> pleft) > treeHeight (proot-> pright))
        return treeHeight (proot-> pleft) + 1;
    else
        return treeHeight (proot-> pright) + 1;
}

int height(node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->pleft), height(node->pright));
}

int AVL(node* root) {
    if (root == NULL)
        return 1;
    int lh = height(root->pleft);
    int rh = height(root->pright);
    if (abs(lh - rh) <= 1 && AVL(root->pleft) && AVL(root->pright)) return 1;
    return 0;
}

int max(int x, int y) { 
    return (x >= y) ? x : y;
}

void tree_remove (node *&p)
{
  if(p!=NULL)
  {
    tree_remove(p->pleft);
    tree_remove(p->pright);
    delete p;
    p = NULL;
  }
}

int numOfLists(node* root)
{
	int result = 0;
	if(root == NULL) 
		result = 0;
	else if(root ->pleft == NULL && root ->pleft == NULL)
	{
		result = 1;
	}
	else 
	{
		result = numOfLists(root -> pleft) + numOfLists(root -> pright);
	}
	return result;
}
int numOfElem(node* root)
{
	int elem = 0;
	if (root == NULL)
		elem = 0;
	else 
	{
		elem = 1 + numOfElem(root -> pleft) + numOfElem(root -> pright);
	}
	return elem;
}