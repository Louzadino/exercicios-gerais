#include <stdio.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

int main(){

    int tam, tipo, opcao, idx;
    tGerenciador* gerenciador = CriaGerenciador();

    printf("tad_gen_02\n");

    while(1){

        printf("Escolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote específico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");
        scanf("%d", &opcao);
        scanf("%*c");

        if (opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
            scanf("%d %d", &tipo, &tam);

            if (tipo == 1 || tipo == 2){
                tPacote* pacote = CriaPacote(tipo, tam);
                LePacote(pacote);
                AdicionaPacoteNoGerenciador(gerenciador, pacote);
            } else {
                printf("Digite um tipo valido!\n");
            }

        } else if (opcao == 2){
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(gerenciador, idx);

        } else if (opcao == 3){
            ImprimirTodosPacotes(gerenciador);
            break;
        } else {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }

    DestroiGerenciador(gerenciador);
    return 0;
}
