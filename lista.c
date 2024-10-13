#include<stdio.h>

int lista[9];
int controle = 0;
//assinatura de funcao, indica que sera usada independente da implementacao
void mostraMenu();
void visualizarLista();
void esvaziarLista();

int main(){
    int opcao;
    mostraMenu();
    printf("Informe o numero da opcao que deseja realizar: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            //funcao para executar opcao 1
            visualizarLista();
        }
    return 0;
}
void visualizarLista(){
    if(controle==0){
        printf("Sua lista esta vazia\n");
    }else {
        for(int i=0; i<controle; i++){
            printf(lista[i]);
        }
    }
  
}

void esvaziarLista()
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
