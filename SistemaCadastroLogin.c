#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Prototipos (organizacao) */
void clearInput(void);
void stripNewline(char *s);
int senha_valida(const char *pass);
void modulo_pessoal(void);
void modulo_financeiro(double brl_to_usd, double brl_to_eur);
void modulo_academico(void);
void modulo_utilidades(double pi);
void gerarRelatorioPDF(void);

int main(void) {
    size_t MAX_USER = 50;
    size_t MAX_PASS = 50;
    double pi = 3.141592653589793;
    double brl_to_usd = 5.00;
    double brl_to_eur = 5.50;

    char *usuario = malloc((MAX_USER + 1) * sizeof(char));
    char *senha = malloc((MAX_PASS + 1) * sizeof(char));
    char *login = malloc((MAX_USER + 1) * sizeof(char));

    printf("=== SISTEMA DE CADASTRO ===\n");
    printf("Cadastrar usuario (login): ");
    if (fgets(usuario, (int)MAX_USER + 1, stdin) == NULL) { 
       printf("Erro na entrada.\n"); goto cleanup; 
    }
    stripNewline(usuario);

    printf("Cadastrar senha: ");
    if (fgets(senha, (int)MAX_PASS + 1, stdin) == NULL) { 
       printf("Erro na entrada.\n"); goto cleanup; 
    }
    stripNewline(senha);

    if (!senha_valida(senha)) {
        printf("Senha invalida. O programa sera encerrado.\n");
        system("pause");
        goto cleanup;
    }

    printf("\nCadastro efetuado com sucesso!\n");

    /* Login */
    printf("\nFACA LOGIN\nLogin: ");
    if (fgets(login, (int)MAX_USER + 1, stdin) == NULL) { 
        printf("Erro na entrada.\n"); goto cleanup; 
    }
    stripNewline(login);

    if (strcmp(login, usuario) != 0) {
        printf("Login incorreto. Encerrando o programa.\n");
        system("pause");
        goto cleanup;
    }

    /* Mostrar menu principal */
    int opcao;
    int ret;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1 - Pessoal\n");
        printf("2 - Financeiro\n");
        printf("3 - Academico\n");
        printf("4 - Utilidades\n");
        printf("0 - Sair\n");
        printf("Escolha? ");
        ret = scanf("%d", &opcao);
        if (ret != 1) {
            printf("Entrada invalida.\n");
            clearInput();
            system("pause");
            continue;
        }
        clearInput();

        switch (opcao) {
            case 1: modulo_pessoal(); break;
            case 2: modulo_financeiro(brl_to_usd, brl_to_eur); break;
            case 3: modulo_academico(); break;
            case 4: modulo_utilidades(pi); break;
            case 0:
                printf("Encerrando sistema...\n");
                gerarRelatorioPDF();  // gera o relatório sempre ao sair
                system("pause");
                break;
            default: 
                printf("Opcao invalida.\n"); 
                system("pause"); 
                break;
        }
    } while (opcao != 0);

cleanup:
    free(usuario);
    free(senha);
    free(login);
    return 0;
}

/* utilitarios */
void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void stripNewline(char *s) {
    if (s == NULL) return;
    size_t len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
}

int senha_valida(const char *pass) {
    if (pass == NULL) return 0;
    size_t len = strlen(pass);
    if (len < 6) return 0;
    if (strcmp(pass, "123456") == 0) return 0;
    if (len == 0) return 0;
    return 1;
}

/* Modulo Pessoal */
void modulo_pessoal(void) {
    int idade;
    double peso, altura, imc;
    int ret;
    printf("\n--- MODULO PESSOAL ---\n");
    printf("Digite sua idade: ");
    ret = scanf("%d", &idade);
    if (ret != 1) { printf("Entrada invalida.\n"); clearInput(); system("pause"); return; }
    clearInput();

    if (idade < 18){
       printf("Classificacao: Menor de idade.\n");
    }else printf("Classificacao: Maior de idade.\n");

    if (idade < 16) {
       printf("Direito de voto: Nao vota.\n");
    } else if (idade <= 17) {
       printf("Direito de voto: Voto opcional.\n");
    } else if (idade <= 69){
       printf("Direito de voto: Voto obrigatorio.\n");
    } else printf("Direito de voto: Voto opcional.\n");

    printf("\nCalcular IMC\n");
    printf("Digite o peso (kg): ");
    ret = scanf("%lf", &peso);
    if (ret != 1) { 
        printf("Entrada invalida.\n"); clearInput(); system("pause"); 
        return; 
    }
    printf("Digite a altura (m): ");
    ret = scanf("%lf", &altura);
    if (ret != 1) { 
        printf("Entrada invalida.\n"); 
        clearInput(); 
        system("pause"); 
        return; 
    }
    clearInput();

    if (altura <= 0) { 
        printf("Altura invalida.\n"); 
        system("pause"); 
        return; 
    }
    imc = peso / (altura * altura);
    printf("IMC = %.2f\n", imc);
    if (imc < 18.5) { 
       printf("Classificacao IMC: Abaixo do peso\n");
    } else if (imc < 25.0) { 
       printf("Classificacao IMC: Peso normal\n");
    } else if (imc < 30.0) {
       printf("Classificacao IMC: Sobrepeso\n");
    } else printf("Classificacao IMC: Obesidade\n");

    system("pause");
}

