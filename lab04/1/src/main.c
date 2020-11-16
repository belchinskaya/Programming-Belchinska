#define PI 3.14
#define R 3
//#define L 18.84
//#define S 28.26
//#define V 113.04
int main() {
	int F;
	char str1 = 'L';
	char str2 = 'S';
	char str3 = 'V';
	int result;
	switch(F) {
		case 'L':
			result = 2 * PI * R;
			break;
		case 'S':
			result = PI * R * R;
			break;
		case 'V': 
			result = 4 / 3 * (PI * R * R * R);
			break;
	}
	return 0;
}
