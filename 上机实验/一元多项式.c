#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	float coef; //ϵ�� 
	int expon; //ָ�� 
	struct node *next; 
}node, *Polynomial;



Polynomial CreatPolyn(Polynomial P){
	Polynomial s;
	Polynomial head;
	char a = 'a';
	//P = (node*)malloc(sizeof(struct node));
	head = P; //���ͷ��� 
	P->next = NULL;	//ͷ����ʼ�� 
	while(a != '\n'){
		s = (struct node*)malloc(sizeof(struct node));
		scanf("%f %d",&s->coef,&s->expon); //��s��㸳ֵ 
		s->next = P->next;
		P->next = s;
	    scanf("%c",&a);
	}
	return head;
}


Polynomial AddPolyn(Polynomial Pa,Polynomial Pb){
	Polynomial p1,p2,p3;  
	float sum; //ϵ��֮�� 
	p1 = Pa->next; //ָ��Pa�ĵ�ǰ��� 
	p2 = Pb->next; //ָ��Pb�ĵ�ǰ��� 
	p3 = Pa; //λ��ָ�룬ָ��Ͷ���ʽPa,ʹ��p3�޸�Pa 
	Polynomial r; //���ͷſռ����ʱ���
	 
	while(p1 && p2){
	  if(p1->expon == p2->expon){ //Pa��ǰָ������Pb
		sum = p1->coef+p2->coef;
		 if(sum!=0){
			p1->coef = sum;
			p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
			r = p2;
			p2 = p2->next;free(r);}
		 else{ //����Ϊ0ʱ������ƶ�һ����� 
			r = p1->next; free(p1); p1 = r;
			r = p2->next; free(p2); p2 = r;}
	 }
	 else if(p1->expon < p2->expon){ //Pa��ǰָ��С��Pb 
			//Pa�ĵ�ǰ��㲻�䣬Pb��λ������� 
			p3->next = p2;
			p3 = p3->next;
			p2 = p2->next;
			
	 }
	 else{ //Pa��ǰָ������Pb 
		   //Pb��ǰλ�üӵ�Pa��ǰλ��֮ǰ��Pb���һλ��Pa���һλ 
            p3->next = p1;
			p3 = p3->next;
			p1 = p1->next;
		}
	}
 if(p1 != NULL){ //���Paδ����������ȫ�����ӵ�p3 
  p3->next = p1;
 }
 else{ //���Pbδ����������ȫ�����ӵ�p3 
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

