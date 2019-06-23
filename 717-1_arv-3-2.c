#include <stdio.h>
#include<stdlib.h>

struct node {
 	int value;
	struct node *n;
	struct node *bef;
} node;

struct listx2{		
	struct node* first;
	struct node* fin;	
} listx2;

int isEmpty(struct listx2* spisok)
{
	return spisok->first==NULL && spisok->fin==NULL;
}

struct node* find(struct listx2* spisok,int k)
{
	struct node *tmp=spisok->first;
	while(tmp->value!=k){
		if(tmp->n!=NULL){
			tmp=tmp->n;
		}else{
			return 0;
		}
	}
	return tmp;
}

struct node* find_invers(struct listx2* spisok,int k)
{
	struct node *tmp=spisok->fin;
	while(tmp->value!=k){
		if(tmp->bef!=NULL){
			tmp=tmp->bef;
		}else{
			return 0;
		}
	}
	return tmp;
}

void init(struct listx2* spisok,int value)
{
	struct node* tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value=value;
	tmp->n=NULL;
	tmp->bef=NULL;
	spisok->first = tmp;
	spisok->fin = tmp;
}

int push_back(struct listx2* spisok, int x)
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
		struct node *tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->bef=spisok->fin;
		tmp->n=NULL;
		spisok->fin=tmp;
		tmp->bef->n=tmp;
	}
	return 0;
}

int push_front(struct listx2* spisok,int x) 
{
	if(isEmpty(spisok)==1)
		init (spisok,x);
	else
	{
        struct node *tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value=x;
		tmp->bef=NULL;
		tmp->n=spisok->first;
		spisok->first=tmp;
		tmp->n->bef=tmp;
	}
	return 0;
}

int clear(struct listx2* spisok)
{
	if(isEmpty(spisok)==1)
	{
		struct node *tmp=spisok->first;
		struct node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->n;
			free(tmp);
			tmp=temp;
		}
		spisok->first=NULL;
		spisok->fin=NULL;
	}
}

void _remove(struct listx2* spisok, struct node *tmp){
	if(tmp!=NULL){
		if (tmp==spisok->first && tmp==spisok->fin) {
			clear(spisok);
			return;
		}
		if (tmp==spisok->first)
		{
			spisok->first=tmp->n;
			tmp->n->bef=NULL;
		}
		else if(tmp==spisok->fin)
		{
			spisok->fin=tmp->bef;
			tmp->bef->n=NULL;
		}
		else if (tmp!=spisok->first && tmp!=spisok->fin)
		{
			tmp->n->bef=tmp->bef;
			tmp->bef->n=tmp->n;
		}
		free(tmp);
	}
}

int removeLast(struct listx2* spisok,int x)
{
	struct node* element = find_invers(spisok,x);
	if (element!=NULL){
		_remove(spisok,element);
		return 0;
	}
	return -1;
}

int removeFirst(struct listx2* spisok, int x)
{
	struct node* element = find(spisok,x);
	if (element!=NULL){
		_remove(spisok,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct listx2* spisok,int num, int data)
{
	struct node* tmp = spisok->first;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->n;
		if(tmp==NULL) 
			return -1;
	}
	struct node *temp = malloc(sizeof(node));
	temp->value=data;
	temp->n=tmp->n;
	temp->bef=tmp;
	tmp->n->bef=temp;
	tmp->n=temp;  
	return 0;   
}

int insertBefore(struct listx2* spisok,int num, int data)
{
	struct node* tmp = spisok->first;
	for (int i = 1;i<num;i++)
	{
		tmp=tmp->n;
		if(tmp==NULL) 
			return -1;
	}
	struct node *temp = malloc(sizeof(node));
	temp->value=data;
	temp->bef=tmp->bef;
	temp->n=tmp;
	tmp->bef=temp;
	temp->bef->n=temp;      
	return 0; 
}

void print(struct listx2* spisok)
{
	struct node* tmp=spisok->first;
	while(tmp->n!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->n;
	}
	printf("%d\n", tmp->value);
}

void print_invers(struct listx2* spisok)
{
	struct node* tmp=spisok->fin;
	while(tmp->bef!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->bef;
	}
	printf("%d\n", tmp->value);	
}



int main()
{
	int n,a;
	struct listx2* struc=(struct listx2*)malloc(sizeof(struct listx2));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(struc,a);
	}
	print(struc);
	
	int k[3];
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(struc,k[i])!=NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	int m;
	scanf("%d",&m);
	push_back(struc,m);
	print_invers(struc);

	int t;
	scanf("%d",&t);
	push_front(struc,t);
	print(struc);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(struc,j,x);
	print_invers(struc);

	int u,y;
	scanf("%d%d",&u,&y);
	insertBefore(struc,u,y);
	print(struc);
	int z;
	scanf("%d",&z);
	removeFirst(struc,z);
	print_invers(struc);
	int r;
	scanf("%d",&r);
	removeLast(struc,r);
	print(struc);

	clear(struc);
	return 0;
}
