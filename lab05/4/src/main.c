#define NUM 6 //задане число
int main () {
	int sum = 0;
	int temp_for = 0;
	int result_for = 0;
	for (int i = 1; i < NUM; i++) {//ділимо дане число націло (тобто остача = 0)
		temp_for = NUM % i;
		if (temp_for == 0) {//якщо остача від ділення 0 - сумуємо дільники
			sum += i;
		} 
	}
	if (sum == NUM) {
		result_for = 1;//число досконале
	}
	else {
		result_for = 0;//число не досконале
	}
	int sum_while = 0;
	int temp_while = 0;
	int result_while = 0;
	int step_while = 1;//ділимо дане число націло
	while (step_while < NUM) {
		temp_while = NUM % step_while;
		if (temp_while == 0) {//якщо остача від ділення 0 - сумуємо дільники
			sum_while += step_while;
		}
	step_while++;
	}
	if (sum == NUM) {
		result_while = 1;//число досконале
	}
	else {
		result_while = 0;//число не досконале
	}


	
	int sum_do = 0;
	int temp_do = 0;
	int result_do = 0;
	int step_do = 1;
	do {
		temp_do = NUM % step_do;
		if (temp_do == 0) {
			sum_do += step_do;
		}
	step_do++;
	} while (step_do < NUM);
	if (sum == NUM) {
		result_do = 1;//число досконале
	}
	else {
		result_do = 0;//число не досконале
	}

return 0;
}
