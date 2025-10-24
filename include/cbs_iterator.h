#ifndef CBS_ITERATOR_H
#define CBS_ITERATOR_H

typedef struct CBS {
    char *psp;
    unsigned n;
} cbs_t;

typedef struct CbsIterator {
    cbs_t value;
    int finished;
    unsigned n;
    unsigned len;
} iterator_t;

// Инициализация итератора для n пар скобок
void iterator_init(iterator_t *i, unsigned n);

// Получение текущего значения
const cbs_t *iterator_value(const iterator_t *i);

// Проверка наличия следующего элемента
int iterator_has_next(const iterator_t *i);

// Переход к следующей ПСП
void iterator_next(iterator_t *i);

// Освобождение ресурсов
void iterator_destroy(iterator_t *i);

#endif