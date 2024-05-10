# Имя программы
TARGET = cookie-server.out

# Компилятор и флаги
CXX = g++ -std=c++20 -O3 -lpqxx -lpq

# Исходные файлы
SOURCES = main.cc utils.hh utils.cc user_session.hh user_session.cc server.hh server.cc packet_request_t.hh cookie_users_db.hh cookie_users_db.cc

# Объектные файлы
OBJECTS = $(SOURCES:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило сборки программы
$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

# Правило компиляции объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило очистки
clean:
	rm -f $(OBJECTS) $(TARGET)

# Правило установки
install:
	cp $(TARGET) /usr/local/bin/

# Правило запуска
run:
	./$(TARGET)