/* Modulo Financeiro */
void modulo_financeiro(double brl_to_usd, double brl_to_eur) {
    double salario, anual;
    int dias;
    double diaria, periodo;
    double valor_brl;
    int ret;
    printf("\n--- MODULO FINANCEIRO ---\n");
    printf("Digite seu salario mensal (R$): ");
    ret = scanf("%lf", &salario);
    if (ret != 1) { 
        printf("Entrada invalida.\n"); 
        clearInput(); 
        system("pause"); 
        return; 
    }
    anual = salario * 12.0;
    printf("Salario em 12 meses: R$ %.2f\n", anual);

    printf("\nCalcular por dias trabalhados\n");
    printf("Dias trabalhados no periodo: ");
    ret = scanf("%d", &dias);
    if (ret != 1) { 
        printf("Entrada invalida.\n"); 
        clearInput(); 
        system("pause"); 
        return; 
    }
    printf("Valor da diaria (R$): ");
    ret = scanf("%lf", &diaria);
    if (ret != 1) { 
        printf("Entrada invalida.\n"); 
        clearInput(); 
        system("pause"); 
        return; 
    }
    clearInput();
    periodo = dias * diaria;
    printf("Salario do periodo: R$ %.2f\n", periodo);

    printf("\nConversao de moedas (ex.: BRL -> USD / EUR)\n");
    printf("Digite um valor em reais (R$): ");
    ret = scanf("%lf", &valor_brl);
    if (ret != 1) { 
        printf("Entrada invalida.\n");
        clearInput(); 
        system("pause"); 
        return; 
    }
    clearInput();
    if (brl_to_usd != 0.0) {
       printf("Valor em USD (aprox): $ %.2f\n", valor_brl / brl_to_usd);
    } else printf("Taxa BRL->USD nao definida.\n");
    
    if (brl_to_eur != 0.0) { 
       printf("Valor em EUR (aprox): EUR %.2f\n", valor_brl / brl_to_eur);
    } else printf("Taxa BRL->EUR nao definida.\n");

    system("pause");
}

/* Modulo Academico */
void modulo_academico(void) {
    int n;
    double soma = 0.0, nota;
    int ret;
    printf("\n--- MODULO ACADEMICO ---\n");
    printf("Quantas notas deseja informar? ");
    ret = scanf("%d", &n);
    if (ret != 1 || n <= 0) {
        printf("Entrada invalida.\n");
        clearInput();
        system("pause");
        return;
    }
    clearInput();

    {
        int i;
        for (i = 1; i <= n; ++i) {
            printf("Digite a nota %d: ", i);
            ret = scanf("%lf", &nota);
            if (ret != 1) {
               printf("Entrada invalida.\n");
               clearInput();
               system("pause");
               return;
            }
            soma += nota;
        }
    }

    clearInput();
    double media = soma / n;
    printf("Soma das notas: %.2f\n", soma);
    printf("Media: %.2f\n", media);
    printf("Dobro da media: %.2f\n", 2.0 * media);

    if (media >= 7.0){
          printf("Resultado: Aprovado\n");
    } else if (media >= 5.0){
          printf("Resultado: Recuperacao\n");
    } else {
          printf("Resultado: Reprovado\n");
    }

    system("pause");
}

