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

    while(opcao != 7){
        mostraMenu();

        printf("Digite o numero da operacao: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                visualizarLista();
                break;
            case 2:
                inserirCodigo();
                break;
            case 3:
                consultar_lista();
                break;
            case 4:
                remove_elemento();
                break;
            case 5:
                qtd_elementos();
                break;
            case 6:
                esvaziar_lista();
                break;
            case 7:
                visualizarLista();
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
    system("cls || clear"); //limpa a tela
}

/*****************************************/
void qtd_elementos()
{
    if (lista_esta_vazia())
        return;

    if (controle == 1)
        printf("A lista contem %d elemento.\n\n", controle);
    else
        printf("A lista contem %d elementos.\n\n", controle);
}

/*****************************************/
void remove_elemento()
{
    clear();

    if (lista_esta_vazia())
        return;

    int indice;
    int valor;

    do
    {
        printf("Digite de qual indice deseja remover um elemento (entre 0 e %d): ", controle-1);
        scanf(" %d", &indice);

        if (indice < 0 || indice >= 9)
        {
            printf("O indice deve ser entre 0 e %d.\n", controle-1);
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
    } while (indice < 0 || indice >= controle-1);
}

/*****************************************/
void inserirCodigo(){
    clear();

    if (lista_esta_cheia())
        return;

    int indice;
    int valor;

    do{
        printf("Digite qual indice deseja inserir (entre 0 e %d): ", controle);
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
            printf("No indice %d tem o valor %d \n", indice, lista[indice]);
        }
    }while(indice < 0 || indice >= 9);
}

/*****************************************/
void visualizarLista(){
    clear();

    // if(lista_esta_vazia())
    //     return;
    
    // printf("indice:");
    // for (int i = 0; i < controle; i++) {
    //     printf("   %d", i);
    // }

    // printf("\nvalor:  ");
    // printf("| ");
    // for(int i=0; i<controle; i++){
    //     printf("%d | ", lista[i]);
    // }

    // printf("\n");

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
    clear();
    
    if(lista_esta_vazia()){
        clear();

        printf("-------------------------\n"); 
        printf("| A lista ja esta vazia |\n");
        printf("-------------------------\n");

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
        printf("----------------------\n");
        printf("| A lista esta vazia |\n");
        printf("----------------------\n");

        visualizarLista();

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
    printf("\n---------- Menu de interacao ----------\n");
    printf("1 - Visualizar lista\n");
    printf("2 - Inserir codigo\n");
    printf("3 - Consultar codigo\n");
    printf("4 - Remover codigo\n");
    printf("5 - Visualizar quantidade de elementos\n");
    printf("6 - Esvaziar lista\n");
    printf("7 - Finalizar\n\n");
}



