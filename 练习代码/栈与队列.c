#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct SqStask {
 int *base; //储存空间基址 
 int *top; //栈顶指针 
 int stacksize; //栈的长度 
}SqStack; 

SqStack InitStack(void){ //创建一个空栈 
    SqStack S;
	S.base = (int *)malloc(sizeof(int));
	if (!S.base) printf("分配错误");
	S.top = S.base;
	S.stacksize = 0;
	return S;
}//InitStack

SqStack Push(SqStack S,int e){
	//插入e为新的栈顶元素
	if(S.top - S.base >= S.stacksize) {
		//栈满，追加储存空间
		S.base = (int *)realloc(S.base,(S.stacksize + 1)*sizeof(int));
		if(!S.base) printf("储存分配失败"); //储存分配失败 
		S.top = S.base+1;
		S.stacksize++; 
	}
	*S.top++ = e;
	return S;
}//Push

int GetTop(SqStack S){  
	//若栈不为空，则用e返回S的栈顶元素
	int e;
	if(S.top == S.base) {
		printf("ERROR");
		return 0;
	}
	e = *(S.top - 1);
	return e;
}//GetTop

int Pop(SqStack S){
	//若栈不为空，删除栈顶元素，用e返回其值
	if(S.top == S.base) printf("栈为空");
	int e;
	e = *--S.top; //先--再读取 
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
	//对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
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
	//利用字符串S，从终端接受一行并传送至调用过程的数据区
	SqStack S = InitStack();
	char ch;
	int c;
	ch = getchar(); //从终端接收第一个字符 
	while (ch != EOF){ //EOF为全文结束符
	  while(ch != EOF && ch != '\n') {
	  	switch(ch){
	  		case'#': c = Pop(S); break; //仅当栈为非时退栈
			case'@': S = InitStack(); break; //重置S为空栈
			default: S = Push(S,ch); break; //有效字符进栈，未考虑栈满情况 
		   }
		  ch = getchar(); //从终端接收下一个字符
	    }
		S = InitStack(); //重置S为空栈 
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
 int num,e; //e为放入栈元素，num为取栈顶元素 
 e = 9;
 printf("请输入入栈元素:"); 
 scanf("%d",&e);
 S = Push(S,e);
 num = Pop(S);
 printf("%d\n",num);
 printf("%d",StackEmpty(S));
 return 0;
}
