// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>

// biblioteca do programa do arquivo cabeçalho
#include "funcoes.h"
#include "textos.h"

//------------------------------------------------------------------------------------------------------------------------
/*// essa lista é para ser chmada pela função e é um explicativo sobre museus
char* museus[4] = {"A semana de arte moderna foi um movimento dos anos 1920, que revolucionou a arte Brasileira",
                   "Santos Dumont eh o Pai da aviacao, criou o primeiro aviao em Paris",
                   "Paris sediarah os Jogos Olimpicos no ano de 2024, depois de ter sediado em 1900 e 1924.",
                   "A Guerra Fria foi uma corrida armamentista e polarizacao entre EUA e Uniao Sovietica entre 1947 e 1991."
};
*/


char* nome_museus[8] = {"100 anos Semana Arte Moderna", "150 anos Santos Dumont", "Olimpíadas Paris 2024", "Guerra Fria", "SAM", "SD", "OPR", "GFR"};

int ingressos[4][10];

int soma_idade[4] = {0, 0, 0, 0};

Cadastro *inicio = NULL;





//-----------------------------------------------------------------------------------------------------------------------------
//essa função tem a entrada da opção feita no menu principal, ele faz um loop para os menus secundários dos museus
// e chama o texto do museu escolhido pela opção; e chama a função de cada museu.
void menu_museus(int opcoes){
    int op;
    do{
        printf("\n\n\n\t\tBem- vindo ao museu %s\n\n", nome_museus[opcoes - 1]);
        printf("\n\t\t1 - Sobre o Museu\n");
        printf("\t\t2 - Compra de Ingressos\n");
        printf("\t\t0 - Voltar ao menu principal\n\n");

        op = entrada_num(1, "\n\n\t\tEntre com a opção: ");
        system("cls");

        switch(op){
            case 1: sobre_museus(opcoes); pausar_tela(); break;
            case 2: ingresso(opcoes); break;
            case 0: break;
            default: printf("Opção Inválida!!!"); Sleep(1500); system("cls");
        }
    }while(op!= 0);


}



//------------------------------------------------------------------------------------------------------------------------------
// função que pausa a tela até o usuário digitar qualquer tecla e depois limpa a tela para a próxima impressão...
void pausar_tela(){
    printf("\n\n\n\n\nPressione qualquer tecla para continuar: ");
    getch();
    system("cls");
}

//-----------------------------------------------------------------------------------------


//Cadastro
void cadastro(int opcoes, int ins_del, int opcoes_ticket){
    //insert ou deleta - para deletar(ultimo registro) = 0, para iserir = 1
    Cadastro *nova = (Cadastro*) malloc(sizeof(Cadastro));
    int voucher = (opcoes * 1000) + (opcoes_ticket * 100);

    if(ins_del == 1)
    {
        int ret;
        int check = 1;
        do{
            printf("\n\n\t\tDigite a idade: ");
            ret = scanf("%d", &nova->idade);  // retorna ou 0 se não for inteiro ou o número de bytes
            while(getchar() != '\n'); // limpa o buffer - lê e limpa
            if(ret == 0){
                fprintf(stderr,"\n\n\t\tInforme uma idade\n");
                pausar_tela();
            }else{
                if(nova->idade < 0 || nova->idade > 200){
                    fprintf(stderr, "\n\n\t\tDigite uma idade valida!!!\n");
                    pausar_tela();

                }else{
                    check = 0;
                }
            }


        }while(ret == 0 || check == 1);



        printf("\n\n\t\tDigite o nome: ");
        //
        fgets(nova->nome, sizeof(nova->nome), stdin);

        if(inicio == NULL){
            nova->id = 1 + voucher;
            nova->proximo = NULL;
            inicio = nova;
        }else{
            nova->proximo = inicio;
            int valor_sequencia = (inicio->id % 1000) % 100; //para conseguir os dois ultimos digitos que significa a sequencia do id
            nova->id = valor_sequencia + 1 + voucher;
            inicio = nova;
        }
        printf("\n\n\n\t\t%s", nome_museus[opcoes - 1]);

    }else{
        // deletando ultimo registro
        Cadastro *aux = inicio;
        inicio = aux->proximo;
        free(aux);
        aux = NULL;
    }




    // colocar vagas disponíveis antes do cadastro
    // acertar menu
}

