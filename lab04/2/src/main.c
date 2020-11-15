#define X 123.656
int main() {
int x3 = 0;
int x4 = 0;
int x5 = 0;
int x1 = X / 1000.0;
int x7 = X * 1000;
int x2 = x7 % 1000;
int x6 = x2;
if (x2>0) {	
	x3 = x1 % x6;
	x4 = x3 * 100;
	x5 = x4 / 100.0;
}
else if (x2 = 0) {
	x5 = x3;
}
return 0;
}
