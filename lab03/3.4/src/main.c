#define ABCD 1000
int main() {
	int p = 8;
	int a1 = ABCD / 10;
	int b1 = ABCD % 1000 / 100;
	int c1 = ABCD / 100 % 10;
	int d1 = ABCD % 1000 % 100 % 10; 
	int n = d1 + c1 * p + b1 * p * p + a1 * p * p * p;
return 0;
}