//----------------------------------------------
//controle de ingresso
int ingresso(int opcoes){
    int op;

    // printar o menu
    do{
        printf("\n\n\n\t\tINGRESSOS PARA O MUSEU %s\n\n", nome_museus[opcoes - 1]);

        printf("\n\t\t1 - Condicao de visita\n");
        printf("\t\t2 - Tipos de ingressos e disponibilidade\n");
        printf("\t\t3 - Compra\n");
        printf("\t\t0 - Voltar ao Menu Anterior\n");

        // controle de entrada para receber números decimais de 1 dígito
        op = entrada_num(1, "\n\n\t\tEntre com a opcao: ");
        system("cls");

        //switch
        switch(op){
            case 1: carregar_textos("condicoes_visita.txt"); pausar_tela(); break;
            case 2: carregar_textos("ingresso.txt");
                    pausar_tela();
                    //chama a função -opcoes vai dar o museu - 1 que é para imprimir o relatório e 0 devolver o valor de tksts inteiros
                    disponibilidade(opcoes, 1, 0);
                    pausar_tela();
                    break;
            case 3: compra_ingressos(opcoes);
                    return 1;
            case 0: break;
            default: printf("Opcao Invalida!!!"); Sleep(1500);

        }
    }while(op != 0);
    system("cls");
    return 0;



}


void compra_ingressos(int opcoes)
{
    int op_tkt;
    do{
        printf("\n\n\n\t\tCOMPRA DE INGRESSOS\n\n");
        printf("\n\t\t1 - Inteira\n");
        printf("\t\t2 - Meia\n");
        printf("\t\t3 - Isenta\n");
        printf("\t\t0 - Volta ao menu anterior\n");


        // controle de entrada somente para números de 1 digito (0 a 9)
        op_tkt = entrada_num(1, "\n\n\t\tEntre com a opcao: ");
        system("cls");

        switch(op_tkt){
            case 1: compra(opcoes, op_tkt); break;
            case 2: compra(opcoes, op_tkt); break;
            case 3: compra(opcoes, op_tkt); break;
            case 0: break;
            default: printf("Opcao Invalida!!!"); pausar_tela();

        }
    }while(op_tkt != 0);
    system("cls");
}


int compra(int opcoes, int opcoes_ticket)
{
    // significado do voucher - 4 algoritmos / ex: 4302 - 4-museu(guerrafria); 3- tipo de ingresso(isento); 4-sequencia de compra(1 a 99)
    //int voucher;
    int tipo_ingresso = opcoes_ticket - 1;
    if(disponibilidade(opcoes, 0, tipo_ingresso) == 0){
        printf("\n\n\n\t\t\t\t***INGRESSO ESGOTADO!!***");
        pausar_tela();

    }else{
        lgpd();
        char aceite[50];
        do{
            printf("\n\n\n\n\n\t\t\tVoce aceita os termos de condicoes da coleta de dados (s/n): ");
            //while (getchar() != '\n');//(limpar o buffer)
            fgets(aceite, sizeof(aceite), stdin);
            if (strlen(aceite) > 2){
                fprintf(stderr,"\n\n\n\t\t\topção incorreta, informe apenas (s ou n)\n\n");
            }
            else if (aceite[0] == 's' || aceite[0] == 'S'){
                printf("\n\n\n\t\t\taceito!!");
                pausar_tela();
                cadastro(opcoes, 1, opcoes_ticket);
                pausar_tela();
                break;
            }
            else if (aceite[0] == 'n' || aceite[0] == 'N'){

                printf("\n\n\n\t\t\tCompra cancelada!!\n");
                pausar_tela();
                return 1;
            }
            else{
                fprintf(stderr,"\n\n\n\t\t\topção incorreta, informe apenas (s ou n)\n\n");
            }

        }while(1);// loop infinito as saídas estão com break.

        int num_cartao;

        if(opcoes_ticket == 3){

            // controle de idade de idosos
            if(inicio->idade < 61){
                printf("\n\n\t\t\t\tPara isentar a entrada deve ser maior de 60 anos!!!");
                printf("\n\n\n\t\t\tEscolha outro tipo de ingresso!!!");
                cadastro(opcoes, 0, opcoes_ticket); // deleta ultimo registro
                pausar_tela();
                return 1;
            }
            printf("\n\n\t\tVoucher: %s%d\n", nome_museus[opcoes + 3], inicio->id);// + voucher);
            //somando idade
            soma_idade[opcoes - 1] += inicio->idade;
            printf("\n\n\n\n\t\tHorario da visita: 08:00h as 17:00h");
            printf("\n\n\n\n\t\tSera verificado documento na entrada para comprovar o tipo de ingresso!");

            salvar_cadastro(); //adiciona na lista encadeada
            ingressos[opcoes -1][9] = inicio->id; // carrega a matriz

            pausar_tela();
            return 1;
        }
        if(opcoes_ticket == 1) // inteira
            printf("\n\n\t\tValor R$ 100,00");
        else // meia entrada
            printf("\n\n\t\tValor R$ 50,00");

        // entrada para o cartão de credito
        num_cartao = entrada_num(5, "Entre com o numero do cartão de crédito (5 algarismos): ");

        printf("\n\n\t\tCompra realizada!");
        pausar_tela();
        printf("\n\n\n\n\t\t\tVoucher: %s%d\n", nome_museus[opcoes + 3], inicio->id);// + voucher);
        //somando idade
        soma_idade[opcoes - 1] += inicio->idade;

        printf("\n\n\n\t\tHorario da visita: 08:00h as 17:00h");
        printf("\n\n\n\n\t\tATENCÂO!!!!\n\n\t\t\tSera verificado DOCUMENTO na entrada para comprovar o tipo de ingresso!");
        pausar_tela();

        //gravação em arquivo
        salvar_cadastro();

        // gravação da compra na matriz
        carregar_matriz();
        }
    return 0;
}

