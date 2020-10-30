#define NUM 1654
int main() {
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	n1 = NUM / 1000;
	n2 = NUM % 1000 / 100;
	n3 = NUM% 100 / 10;
	n4 = NUM % 1000 % 100 % 10;
	n5 = n1 + n2 + n3 + n4;
return 0;
}
