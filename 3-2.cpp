#include <iostream>
using namespace std;
typedef struct Node{
	int val;
	struct Node *next;
}node,*queue;
int init(queue &q,queue &rear){
	q=rear=NULL;
	return 0;
}
bool isempty(queue &q){
	return q==NULL;
}
int push(queue &q,queue &rear,int x){
	if (q==NULL){
		q=new node;
		if (q==NULL) {cout<<"OVERFLOW\n";return -1;}
		q->val=x;
		q->next=NULL;
		rear=q;
		return 0;
	}
	queue temp=new node;
	if (temp==NULL) {cout<<"OVERFLOW\n";return -1;}
	temp->val=x;
	temp->next=NULL;
	rear->next=temp;
	rear=temp;
	return 0;
}
int pop(queue &q,queue &rear){
	if (isempty(q)) {cout<<"EMPTY\n";return -1;}
	queue temp=q;
	q=q->next;
	delete temp;
	return 0;
}
int main(){
	queue q,rear;
	init(q,rear);
	int n,i,x;
	cin>>n;
	for (i=0;i<n;i++)
		push(q,rear,(cin>>x,x));
	queue h;
	if (!isempty(q)){
		for (h=q;h!=rear;h=h->next)
			cout<<h->val<<" ";
		cout<<h->val<<endl;
	}
	cin>>n;
	for (i=0;i<n;i++)
		pop(q,rear);
	cout<<"Left elem:";
	if (!isempty(q)){
		for (h=q;h!=rear;h=h->next)
			cout<<h->val<<" ";
		cout<<h->val<<endl;
	}
	else cout<<"EMPTY\n";
	return 0;
}