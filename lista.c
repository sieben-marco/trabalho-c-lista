#include<stdio.h>
#include<stdlib.h> //uso da funcao System
#include "lista.h" // inclui as assinaturas das funcoes usadas

#define MAX 5

// declaracoes globais
int lista[MAX];
int controle = 0;

int main(){
    // declaracoes locais
    int opcao;

    visualizarLista();

    while(opcao != 7){
        mostraMenu();

        printf("Digite o numero da operacao: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                clear();
                visualizarLista();
                break;
            case 2:
                clear();
                inserirCodigo();
                break;
            case 3:
                clear();
                consultar_lista();
                break;
            case 4:
                clear();
                remove_elemento();
                break;
            case 5:
                clear();
                qtd_elementos();
                break;
            case 6:
                clear();
                esvaziar_lista();
                break;
            case 7:
                clear();
                visualizarLista(); // mostra a lista antes de encerrar
                printf("\n\nPrograma finalizado.\n");
                break;
            default:
                clear();
                printf("\nDigite uma opcao valida.\n");
                break;
        }
    }

    return 0;
}

/*****************************************/
void clear(){
    system("cls || clear"); //limpa a tela
}

/*****************************************/
void qtd_elementos()
{
    // retorna se a lista esta vazia
    if (lista_esta_vazia())
        return;

    printf("------------");

    // condicao para mensagem no singular ou no plural
    if (controle == 1)
        printf("\nA lista contem %d elemento.\n", controle);
    else
        printf("\nA lista contem %d elementos.\n", controle);
}

/*****************************************/
void remove_elemento()
{
    clear();

    // retorna se a lista esta vazia
    if (lista_esta_vazia())
        return;

    visualizarLista();

    int indice; // armazena a posicao de remocao

    do
    {
        printf("Digite de qual indice deseja remover um elemento (entre 0 e 8): ");
        scanf(" %d", &indice);

        if (indice < 0 || indice >= 9)
        {
            printf("O indice deve ser entre 0 e 8.\n");
        }
        else if (indice >= 0 && indice < controle)
        {
            /**
             * 
             */
            for(int i = indice; i < controle-1; i++){
                lista[i] = lista[i+1];
            }
            
            controle--;
        }
    } while (indice < 0 || indice >= 9);

    visualizarLista();
}

/*****************************************/
void inserirCodigo(){
    clear();

    if (lista_esta_cheia())
        return;

    visualizarLista();

    int indice;
    int valor;

    do{
        printf("\nDigite qual indice deseja inserir (entre 0 e 8): ");
        scanf("%d", &indice);
        
        if (indice < 0 || indice >= 9)
        {
            printf("O indice deve ser entre 0 e 8.\n");
        }
        else if (indice >= controle)
        {
            printf("Digite o valor da posicao: ");
            scanf("%d", &valor);

            lista[controle] = valor;
            controle++;//atualiza quantidade de valores na lista
        }
        else if (indice >= 0 && indice < controle)
        {
            printf("Digite o valor da posicao: ");
            scanf("%d", &valor);

            /**
             * inicia o contador com valor igual ao controle (ultimo indice)
             * descrementa contador enquanto for menor que o indice desejado
             * a lista no indice atual recebe o valor do indice menos um (valor anterior)
             * quando contador igual ao indice desejado, a lista recebe o valor desejado neste indice
             */
            for(int i=controle; i>indice; i--){
                lista[i] = lista[i-1];
            }
            
            lista[indice] = valor;
            controle++; // incrementa a quantidade de elementos na lista
        }
    }while(indice < 0 || indice >= 9);
    
    printf("\n");
    visualizarLista();
}

/*****************************************/
void consultar_lista()
{
    clear();

    if (lista_esta_vazia())
        return;
    
    visualizarLista();

    int indice;

    do{
        printf("\nDigite qual indice deseja consultar (entre 0 e 8): ");
        scanf("%d", &indice);
        
        if (indice < 0 || indice >= 9)
        {
            printf("O indice deve ser entre 0 e 8.\n");
        }
        else if (indice >= controle)
        {
            printf("O indice informado e maior que a quantidade de elementos.\n");
        }
        else if (indice >= 0 && indice < controle)
        {
            printf("\nO indice %d conttem o valor %d\n", indice, lista[indice]);
            printf("-----------\n");
        }
    }while(indice < 0 || indice >= 9);
}

/*****************************************/
void visualizarLista(){
    printf("lista = [ ");

    for (int i = 0; i < controle; i++)
    {
        if (i != controle-1)
        {
            printf("%d, ", lista[i]);
        }
        else
        {
            printf("%d ", lista[i]);
        }
    }

    printf("]\n");

    qtd_elementos();
}

/*****************************************/
void esvaziar_lista()
{   
    if(lista_esta_vazia()){
        clear();

        printf("A lista ja esta vazia\n");

        return;
    }

    controle = 0;
    printf("Lista esvaziada\n");
}

/*****************************************/
int lista_esta_vazia()
{
    if (controle == 0)
    {
        printf("A lista esta vazia\n");

        return 1;
    }

    return 0;
}

/*****************************************/
int lista_esta_cheia()
{
    if (controle == MAX)
    {
        printf("----------------------\n");
        printf("| A lista esta cheia |\n");
        printf("----------------------\n");

        return 1;
    }

    return 0;
}

/*****************************************/
void mostraMenu(){
    printf("\n------- Menu de interacao -------\n");
    printf("1 - Visualizar lista\n");
    printf("2 - Inserir elemento\n");
    printf("3 - Consultar elemento\n");
    printf("4 - Remover elemento\n");
    printf("5 - Visualizar quantidade de elementos\n");
    printf("6 - Esvaziar lista\n");
    printf("7 - Finalizar\n\n");
}
