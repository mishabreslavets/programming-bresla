#include <stdbool.h>
bool is_simple();
int main(){
	int input_number = 37; //введення числа на перевірку
	scanf("%d", &input_number);
	bool res = is_simple(input_number); //змінна що буде відповідати за результат
	return 0;
}
bool is_simple(int input_number){
	for(int i = 2; i*i <= input_number; i++){ 
		if (input_number%i == 0){ //перевірка на цілочисленне ділення тобто складенність
			return false;
		}
	}
	return true;

}
