#include <bits/stdc++.h>
using namespace std;
typedef struct _Node{
	int value;  //luu gia tri cua node
	struct _Node* next;  //con tro chi den node tiep theo
	
}Node;

Node* head; //tao 1 con tro node

Node* makeNewNode(int X){  //tao ham makeNewNode voi dau vao la gia tri cua node do, gia tri tra ve là 1 con tro
	Node* p = NULL; //tao con tro node voi gia tri tro den la NULL
	p = (Node*)malloc(sizeof(Node));  //cap phat dong bo nho cho p
	if (p==NULL){		//neu con tro den la NUll thì in ra bi loi
		printf("Error in mem alloc\n");   //chua cap phat thanh cong
		exit(0);			//thoat ham
	}
	p->value=X;			//gan gia tri X cho value node		
	p->next=NULL;		//gan con tro node = NULL
	
	return p;
}

Node* insertAfter(Node* h, Node* p, int x){
	if (p == NULL) return h;
	Node* q = makeNewNode(x);
	if (h == NULL) return q;
	q->next = p->next;
	p->next = q;
	return h;
}

Node* insertAfter(node* head, node* p, int X)    //insert 1 node phía sau p
{
	if (p==NULL) 
}

void display(Node* head){
	Node* p = head; //gan p tro den node dau tien
	printf("\n");
	while(p!=NULL){
		printf("%d ",p->value);	//print value cua p
		p=p->next;	//gan p bang con tro tiep theo
	}
}

int main(){
	Node *old_p,*p,*head=NULL;
	int i;
	
	
	//tao danh sach 1000 node value tu 1 --> 1000
	for(i=1;i<1001;i++){
		p=makeNewNode(i);
		if(i==1){
			head=p;  //neu là gia tri dau thi gan con tro cho head
		}
		else{
			old_p->next=p;
		}
		old_p=p;
	}
	
	display(head);
}



















