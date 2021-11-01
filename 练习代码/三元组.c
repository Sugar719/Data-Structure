#include<stdio.h>
#define MAXSIZE 12500
//稀疏矩阵的三元组顺序存储表示
typedef struct{
	int i,j; //该非零元的行下标和列下标
	int e; 
}Triple; 
typedef struct{
	Triple data[MAXSIZE+1]; //非零三元组表,data[0]未用
	int mu,nu,tu; //矩阵的行数、列数和非零元个数 
}TSMatrix;

TSMatrix TransposeSMatrix(TSMatrix M){
	TSMatrix T;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if(T.tu){
		int q = 1;
		for(int col = 1; col <= M.nu; ++col)
		 for(int p = 1; p <= M.tu; ++p)
		  if(M.data[p].j == col){
		  	T.data[q].i = M.data[p].j; T.data[q].j = M.data[p].i;
		  	T.data[q].e = M.data[p].e; ++q;}
	}
	return T;
}//TransposeSMatrix
 
TSMatrix FastTransposeSMatrix(TSMatrix M){
	//采用三元组顺序表存储表述，求稀疏矩阵M的转置矩阵T 
	TSMatrix T;
	int num[MAXSIZE],cpot[MAXSIZE],col,t,p,q;
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if(T.tu){
		for(col = 1; col <= M.nu; ++col) num[col] = 0;
		for(t = 1; t <= M.tu; ++t) ++num[M.data[t].j]; //求M中每一列含非零元素的个数
		cpot[1] = 1;
		//求第col列中第一个非零元在b.data中的序号
		for(col = 2; col <= M.tu; ++col) cpot[col]=cpot[col-1]+num[col-1];
		for(p = 1; p <= M.tu; ++p){
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j; T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e; ++cpot[col];
		}//for
	}//if
	return T;
}//FastTransposeSMatrix

TSMatrix TransposeSMatrix(TSMatrix M);
TSMatrix FastTransposeSMatrix(TSMatrix M);

int main(){
	TSMatrix M,T;
	M.data[1].e = 1;
	M.data[1].i = 1;
	M.data[1].j = 1;
	
	M.data[2].e = 2;
	M.data[2].i = 2;
	M.data[2].j = 1;
	
	M.data[3].e = 3;
	M.data[3].i = 3;
	M.data[3].j = 1;
	//矩阵为第一列1，2，3
	 
	M.mu = 3;
	M.nu = 3;
	M.tu = 3;
	
	for(int i=1;i<=3;i++){
		printf("M中元素:%d,行数:%d,列数:%d\n",M.data[i].e,M.data[i].i,M.data[i].j);
	}//输出原矩阵M 
	
	//T = TransposeSMatrix(M);
	T = FastTransposeSMatrix(M);
	
	for(int i=1;i<=3;i++){
		printf("T中元素:%d,行数:%d,列数:%d\n",T.data[i].e,T.data[i].i,T.data[i].j);
	}//输出现矩阵
	return 0;
}













