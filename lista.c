// desenvolver lista
#include<stdio.h>
int vet[9];
//assinatura da funcao indica que sera usada essa funcao independente da implementacao
void mostraMenu();

int main(){
    mostraMenu();

    return 0;
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