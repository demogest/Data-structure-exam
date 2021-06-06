#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int n,i,j,s1,s2;
	cin>>n;
	if (n==0) return 0;
	q.push(1);
	cout<<"1\n";
	for (i=2;i<=n;i++){
		s1=0;
		for (j=1;j<i;j++){
			s2=q.front();
			cout<<s1+s2<<" ";
			q.pop();
			q.push(s1+s2);
			s1=s2;
		}
		cout<<"1\n";
		q.push(1);
	}
	return 0;
}