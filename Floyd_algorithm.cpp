//алгоритм Флоида
//по матрице весов(С) находит все кратчайшие пути в графе
//в даннном случае матрица весов задается рандомно
//Закомментированный участок кода, где происходит присвоение ячейкам матрицы определенный значений предназначен
//для демонстрации правильности работы программы.

#include "stdio.h"
#include "stdlib.h"

#define N 6
#define MAX 1000

int main(){
	int i, j, k, l;
	int C[N][N],H[N][N],T[N][N];
	//С-матрица весов
	//Т-матрица кратчайших путей
	//Н-матрица предшествований
	printf("Start matrix:\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (rand() % 3 == 0)
				C[i][j] = MAX;
			else
				C[i][j] = rand() % 9+1;
			if (i == j)
				C[i][j] = 0;
		}
	}
	/*
	C[0][0] = 0; C[0][1] = 6; C[0][2] = MAX; C[0][3] = 10; C[0][4] = 12; C[0][5] = MAX;
	C[1][0] = MAX; C[1][1] = 0; C[1][2] = 6; C[1][3] = MAX; C[1][4] = MAX; C[1][5] = MAX;
	C[2][0] = MAX; C[2][1] = MAX; C[2][2] = 0; C[2][3] = MAX; C[2][4] = MAX; C[2][5] = 6;
	C[3][0] = MAX; C[3][1] =4 ; C[3][2] =8 ; C[3][3] = 0; C[3][4] = 6; C[3][5] = 14;
	C[4][0] = MAX; C[4][1] = 7; C[4][2] = 5; C[4][3] = MAX; C[4][4] = 0; C[4][5] = 10;
	C[5][0] = MAX; C[5][1] = MAX; C[5][2] = MAX; C[5][3] = MAX; C[5][4] = MAX; C[5][5] = 0;
	*/
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d\t", C[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			T[i][j] = C[i][j];
			if (C[i][j] == MAX)
				H[i][j] = 0; //нету дуги из i в j
			else
				H[i][j] = j+1; //есть дуга из i в j
			if (i == j)
				H[i][j] = 0;
		}
	printf("T:\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d\t", T[i][j]);
		}
		printf("\n");
	}
	printf("H:\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d\t", H[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++)
	{
		printf("i=%d\n",i);
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				if ((i != j) && (T[j][i] != MAX) && (i != k) && j!=k && (T[i][k] != MAX) )
					if ((T[j][k] == MAX) || (T[j][k] > (T[j][i] + T[i][k])))
					{
						H[j][k] = H[i][j]; //запомнить новый путь 
						T[j][k] = T[j][i] + T[i][k];//и его длину
						printf("H[%d,%d]=%d, T=[%d,%d]=%d\n", j, k, H[j][k], j, k, T[j][k]);
					}
		l = 1;
		for (j = 0; j < N; j++)
		{
			if (T[i, j] < 0)
				l=0;
		}
		if (l == 0)
			break;
	}
	printf("Result\n");
	printf("T:\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d\t", T[i][j]);
		}
		printf("\n");
	}
	printf("H:\n");
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			printf("%d\t", H[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
