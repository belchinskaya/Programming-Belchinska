int main () {
	int NUM1 = 16;// задане число
	int NUM2 = 20;// задане число
	int nod_while = 0;
	while (NUM1 != 0 && NUM2 != 0) { /*ділимо більше число на менше доки остача від ділення не буде 0*/  
		if (NUM1 > NUM2) {	
			NUM1 %= NUM2;//nod_while = NUM1 % NUM2;
			//NUM1 = NUM2;
			//NUM2 = nod_while;
		} else if (NUM1 < NUM2) {
			NUM2 %= NUM1;//nod_while = NUM2 % NUM1;
			//NUM2 = NUM1;
			//NUM1 = nod_while;
		}
	}
	do { 
		if (NUM1 > NUM2) {      
			NUM1 %= NUM2;//nod_while = NUM1 % NUM2;
                        //NUM1 = NUM2;
                        //NUM2 = nod_while;
		} else if (NUM1 < NUM2) {
			NUM2 %= NUM1;//nod_while = NUM2 % NUM1;
                        //NUM2 = NUM1;
                        //NUM1 = nod_while;
		}      
	} while (NUM1 != 0 && NUM2 != 0);
return 0;
}	
