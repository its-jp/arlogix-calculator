# Arlogix Calculator

O principal objetivo do projeto é implementar do zero os componentes fundamentais de uma calculadora, incluindo estruturas de dados (pilha, fila, etc.), um lexer para tokenização de expressões e um parser usando o algoritmo Shunting-yard, evitando o uso da Biblioteca Padrão do C++ (STL) para fins de aprendizado.

O nome Arlogix vem da junção das palavras arithmetic (aritmética) + logic (lógica), resultando no nome Arlogix.

### Pré-requisitos

-   **CMake**: Versão 3.16 ou superior.
-   **Compilador C++**: Um compilador com suporte a C++17 (como GCC ou Clang).
-   **Qt6**: A biblioteca de desenvolvimento de UI.

### Compilação e Execução

1.  Clone o repositório:
    ```bash
    git clone https://github.com/its-jp/arlogix-calculator.git
    cd arlogix-calculator
    ```

2.  Crie um diretório de build, configure o projeto com CMake e compile:
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ```

3.  Execute a calculadora:
    ```bash
    ./arlogix-calculator
    ```




## Arquitetura

O projeto é modular e segue um fluxo de processamento de dados claro, desde a entrada do usuário até o resultado final.

`Entrada na UI` -> `Lexer` -> `Shunting-yard` -> `Calculadora` -> `Resultado na UI`

1. Ferramentas de build:
    -   Para facilitar o processo de compilação e adição de dependências (para desenvolver a interface gráfica), optamos por usar o CMake para automatizar as etapas de linking;
2. Organização do projeto:
    - O projeto segue a seguinte estrutura:
    ```
        lib/
        ├── build/
        ├── calculator/
        ├── lexer/
        ├── shunting yard/
        ├── string/
        ├── structures/
        └── ui/
        tests/
        └── main.cpp	
        main.cpp		
        CMakeFiles.txt			
    ```
    - O diretório `lib/` contém o código fonte em si do projeto, sendo que cada parte da calculadora está separada em suas respectivas pastas:
        1. `build/` é a pasta responsável por conter os arquivos da compilação junto com tudo que for necessário para a execução do projeto;
        2. `calculator/` é a pasta que contém o código fonte das funções da calculadora, como por exemplo, calcular uma função infixa;
        3. `lexer/` é a pasta que contém o código que faz a parte da tokenização da expresão inserida pelo usuário;
        4. `shunting yard/` é a pasta que contém a implementação do Shunting Yard, que faz a tradução de notação infixa para posfixa;
        5. `string/` contém a nossa própria implementação da classe string da STL, a famosa std::string;
        6. `structures/` contém a implementação das estruturas de dados utilizadas no projeto, como lista ligada e pilha;
        7. `ui` contém a implementação da interface gráfica da calculadora;
    - `tests/`: Diretório que contém os testes automatizados da calculadora, para garantir que nenhuma mudança quebre funções essenciais do projeto, como o cálculo de expressões infixas;
    - `main.cpp`: Arquivo presente na raíz do projeto que contém o código para inicializar a interface gráfica;
    - `CMakeLists.txt`: é o arquivo das configurações do projeto para o CMake;

## Casos Limite e Limitações
- **Ordem de Operadores**: A calculadora respeita a precedência matemática padrão (potência antes de multiplicação/divisão, que vêm antes de adição/subtração).


## Decisões de projeto
 - **Implementação próprio de std::string**: Como não nos foi autorizado utilizar a STL do C++, optamos por criar uma classe **String** própria para que não precisássemos nos preocupar com o gerenciamento de memória manual das C-Strings (vetores de caracteres que necessitam de alocação e desalocação de memória manual).
 -   **CMake como sistema de build**: O CMake foi escolhido por sua flexibilidade, portabilidade entre plataformas e excelente suporte para a integração de bibliotecas externas como o Qt.
 -   **Qt para a Interface Gráfica**: O Qt foi selecionado por ser um framework de UI maduro, poderoso e multiplataforma, permitindo que a mesma base de código funcione em diferentes sistemas operacionais. 
