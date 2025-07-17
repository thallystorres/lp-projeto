classDiagram
    class Pessoa {
        -int id
        -string nome
        -string cpf
        +Pessoa(int id, const string &amp;nome, const string &amp;cpf)
        +mostrarDados() void
        +setNome(const string&amp; nome) void
        +getId() int
        +getNome() string
        +getCpf() string
    }

    class Cliente {
        -string endereco
        -vector&lt;Pedido&gt; pedidos
        +Cliente(int id, const string &amp;nome, const string &amp;cpf, const string&amp; endereco)
        +getEndereco() string
        +mostrarDados() void
        +adicionarPedido(const Pedido&amp; pedido) void
    }

    class Funcionario {
        -string cargo
        -double salario
        +Funcionario(int id, const string&amp; nome,const  string&amp; cpf,const  string&amp; cargo, double salario)
        +mostrarDados() void
    }

    class Categoria {
        -int id
        -string nome
        +Categoria(int id, const string&amp; nome)
        +getId() int
        +getNome() string
        +mostrarDados() const void
    }

    class Produto {
        -int id
        -string nome
        -double preco
        -Categoria* categoria
        +Produto(int id, const string &amp;nome, double preco, Categoria *categoria)
        +getId() int
        +getNome() string
        +getPreco() double
        +getCategoria() Categoria*
        +mostrarDados() const void
    }

    class Pedido {
        -int id
        -string data
        -vector&lt;Produto *&gt; produtos
        -Pagamento pagamento
        -StatusPedido status
        +Pedido(int id, const string &amp;data)
        +getPagamento() Pagamento&amp;
        +marcarComoPago() void
        +adicionarProduto(Produto *produto) void
        +calcularTotal() double
        +mostrarDados() const void
    }

    class Pagamento {
        -int idPedido
        -string metodo
        -bool efetuado
        +Pagamento(int idPedido)
        +processarPagamento(const string &amp;metodoPagamento, double valor) void
        +mostrarDados() const void
    }
    
    class Cardapio {
        -vector&lt;Categoria&gt; categorias
        -vector&lt;Produto&gt; produtos
        -int proximaCategoriaId
        -int proximoProdutoId
        +adicionarCategoria(const string&amp; nome) void
        +buscarCategoriaPorId(int id) Categoria*
        +listarCategorias() const void
        +adicionarProduto(const string &amp;nome, double preco, int categoriaId) void
        +buscarProdutoPorId(int id) Produto*
        +listarProdutos() const void
        +removerProduto(int id) void
    }

    class GerenciadorClientes {
        -vector&lt;Cliente&gt; clientes
        -int proximoClienteId
        +adicionarCliente(const string&amp; nome, const string&amp; cpf, const string&amp; endereco) void
        +buscarClientePorId(int id) Cliente*
        +listarClientes() const void
    }

    class Comanda {
        -vector&lt;Pedido&gt; todosOsPedidos
        -int proximoPedidoId
        +registrarPedido(const Pedido&amp; pedido) void
        +getProximoId() int
    }

    Pessoa <|-- Cliente
    Pessoa <|-- Funcionario
    
    GerenciadorClientes "1" *-- "0..*" Cliente : gerencia
    Cliente "1" o-- "0..*" Pedido : faz
    
    Comanda "1" *-- "0..*" Pedido : registra
    
    Pedido "1" *-- "1..*" Produto : contém
    Pedido "1" -- "1" Pagamento : tem
    
    Cardapio "1" *-- "0..*" Produto : gerencia
    Cardapio "1" *-- "0..*" Categoria : gerencia
    Produto "1" -- "1" Categoria : pertence a
