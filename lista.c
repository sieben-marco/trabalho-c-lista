#include<stdio.h>

// declaracoes globais
int lista[9];
int controle = 0;

// assinatura de funcao, indica que sera usada independente da implementacao
void mostraMenu();
void visualizarLista();
void consultar_lista();
void esvaziar_lista();

int main(){
    // declaracoes locais
    int opcao;

    mostraMenu();

    printf("Informe o numero da opcao que deseja realizar: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            // funcao para executar opcao 1
            visualizarLista();
            break;
        case 2:
            // funcao para executar opcao 2
            consultar_lista();
            break;
    }

    return 0;
}

void consultar_lista()
{
    if (controle == 0) // se a lista esta vazia
        return;
    
    int indice;

    visualizarLista();

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

void visualizarLista(){
    if(controle==0){
        printf("Sua lista esta vazia\n");
        return;
    }

    for(int i=0; i<controle; i++){
        printf("%d | ", lista[i]);
    }

    printf("\n");
}

void esvaziar_lista()
{
    controle = 0;
}

void mostraMenu(){
    printf("### Menu de interacao ###\n");
    printf("1 - Visualizar lista\n");
    printf("2 - Consultar codigo\n");
    printf("3 - Inserir codigo\n");
    printf("4 - Remover codigo\n");
    printf("5 - Visualizar quantidade de elementos\n");
    printf("6 - Esvaziar lista\n");
}
