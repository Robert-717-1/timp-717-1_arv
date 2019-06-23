#include <stdio.h>
#include <stdlib.h>

typedef struct w
{
	int comich;
	struct w *left;
	struct w *right;
	struct w *parent;
} w;

typedef struct tree
{
	struct w *root;
	int count;
} tr;

typedef struct listw
{
	w *e_tree;
	struct listw *next;
}Listw;

typedef struct list
{
	Listw *first;
	Listw *last;
}List;

void createlist(List *q)
{
	q->first = NULL;
	q->last = NULL;
};
int push(List *q, w *n)
{
	Listw *newList = (Listw*)malloc(sizeof(Listw));
	newList->e_tree = n;
	newList->next = NULL;
	if (q->first)
		q->last->next = newList;
	else
		q->first = newList;
	q->last = newList;
	return 0;
}

void init(tr *tree) {

	tree->root = NULL;
}
int insert(tr *tree, int comich) {
	w *u = (w*)malloc(sizeof(w));

	u->comich = comich;


	if (tree->root == NULL) {
		u->left = u->right = NULL;
		u->parent = NULL;
		tree->root = u;
		tree->count = 1;
		return 0;
	}

	if (u->comich == tree->root->comich)
		return -1;

	w *r = (w*)malloc(sizeof(w)), *root3 = NULL;

	r = tree->root;

	while (r != NULL)
	{
		root3 = r;
		if (comich < r->comich)
			r = r->left;
		else
			r = r ->right;
	}

	if (u->comich == root3->comich) {
		return -1;
	}

	u->parent = root3;
	u->left = NULL;
	u->right = NULL;

	if (comich < root3->comich)
		root3->left = u;
	else
		root3->right = u;
	tree->count++;
	return 0;
}
void clearlist(List  *q)
{
	Listw *u, *nq;
	u = q->first;
	do
	{
		nq = u;
		u = u->next;
		free(nq);
	} while (u);
	q->first = NULL;
	q->last = NULL;
}
void print(tr* t)
{
	w *power[15];
	int saitam =0;
	w *power2[15];
	int saitam2 =0;
	w * node = t -> root;
	while(saitam2 <t ->count)
	{
		while (node!= NULL)
		{
			saitam2++;
			if(node -> right != NULL)
			{saitam++;
				power[saitam] = node->right;
			}
			power2[saitam2] = node;
			node = node->left;

		}
		node = power[saitam];
		saitam -- ;
	}
	for (int i = 1 ;i <= saitam2;i++)
	{
		printf("%d ",power2[i]->comich);
}
printf("\n");
}
int main() {
	tr *tree = (tr*)malloc(sizeof(w));
	init(tree);

	int a[7];
	for (int i = 0; i < 7; i++){
        scanf("%d",&a[i]);
		insert(tree, a[i]);
}
	print(tree);
}
