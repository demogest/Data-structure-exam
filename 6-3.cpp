#include <bits/stdc++.h>

#define MAXSIZE 100000
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
void execute( htb &h, int c, string acc, string pass ); 

int main() 
{  
	int n, i,command; 
	string acc, pass; 
	htb h;
	cin>>n;
	create(h,n);
	for(i=0;; i++) 
	{ 
		cout<<"1.Sign up\n2.Sign in\n0.Exit\nInput('chose number' 'account' 'password'):";
        fflush(stdin);
		cin>>command;
		if (command == 0) break;
		cin>>acc>>pass;
		execute( h, command, acc, pass ); 
	}  
	delete h;
	return 0;
}

int getPrime( int N ) 
{
	int i, p = (N%2)? N+2 : N+1;
	while( p <= MAXSIZE ) 
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

void execute( htb &h, int c, string acc, string pass ) 
{  
	Pos p, tmp; 
	int pos;
	p = Find( h, acc ); 
	if(!p && c == 1) 
	{
		tmp= new node;
		tmp->Data=acc;
		tmp->pwd=pass;
		pos = Hash(acc, h->size);
		tmp->Next = h->Heads[pos].Next; 
		h->Heads[pos].Next= tmp;
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
