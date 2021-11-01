#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	float coef; //系数 
	int expon; //指数 
	struct node *next; 
}node, *Polynomial;



Polynomial CreatPolyn(Polynomial P){
	Polynomial s;
	Polynomial head;
	char a = 'a';
	//P = (node*)malloc(sizeof(struct node));
	head = P; //存放头结点 
	P->next = NULL;	//头结点初始化 
	while(a != '\n'){
		s = (struct node*)malloc(sizeof(struct node));
		scanf("%f %d",&s->coef,&s->expon); //给s结点赋值 
		s->next = P->next;
		P->next = s;
	    scanf("%c",&a);
	}
	return head;
}


Polynomial AddPolyn(Polynomial Pa,Polynomial Pb){
	Polynomial p1,p2,p3;  
	float sum; //系数之和 
	p1 = Pa->next; //指向Pa的当前结点 
	p2 = Pb->next; //指向Pb的当前结点 
	p3 = Pa; //位置指针，指向和多项式Pa,使用p3修改Pa 
	Polynomial r; //待释放空间的临时结点
	 
	while(p1 && p2){
	  if(p1->expon == p2->expon){ //Pa当前指数等于Pb
		sum = p1->coef+p2->coef;
		 if(sum!=0){
			p1->coef = sum;
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
			r = p2;
			p2 = p2->next;free(r);}
		 else{ //当和为0时，向后移动一个结点 
			r = p1->next; free(p1); p1 = r;
			r = p2->next; free(p2); p2 = r;}
	 }
	 else if(p1->expon < p2->expon){ //Pa当前指数小于Pb 
			//Pa的当前结点不变，Pb的位置向后移 
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
			
	 }
	 else{ //Pa当前指数大于Pb 
		   //Pb当前位置加到Pa当前位置之前，Pb向后一位，Pa向后一位 
            p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
	}
 if(p1 != NULL){ //如果Pa未结束，将其全部链接到p3 
  p3->next = p1;
 }
 else{ //如果Pb未结束，将其全部链接到p3 
  p3->next = p2;
 }
 return Pa;
}

void Print(Polynomial P,int n){
	int i =0;
	Polynomial P1,P2;
	P2 = P;
	P1 = P;
	for(i=0;i<n;i++){
		P2 = P1;
		P1 = P; 
		P = P->next;}
	if(P2 != NULL){
	 if(P->expon > P1->expon) printf("%.1f %d",P1->coef,P1->expon);
	 else printf("%.1f %d",P->coef,P->expon);}
	return;
}

Polynomial CreatPolyn(Polynomial P);
Polynomial AddPolyn(Polynomial Pa,Polynomial Pb);
void Print(Polynomial P1,int n);


int main( ){
	Polynomial P1, P2;
	int n;
	P1 = (node*)malloc(sizeof(struct node));
	P1 = CreatPolyn(P1);
	P2 = (node*)malloc(sizeof(struct node));
	P2 = CreatPolyn(P2);
	P1 = AddPolyn(P1,P2);
	scanf("%d",&n);
	//printf("%.1f %d",P1->next->coef,P1->next->expon);
	Print(P1,n);
	return 0;
}

