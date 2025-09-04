# Makefile para Tarefa 1 - OSA Lab01
# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Nome do executável
TARGET = programa

# Arquivos fonte
SOURCES = main.cpp arquivo_utils.cpp

# Arquivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Alvo padrão
all: $(TARGET)

# Compilação do executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compilação dos arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Execução do programa
run: $(TARGET)
	./$(TARGET)

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Declaração de alvos que não são arquivos
.PHONY: all run clean