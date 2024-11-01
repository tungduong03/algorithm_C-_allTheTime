#include <bits/stdc++.h>
using namespace std;

struct DNode{
	int val;
	DNode* prev;
	DNode* next;
};
DNode* first;
DNode* last;

DNode* makeNode(int v){
	DNode* p = new DNode;
	p->val=v;
	p->next=NULL;
	p->prev=NULL;
	return p;
}

void remove(DNode* p){
	if (p==NULL) return;
	if (first==last && p=first) {
		first=NULL;
		last=NULL;
		delete p;
		return;
	}
	if (p==first){
		first=p->next;
		first->prev=NULL;
		delete p; 
		return;
	}
	if (p==last){
		last=p->prev;
		last->next=NULL;
		delete p;
		return;
	}
	p->prev->next=p->next; 
	p->next->prev=p->prev;
	delete p;
	return;
}

void insertLast(int x){
	DNode* q = makeNode(x);
	if (first==NULL && last==NULL){
		first=q;
		last=q;
		return;
	}
	q->prev=last;
	last->next=q;
	last=q;
}

void display(){
	DNode q= first;
	while(q!=NULL){
		cout<<q->val<<" ";
		q=q->next;
	}
}
main()
{
	insertLast(3);
	insertLast(4);
	insertLast(5);
}
