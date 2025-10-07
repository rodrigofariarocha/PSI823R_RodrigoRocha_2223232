#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "funcs.c"
 
int main(){
    system("chcp 65001");
    system("cls");
 
    int escolha;
    bool valid = true;

    loadUtilizador();
 
    do{
        menu();
        fflush(stdin);
        scanf("%d", &escolha);
       
        switch (escolha) {
            case 1:
                system("cls");
                registo();
                break;
            case 2:
                system("cls");
                login();
                break;
            case 3:
                system("cls");
                printf("Saindo da aplicação...\n");
                exit();
            default:
                system("cls");
                printf("Opção inválida! Tente novamente.\n\n");
                break;
            }
    }while(valid);
 
    return 0;
}