#include <bits/stdc++.h>
using namespace std;
typedef struct BinarySortTree{
    struct BinarySortTree *left;
    struct BinarySortTree *right;
    int value;
}*bst,node;
bst search(bst root,int key){
    if (root==NULL||key == root->value) return root;
    else if (key<root->value) return search(root->left,key);
    else return search(root->right,key);
}
void insert(bst &root,int key){
    if (root == NULL){
        root= new node;
        root->value=key;
        root->right=root->left=NULL;
        return;
    }
    if (key>root->value)
        insert(root->right,key);
    else if (key<root->value)
        insert(root->left,key);
    return;
}
void dele(bst &root,int key){
    bst fa=root;
    bst find=root;
    while(find!=NULL&&find->value!=key){
        fa=find;
        if (find->value>key){
            find=find->left;
            continue;
        }
        if (find->value<key){
            find=find->right;
            continue;
        }
    }
    if (find==NULL){
        cout<<"Not found\n";
        return;
    }
    if (find->left==NULL&&find->right==NULL){
        if (find == fa){
            root=NULL;
            delete find;
            return;
        }
        if (fa->value>find->value) fa->left=NULL;
        else fa->right=NULL;
        delete find;
        return;
    }
    else if (find->left==NULL){
        if (find == fa){
            root = root->right;
            delete find;
            return;
        }
        if (fa->value>find->value) fa->left=find->right;
        else fa->right=find->right;
        delete find;
        return;
    }
    else if (find->right==NULL){
        if (find == fa){
            root = root->left;
            delete find;
            return;
        }
        if (fa->value>find->value) fa->left=find->left;
        else fa->right=find->left;
        delete find;
        return;
    }
    else{
        bst tmp = find->right;
        bst pa = find;
        while(tmp->left!=NULL){
            pa=tmp;
            tmp=tmp->left;
        }
        if (pa == find){
            tmp->left=find->left;
            if (root == find){
                root=root->right;
                delete find;
                return;
            }
            if (fa->value>tmp->value) fa->left=tmp;
            else fa->right=tmp;
            delete find;
            return;
        }
        else{
            pa->left=NULL;
            tmp->left=find->left;
            tmp->right=find->right;
            if (find == root){
                root=tmp;
                delete find;
                return;
            }
            if (fa->value>tmp->value) fa->left=tmp;
            else fa->right=tmp;
            delete find;
            return;
        }
    }
}
void inorder(bst root){
    if (root==NULL) return;
    cout<<root->value<<" ";
    inorder(root->left);
    inorder(root->right);
}
int main(){
    int n,key;
    bst root=NULL,tmmp;
    cin>>n;
    for (int i=0;i<n;i++){
        insert(root,(cin>>key,key));
    }
    cout<<((tmmp=search(root,(cin>>key,key)),tmmp)==0?"Not found":"Found")<<endl;
    dele(root,(cin>>key,key));
    inorder(root);
    system("pause");
    return 0;
}