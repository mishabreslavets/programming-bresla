int main(){
	const int N = 4; // граніци масива
	int original_matrix[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	int cur = 0;
	for(int i = 0; i < N; i++){
		cur = original_matrix[i][0]; // передаю значення першого елемента строки
		for(int j = 0; j < N; j++){
			if(j+1 == N){ //перевірка, чи є ций елемент останнім у строці
			original_matrix[i][j] = cur;//якщо так, до передаю значення зы змінної cur
			}else{
			original_matrix[i][j] = original_matrix[i][j+1];//якщо ні, то передаю значення наступного елемента
			}
		}
	}
	return 0;
}
