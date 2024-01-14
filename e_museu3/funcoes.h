#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED





typedef struct cadastro{
    char nome[101];
    int id;
    int idade;
    struct cadastro *proximo;
} Cadastro;

extern Cadastro *inicio;

//extern char* museus[4]; // declaração de variável global!!! é usado em todo o programa
extern char* nome_museus[8];
extern int ingressos[4][10];
//extern int contador_id;


// declarações de funções
void pausar_tela();

void limpar_memoria(int op);

void menu_museus(int opcao);

void cadastro(int opcoes, int ins_del, int opcoes_ticket);

int ingresso(int opcoes);

int disponibilidade(int opcoes, int print, int tipo_tkt);

void compra_ingressos(int opcoes);

int compra(int opcoes, int opcoes_ticket);

int entrada_num(int digitos, char* texto);

void relatorio();

void salvar_cadastro();

int carregar_cadastro();

int carregar_matriz();

int carregar_textos(char* arquivo);



#endif // FUNCOES_H_INCLUDED
