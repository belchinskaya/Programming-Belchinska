int main() {

	int k = 2;
	int m = 1;
	int n = 3; 

	int temp; 

		if (k > n) {
			temp = k;
			k = n;
			n = temp;
		}
		if (k > m) {
			temp = k;
			k = m;
			m = temp;
		}
		if (m > n) {
			temp = m;
			m = n;
			n = temp;
		}
	
	return 0;
}
