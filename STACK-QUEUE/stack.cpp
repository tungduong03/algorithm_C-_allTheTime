#include <bits/stdc++.h>
using namespace std;
#define INF -1000000;
#define datatype int
typedef struct _Node{
	datatype inf;
	struct _Node *next;
} Node;

typedef struct _Stack{
	Node *top; 
} Stack;

Stack *stackInit(){
	Stack *p = (Stack*)malloc(sizeof(Stack));
	if (p==NULL){
		printf("Error\n");
		exit(0);
	}
	p->top=NULL;
	return p;
}

Node *makenewNode(datatype x){
	Node *p = (Node*)malloc(sizeof(Node));
	if (p==NULL){
		printf("Error\n");
		exit(0);
	}
	p->inf=x;
	p->next=NULL;
}

void push(datatype x, Stack *s){
	Node *tmp = makenewNode(x);
	tmp->next = s->top;
	s->top = tmp;
}

datatype pop(Stack *s){
	Node *tmp = s->top;
	if (s->top==NULL) return INF;
	datatype x = s->top->inf;
	s->top = tmp->next;
	free(tmp);
	return x;
}

bool isEmpty(Stack *s){
	if (s->top==NULL) {
		return true;
	}
	return false;
}

void stackDestroy(Stack *s){
	Node *tmp, *p = s->top;
	while (p!=NULL){
		tmp = p->next;
		free(p);
		p=tmp;
	}
	free(s);
}

int main(){
	Stack *s=stackInit();
	push(10,s);
	push(1,s);
	push(5,s);
	
	while (!isEmpty(s)){
		cout<<"pop: "<<pop(s)<<endl;
	}
	
	return 0;
}
