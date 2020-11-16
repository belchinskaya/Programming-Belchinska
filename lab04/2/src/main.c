#define X 123.656
int main() {
	int num1 = X * 1000 / 1000;
	int x = X * 1000;
	int num2 = x % 1000;
	float division;
	division = (float) num2 / (float) num1;
	int x1 = division * (float) 100;
	float result = (float) x1 / 100;
	return 0;
}