//listar e limpar memoria
void limpar_memoria(int op){
    // na opção 1 ele lista todos os cadastrados na opção 0 ele apenas limpa a memória

    Cadastro *aux = inicio;
    if (op != 0){

        printf("\n\n\t\t***Listar Cadastro***\n");
        if(aux == NULL){
            printf("Nenhum cadastro encontrado\n\n");
        }else{
            printf("\n%-20s %-20s %-100s\n", "ID", "IDADE", "NOME");
            while(aux!=NULL){
                printf("\n%-20d %-20d %-100s\n", aux->id, aux->idade, aux->nome);
                aux = aux->proximo;
            }
            printf("fim do cadastro");
        }
    }
    // liberar memoria
    while(inicio != NULL){
        aux = inicio;
        inicio = aux->proximo;
        free(aux);
        aux=NULL;
    }
}

int disponibilidade(int opcoes, int print, int tipo_tkt){
    /*se print for 0 (não haverá print) se for 1 ou qualquer outra haverá
                      tipo_tks: o que irá retornar: 0 - disponibilidade inteira; 1 - meia; 2 - isento
    */

    int int_meia_free[3] = {0, 4, 0};
    //verificando se a isento foi vendida ou não
    if(ingressos[opcoes - 1][9] == 300)
            int_meia_free[2] = 1;

    for (int i = 0; i < 9; i++){
        // verificação dos ingressos de inteira
        if(ingressos[opcoes - 1][i] == 100){
            int_meia_free[0]++;

        }//verificando as condições dos ingressos de meia diminuindo de 4 (40%)
        else if((ingressos[opcoes - 1][i] % 1000) > 200){
            int_meia_free[1]--;
        }
    }
    // garante a não exclusividade da meia entrada (ex: se foram vendidas 8 inteiras, tem apenas 1 vaga inteira
    // e continuaria tendo 4 meias -> nesse if garante que vai ter 1 vaga inteira e 1 vaga meia, quem chegar
    // primeira pega a vaga.
    if (int_meia_free[1] > int_meia_free[0])
        int_meia_free[1] = int_meia_free[0];

    // imprimindo relatório de disponibilidade
    if(print != 0){
        printf("\n\n\n\n\n\t\t\t\t\t\tDISPONIBILIDADE DE INGRESSOS E Valores dos tickets do Museu %s\n", nome_museus[opcoes - 1]);
        printf("\n\n\n\t\t\tInteira:\t%d    ingressos disponíveis", int_meia_free[0]);
        printf("\n\n\n\t\t\tMeia:\t\t%d    ingressos disponíveis", int_meia_free[1]);
        printf("\n\n\n\t\t\tIsento:\t\t%d    ingresso disponível\n\n", int_meia_free[2]);
        printf("\n\n\t\t\t\t\t\tPRECOS: \n");
        printf("\n\n\n\t\t\tInteira R$ 100,00");
        printf("\n\n\n\t\t\tMeia    R$  50,00\n");
    }

    return int_meia_free[tipo_tkt];

}

int entrada_num(int digitos, char* texto)
{
    int numero;
    int ret;
    int fator = 1;
    //acertando a quantidade de dígitos
    for(int i = 0; i < digitos; i++)
        fator *= 10;
    do{
        printf("\n\n\t\t\t%s", texto);
        ret = scanf("%d", &numero); // retorna ou 0 se não for inteiro ou o número de bytes
        while(getchar() != '\n'); // limpa o buffer - lê e limpa

        if(ret == 0){
            fprintf(stderr,"\n\n\t\tVoce deve informar um numero de %d digito/s\n", digitos);
        }else{
            if(numero < (fator/10) || numero >= fator){
                if(fator == 10 && numero == 0)
                    return numero;
                fprintf(stderr, "\n\n\t\tDigite apenas %d digito/s positivo/s!!!\n", digitos);
            }else{
                return numero;
            }
        }
    }while(1);


    return 0;

}

