#include<stdio.h>

// declaracoes globais
int lista[9];
int controle = 0;

//assinatura de funcao, indica que sera usada independente da implementacao
void mostraMenu();
void visualizarLista();
void consultar_lista();
void esvaziar_lista();
void inserirCodigo();

int main(){
    // declaracoes locais
    int opcao;
    mostraMenu();

    while(opcao != 7){
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
        }
    }

    return 0;
}
void inserirCodigo(){

    int indice;
    int valor;
    if(controle==0){
    printf("|--------------------|\n");
    printf("| A lista esta vazia |\n");
    printf("|--------------------|\n");
    
    printf("Informe a posicao que deseja inserir: \n");
    scanf("%d", &indice);
    }else{}
    
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

void consultar_lista()
{

}

void visualizarLista(){
    if(controle==0){
        printf("|--------------------|\n");
        printf("| A lista esta vazia |\n");
        printf("|--------------------|\n");
    }else {
        for(int i=0; i<controle; i++){
            printf("%d | ", lista[i]);
        }
        printf("\n");
    }
  
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
    printf("7 - Finalizar\n");
}
