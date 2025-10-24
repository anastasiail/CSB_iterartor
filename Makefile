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
SRC_FILES = $(SRC_DIR)/cbs_iterator.c $(SRC_DIR)/main.c
TEST_FILES = $(SRC_DIR)/cbs_iterator.c $(TEST_DIR)/test_cbs_iterator.c

# Объектные файлы
OBJ_FILES = $(BUILD_DIR)/cbs_iterator.o $(BUILD_DIR)/main.o
TEST_OBJ_FILES = $(BUILD_DIR)/cbs_iterator.o $(BUILD_DIR)/test_cbs_iterator.o

# Основная цель
all: $(BUILD_DIR) $(TARGET)

# Тесты
test: $(BUILD_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

# Создание директории для сборки
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Основная программа
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $^

# Программа тестирования
$(TEST_TARGET): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $@ $^

# Компиляция объектных файлов
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c -o $@ $<

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Отладочная сборка
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(BUILD_DIR) $(TARGET)

# Зависимости
$(BUILD_DIR)/cbs_iterator.o: $(SRC_DIR)/cbs_iterator.c $(INCLUDE_DIR)/cbs_iterator.h
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/cbs_iterator.h
$(BUILD_DIR)/test_cbs_iterator.o: $(TEST_DIR)/test_cbs_iterator.c $(INCLUDE_DIR)/cbs_iterator.h

.PHONY: all test clean run debug
