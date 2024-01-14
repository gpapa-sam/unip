// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#include "funcoes.h"




void sobre_museus(opcoes){
    char* locais[4] = {"arte_moderna.txt", "Santos_Dumont.txt", "paris.txt", "guerra_fria.txt"};

    printf("\n\n\n");
    carregar_textos(locais[opcoes - 1]);

}

void lgpd()
{
    printf("\n\n\n");
    char* lgpd = {"\t\t\t\tPara a venda de ingressos será colhido os dados referentes ao nome completo e idade.\n"
                   "\t\t\t\tOs dados são necessários para conferência do tipo de ingresso escolhido;\n"
                   "\t\t\t\tOs dados coletados em cadastro serão mantidos em arquivos protegidos e\n"
                   "\t\t\t\tpoderão ser usados para ofertas especiais futuras, tudo conforme a\n"
                   "\t\t\t\tLei Geral de Proteção de Dados (13709/18);\n"
                   "\n\t\t\t\tOs dados não serão compartilhados com outras empresas!"};
    printf("\t\t\t\t\tTERMO DE COLETA DE DADOS E PROTEÇÃO CONFORME LGPD\n\n\n%s\n", lgpd);

}
