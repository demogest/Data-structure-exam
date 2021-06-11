#include <bits/stdc++.h>

#define MAXTABLESIZE 100000
using namespace std;
typedef struct LNode node,*List,*Pos;
struct LNode
{ 
	string Data;
	string pwd; 
	struct LNode * Next;
}; 

typedef struct TblNode ht,*htb; 
struct TblNode
{
	int size;
	List Heads;
};

void create(htb &h, int size);
void Insert( htb H, int c, string acc, string pass ); 
void release( htb H );

int main() 
{  
	int n, i,comm; 
	string acc, pass; 
	htb H;
	cin>>n;
	create(H,n);
	for(i=0;; i++) 
	{ 
        fflush(stdin);
		cin>>comm;
		if (comm == 0) break;
		cin>>acc>>pass;
		Insert( H, comm, acc, pass ); 
	}  
	delete H;
	return 0;
}

int getPrime( int N ) 
{
	int i, p = (N%2)? N+2 : N+1;
	while( p <= MAXTABLESIZE ) 
	{ 
		for( i=(int)sqrt(p); i>2; i--) 
			if( !(p%i) ) break;
		if( i==2 ) break;
		else p += 2;
	} 
	return p; 
}

void create(htb &H,int size) 
{  
	int i; 
	H = new ht; 
	H->size= getPrime(size); 
	H->Heads = new node[H->size]; 
	for( i=0; i<H->size; i++ ) 
	{ 
		H->Heads[i].Data="";
		H->Heads[i].pwd="";
		H->Heads[i].Next= NULL;  
	} 
	return; 
}

int Hash( string key, int p ) 
{
	int index = stoi(key);
	return (index % p); 
}

Pos Find( htb H, string key ) 
{  
	Pos p; 
	int pos;
	pos = Hash(key, H->size);
	p = H->Heads[pos].Next; 
	while( p && p->Data!=key ) p = p->Next;
	return p;
}

void Insert( htb H, int c, string acc, string pass ) 
{  
	Pos p, tmp; 
	int pos;
	p = Find( H, acc ); 
	if(!p && c == 1) 
	{
		tmp= new node;
		tmp->Data=acc;
		tmp->pwd=pass;
		pos = Hash(acc, H->size);
		tmp->Next = H->Heads[pos].Next; 
		H->Heads[pos].Next= tmp;
		cout<<"create Success\n";
	} 
	else if( !p && c == 2) cout<<"Account not exist\n";
	else if( p && c == 1) cout<<"Account already exist\n";
	else if( p && c == 2)
	{
		if( p->pwd==pass )
			cout<<"Login Success\n";
		else
			cout<<"Wrong pwd\n";
	}
}