void relatorio()
{

    Cadastro *aux = inicio;
    //cabeçalho
    int ingresso_vendido[4] = {0, 0, 0, 0};
    //int soma_idade[4] = {0, 0, 0, 0};


    char* mus[4] = {"Arte Moderna", "Santos Dumont", "Paris 2024", "Guerra Fria"};

    printf("\n\nMUSEUS\t\t\t  1\t  2\t  3\t  4\t  5\t  6\t  7\t  8\t  9\t  10\n\n");
    for (int i = 0; i < 4; i++){
        printf("%s\t\t", mus[i]);
        for (int j = 0; j < 10; j++){

            if(ingressos[i][j] == 100){
                printf("livre\t");
            }
            else if(ingressos[i][j] == 300){
                printf("livre isento\t");
            }else{
                printf("%s%d\t", nome_museus[i + 4], ingressos[i][j]);
                ingresso_vendido[i] += 1;


            }

        }printf("\n");
    }
    // relatório vendas e idade
    for(int x = 0; x < 4; x++){
        float media_idade = (float)soma_idade[x] / (float) ingresso_vendido[x];
        printf("\n\n%s\n\tingressos vendidos: %d\t\tmedia de idade: %.2f", mus[x], ingresso_vendido[x], media_idade);


    }


}

void salvar_cadastro()
{
    FILE *arquivo;
    arquivo = fopen("cadastro.csv", "a");
    if(arquivo == NULL){
        fprintf(stderr, "Nao foi possivel abrir o arquivo\n");
        pausar_tela();
        return 1;
    }

    inicio->nome[strcspn(inicio->nome, "\n")] = '\0';
    fprintf(arquivo, "%s;%d;%d\n", inicio->nome, inicio->idade, inicio->id);
    //fechando arquivo
    fclose(arquivo);
}


int carregar_cadastro()
{
    int controle;
    FILE *arquivo; // cria o tipo variável arquivo
    arquivo = fopen("cadastro.csv", "r"); //abrindo o arquivo
    //verifica se foi aberto corretamente (se achou algo)
    if(arquivo == NULL){
        fprintf(stderr, "\nERRO!!!\nNao foi possivel abrir o arquivo\n");
        pausar_tela();
        return 2;
    }

    // abre um espaço na memória para um cadastro
    Cadastro *nova = (Cadastro*) malloc(sizeof (Cadastro));

    //verifico se o arquivo esta vazio (se sim, fecha a função)
    if(fscanf(arquivo, "%[^;];%d;%d\n", nova->nome, &nova->idade, &nova->id) != 3){
        free(nova);
        nova = NULL;
        return 1;
    }

    // cadastro dos primeiros dados da lista encadeada
    nova->proximo = NULL;
    inicio = nova;

    //somando idade
    int museus = (inicio->id - (inicio->id % 1000)) / 1000;
    soma_idade[museus - 1] += inicio->idade;
    //printf("%d\n", soma_idade[museus - 1]);

    carregar_matriz();

    do{
        controle = 1; // controle para sair do while;
        Cadastro *nova = (Cadastro*) malloc(sizeof(Cadastro)); //criando espaço

        if(fscanf(arquivo, "%[^;];%d;%d\n", nova->nome, &nova->idade, &nova->id) == 3){

            nova->proximo = inicio;
            inicio = nova;
            //somando idade
            int museus = (inicio->id - (inicio->id % 1000)) / 1000;
            soma_idade[museus - 1] += inicio->idade;
            //printf("%d\n", soma_idade[museus - 1]);

            carregar_matriz();
            controle = 0;

        }else{
            free(nova);
            nova = NULL;
        }
    }while(controle == 0);


    return 0;
}


int carregar_matriz()
{
    int museu, tkt, num, resto;
    resto = inicio->id %1000; // ex: 4332 % 1000 = 332
    museu = (inicio->id - resto) / 1000; // ex: 4332 - 332 / 1000 = 4000 / 1000 = 4 (guerra fria)
    tkt = (resto - (resto % 100)) / 100; // ex: (332 - (332 % 100)) / 100 = (332 - 32) / 100 =  300 / 100 = 3-> ISENTO
    num = resto % 100; // ex: 332 % 100 = 32 -> sequencia de compra

    if(tkt == 3){
        ingressos[museu - 1][9] = inicio->id;
    }else{
        for(int t = 0; t < 9; t++){
           if(ingressos[museu - 1][t] % 100 == 0){
                ingressos[museu - 1][t] = inicio->id;
                break;
           }
        }

    }
    return 0;
}


int carregar_textos(char* arquivo)
{
    FILE *file;

    char linha[120];

    file = fopen(arquivo, "r");

    if(arquivo == NULL){
        fprintf(stderr, "\nERRO!!!\nNão foi possível abrir o arquivo\n");
        pausar_tela();
        return 1;

    }

    printf("\n\n\n");
    while(fgets(linha, 120, file) != NULL){
        printf("\t\t\t\t%s", linha);
    }

    fclose(file);
    return 0;

}
