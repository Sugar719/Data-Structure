
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct{
	struct Sqlist *elem; //����ռ��ַ
    int length; //��ǰ���� 
	int listsize; //��ǰ����Ĵ�����������sizeof(ElemType)Ϊ��λ�� 
}SqList, *ElemType;

Status InitList_Sq(SqList &L){
	L.elem = (Sqlist *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); //�������ʧ��
	L.length = 0; //�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE; //��ʼ��������
	return OK; 
}// InitList_Sq


int main(void){
	
}
