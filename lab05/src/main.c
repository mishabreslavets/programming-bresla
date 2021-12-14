#include <stdbool.h>

int main(){
	int input_number = 37; //введення числа на перевірку
	bool res = false; //змінна що буде відповідати за результат
	for(int i = 2; i*i <= input_number; i++){ 
		if (input_number%i == 0){ //перевірка на цілочисленне ділення тобто складенність
			res = true;
		}
	}
	return 0;
}
