#include <iostream>
#define MAXN 10000

using namespace std;
typedef struct queue{
	int a[MAXN];
	int front;
	int rear;
}que;
int init(que &q){
	q.front=q.rear=0;
	return 0;
}
bool isempty(que &q){
	return (q.rear-q.front+MAXN)%MAXN == 0;
}
int push(que &q,int x){
	if((q.rear+1)%MAXN==q.front){
		cout<<"OVERFLOW\n";
		return -1;
	}
	q.a[q.rear]=x;
	q.rear=(q.rear+1)%MAXN;
	cout<<q.a[q.rear-1]<<" Pushed\n";
	return 0;
}
int pop(que &q){
	if (isempty(q)){
		cout<<"EMPTY\n";
		return -1;
	}
	cout<<q.a[q.front]<<" Poped\n";
	q.front++;
	q.front%=MAXN;
	return 0;
}

int main(){
	que q;
	init(q);
	int i,n;
	cin>>n;
	for (i=0;i<n;i++){
		int x;
		push(q,(cin>>x,x));
	}
	int leng;
	cin>>leng;
	for (i=0;i<leng;i++)
		pop(q);
	return 0;
}