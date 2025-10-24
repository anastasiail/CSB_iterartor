# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
DEBUG_FLAGS = -g

# Цели
TARGET = cbs_generator
TEST_TARGET = test_cbs_iterator

# Основная цель
all: $(TARGET)

# Тесты
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Основная программа
$(TARGET): src/main.c src/cbs_iterator.c include/cbs_iterator.h
	$(CC) $(CFLAGS) -o $@ src/main.c src/cbs_iterator.c

# Программа тестирования
$(TEST_TARGET): test/test_cbs_iterator.c src/cbs_iterator.c include/cbs_iterator.h
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ test/test_cbs_iterator.c src/cbs_iterator.c

# Очистка
clean:
	rm -f $(TARGET) $(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

.PHONY: all test clean run