/* Modulo Utilidades */
void modulo_utilidades(double pi) {
    int escolha;
    int ret;
    while (1) {
        printf("\n--- MODULO UTILIDADES ---\n");
        printf("1 - Par / Impar\n");
        printf("2 - Verificar intervalo [10, 50]\n");
        printf("3 - Area e perimetro (circulo)\n");
        printf("4 - Area e perimetro (retangulo)\n");
        printf("5 - Transformar segundos em horas e minutos\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha: ");
        ret = scanf("%d", &escolha);
        if (ret != 1) { 
            printf("Entrada invalida.\n");
            clearInput();
            system("pause");
            continue;
        }
        clearInput();

        switch (escolha) {
            case 0:
                return;

            case 1: {
                int x;
                printf("Digite um numero inteiro: ");
                ret = scanf("%d", &x);
                if (ret != 1) { 
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break; 
                }
                clearInput();
                printf("%d e %s\n", x, (x % 2 == 0) ? "Par" : "Impar");
                system("pause");
                break;
            }

            case 2: {
                int x;
                printf("Digite um numero inteiro: ");
                ret = scanf("%d", &x);
                if (ret != 1) { 
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break; 
                }
                clearInput();
                if (x >= 10 && x <= 50) printf("%d esta dentro do intervalo [10,50]\n", x);
                else printf("%d NAO esta dentro do intervalo [10,50]\n", x);
                system("pause");
                break;
            }

            case 3: { 
                double r;
                printf("Raio do circulo (m): ");
                ret = scanf("%lf", &r);
                if (ret != 1 || r < 0) { 
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break; 
                }
                clearInput();
                double area = pi * r * r;
                double perimetro = 2.0 * pi * r;
                printf("Area: %.2f\nPerimetro (circunferencia): %.2f\n", area, perimetro);
                system("pause");
                break;
            }

            case 4: {
                double base, altura;
                printf("Base do retangulo (m): ");
                ret = scanf("%lf", &base);
                if (ret != 1) { 
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break; 
                }
                printf("Altura do retangulo (m): ");
                ret = scanf("%lf", &altura);
                if (ret != 1) {
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break; 
                }
                clearInput();
                double area = base * altura;
                double perimetro = 2.0 * (base + altura);
                printf("Area: %.2f\nPerimetro: %.2f\n", area, perimetro);
                system("pause");
                break;
            }

            case 5: {
                int segundos;
                printf("Digite a quantidade de segundos: ");
                ret = scanf("%d", &segundos);
                if (ret != 1 || segundos < 0) { 
                    printf("Entrada invalida.\n"); clearInput(); system("pause"); break;
                }
                clearInput();
                int horas = segundos / 3600;
                int minutos = (segundos % 3600) / 60;
                int seg_rest = segundos % 60;
                printf("%d segundos = %d horas, %d minutos e %d segundos\n", segundos, horas, minutos, seg_rest);
                system("pause");
                break;
            }

            default:
                printf("Opcao invalida.\n");
                system("pause");
                break;
        }
    }
}

/* Gera Relatorio em formato .pdf (na pratica, texto salvo com extensao .pdf) */
void gerarRelatorioPDF(void) {
    FILE *arquivo;
    arquivo = fopen("RELATORIO.pdf", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o relatorio PDF!\n");
        return;
    }

    fprintf(arquivo, "Relatorio do Projeto - Formato SBC\n\n");
    fprintf(arquivo, "Titulo: Sistema de Cadastro e Login com Modulos Interativos\n\n");
    fprintf(arquivo, "Resumo:\nEste projeto implementa um sistema de cadastro e login em C, ");
    fprintf(arquivo, "com diferentes modulos interativos: pessoal, financeiro, academico e utilidades.\n\n");

    fprintf(arquivo, "## 🔑 Funcionalidades\n\n");
    fprintf(arquivo, "O sistema possui um menu principal com quatro modulos:\n\n");

    fprintf(arquivo, "### 1. Cadastro e Login\n");
    fprintf(arquivo, "- Registro de usuario e senha (com validacao de senha).\n");
    fprintf(arquivo, "- Login com verificacao de credenciais.\n");
    fprintf(arquivo, "- Encerramento do sistema em caso de erro no login ou senha invalida.\n\n");

    fprintf(arquivo, "### 2. Modulo Pessoal\n");
    fprintf(arquivo, "- Solicita idade e classifica como maior ou menor de idade.\n");
    fprintf(arquivo, "- Informa a situacao de voto (nao vota, opcional ou obrigatorio).\n");
    fprintf(arquivo, "- Calcula IMC (Indice de Massa Corporal).\n");
    fprintf(arquivo, "- Exibe classificacao do IMC (abaixo do peso, normal, sobrepeso, obesidade).\n\n");

    fprintf(arquivo, "### 3. Modulo Financeiro\n");
    fprintf(arquivo, "- Calcula salario anual.\n");
    fprintf(arquivo, "- Calcula salario por periodo (dias x diaria).\n");
    fprintf(arquivo, "- Converte BRL para USD e EUR.\n\n");

    fprintf(arquivo, "### 4. Modulo Academico\n");
    fprintf(arquivo, "- Permite informar N notas.\n");
    fprintf(arquivo, "- Calcula soma, media e dobro da media.\n");
    fprintf(arquivo, "- Classifica o aluno em Aprovado, Recuperacao ou Reprovado.\n\n");

    fprintf(arquivo, "### 5. Modulo Utilidades\n");
    fprintf(arquivo, "- Verifica se um numero e par ou impar.\n");
    fprintf(arquivo, "- Verifica intervalo [10, 50].\n");
    fprintf(arquivo, "- Calcula area e perimetro de um circulo.\n");
    fprintf(arquivo, "- Calcula area e perimetro de um retangulo.\n");
    fprintf(arquivo, "- Converte segundos em horas, minutos e segundos.\n\n");

    fprintf(arquivo, "Fim do Relatorio.\n");

    fclose(arquivo);
    printf("\n📄 Relatorio gerado com sucesso: RELATORIO.pdf\n");
}
