/**
 * @mainpage
 * # Загальне завдання
 * 1.Переробити програми, що були розроблені під час виконання лабораторних робіт з тем
 * “Масиви” та “Цикли” таким чином, щоб використовувалися функції для обчислення результату.
 * Функції повинні задовольняти основну їх причетність - уникати дублювання коду. Тому,
 * для демонстрації роботи, ваша програма (функція main()) повинна мати можливість викликати
 * розроблену функцію з різними вхідними даними.
 *
 * @author Breslavets M.Y.
 * @date 21-dec-2021
 */

/**
 * @file main.c
 *
 * @brief Основна програма, яка виконує завдання.
 *
 * @author Kbreslavets M.Y.
 * @return Повертає статус виходу
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void shift_matrix();
bool is_simple();
int main(){
	srand(20);
	int input_number = 37; //введення числа на перевірку
	scanf("%d", &input_number);
	bool res = is_simple(input_number); //змінна що буде відповідати за результат
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
/**
 * @brief Переверяє чи є число простим, чи складеним
 *
 * Программа розглядає число та діле його послідовно на числа від 0 до кореня від цього числа
 *
 * @param input_number Введене число
 *
 * @return Повертає результат перевірки
 */

bool is_simple(int input_number){
	for(int i = 2; i*i <= input_number; i++){ 
		if (input_number%i == 0){ //перевірка на цілочисленне ділення тобто складенність
			return false;
		}
	}
	return true;

}
/**
 * @brief Звус матриці по рядках вліво
 *
 * Программа циклічно зсуває елементи вліво зі збереженням першого у кінці
 *
 * @param N Розмір масива
 *
 * @param matrix Масив, що треба зсунити
 *
 * @param result_matrix Масив, у який записується результат
 */

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
