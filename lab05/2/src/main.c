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
return 0;
}
