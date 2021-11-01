
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct{
	struct Sqlist *elem; //储存空间基址
    int length; //当前长度 
	int listsize; //当前分配的储存容量（以sizeof(ElemType)为单位） 
}SqList, *ElemType;

Status InitList_Sq(SqList &L){
	L.elem = (Sqlist *)malloc(LIST_INIT_SIZE *sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); //储存分配失败
	L.length = 0; //空表长度为0
	L.listsize = LIST_INIT_SIZE; //初始储存容量
	return OK; 
}// InitList_Sq


int main(void){
	
}
