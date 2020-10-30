int main() {
	int k=2;
	int m=1;
	int n=3; 
	int min;
	int max; {
		k<m ? min=k : min=m;
		k< n ? min=k : min=n;
		n<m ? min=n : min=m;
		k>m ? max=k : min=m;
		k>n ? min=k : min=n;
		n>m ? min=n : min=m;
	}
return 0;
}