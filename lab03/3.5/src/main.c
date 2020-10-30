#define N 123
int main() {
	int n1 = 0;
	int n2 = 0;
	n1 = N /100;	
	n2 = N % 100 % 10;
	int n3 = 0;
	n3 = n1 / n2;
	float n4 = n3 * 100;
	int n5 = n4;
	float n6 = n5 / 100.0;
return 0;
}
