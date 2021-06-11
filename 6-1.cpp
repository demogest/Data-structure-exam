#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int key,vector<int> &a){
    int i=0,j=a.size()-1;
    int mid = (i+j)/2;
    while(key!=a[mid] && i<=j){
        if (key>a[mid]){
            i=mid+1;
            mid = (i+j)/2;
            continue;
        }
        else if (key<a[mid]){
            j=mid-1;
            mid = (i+j)/2;
            continue;
        }
    }
    if (a[mid]==key) return mid;
    return -1;
}
int main(){
    vector<int> a;
    int key,result;
    string s="";
    for (char c=getchar();;c=getchar()){
        if (c==' '){
            a.push_back(stoi(s));
            s="";
            continue;
        }
        if (c=='\n'){
            a.push_back(stoi(s));
            break;
        }
        s=s+c;
    }
    sort(a.begin(),a.end());
    ((result = BinarySearch((cin>>key,key),a),result) != -1)&&cout<<result+1<<endl;
    (result == -1)&&cout<<"Not found\n";
    return 0;
}