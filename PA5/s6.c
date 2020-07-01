int foo(int a[10], int b[10]){
	int i, s;
	s = 0;
	for(i=0;i<10;i++){
		int j;
		j = 0;
		while(1){
			s += a[i] * b[j];
			if(++j==10){
				break;
			}
		}
		if(a[i] == 0){
			break;
		}
	}
	return s;
}

int main(void){
	int i, x[10], y[10];
	for(i=0;i<10;i++){
		x[i] = 2 * i - 1;
		y[i] = x[i];
		y[i] *= y[i];
	}
	print(foo(x,y));
	return 0;
}