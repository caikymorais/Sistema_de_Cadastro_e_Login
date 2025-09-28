# Sistema de Cadastro e Login em C

Este é um projeto simples de console desenvolvido em linguagem C que implementa um sistema de cadastro e login de usuário. Após o login, o usuário tem acesso a um menu com diversos módulos, incluindo funcionalidades pessoais, financeiras, acadêmicas e de utilidades gerais.

## 🔑 Funcionalidades Principais

O sistema é dividido em um fluxo de cadastro/login e quatro módulos principais, cada um com suas próprias ferramentas.

### 1. Sistema de Cadastro e Login
* **Cadastro de Usuário**: Permite que um novo usuário crie um login e uma senha.
* **Validação de Senha**: A senha deve ter no mínimo 6 caracteres e não pode ser uma senha comum como "123456".
* **Autenticação**: Verifica as credenciais fornecidas para dar acesso ao menu principal.

---

### 2. Módulo Pessoal 🧑‍💻
* **Classificação de Idade**: Informa se o usuário é maior ou menor de idade.
* **Direito de Voto**: Com base na idade, informa se o voto é opcional, obrigatório ou se o usuário não pode votar.
* **Cálculo de IMC**: Calcula o Índice de Massa Corporal a partir do peso e da altura e exibe a classificação (Abaixo do peso, Peso normal, Sobrepeso, Obesidade).

---

### 3. Módulo Financeiro 💰
* **Cálculo de Salário**: Calcula o salário anual com base no salário mensal.
* **Cálculo por Período**: Calcula o valor a receber com base nos dias trabalhados e no valor da diária.
* **Conversor de Moedas**: Converte valores de Real (BRL) para Dólar (USD) e Euro (EUR) com taxas pré-definidas.

---

### 4. Módulo Acadêmico 🎓
* **Cálculo de Média**: Permite ao usuário inserir N notas para calcular a soma e a média aritmética.
* **Situação do Aluno**: Com base na média, informa se o aluno está **Aprovado**, em **Recuperação** ou **Reprovado**.

---

### 5. Módulo de Utilidades 🛠️
Este módulo oferece um submenu com várias ferramentas práticas:
* Verificador de **Par ou Ímpar**.
* Verificador de **intervalo numérico** (se um número está entre 10 e 50).
* Cálculo de **área e perímetro** para círculos e retângulos.
* Conversor de **segundos** para o formato de horas, minutos e segundos.

---

### 6. Geração de Relatório 📄
Ao sair do programa (opção 0 no menu principal), um arquivo de texto chamado `RELATORIO.pdf` é gerado automaticamente na pasta do projeto. Este arquivo contém um resumo de todas as funcionalidades do sistema.

## 🚀 Como Executar o Projeto

Para compilar e executar este projeto, você precisará de um compilador C.

1.  **Clone o repositório:**
    ```bash
    git clone https://github.com/caikymorais/Sistema_de_Cadastro_e_Login.git
    ```

2.  **Navegue até a pasta do projeto:**
    ```bash
    cd Sistema_de_Cadastro_e_login
    ```

3.  **Compile o código:**
    Use o seguinte comando no terminal:
    ```bash
    gcc SistemaCadastroLogin.c -o programa
    ```

4.  **Execute o programa:**
    ```bash
    ./programa
    ```

## 🛠️ Tecnologias Utilizadas
* **Linguagem C**
* **Bibliotecas Padrão**: `stdio.h`, `string.h`, `stdlib.h`

---
**Feito por [Felipe Daniel, Caiky de Morais e Marcos de Sousa]**
