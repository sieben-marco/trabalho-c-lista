#include<stdio.h>
#include<stdlib.h> //uso da funcao System
#include "lista.h" // inclui as assinaturas das funcoes usadas

// declaracoes globais
int lista[9];
int controle = 0;

int main(){
    // declaracoes locais
    int opcao;

    while(opcao != 7){
        mostraMenu();

        printf("Digite o numero da operacao: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                //funcao para executar opcao 1
                visualizarLista();
                break;
            case 2:
                //funcao para executar opcao 2
                consultar_lista();
                break;
            case 3:
                //funcao para execurar opcao 3
                inserirCodigo();
                break;
            case 6:
                esvaziar_lista();
                break;
            case 7:
                //mostrar lista
                printf("\n\nPrograma finalizado.\n");
                break;
            default:
                printf("\nDigite uma opcao valida.\n");
                break;
        }
    }

    return 0;
}

/*****************************************/
void clear(){
    //limpar tela
    system("cls || clear");
}

/*****************************************/
void inserirCodigo(){
    clear();
    int indice;
    int valor;
    
    // lista_esta_vazia();
    printf("Informe a posicao que deseja inserir: \n");
    scanf("%d", &indice);
    
    //se indice for maior ou igual ao valor de controle, insere o valor no primeiro indice disponivel
    if(indice>=controle){
        printf("Digite o valor da posicao: \n");
        scanf("%d", &valor);

        lista[controle] = valor;
        controle++;//atualiza quantidade de valores na lista
        return;
    }
    //se indice estiver no intervalo de 0 e entre controle, alterna posicoes e insere valor
    if(indice >= 0 && indice < controle){
        printf("Digite o valor da posicao: \n");
        scanf("%d", &valor);

        for(int i=controle; i>indice; i--){
            lista[i] = lista[i-1];
        }
        
        lista[indice] = valor;
        controle++;

        visualizarLista();
        return;

    }
}

/*****************************************/
void consultar_lista()
{
    clear();
    if (lista_esta_vazia())
    {
        visualizarLista();
        return;
    }
    
    int indice;


    do{
        printf("Digite qual indice deseja consultar (entre 0 e 8):");
        scanf("%d", &indice);
        
        if (indice >= 9) // Garantindo que o usuário insira um índice até 8
        {
            printf("O indice deve ser entre 0 e 8.\n");
        }
        else if (indice >= controle)
        {
            printf("A quantidade de elementos e menor que o indice escolhido.\n");
        }
        else if (indice < 0)
        {
            printf("O indice nao pode ser negativo.\n");
        }
        else if (indice >= 0 && indice < controle)
        {
            printf("No indice %d tem o valor %d \n", indice, lista[indice]);
        }
    }while(indice < 0 || indice >= 9);
}

/*****************************************/
void visualizarLista(){
    clear();

    if(lista_esta_vazia()) return;

    if (controle == 1) printf("A lista contem %d elemento.\n\n", controle);
    else printf("A lista contem %d elementos.\n\n", controle);
    
    printf("indice:");
    for (int i = 0; i < controle; i++) {
        printf("   %d", i);
    }

    printf("\nvalor:  ");
    printf("| ");
    for(int i=0; i<controle; i++){
        printf("%d | ", lista[i]);
    }

    printf("\n");
}

/*****************************************/
void esvaziar_lista()
{
    controle = 0;
}

/*****************************************/
int lista_esta_vazia()
{
    if (controle == 0)
    {
        printf("----------------------\n");
        printf("| A lista esta vazia |\n");
        printf("----------------------\n");

        return 1;
    }

    return 0;
}

/*****************************************/
void mostraMenu(){
    printf("\n### Menu de interacao ###\n");
    printf("1 - Visualizar lista\n");
    printf("2 - Consultar codigo\n");
    printf("3 - Inserir codigo\n");
    printf("4 - Remover codigo\n");
    printf("5 - Visualizar quantidade de elementos\n");
    printf("6 - Esvaziar lista\n");
    printf("7 - Finalizar\n\n");
}
