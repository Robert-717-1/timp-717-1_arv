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
void print(w* node)
{
	if (node)
	{
		List *o =(List*)malloc(sizeof(List));
		List *o_ = (List*)malloc(sizeof(List));
		createlist(o);
		createlist(o_);
		w *u = NULL;
		Listw*q = NULL;
		int c = 0, val = node->comich, j = 0;
		w *l = node->left;
		w *r = node->right;
		push(o, node);
		while (1)
		{
			while (o->first)
			{
				if (o->first)
	{
		Listw *nodelist_pop;
		u = o->first->e_tree;
		nodelist_pop = o->first;
		o->first = o->first->next;
		if (o->first == NULL)
			o->last = NULL;
		free(nodelist_pop);
	}
	else
		u = NULL;
				if (o->first == NULL)
				{
					if (u->comich == val && c == 1){}
					else
						printf("%d ", u->comich);
				}
				else if (u->comich == val && c == 1){}
				else
					printf("%d ", u->comich);
				if (u->left)
					push(o_, u->left);
				else
					push(o_, node);
				if (u->right)
					push(o_, u->right);
				else
					push(o_, node);
			}
			node->left = node->right = NULL;
			c = 1;
			q = o_->first;
			while (o_->first->e_tree->comich == val)
			{
				o_->first = o_->first->next;
				if (o_->first->next == NULL)
					if (o_->first->e_tree->comich == val)
					{
						j = 1;
						node->left = l;
						node->right = r;
						clearlist(o_);
						break;
					}
			}
			o_->first = q;
			if (j == 1)
				break;
			o->first = o_->first;
			o->last = o_->last;
			o_->first = NULL;
			o_->last = NULL;
		}
	}

}
int main() {
	tr *tree = (tr*)malloc(sizeof(w));
	init(tree);

	int a[7];
	for (int i = 0; i < 7; i++){
        scanf("%d",&a[i]);
		insert(tree, a[i]);
    }
	print(tree->root);
	printf("\n");
}
