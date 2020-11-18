#define PI 3.14
#define R 3

int main() {
	char F = 'L';
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
