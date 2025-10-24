#include <stdio.h>
#include <stdlib.h>
#include "cbs_iterator.h"

void test_n0() {
    printf("Для n=0: \n");
    iterator_t it;
    iterator_init(&it, 0);
    
    int count = 0;
    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);
        printf("ПСП: '%s'\n", val->psp,);
        count++;
        iterator_next(&it);
    }
    
    printf("Всего последовательностей: %d\n", count);
    printf("Результат: %s\n\n", count == 1 ? "Верно" : "Не верно");
    
    iterator_destroy(&it);
}

void test_n1() {
    printf("Для n=1: \n");
    iterator_t it;
    iterator_init(&it, 1);
    
    int count = 0;
    printf("Все ПСП для n=1:\n");
    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);
        printf("  %s\n", val->psp);
        count++;
        iterator_next(&it);
    }
    
    printf("Всего последовательностей: %d\n", count);
    printf("Результат: %s\n\n", count == 1 ? "Верно" : "Не верно");
    
    iterator_destroy(&it);
}

void test_n2() {
    printf("Для n=2: \n");
    iterator_t it;
    iterator_init(&it, 2);
    
    int count = 0;
    printf("Все ПСП для n=2:\n");
    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);
        printf("  %s\n", val->psp);
        count++;
        iterator_next(&it);
    }
    
    printf("Всего последовательностей: %d\n", count);
    printf("Результат: %s\n\n", count == 2 ? "Верно" : "Не верно");
    
    iterator_destroy(&it);
}

void test_n3() {
    printf("Для n=3: \n");
    iterator_t it;
    iterator_init(&it, 3);
    
    int count = 0;
    printf("Все ПСП для n=3:\n");
    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);
        printf("  %s\n", val->psp);
        count++;
        iterator_next(&it);
    }
    
    printf("Всего последовательностей: %d\n", count);
    printf("Результат: %s\n\n", count == 5 ? "Верно" : "Не верно");
    
    iterator_destroy(&it);
}

void test_n4() {
    printf("Для n=20\n");
    iterator_t it;
    iterator_init(&it, 20);
    
    int count = 0;
    printf("Все ПСП для n=20:\n");
    while (iterator_has_next(&it)) {
        const cbs_t *val = iterator_value(&it);
        printf("  %s\n", val->psp);
        count++;
        iterator_next(&it);
    }
    
    printf("Всего последовательностей: %d\n", count);
    printf("Результат: %s\n\n", count == 7 ? "Верно" : "Не верно");
    
    iterator_destroy(&it);
}

int main() {
    printf("Тестирование: \n\n");
    
    test_n0();
    test_n1();
    test_n2();
    test_n3();
    test_n4();
    
    printf("Введите n: ");
    
    int n;
    if (scanf("%d", &n) == 1) {
        iterator_t it;
        iterator_init(&it, n);
        
        printf("Все ПСП для n=%d:\n", n);
        long long count = 0;
        
        while (iterator_has_next(&it)) {
            const cbs_t *val = iterator_value(&it);
            printf("%s\n", val->psp);
            count++;
            iterator_next(&it);
        }
        
        printf("Всего последовательностей: %lld\n", count);
        iterator_destroy(&it);
    }
    
    return 0;
}