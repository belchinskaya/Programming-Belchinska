#define NUM 3//задане число
int main () {
	int tempFor  = 0;
	int resultFor = 0;
	for (int i = 2; i < NUM; i++) {/*якщо число ділиться націло (тобто остача від ділення =0) на число менше за нього, то воно складене*/
		tempFor = NUM % i;
		if (tempFor == 0) {
			resultFor = 0;//число складене
		} else { 
			resultFor = 1;//число просте
		}
	}
	int i = 2;
	int resultWhile = 0;
	int tempWhile = 0;
	while (i < NUM) {
		tempWhile = NUM % i;
		if (tempWhile == 0) {
			resultWhile = 0;//число складене
		} else { 
			resultWhile = 1;//число просте
		}
		i++;
	}
	int j = 2;
	int resultDo = 0;
	int tempDo = 0;
	do  {
		tempDo = NUM % j;
		if (tempDo == 0) {
			resultDo = 0;//число складене
		} else {
			resultDo = 1;//число просте
		}
		j++;
	} while (j < NUM);
	return 0;
}
