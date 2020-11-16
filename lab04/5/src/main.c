#define X -2
int main() {
	int y = 0;
	if (X < -1) {
		y = -1 * X - 1;
	}
	else if (X == -1) {
		y = 0;
	}
	else if (X != 0) {
		y = 1;
	}
	else if (X == 1) {
		y = 0;
	}
	else if (X > 1) {
		y = X - 1;
	}
	return 0;
}
