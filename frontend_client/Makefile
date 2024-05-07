CXX = g++
CXXFLAGS = -std=c++20 -lsfml-graphics -lsfml-window -lsfml-system

# Список исходных файлов
SOURCES = main.cxx cookie_clicker.hxx cookie_clicker.cxx network_client.hxx network_client.cxx user_info.hxx user_info.cxx base_packet.hxx create_packet_data.hxx create_packet_data.cxx login_packet.hxx login_packet.cxx packet_types.hxx packet_types.cxx system_utils.hxx system_utils.cxx undefined_packet.hxx

# Генерация имен объектных файлов
OBJECTS = $(SOURCES:.cpp=.o)

# Имя исполняемого файла
EXECUTABLE = CookieClient.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
