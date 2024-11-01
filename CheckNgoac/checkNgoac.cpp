#include <bits/stdc++.h>
using namespace std;
#define INF '#';
#define datatype char
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
Stack *s=stackInit();


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

int match(char a, char b){
	if (a=='{' && b=='}') return 1;
	if (a=='[' && b==']') return 1;
	if (a=='(' && b==')') return 1;
	return 0;
}

bool solve(char* x, int n, Stack *s){
	for(int i = 0; i <= n-1; i++){
		if (x[i] == '[' || x[i] == '(' || x[i] == '{'){
			push(x[i], s);
		}
		else {
			if(isEmpty(s)){
				return false;
			}
			else {
			char c = pop(s); 
			if(!match(c,x[i]))  return false;
			}
		}
	}
	return isEmpty(s);
}

int main(){
	
	datatype x[6]={'[','{','(',')','}','}'};
	cout<<solve(x,6,s);
	return 0;
}
