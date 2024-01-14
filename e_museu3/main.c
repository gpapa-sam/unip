// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // entrada e saída que serve tantopara o windowns como para o linux
#include <Windows.h> // usada para o Sleep
#include <locale.h>

// biblioteca do programa
#include "funcoes.h"
#include "textos.h"


int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int op;
    inicio = NULL; //inicia a lista encadeada

    //caregando a matriz
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 10; j++){
            if (j == 9)
                ingressos[i][j] = 300;
            else
                ingressos[i][j] = 100;
        }
    }
    //carregando o arquivo de cadastro e ajustando a matriz
    carregar_cadastro();

    do{
        system("cls"); // lçimpa a tela toda a vez que o loop volta
        printf("\n\n\n\t\tMuseu Multitemático\n\n");
        printf("\n\t\t1 - 100 anos da semana da Arte Moderna\n");
        printf("\t\t2 - 150 anos de Santos Dumont\n");
        printf("\t\t3 - Jogos Olímpicos de Paris 2024\n");
        printf("\t\t4 - Guerra Fria\n");
        printf("\t\t5 - Relatório\n");
        printf("\t\t0 - Sair");

        //função que faz o controle de entrada para permiter somente os valores inteiros de 0 a 9
        op = entrada_num(1, "\n\n\t\tEntre com a opção: ");
        system("cls");

        switch(op){
            case 1: menu_museus(op); break;
            case 2: menu_museus(op); break;
            case 3: menu_museus(op); break;
            case 4: menu_museus(op); break;
            case 5: relatorio(); pausar_tela(); break;
            case 0: printf("Bye...\n\n\n\n\n");Sleep(1200); break;
            default : printf("\n\n\t\tOpção Inválida!!!");pausar_tela();
        }
    }while(op != 0);

    // na opção 1 ele lista todos os cadastrados na opção 0 ele apenas limpa a memória
    limpar_memoria(1);

    return 0;
}
