#include <stdbool.h>

int main(){
	int input_number = 37;
	bool res = false;
	for(int i = 2; i*i <= input_number; i++){
		if (input_number%i == 0){
			res = true;
		}
	}
	return 0;
}
