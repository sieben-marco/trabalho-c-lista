#include<stdio.h>
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
        scanf("%d", &opcao);

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
void inserirCodigo(){

    int indice;
    int valor;
    if(controle==0){
        printf("----------------------\n");
        printf("| A lista esta vazia |\n");
        printf("----------------------\n");
        
        printf("Informe a posicao que deseja inserir: \n");
        scanf("%d", &indice);
    }
    
    //se indice for maior que valor de controle, insere o valor no primeiro indice disponivel
    if(indice>controle){
        printf("Digite o valor da posicao: \n");
        scanf("%d", &valor);

        lista[controle] = valor;
        controle++;//atualiza quantidade de valores na lista
        return;
    }
    //se indice estiver no intervalo entre 0 e controle, modifica posicoes e insere valor
    if(indice > 0 && indice < controle){
        for(int i=controle; i>indice; i--){
            lista[i+1] = lista[i];
        }
        visualizarLista();
        return;

    }
   

}

/*****************************************/
void consultar_lista()
{
    if (controle == 0) // se a lista esta vazia
    {
        visualizarLista();
        return;
    }
    
    int indice;


    printf("Digite qual índice deseja consultar: ");
    scanf("%d", &indice);
    
    if (indice > controle)
    {
        printf("A quantidade de elementos e menor que o indice escolhido.\n");
        visualizarLista();
        return;
    }

    if (indice < 0)
    {
        printf("O indice nao pode ser negativo.\n");
        visualizarLista();
        return;
    }

    if (indice > 0 && indice < controle)
    {
        printf("%d\n", lista[indice]);
        visualizarLista();
        return;
    }
}

/*****************************************/
void visualizarLista(){
    if(controle==0){
        printf("----------------------\n");
        printf("| A lista esta vazia |\n");
        printf("----------------------\n");
        return;
    }

    printf("A lista contem %d elementos.\n", controle);

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
