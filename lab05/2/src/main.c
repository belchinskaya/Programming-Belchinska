#define SIMPLENUM 3//задане число
int main () {
	int numberOfDivisors  = 0;
	int result = 0;
	for (int i = 1; i <= SIMPLENUM; i++) {/*якщо число ділиться націло (тобто остача від ділення =0) тільки на 1 та на саме себе, то воно просте*/
		numberOfDivisors = SIMPLENUM % i;
		if (numberOfDivisors == 0 && numberOfDivisors <= 2) {
			result = 1;//число просте
		}
		else { 
			result = 0;//число складене
		}
	}
	int temp_while = 1;
	int result_while = 0;
	int numberOfDivisors_while = 0;
	while (temp_while <= SIMPLENUM) {
		numberOfDivisors_while = SIMPLENUM % temp_while;
		if (numberOfDivisors_while == 0 && numberOfDivisors_while <= 2) {
			result_while = 1;//число просте
		}
		else { 
			result_while = 0;//число складене
		}
		temp_while++;
	}
	int temp_do = 0;
	int result_do = 0;
	int numberOfDivisors_do = 0;
	while (temp_do <= SIMPLENUM) {
		numberOfDivisors_do = SIMPLENUM % temp_do;
		if (numberOfDivisors_do == 0 && numberOfDivisors_do <= 2) {
			result_do = 1;
		}
		else {
			result_do = 0;
		}
		temp_do++;
	}
return 0;
}
