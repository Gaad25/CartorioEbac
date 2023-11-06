#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    char validacao[2]; // Deve ter espaço para o caractere e o '\0'

    do
    {
        printf("Digite o CPF: ");
        scanf("%39s", cpf); // %39s para prevenir buffer overflow

        // Forma o nome do arquivo baseado no CPF e adiciona a extensão .txt
        snprintf(arquivo, sizeof(arquivo), "%s.txt", cpf);

        // Tenta abrir o arquivo para escrita
        FILE *file = fopen(arquivo, "w");
        if (file == NULL)
        {
            perror("Não foi possível abrir o arquivo");
            exit(EXIT_FAILURE);
        }

        // Escreve o CPF no arquivo e fecha
        fprintf(file, "%s,", cpf);
        fclose(file);

        // Continua para os outros campos
        printf("Digite o Nome: ");
        scanf("%39s", nome);
        printf("Digite o Sobrenome: ");
        scanf("%39s", sobrenome);
        printf("Digite o Cargo: ");
        scanf("%39s", cargo);

        // Abre o arquivo para append e escreve os outros dados
        file = fopen(arquivo, "a");
        if (file == NULL)
        {
            perror("Não foi possível abrir o arquivo");
            exit(EXIT_FAILURE);
        }
        fprintf(file, "%s,%s,%s", nome, sobrenome, cargo);
        fclose(file);

        // Pergunta se o usuário quer inserir mais
        printf("Deseja inserir mais nomes? (s/n): ");
        scanf("%1s", validacao); // %1s para ler apenas um caractere

        // Verifica a resposta
        if (validacao[0] == 'n' || validacao[0] == 'N')
        {
            break; // Sai do loop se a resposta for 'n' ou 'N'
        }

        system("pause");

    } while (1); // Loop infinito, controlado pela resposta do usuário
}

void consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

void deletar()
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    remove(cpf);
    FILE *file;
    file = fopen(cpf, "r");
    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema!. \n");
        system("pause");
    }
}

int main()
{
    // Declaração de variáveis
    int opcao = 0;

    // Configuração para suportar acentuação e caracteres especiais da língua portuguesa
    setlocale(LC_ALL, "Portuguese");

    // Loop para o menu
    while (1)
    {

        system("cls"); // Limpa a tela do console

        // Apresentação do menu ao usuário
        printf("### Registro Nomes###\n\n");
        printf("Escolha Função: \n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
        printf("\t4 - Sair\n\n"); // Opção para sair do loop
        printf("Digite a opção: ");

        // Leitura da opção escolhida pelo usuário
        scanf("%d", &opcao);

        // Limpa a tela do console
        system("cls");

        // Estrutura de controle para tratar a opção escolhida
        switch (opcao)
        {
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
            printf("Obrigado por utilizar o sistema!.");
            return 0;
            break;

        default:
            printf("Opção Inválida\n"); // Ação padrão para opções não reconhecidas
            system("pause");
            break;
        }
    }
    return 0;
}
