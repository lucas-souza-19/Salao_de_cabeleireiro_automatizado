// Salao_de_cabeleireiro_automatizado.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 10

typedef struct
{
    int fila;
    float total;
    char nome[50];

} Cliente;

Cliente cliente[10];
int qtd = 0;

void salva()
{
    FILE* arquivo = fopen("listaClientes.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return;
    }

    int i;

    for (i = 0; i < qtd; i++)
    {
        fprintf(arquivo, "%d %.2f %s\n", cliente[i].fila, cliente[i].total, cliente[i].nome);
    }
    fclose(arquivo);
    printf("\nSalvo com sucesso!\n");
    printf("------------------------------\n\n");

}

void dados()
{
    FILE* arquivo = fopen("listaClientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao carregar dados!\n");
        return;
    }
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d", &cliente[qtd].fila);
        fscanf(arquivo, "%.2f", &cliente[qtd].total);
        fscanf(arquivo, "%49[^\n]", cliente[qtd].nome);
        qtd++;
    }
    fclose(arquivo);
}

int espere()
{
    system("pause");
    return 0;
}

int exibirCorteM()
{
    printf("\nCortes masculinos:\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("          1          |            2            |           3           |         4\n");
    printf("    Cabelo e barba   |    Corte com platinado  |         Luzes         |    Raspar na zero\n");
    printf("  Tempo: 30 minutos  |     Tempo: 1 hora       |    Tempo: 1h e 10m    |   Tempo: 10 minutos\n");
    printf("  Preço: R$ 50.00    |     Preço: R$ 100.00    |    Preço: R$ 70.00    |   Preço: R$ 10.00\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Digite o código do seu corte: ");
}

int exibirCorteF()
{
    printf("\nCortes femininos:\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("             5                |                6               |             7            |           8\n");
    printf("  Tirar as pontas e hidratar  |    Chanel reto e hidratação    |      Pintar o cabelo     |   Tranças(box braids)\n");
    printf("      Tempo: 2 horas          |        Tempo: 3 horas          |      Tempo: 1h e 30m     |    Tempo: 7 horas\n");
    printf("      Preço: R$ 200.00        |        Preço: R$ 150.00        |      Preço: R$ 100.00    |    Preço: R$ 600.00\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("Digite o código do seu corte: ");
}

int exibirProduto()
{
    printf("\nProdutos à venda:\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("        1          |           2          |           3           |            4       \n");
    printf("   Gel fixador     |   Pomada para barba  |   Hidratante capilar  | Shampoo e Condicionador\n");
    printf("  Preço: R$ 15.00  |    Preço: R$ 30.00   |     Preço: R$ 20.00   |     Preço: R$ 40.00\n");
    printf("-------------------------------------------------------------------------------------------\n");
}

int main()
{
    dados();
    int opcao, i, cod, valor, lista[10];
    char resposta, sexo, prod;
    float pcabelo = 0, pproduto = 0, aux1 = 0, aux2 = 0, total = 0;
    setlocale(LC_ALL, "Portuguese");


    do
    {
        system("cls");
        printf("------------------------------\n");
        printf("\nBem-vindo ao IFSP Barber Shop! \n\nPor favor, escolha alguma das opções abaixo: \n");
        printf("\n1 - Escolher corte\n");
        printf("2 - Posição na fila de espera\n");
        printf("3 - Salvar\n");
        printf("4 - Registro de Clientes\n");
        printf("0 - Finalizar programa\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);

        printf("------------------------------\n");

        switch (opcao)
        {
        case 1:
            if (qtd < MAX)
            {
                printf("Nome: ");
                setbuf(stdin, NULL);
                scanf(" %49[^\n]", cliente[qtd].nome);
                printf("\nDeseja escolher entre cortes masculinos ou femininos (m/f)?  ");
                setbuf(stdin, NULL);
                scanf("%c", &sexo);

                if (sexo == 'M' || sexo == 'm')
                {
                    exibirCorteM();
                    scanf("%d", &cliente[i].fila);
                }

                if (sexo == 'F' || sexo == 'f')
                {
                    exibirCorteF();
                    scanf("%d", &cliente[i].fila);
                }

                switch (cliente[i].fila)
                {

                case 1:
                    printf("\n\tPreço = 50.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 50;
                    break;
                case 2:
                    printf("\n\tPreço = 100.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 100;
                    break;
                case 3:
                    printf("\n\tPreço = 70.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 70;
                    break;
                case 4:
                    printf("\n\tPreço = 10.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 10;
                    pcabelo = aux1;
                    total = pcabelo;
                    break;
                case 5:
                    printf("\n\tPreco = 200.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 200;
                    break;
                case 6:
                    printf("\n\tPreço = 150.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 150;
                    break;
                case 7:
                    printf("\n\tPreço = 100.00\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 100;
                    break;
                case 8:
                    printf("\n\tPreço = 600.0\n");
                    printf("-------------------------------------------------------\n");
                    aux1 = 600;
                    break;
                }
                pcabelo = aux1;
                total = pcabelo;

                printf("\nDeseja comprar algum produto (s/n)? ");
                setbuf(stdin, NULL);
                scanf("%c", &prod);

                if (prod == 's' || prod == 'S')
                {
                    exibirProduto();
                    setbuf(stdin, NULL);
                    scanf("%d", &cod);
                    printf("--------------------------------------\n");

                    switch (cod)
                    {
                    case 1:
                        printf("\tPreço: 15.0\n");
                        printf("--------------------------------------\n");
                        aux2 = 15;
                        break;
                    case 2:
                        printf("\tPreço: 30.0\n");
                        printf("--------------------------------------\n");
                        aux2 = 30;
                        break;
                    case 3:
                        printf("\tPreço: 20.0\n");
                        printf("--------------------------------------\n");
                        aux2 = 20;
                        break;
                    case 4:
                        printf("\tPreço: 40.0\n");
                        printf("--------------------------------------\n");
                        aux2 = 40;
                        break;

                    }
                    pproduto = aux2;
                    total = pcabelo + pproduto;

                }
                else
                {
                    pproduto = 0;
                }
                cliente[qtd].total = total;
                printf("\n\n----------------------\n");
                printf("        ELLU          ");
                printf("\n\n   IFSP Barber Shop\n");
                printf("\n   Cabelo: %.2f", pcabelo);
                printf("\n   Produto: %.2f", pproduto);
                printf("\n\n   VALOR: RS %.2f", total);
                printf("\n------------------------\n\n");
                qtd++;
                espere();



            }
            else
            {
                printf("\n\tLista cheia!\n");
                printf("-------------------------------------\n");
                espere();
            }
            break;

        case 2:

            system("cls");
            printf("\n-------------------------------------\n");
            printf("\tLISTA DE ATENDIMENTO\n");

            if (qtd == 0)
            {
                printf("\n\tVocê é o primeiro cliente.\n\n");
            }
            else if (qtd == 11) {
                printf("\n\tLista cheia!\n");
            }
            else
            {
                printf("\n\tVoce é o %dº da fila.\n\n", qtd);
            }

            printf("-------------------------------------\n");
            espere();
            break;
        case 3:
            salva();
            espere();
            break;
        case 4:
            printf("-------------------------------------\n");
            printf("\nRegistro de Clientes\n\n");
            for (i = 0; i < qtd; i++)
            {
                printf("%.2f %s\n", cliente[i].total, cliente[i].nome);
            }
            printf("-------------------------------------\n");
            espere();
            break;

        case 0:
            break;

        default:
            printf("Opção inválida!\n");
            espere();
        }
    } while (opcao != 0);

    return 0;
}



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
