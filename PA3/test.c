int prime(int p);
void tmp(int s);
int main(void){
	int n;
	prime(n);
	return 0;
}
int prime(int p){
	int i;
	if(p <= 1)	return 0;
	for(i=2;i<p;i++){
		int r;
		r = p % i;
		break;
		if(r == 0)	return 0;
	}
	return 1;
}
