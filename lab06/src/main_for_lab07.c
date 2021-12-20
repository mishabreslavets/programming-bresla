//#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
void shift_matrix();
int main(){
	srand(20);
	const int N = 4; // граніци масива
	int original_matrix[N][N];
	int result_matrix[N*N];
	for(int i = 0; i<N; i++){  //заповнювання двувимірного масива рандомними числами
		for(int j = 0; j < N; j++){
			original_matrix[i][j] = rand()%10;
		}
	}

        for(int i = 0; i<N; i++){  //заповнювання двувимірного масива з консолі
                for(int j = 0; j < N; j++){
                        scanf("%d", &original_matrix[i][j]);
                }
        }


	int matrix[N*N];
	for(int i = 0; i < N; i++){ // перевод до одновимірного масива
		for(int j = 0; j < N; j++){
			matrix[i * N + j] = original_matrix[i][j];
		}
	}

	shift_matrix(matrix, N, result_matrix);

	int shifted_matrix[N][N]; //перевод обратно до двувимірного виду
	for(int j = 0; j < N; j++){
		for(int k = 0; k < N; k++){
			shifted_matrix[j][k] = result_matrix[j*N+k];
		}
	}
	return 0;
}
void shift_matrix(int matrix[], int N, int result_matrix[]){
	int cur = 0;
	for(int i = 0; i < N; i++){
		cur = matrix[i*N]; // передаю значення першого елемента строки
		for(int j = 0; j < N; j++){
			if(j+1 == N){ //перевірка, чи є ций елемент останнім у строці
				result_matrix[i*N+j] = cur;//якщо так, до передаю значення зы змінної cur
			}else{
				result_matrix[i*N+j] = matrix[i*N+j+1];//якщо ні, то передаю значення наступного елемента
			}
		}
	}
}
