int add2(int x, int y) {
	int n;
	n = x + y;
	return n * 2;
}
int foo(int x, int y, int z) {
	int a, b;
	a = 2;
	return b = add2(a, y+z*3);
}
int bar(void) {
	foo(2020, 6, 2);
}