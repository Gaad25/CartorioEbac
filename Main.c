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

    printf("Digite o CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Nome: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Sobrenome: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o Cargo: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
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
