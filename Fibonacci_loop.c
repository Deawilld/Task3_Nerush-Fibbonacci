#include <stdio.h>
#include <locale.h>
void fibonachi(int n) {
     long long a = 0, b = 1, next;

    printf("First %d Fibonacci numbers:\n", n);
    printf("%llu ", a);

    for (int i = 3; i <= n; i++) {
        next = a + b;
        printf("%llu ", next);
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int num_n;
    setlocale(LC_ALL, "Rus");
    printf("Please, enter the number: ");
    scanf("%d", &num_n);

    fibonachi(num_n);

    return 0;
}
