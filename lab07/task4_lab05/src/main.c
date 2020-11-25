#include <stdio.h>
#include <time.h>

int get_num_type_for(int num);
int get_num_type_while(int num);
int get_num_type_do(int num);
int main() {

	srand(time(NULL));
	int x = rand() % 25 + 3;//генерація числа

	int result_for = get_num_type_for(x);
	int result_while =  get_num_type_while(x);
	int result_do =  get_num_type_do(x);
	return 0;
}

int get_num_type_for(int num) {
	int sum = 0;
	int temp_for = 0;
	int result_for = 0;
	for (int i = 1; i < num; i++) {//ділимо дане число націло (тобто остача = 0)
		temp_for = num % i;
		if (temp_for == 0) {//якщо остача від ділення 0 - сумуємо дільники
			sum += i;
		} 
	}
	if (sum == num) {
		result_for = 1;//число досконале
	}
	else {
		result_for = -1;//число не досконале
	}
	return result_for;
}


int get_num_type_while(int num) {
	int sum_while = 0;
	int temp_while = 0;
	int result_while = 0;
	int step_while = 1;//ділимо дане число націло
	while (step_while < num) {
		temp_while = num % step_while;
		if (temp_while == 0) {//якщо остача від ділення 0 - сумуємо дільники
			sum_while += step_while;
		}
	step_while++;
	}
	if (sum_while == num) {
		result_while = 1;//число досконале
	}
	else {
		result_while = -1;//число не досконале
	}
	return result_while;
}


int get_num_type_do(int num) {
	int sum_do = 0;
	int temp_do = 0;
	int result_do = 0;
	int step_do = 1;
	do {
		temp_do = num % step_do;
		if (temp_do == 0) {
			sum_do += step_do;
		}
	step_do++;
	} while (step_do < num);
	if (sum_do == num) {
                result_do = 1;//число досконале
        }
        else {
                result_do = -1;//число не досконале
        }
        return result_do;
}
