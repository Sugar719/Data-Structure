#include<stdio.h>
#include<stdlib.h>


struct BiNode{
	char data;
	struct BiNode *lchild, *rchild;
};

//先序创建二叉树
struct BiNode *CreateBiTree(){
	char ch;
	struct BiNode *T;
	scanf("%c", &ch);
	if(ch == '#'){
		T = NULL;
	}
	else
	{
		T = (struct BiNode *)malloc(sizeof(struct BiNode));
		T->data = ch;
		T->lchild = CreateBiTree(); 
		T->rchild = CreateBiTree();
		
	}
	return T;
} 

//层序遍历 
void Inorder(struct BiNode *root){
	int i = 0;
	struct BiNode *p,*a[100];
	p = root;
	while(i!=0 || p!=NULL){
		while(p!=NULL){
			i++;
			a[i]=p;
			p = p->lchild;
			
		}
		if (i != 0){
			p = a[i];
			i--;
			printf("%c a", &p->data);
			p = p->lchild;			
		}
	}
	
}

struct BiNode *CreateBiTree();
void Inorder(struct BiNode *root);

int main(){
	struct BiNode *T;
	T = CreateBiTree();
	Inorder(T);
	return 0;
}







