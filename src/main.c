#include <stdio.h>
#include "cbs_iterator.h"

int main(void) {
    int n;

    printf("Введите n: ");
    
    int scan_result = scanf("%d", &n);
    if (scan_result != 1 || n < 0) {
        printf("Ошибка: введите неотрицательное число\n");
        return 1;
    }

    printf("Генерация ПСП для n = %d:\n", n);

    iterator_t it;
    iterator_init(&it, (unsigned)n);

    long long k = 0;

    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);

        printf("%s\n", val->psp);
        k++;

        iterator_next(&it);
    }

    iterator_destroy(&it);

    printf("Найдено последовательностей: %lld\n", k);
    
    return 0;
}