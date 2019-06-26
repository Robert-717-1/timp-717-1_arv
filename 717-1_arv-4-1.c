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

void init(tr *tree) {

	tree->root = NULL;
}

void clear(tr *tree) {
	while (tree->root != NULL)
		RemoveMin(tree->root, tree);
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

int RemoveMin(w *n, tr *t) {
	t->count--;

	if (t->count != 1) {

		while (n->left != NULL)
			n = n->left;

		if (n->right != NULL) {
			n->right->parent = n->parent;

			if (n == t->root)
				t->root = n->right;
			else
				n->parent->left = n->right;
		}
		else
			n->parent->left = NULL;

		int comich = n->comich;
		free(n);

		return comich;
	}
	else {
		t->root = NULL;
		t->count = 0;
		free(t->root);

		return 0;
	}
}

w *s(w *node, int comich) {
	if ((node == NULL) || (node->comich == comich))
		return node;
	if (comich < node->comich)
		return s(node->left, comich);
	else
		return s(node->right, comich);
}

w *d(w *root) {
	w *l = root;
	while (l->left != NULL)
		l = l->left;
	return l;
}

int findw(tr *tree, int comich, w **node) {
	w *u, *root2;
	root2 = tree->root;
	u = s(root2, comich);
	if (u == NULL) {
		return 1;
	}

	*node = u;
	return 0;
}


int rotateLeft(tr* tree) {
	w *u = tree->root->right;

	if (u == NULL)
		return 1;

	tree->root->right = u->left;
	u->left = tree->root;
	u->parent = tree->root->parent;
	tree->root->parent = u;
	tree->root = u;

	return 0;
}

int rotateRight(tr *tree) {
	w *u = tree->root->left;

	if (u == NULL)
		return 1;

	tree->root->left = u->right;
	u->right = tree->root;
	u->parent = tree->root->parent;
	tree->root->parent = u;
	tree->root = u;

	return 0;
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
					if (u->comich == val && c == 1)
						printf("_\n");
					else
						printf("%d\n", u->comich);
				}
				else if (u->comich == val && c == 1)
					printf("_ ");
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
	else
		printf("-\n");
}

void printtr(tr *tree) {
	print(tree->root);

}

w* _Remove(w* tree, int comich)
{
	w* temp;
	if (!tree) {
		return tree;
	}
	else if (comich < tree->comich) {
		tree->left = _Remove(tree->left, comich);
	}
	else if (comich > tree->comich) {
		tree->right = _Remove(tree->right, comich);
	}
	else {
		if (tree->left && tree->right) {
			temp = d(tree->right);
			temp->left = tree->left;
			temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->left == tree->right) {
			free(tree);
			return NULL;
		}
		else {
			if (!tree->left) temp =tree->right;
			else temp = tree->left;
			free(tree);
			return temp;
		}
	}
	return tree;
}

int Remove(tr *tree, int comich) {
	w *u = _Remove(tree->root, comich);
	if (!u)
		return 1;
	else {
		tree->count--;
		tree->root = u;
		return 0;
	}
}

void OutPutParentAndPred (int j, w* tree)
{
    w *r = (w*)malloc(sizeof(w));

    if (findw(tree, j, &r) == 1)
        printf("-");
    else {
        if (r->parent == NULL)
            printf("_ ");
        else
            printf("%d ", r->parent->comich);
        if (r->left == NULL)
            printf("_ ");
        else
            printf("%d ", r->left->comich);
        if (r->right == NULL)
            printf("_ ");
        else
            printf("%d ", r->right->comich);
    }
}


int main() {
	tr *tree = (tr*)malloc(sizeof(w));
	init(tree);

	int a[4];
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	for (int i = 0; i < 4; i++)
		insert(tree, a[i]);

	print(tree->root);

	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	for (int i = 0; i < 3; i++)
		insert(tree, a[i]);

	print(tree->root);

	int m;
    for(int i = 0 ;i < 2;i++){
        scanf("%d", &m);
        OutPutParentAndPred(m,tree);
        printf("\n");
    }
    int m3;
	scanf("%d", &m3);

	Remove(tree, m3);

	print(tree->root);

	while (rotateLeft(tree) == 0);

	print(tree->root);
	while (rotateRight(tree) == 0);

	print(tree->root);

	printf("%d\n", tree->count);

	clear(tree);

	print(tree->root);

}
