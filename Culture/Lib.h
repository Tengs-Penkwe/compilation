void foobar(int);
void __attribute__((constructor)) init_function(void);
void __attribute__((destructor)) fini_function(void);
