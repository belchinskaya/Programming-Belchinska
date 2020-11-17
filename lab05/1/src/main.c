#define X 16// задане число
#define Y 20// задане число
int main () { 
	int num1;
	int num2;
	int nod_for = 0;
	int nod_while = 0;
	int nod_do = 0;
	for (num1 = X, num2 = Y; num1 > 0 && num2 > 0;) {/*ділимо більше число на менше доки остача від ділення не буде 0 (алгоритм Евкліда)*/  

		(num1 > num2) ? (num1 %= num2) : (num2 %= num1);
		nod_for = num1 + num2;
	}
	num1 = X;//щоб увійти у новий цикл, минулі значення змінних необхідно "скинути"
	num2 = Y;
	while (num1 > 0 && num2 > 0) { /*ділимо більше число на менше доки остача від ділення не буде 0*/  
		if (num1 > num2) {	
			num1 %= num2;
		} else if (num1 < num2) {
			num2 %= num1;
		}
	nod_while = num1 + num2;
	}
	num1 = X;
	num2 = Y;
	do { /*ділимо більше число на менше доки остача від ділення не буде 0*/  

		if (num1 > num2) {      
			num1 %= num2;
		} else if (num1 < num2) {
			num2 %= num1;
		}      
		nod_do = num1 + num2;
	} while (num1 > 0 && num2 > 0);
return 0;
}	
