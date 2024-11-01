#include <stdio.h>
#define  INF -1000
typedef int datatype;

typedef struct _node{
	datatype element;
	struct _node *next;
}Node;

typedef struct _Queue{
	Node *front;
	Node *back;
}Queue;

Queue *queueInit(){
	Queue *p = (Queue*)malloc(sizeof(Queue));
	if (p==NULL){
		printf("Error\n");
		exit(0);
	}
	p->back=NULL;
	p->front=NULL;
	return p;
}

Node *makenewNode(datatype x){
	Node *p = (Node*)malloc(sizeof(Node));
	if (p==NULL){
		printf("Error\n");
		exit(0);
	}
	p->element = x;
	p->next = NULL;
}

void enqueue(datatype x, Queue *s){
	Node *tmp = makenewNode(x);
	tmp->next = s->back;
	s->back = tmp;
	if (s->front==NULL) s->front = tmp;
}

datatype dequeue(Queue *s){
	Node *tmp = s->back;
	if (s->front==NULL) return INF;
	datatype x = s->front->element;
	s->front = tmp->next;
	free(tmp);
	return x;
}

int isEmpty(Queue *s){
	if (s->back==NULL) {
		return 1;
	}
	return 0;
}

main(){
	Queue *q = queueInit();
	enqueue(10,q);

	while (isEmpty(q))
	{
		printf("queue: %c\n",dequeue(q));
	}
	return 0;
}
