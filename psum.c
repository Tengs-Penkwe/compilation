void psum1(float a[], float p[], long n) {
	p[0] = a[0];
	for(long i = 1; i < n; i++) {
		p[i] = p[i-1] + a[i];
	}
}
