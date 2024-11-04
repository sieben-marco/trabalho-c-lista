#include<stdio.h>
#include<stdlib.h> // uso da funcao system()
#include "lista.h" // inclui as assinaturas das funcoes usadas

#define MAX 9

// declaracoes globais
int lista[MAX];
int controle = 0;

int main(){
    // declaracoes locais
    int opcao;

    clear();
    visualizarLista();
    qtd_elementos(0);

    while(opcao != 6){
        mostraMenu();

        printf("Digite o numero da operacao: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                clear();
                inserirCodigo();
                break;
            case 2:
                clear();
                consultar_lista();
                break;
            case 3:
                clear();
                remove_elemento();
                break;
            case 4:
                clear();
                qtd_elementos(1);
                break;
            case 5:
                clear();
                esvaziar_lista();
                break;
            case 6:
                clear();
                visualizarLista(); // mostra a lista antes de encerrar
                qtd_elementos(0);
                printf("\nPROGRAMA FINALIZADO.\n\n");
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
void qtd_elementos(int eh_menu)
{
    if (eh_menu){
        printf("--- QUANTIDADE DE ELEMENTOS ---\n");
        visualizarLista();
    }

    // retorna se a lista esta vazia
    if (lista_esta_vazia())
        return;

    // condicao para mensagem no singular ou no plural
    if (controle == 1)
        printf("A lista contem %d elemento.\n", controle);
    else
        printf("A lista contem %d elementos.\n", controle);
}

/*****************************************/
void remove_elemento()
{
    printf("--- REMOCAO DE ELEMENTO ---\n");
    visualizarLista();

    // retorna se a lista esta vazia
    if (lista_esta_vazia())
        return;
    
    qtd_elementos(0);

    int indice; // armazena a posicao de remocao

    do
    {
        printf("\nDigite o indice do elemento que deseja remover (entre 0 e %d): ", MAX-1);
        scanf(" %d", &indice);

        if (indice < 0 || indice >= MAX)
        {
            printf("\nO indice deve ser entre 0 e %d.\n", MAX-1);
        }
        else if (indice >= controle)
        {
            printf("\nO indice informado e maior que a quantidade de elementos.\n");
        }
        else if (indice == controle-1) // Se o valor digitado for igual ao controle-1, remove o ultimo elemento 
        {
            controle--;
        }
        else if (indice >= 0 && indice < controle)
        {
            /** 
             * i recebe o valor (indice) digitado pelo usuario
             * loop ate que o valor digitado seja menor que a lista 
             * Lista na posicao digitada recebe o valor digitado mais um para pegar valor da frente
             * Valor da frente é atribuido a posicao que continha valor removido
            */
            for(int i = indice; i < controle-1; i++){
                lista[i] = lista[i+1];
            }
            
            controle--;
        }
    } while (indice < 0 || indice >= MAX || indice >= controle);

    visualizarLista();
    qtd_elementos(0);
}

/*****************************************/
void inserirCodigo(){
        
    printf("--- INSERCAO DE ELEMENTO ---\n");
    visualizarLista();

    // retorna se a lista esta vazia
    if (lista_esta_cheia())
        return;

    qtd_elementos(0);

    int indice;
    int valor;

    do{
        printf("\nDigite em qual indice deseja inserir (entre 0 e %d): ", MAX-1);
        scanf("%d", &indice);
        
        if (indice < 0 || indice >= MAX)
        {
            printf("\nO indice deve ser entre 0 e %d.\n", MAX-1);
        }
        else if (indice == controle) // neste caso o controle ja possui o valor do primeiro indice livre
        {
            printf("Digite o valor do elemento: ");
            scanf("%d", &valor);

            lista[controle] = valor;
            controle++;//atualiza quantidade de valores na lista
        }
        else if (indice >= 0 && indice < controle)
        {
            printf("Digite o valor do elemento: ");
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
    }while(indice < 0 || indice >= MAX);
    
    printf("\n");
    visualizarLista();
    qtd_elementos(0);
}

/*****************************************/
void consultar_lista()
{
    printf("--- CONSULTA DE ELEMENTO ---\n");
    visualizarLista();

    // retorna se a lista esta vazia
    if (lista_esta_vazia())
        return;

    qtd_elementos(0);

    int indice;

    do{
        printf("\nDigite qual indice deseja consultar (entre 0 e %d): ", MAX-1);
        scanf("%d", &indice);
        
        if (indice < 0 || indice >= MAX)
        {
            printf("\nO indice deve ser entre 0 e %d.\n", MAX-1);
        }
        else if (indice >= controle)
        {
            printf("\nO indice informado e maior que a quantidade de elementos.\n");
        }
        else if (indice >= 0 && indice < controle)
        {
            printf("\nO indice %d contem o valor %d\n", indice, lista[indice]);
        }
    }while(indice < 0 || indice >= MAX || indice >= controle);
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
}

/*****************************************/
void esvaziar_lista()
{   
    printf("--- ESVAZIAR LISTA ---\n");
    visualizarLista();

    // retorna se a lista esta vazia
    if(controle == 0){
        printf("A lista ja esta vazia\n");

        return;
    }

    qtd_elementos(0);

    controle = 0;
    printf("\nLista esvaziada\n");

    visualizarLista();
    qtd_elementos(0);
}

/*****************************************/
int lista_esta_vazia()
{
    // retorna se a lista esta vazia
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
    // retorna se a lista esta cheia
    if (controle == MAX)
    {
        printf("A lista esta cheia\n");

        return 1;
    }

    return 0;
}

/*****************************************/
void mostraMenu(){
    printf("\n------- MENU DE INTERACAO -------\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Consultar elemento\n");
    printf("3 - Remover elemento\n");
    printf("4 - Visualizar quantidade de elementos\n");
    printf("5 - Esvaziar lista\n");
    printf("6 - Finalizar\n\n");
}
