#define N 3
#define M 4
int main()

{
	int P1=1;
	for (int i=1; i<=M; i++) {
		P1 *= N;	
	}
	int P2=1;
	int q=1;
	while (q<=M) {
		P2 *= N;
		q++;
	}
	int P3=1;
	int j=1;
	do {
		P3 *= N;
		j++;
	} while (j<=M);
return 0;
}
