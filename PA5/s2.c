int main(void){
	int a[10], i, s;
	for(i=0;i<10;i++){
		a[i] = 2*i + 1;
	}
	i = s = 0;
	while(i<10){
		s += a[i++];
	}
	print(s);
	return 0;
}
