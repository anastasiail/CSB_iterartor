# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

# Цели
TARGET = cbs_generator
TEST_TARGET = test_cbs_iterator

# Директории
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
BUILD_DIR = build

# Исходные файлы
MAIN_SRC = $(SRC_DIR)/main.c
CBS_SRC = $(SRC_DIR)/cbs_iterator.c
TEST_SRC = $(TEST_DIR)/test_cbs_iterator.c

# Объектные файлы
MAIN_OBJ = $(BUILD_DIR)/main.o
CBS_OBJ = $(BUILD_DIR)/cbs_iterator.o
TEST_OBJ = $(BUILD_DIR)/test_cbs_iterator.o

# Основная цель
all: $(BUILD_DIR) $(TARGET)

# Тесты
test: $(BUILD_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

# Создание директории для сборки
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Основная программа
$(TARGET): $(CBS_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $^

# Программа тестирования
$(TEST_TARGET): $(CBS_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^

# Компиляция объектных файлов для основной программы
$(BUILD_DIR)/main.o: $(MAIN_SRC) $(INCLUDE_DIR)/cbs_iterator.h
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c -o $@ $(MAIN_SRC)

$(BUILD_DIR)/cbs_iterator.o: $(CBS_SRC) $(INCLUDE_DIR)/cbs_iterator.h
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c -o $@ $(CBS_SRC)

# Компиляция объектных файлов для тестов
$(BUILD_DIR)/test_cbs_iterator.o: $(TEST_SRC) $(INCLUDE_DIR)/cbs_iterator.h
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c -o $@ $(TEST_SRC)

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Отладочная сборка
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BUILD_DIR) $(TARGET)

.PHONY: all test clean run debug
