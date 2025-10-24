#include "cbs_iterator.h"
#include <stdlib.h> 
#include <string.h>

void iterator_init(iterator_t *i, unsigned n) {
    if (i == NULL) {
        return;
    }

    i->n = n;
    i->len = 2 * n;
    i->finished = 0;

    i->value.n = n;
    i->value.psp = (char *)malloc(i->len + 1); // +1 на нулевой символ

    if (n == 0) {
        // Одна пустая строка
        i->value.psp[0] = '\0';
    } else {
        // Генерируем первую последовательность: n (, за ними n )
        memset(i->value.psp, '(', n);
        memset(i->value.psp + n, ')', n);
        i->value.psp[i->len] = '\0';
    }
}

const cbs_t *iterator_value(const iterator_t *i) {
    return &i->value;
}

int iterator_has_next(const iterator_t *i) {
    return !i->finished;
}

void iterator_next(iterator_t *i) {
    if (i->finished) {
        return;
    }

    if (i->n == 0) {
        i->finished = 1;
        return;
    }

    char *s = i->value.psp;
    int len = i->len;
    int n = i->n;

    // Алгоритм поиска следующей лексикографической ПСП:
    // Ищем первую с конца (, для которой справа от нее есть больше ) чем ( - это опорный элемент

    int open_after = 0;
    int close_after = 0;
    int pivot = -1;
    for (int j = len - 1; j >= 0; j--) {
        if (s[j] == '(') {
            open_after++;
            if (close_after > open_after) { // Нашли
                pivot = j;
                break;
            }
        } else {
            close_after++;
        }
    }

    if (pivot == -1) { // Если не нашли такой индекс, то это была последняя ПСП
        i->finished = 1;
        return;
    }

    // Меняем ( на ) в опорной позиции
    s[pivot] = ')';

    // Считаем, сколько ( и ) справа от pivot
    int open_before = n - open_after; // Так как в ПСП n штук ( и n штук ), то до опорного элемента кол-во ( = n - кол-во ( после опорного
    int close_before = (n - close_after) + 1; // +1, так как поменяли одну ( на )

    // Сколько ( необходимо добавить после pivot
    int open_needed = n - open_before;

    // Сколько ) необходимо добавить после pivot
    int close_needed = n - close_before;

    // Добавляем
    int k = pivot + 1;
    for (int o = 0; o < open_needed; o++) {
        s[k++] = '(';
    }
    for (int c = 0; c < close_needed; c++) {
        s[k++] = ')';
    }
}

void iterator_destroy(iterator_t *i) {
    if (i != NULL) {
        free(i->value.psp);
        i->value.psp = NULL;
    }
}