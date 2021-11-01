#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct SqStask {
 int *base; //����ռ��ַ 
 int *top; //ջ��ָ�� 
 int stacksize; //ջ�ĳ��� 
}SqStack; 

SqStack InitStack(void){ //����һ����ջ 
    SqStack S;
	S.base = (int *)malloc(sizeof(int));
	if (!S.base) printf("�������");
	S.top = S.base;
	S.stacksize = 0;
	return S;
}//InitStack

SqStack Push(SqStack S,int e){
	//����eΪ�µ�ջ��Ԫ��
	if(S.top - S.base >= S.stacksize) {
		//ջ����׷�Ӵ���ռ�
		S.base = (int *)realloc(S.base,(S.stacksize + 1)*sizeof(int));
		if(!S.base) printf("�������ʧ��"); //�������ʧ�� 
		S.top = S.base+1;
		S.stacksize++; 
	}
	*S.top++ = e;
	return S;
}//Push

int GetTop(SqStack S){  
	//��ջ��Ϊ�գ�����e����S��ջ��Ԫ��
	int e;
	if(S.top == S.base) {
		printf("ERROR");
		return 0;
	}
	e = *(S.top - 1);
	return e;
}//GetTop

int Pop(SqStack S){
	//��ջ��Ϊ�գ�ɾ��ջ��Ԫ�أ���e������ֵ
	if(S.top == S.base) printf("ջΪ��");
	int e;
	e = *--S.top; //��--�ٶ�ȡ 
	return e; 
}//Pop

bool StackEmpty(SqStack S){
	if(S.top == S.base){
       return true;
	}
	else{
	   return false;	
	}
}//StackEmpty

void conversion(void){
	//�������������һ���Ǹ�ʮ������������ӡ��������ֵ�İ˽�����
	int N,e;
	SqStack S;
	scanf("%d",N);
	while(N){
		Push(S, N % 8);
		N = N/8;
	}
	while(!StackEmpty(S)){
		e = Pop(S);
		printf("%d",e);
	}
}//conversion

void LineEdit(){
	//�����ַ���S�����ն˽���һ�в����������ù��̵�������
	SqStack S = InitStack();
	char ch;
	int c;
	ch = getchar(); //���ն˽��յ�һ���ַ� 
	while (ch != EOF){ //EOFΪȫ�Ľ�����
	  while(ch != EOF && ch != '\n') {
	  	switch(ch){
	  		case'#': c = Pop(S); break; //����ջΪ��ʱ��ջ
			case'@': S = InitStack(); break; //����SΪ��ջ
			default: S = Push(S,ch); break; //��Ч�ַ���ջ��δ����ջ����� 
		   }
		  ch = getchar(); //���ն˽�����һ���ַ�
	    }
		S = InitStack(); //����SΪ��ջ 
		if(ch != EOF) ch = getchar();
	} 
}//LineEdit


SqStack InitStack(void);
SqStack Push(SqStack S,int e);
int GetTop(SqStack S);
int Pop(SqStack S);
bool StackEmpty(SqStack S); 
void conversion(void);

int main(void){
 SqStack S;
 bool a;
 S = InitStack();
 a = StackEmpty(S);
 printf("%d\n",a);
 int num,e; //eΪ����ջԪ�أ�numΪȡջ��Ԫ�� 
 e = 9;
 printf("��������ջԪ��:"); 
 scanf("%d",&e);
 S = Push(S,e);
 num = Pop(S);
 printf("%d\n",num);
 printf("%d",StackEmpty(S));
 return 0;
}
