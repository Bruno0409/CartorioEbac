#include <stdio.h>  // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() {
    // Início da criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
    scanf("%s", cpf); // Refere-se as string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das string

    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    fprintf(file, "%s", cpf); // Salva o valor da variável
    fclose(file); // Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo, não localizado! \n");
        return 1;
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("Essas são as informações de usuário: \n ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);

    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o cpf a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("O usuário não se encontra no sistema!\n\n");
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    int opcao = 0; // Definindo variáveis
    char senhadigitada[20];

    printf("### Cartório da EBAC ### \n\n");
    printf("Login de administrador! \n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    if (strcmp(senhadigitada, "admin") == 0) {
        while (1) {
            printf("### Cartório da EBAC ###\n\n"); // Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes.\n");
            printf("\t2 - Consultar nomes.\n");
            printf("\t3 - Deletar nomes.\n\n");
            printf("\t4 - Sair do sistema.\n\n");

            printf("Opção: "); // Fim do menu
            scanf("%d", &opcao); // Armazenando a escolha do usuário

            switch (opcao) { // Início da seleção
                case 1:
                    registro();
                    break;

                case 2:
                    consulta();
                    break;

                case 3:
                    deletar();
                    break;

                case 4:
                    printf("Obrigado por utilizar o sistema! \n");
                    return 0;

                default:
                    printf("Essa opção não está disponível!\n");
                    break;
            } // Fim da seleção
        }
    } else {
        printf("Senha incorreta!\n");
    }

    return 0;
}
