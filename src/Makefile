# ==============================================================================
# Makefile para o projeto do Sistema de Gestão de Restaurante
# ==============================================================================

# --- Variáveis de Compilação ---

# Compilador C++ que será usado
CXX = g++

# Flags do compilador:
# -std=c++17: Usa o padrão C++17 (moderno e recomendado)
# -Wall: Mostra todos os avisos (warnings), uma ótima prática
# -g: Inclui informações de debug para usar com um depurador (como o gdb)
CXXFLAGS = -std=c++17 -Wall -g

# --- Variáveis do Projeto ---

# Nome do arquivo executável que será gerado
TARGET = restaurante

# Lista de todos os arquivos fonte (.cpp) do projeto
# Adicione ou remova arquivos aqui conforme seu projeto cresce
SOURCES = main.cpp \
          Pessoa.cpp \
          Cliente.cpp \
          Funcionario.cpp \
          Categoria.cpp \
          Produto.cpp \
          Cardapio.cpp \
          Pedido.cpp \
          Pagamento.cpp \
		  GerenciadorClientes.cpp \
		  Comanda.cpp \
		  Menu.cpp

# Gera automaticamente a lista de arquivos objeto (.o) a partir dos fontes (.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


# --- Regras de Compilação ---

# A primeira regra é a padrão, chamada quando você digita apenas "make"
# Ela diz que o objetivo principal ("all") é criar o nosso executável ($(TARGET))
all: $(TARGET)

# Regra para linkar todos os arquivos objeto (.o) e criar o executável final
$(TARGET): $(OBJECTS)
	@echo "Ligando os arquivos para criar o executável..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Executável '$(TARGET)' criado com sucesso!"

# Regra padrão para compilar um arquivo .cpp em um arquivo .o
# O comando é executado para cada arquivo .cpp que precisa ser compilado
%.o: %.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Regras de Limpeza e Execução ---

# Regra "clean": remove todos os arquivos gerados pela compilação
# Permite começar uma compilação "limpa" do zero
clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Limpeza concluída."

# Regra "run": compila o projeto (se necessário) e o executa
run: all
	@echo "Executando o programa..."
	./$(TARGET)

# Declaração de que "all", "clean" e "run" não são nomes de arquivos
.PHONY: all clean run