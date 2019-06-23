#include <stdio.h>
#include<stdlib.h>

typedef struct node { //инициализация структуры 
//в которой будут хранится значения элементов списка и ссылки на них
 	int v;
	struct node *next;
} node;

typedef struct list{//инициализация структуры в которой будет хранится первое значение списка		
	struct node* first;	
} list;


void init( list* struc,int x)//инициализация 
{
    node* t = ( node*)malloc(sizeof( node));
	t->v=x;
	t->next=NULL;
	struc->first = t;
}
int isEmpty( list* struc)//проверка на пустоту
{
	if (struc ->first == NULL)
	return 1;
}
 node* find( list* struc,int x)// поиск определенного значения
{
	 node *t_=( node*)malloc(sizeof(node));
	t_=struc->first;
	while(t_->v!=x){
		if(t_->next!=NULL)
			t_=t_->next;
		else
			return 0;
	}
	return t_;
}


int push_back( list* struc, int x)//вставка назад
{
	if(isEmpty(struc)==1)
		{
		    init (struc,x);
		}
	else
	{
		node* t = ( node*)malloc(sizeof( node));
		t->v=x;
		t->next=NULL;
	    node* te = (node*)malloc(sizeof(node));
	    te = struc->first;
		while(te->next!=NULL)
			
			    te=te->next;
			
		te->next=t;
			
		
	}
	return 0;
}

int push_front( list* struc,int x) //вставка вперед
{
	if(isEmpty(struc)==1)
		init (struc,x);
	else
	{
		node *t = ( node*)malloc(sizeof( node));
		t->v=x;
		t->next=struc->first;
		struc->first=t;
	}
	return 0;
}

int removeFirst( list* struc, int x)//удаление первого элемента
{
    node* elem = (node *)malloc(sizeof(node));
    elem = find(struc,x);
	if (elem!=NULL){
		
		if (elem==struc->first)
			struc->first=elem->next;
		else
		{
			node *te = ( node*)malloc(sizeof(node));
			te=struc->first;
			while(te->next!=elem)
				te=te->next;
			te->next = elem->next;
		}
		free(elem);
	
		return 0;
	}
	return 1;
}

int insertAfter	( list* struc,int num, int x)// вставка после определенного элемента
{
	 node *te = ( node* )malloc(sizeof(node));
	te->v=x;

	node* t = ( node* )malloc(sizeof(node)); 
	t = struc->first;
	node* r = ( node* )malloc(sizeof(node)); 
	r = struc->first;
	
	for (int i = 1;i<num+1;i++)
	{
		r=t;
		t=t->next;
		if(t==NULL) 
			return -1;
	}
	r->next=te;
	te->next=t;
	return 0;   
}

void print( list* struc)// вывод списка
{
	 node* t=(node *)malloc(sizeof(node));
	 t=struc->first;
	while(t->next!=NULL)
	{
		printf("%d ", t->v);
		t=t->next;
	}
	printf("%d\n", t->v);
}


int clear( list* list_)//очищение списка (Стратхольма)
{
	
		 node * t =(node*)malloc(sizeof(node));
		 t=list_->first;
		 node *te=(node*)malloc(sizeof(node));
		 te=NULL;
		while(t!=NULL)
		{
			te=t->next;
			free(t);
			t=te;
		}
		list_->first=NULL;
	
}

int main()
{
	int a,y,k[3],m,t,j,x,z;
    list* list_= (list*)malloc(sizeof( list));	
	scanf("%d",&a);
	for (int i=0;i<a;i++)
	{
		scanf("%d",&y);
		push_back(list_,y);
	}
	print(list_);
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(list_,k[i])!=NULL)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	scanf("%d",&m);
	push_back(list_,m);
	print(list_);
	scanf("%d",&t);
	push_front(list_,t);
	print(list_);
	scanf("%d%d",&j,&x);
	insertAfter(list_,j,x);
	print(list_);
	scanf("%d",&z);
	removeFirst(list_,z);
	print(list_);
	clear(list_);
	return 0;
}
