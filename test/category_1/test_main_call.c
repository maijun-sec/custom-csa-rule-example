// RUN: %clang_analyze_cc1 -verify %s \
// RUN:   -load %llvmshlibdir/libCustomCSARuleCategory1%shlibext \
// RUN:   -analyzer-checker='example.MainCallChecker'

typedef int (*main_call)(int, char **);

int main(int argc, char **argv) {
    main_call foo = main;
    int ret = foo(argc, argv); // expected-warning {{call to main}}
    return ret;
}
