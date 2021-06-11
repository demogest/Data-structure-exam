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

void Create(htb &h, int size);
void Insert( htb H, char C, string acc, string pass ); 
void release( htb H );

int main() 
{  
	int n, i;
	char comm; 
	string acc, pass; 
	htb H;
	cin>>n;
	Create(H,n);
	for(i=0; i<n; i++) 
	{ 
        fflush(stdin);
		cin>>comm>>acc>>pass;
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

void Create(htb &H,int size) 
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

void Insert( htb H, char C, string acc, string pass ) 
{  
	Pos P, tmp; 
	int pos;
	P = Find( H, acc ); 
	if(!P && C == 'n') 
	{
		tmp= new node;
		tmp->Data=acc;
		tmp->pwd=pass;
		pos = Hash(acc, H->size);
		tmp->Next = H->Heads[pos].Next; 
		H->Heads[pos].Next= tmp;
		cout<<"Success\n";
	} 
	else if( !P && C == 'l') cout<<"Not Exist\n";
	else if( P && C == 'n') cout<<"Exist\n";
	else if( P && C == 'l')
	{
		if( P->pwd==pass )
			cout<<"Success\n";
		else
			cout<<"Wrong pwd\n";
	}
}
