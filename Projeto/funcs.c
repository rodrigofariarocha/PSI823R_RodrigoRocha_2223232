#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "funcs.h"
 
#define DISTANCIA_LISBOA_AVEIRO 280
#define DISTANCIA_LISBOA_BEJA 380
#define DISTANCIA_LISBOA_BRAGA 320
#define DISTANCIA_LISBOA_BRAGANCA 560
#define DISTANCIA_LISBOA_CASTELO_BRANCO 230
#define DISTANCIA_LISBOA_COIMBRA 200
#define DISTANCIA_LISBOA_EVORA 130
#define DISTANCIA_LISBOA_FARO 260
#define DISTANCIA_LISBOA_GUARDA 340
#define DISTANCIA_LISBOA_LEIRIA 150
#define DISTANCIA_LISBOA_PORTALEGRE 220
#define DISTANCIA_LISBOA_PORTO 310
#define DISTANCIA_LISBOA_SANTAREM 80
#define DISTANCIA_LISBOA_SETUBAL 30
#define DISTANCIA_LISBOA_VIANA_DO_CASTELO 390
#define DISTANCIA_LISBOA_VILA_REAL 440
#define DISTANCIA_LISBOA_VISEU 240
 
#define MAX_UTILIZADORES 300
#define NOME_UTILIZADOR_LEN 50
#define PASSWORD_LEN 50
#define FILE_NAME "utilizadores.txt"
#define FICHEIRO_CODIGO_DESCONTO "código_desconto.txt"
 
#define RESET_COLOR "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\e[0;31m"
 
#define FICHEIRO_BILHETES "bilhetes.txt"
#define MAX_LUGARES 25
 
#define PRECO_BILHETE 0
 
 
//------------------------------------------------------------------------------------
//                                  ESTRUTURAS
//------------------------------------------------------------------------------------
typedef struct {
    char nomeUtilizador[NOME_UTILIZADOR_LEN];
    char password[PASSWORD_LEN];
} Utilizador;
 
typedef struct {
    char nome[50];
    char cidade[50];
    char distancia[50];
    int lugarAutocarro;
    int precoFinal;
    char horario[4];
} Ticket;
 
typedef struct {
    char codigo[20];
    float desconto;
} codigoDesconto;
 
 
Utilizador utilizadores[MAX_UTILIZADORES];
int countDeUtilizadores = 0;
 
//------------------------------------------------------------------------------------
//                            FUNÇÕES DOS FICHEIROS
//------------------------------------------------------------------------------------
// FUNÇÃO PARA TICKET FILE
void ficheiroBilhetesComDesconto(char *nomeUtilizador, char *cidade, int distancia, int numeroLugar, float novoPreco, char *horario) {
    bool lugares[MAX_LUGARES] = {false};
 
    Ticket myTicket;
    myTicket.lugarAutocarro = 0;
    myTicket.precoFinal = 0;
 
    FILE *fp = fopen("bilhetes.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo bilhetes.txt!\n");
        return;
    } else {
        fprintf(fp, "Nome: %s\n", nomeUtilizador);
        fprintf(fp, "Destino: %s\n", cidade);
        fprintf(fp, "Distância até ao destino: %d km\n", distancia);
        fprintf(fp, "Nº Lugar: %d\n", numeroLugar);
        fprintf(fp, "Horário de partida: %s\n", horario);
        fprintf(fp, "Total a pagar: %.2f€\n\n", novoPreco);
 
        fprintf(fp, "--------------------------\n\n");
 
        fclose(fp);
    }
}

void ficheiroBilhetesSemDesconto(char *nomeUtilizador, char *cidade, int distancia, int numeroLugar, float preco, char *horario) {
    bool lugares[MAX_LUGARES] = {false};
 
    Ticket myTicket;
    myTicket.lugarAutocarro = 0;
    myTicket.precoFinal = 0;
 
    FILE *fp = fopen("bilhetes.txt", "a");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo bilhetes.txt!\n");
    } else {
        fprintf(fp, "Nome: %s\n", nomeUtilizador);
        fprintf(fp, "Destino: %s\n", cidade);
        fprintf(fp, "Distância até ao destino: %d km\n", distancia);
        fprintf(fp, "Nº Lugar: %d\n", numeroLugar);
        fprintf(fp, "Horário de partida: %s\n", horario);
        fprintf(fp, "Total a pagar: %.2f€\n", preco);
 
        fprintf(fp, "--------------------------\n\n");
 
        fclose(fp);
    }
}
 
 
// VERFICAÇÃO DO UTILIZADOR (JÁ EXISTENTE OU NÃO)
bool loadUtilizador() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL) {
        countDeUtilizadores = 0;
        while (fscanf(file, "%s %s", utilizadores[countDeUtilizadores].nomeUtilizador, utilizadores[countDeUtilizadores].password) == 2) {
            countDeUtilizadores++;
        }
        fclose(file);
        return true;
    }
    return false;
}
 
 
//SAVE DO USER NO FICHEIRO
void saveUtilizador() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL) {
        for (int i = 0; i < countDeUtilizadores; i++) {
            fprintf(file, "%s %s\n", utilizadores[i].nomeUtilizador, utilizadores[i].password);
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o ficheiro!\n");
    }
}
//------------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------------
//                                  FUNÇÕES
//------------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------------
 
 
//------------------------------------------------------------------------------------
//                               TITULOS
//------------------------------------------------------------------------------------
void titulo() {
    system("cls");
    printf("\033[1;34m");
    printf("***********************************************\n");
    printf("\033[1;33m");
    printf("*                                             *\n");
    printf("*        BEM-VINDO À LISBON BUS VOYAGE        *\n");
    printf("*                                             *\n");
    printf("\033[1;34m");
    printf("***********************************************\n");
    printf("\033[0m");
}
 
void titulo2() {
    system("cls");
    printf("\033[1;33m");
    printf("********************************************\n");
    printf("\033[1;34m");
    printf("*                                          *\n");
    printf("*              MENU DE COMPRA              *\n");
    printf("*                                          *\n");
    printf("\033[1;33m");
    printf("********************************************\n");
    printf("\033[0m");
}
 
void titulo3() {
    system("cls");
    printf("\033[33m");
    printf("\nCÓDIGO DE DESCONTO:\n\n");
    printf("\033[0m");
}
 
 
//------------------------------------------------------------------------------------
//                               MENU PRINCIPAL
//------------------------------------------------------------------------------------
void menu() {
    titulo();
    printf("\n1 - Registre-se\n"
           "2 - Já tem conta?\n"
           "3 - Sair da aplicação\n\n"
           "Escolha uma opção: ");
}
 
 
//------------------------------------------------------------------------------------
//                                  REGISTO
//------------------------------------------------------------------------------------
void registo() {
    if (countDeUtilizadores >= MAX_UTILIZADORES) {
        printf("Número máximo de utilizadores atingido.\n\n");
        system("pause");
        menu();
    }

    Utilizador novoUtilizador;
    bool valid = false;
    char ch;
    int i;

    do {
        printf("\033[33m");
        printf("\nREGISTO\n\n");
        printf("\033[0m");

        valid = true;
        printf("Digite o nome de utilizador: ");
        scanf("%s", novoUtilizador.nomeUtilizador);

        for (int i = 0; i < countDeUtilizadores; i++) {
            if (strcmp(utilizadores[i].nomeUtilizador, novoUtilizador.nomeUtilizador) == 0) {
                printf("\nNome de utilizador já existe!\n\n");
                valid = false;
                system("pause");
                main();
            }
        }

        if (!valid) {
            system("pause");
        }

        printf("Digite a password: ");
        i = 0;
        while ((ch = getch()) != '\r' && i < PASSWORD_LEN - 1) {
            if (ch == 8 && i > 0) {
                printf("\b \b");
                i--;
            } else if (ch != 8) {
                novoUtilizador.password[i] = ch;
                i++;
                printf("*");
            }
        }
        novoUtilizador.password[i] = '\0';

        utilizadores[countDeUtilizadores] = novoUtilizador;
        countDeUtilizadores++;
        saveUtilizador(); 

        printf("\n\nRegistro bem-sucedido.\n\n");
        system("pause");
        menu(); 
        return;

    } while (!valid);
}

 
//------------------------------------------------------------------------------------
//                                  LOGIN
//------------------------------------------------------------------------------------
void login() {
    char nomeUtilizador[NOME_UTILIZADOR_LEN];
    char password[PASSWORD_LEN];
    int i = 0;
    char ch;

    printf("\033[33m");
    printf("\nLOGIN\n\n");
    printf("\033[0m");

    printf("Digite o nome de utilizador: ");
    scanf("%s", nomeUtilizador);

    printf("Digite a password: ");
    i = 0;
    while ((ch = getch()) != '\r' && i < PASSWORD_LEN - 1) {
        if (ch == 8 && i > 0) {
            printf("\b \b");
            i--;
        } else if (ch != 8) {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    password[i] = '\0';

    printf("\n");

    bool loginVerify = false;

    for (int i = 0; i < countDeUtilizadores; i++) {
        if (strcmp(utilizadores[i].nomeUtilizador, nomeUtilizador) == 0 && strcmp(utilizadores[i].password, password) == 0) {
            printf("\nLogin bem-sucedido. Bem-vindo, %s!\n\n", nomeUtilizador);
            loginVerify = true;
            system("pause");
            menuCompra(); 
            return;
        }
    }

    if (!loginVerify) {
        printf("\nNome de utilizador ou senha incorretos.\n\n");
        system("pause");
        main(); 
    }
}

 
 
//------------------------------------------------------------------------------------
//                           MENU DE COMPRA
//------------------------------------------------------------------------------------
void menuCompra() {
    int escolha;

    titulo2();
    printf("\n1 - Comprar Bilhete\n");
    printf("2 - Voltar ao Menu Principal\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            system("cls");
            escolherHoraDaViagem();
            break;
        case 2:
            system("cls");
            printf("Voltando...\nPor favor aguarde...\n\n");
            system("pause");
            menu();
            break;
        default:
            system("cls");
            printf("Opção inválida! Tente novamente.\n\n");
            system("pause");
            menuCompra(); 
    }
}
 

//------------------------------------------------------------------------------------
//                           ESCOLHA DO HORARIO
//------------------------------------------------------------------------------------
void escolherHoraDaViagem() {
    system("cls");
    printf("\033[33m");
    printf("\nESCOLHA A HORA DA VIAGEM:");
    printf("\033[0m");

    char horario[5];
    bool valid = false;

    while (!valid) {
        printf("\n\nInsira o horário (ex: 14h): ");
        scanf("%4s", horario);

        int len = strlen(horario);
        if (len != 3) {
            printf("Erro: O horário deve ter 3 caracteres (ex: 14h).\n\n");
            system("pause");
            escolherHoraDaViagem();
        }

        if (horario[2] != 'h') {
            printf("Erro: O horário deve terminar com 'h' (ex: 14h).\n\n");
            system("pause");
            escolherHoraDaViagem();

        if (horario[0] < '0' || horario[0] > '2' || (horario[0] == '2' && (horario[1] < '0' || horario[1] > '3')) || (horario[0] != '2' && (horario[1] < '0' || horario[1] > '9'))) {
            printf("Erro: A hora deve estar entre 00h e 23h.\n\n");
            system("pause");
            escolherHoraDaViagem();
        }

        valid = true;
    }

    printf("\nHorário selecionado: %s\n\n", horario);

    system("pause");
    escolhaDoDestino(horario);
    }
}


//------------------------------------------------------------------------------------
//                           ESCOLHA DO DESTINO
//------------------------------------------------------------------------------------
void escolhaDoDestino(char *horario) {
    int cidadeEscolhida;

    system("cls");

    printf("     ************************************************\n");
    printf("     *          " BLUE "Selecione o seu destino" RESET_COLOR "             *\n");
    printf("     ************************************************\n\n");
    printf("    " RED "Norte" RESET_COLOR "               |    " YELLOW "Centro" RESET_COLOR "             |    " GREEN "Sul" RESET_COLOR "\n");
    printf(" -----------------------------------------------------------------\n");
    printf("  1 - Braga             | 8 - Castelo Branco    | 14 - Beja\n");
    printf("  2 - Bragança          | 9 - Coimbra           | 15 - Évora\n");
    printf("  3 - Porto             | 10 - Leiria           | 16 - Faro\n");
    printf("  4 - Viana do Castelo  | 11 - Santarém         | 17 - Setúbal\n");
    printf("  5 - Vila Real         | 12 - Viseu            |\n");
    printf("  6 - Aveiro            | 13 - Portalegre       |\n");
    printf("  7 - Guarda            |                       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf("\nEscolha uma opção: ");
    fflush(stdin);
    scanf("%d", &cidadeEscolhida);

    char cidade[20];
    int distancia = 0;

    switch (cidadeEscolhida) {
        case 1:
            distancia = DISTANCIA_LISBOA_BRAGA;
            strcpy(cidade, "Braga");
            break;
        case 2:
            distancia = DISTANCIA_LISBOA_BRAGANCA;
            strcpy(cidade, "Bragança");
            break;
        case 3:
            distancia = DISTANCIA_LISBOA_PORTO;
            strcpy(cidade, "Porto");
            break;
        case 4:
            distancia = DISTANCIA_LISBOA_VIANA_DO_CASTELO;
            strcpy(cidade, "Viana do Castelo");
            break;
        case 5:
            distancia = DISTANCIA_LISBOA_VILA_REAL;
            strcpy(cidade, "Vila Real");
            break;
        case 6:
            distancia = DISTANCIA_LISBOA_AVEIRO;
            strcpy(cidade, "Aveiro");
            break;
        case 7:
            distancia = DISTANCIA_LISBOA_GUARDA;
            strcpy(cidade, "Guarda");
            break;
        case 8:
            distancia = DISTANCIA_LISBOA_CASTELO_BRANCO;
            strcpy(cidade, "Castelo Branco");
            break;
        case 9:
            distancia = DISTANCIA_LISBOA_COIMBRA;
            strcpy(cidade, "Coimbra");
            break;
        case 10:
            distancia = DISTANCIA_LISBOA_LEIRIA;
            strcpy(cidade, "Leiria");
            break;
        case 11:
            distancia = DISTANCIA_LISBOA_SANTAREM;
            strcpy(cidade, "Santarém");
            break;
        case 12:
            distancia = DISTANCIA_LISBOA_VISEU;
            strcpy(cidade, "Viseu");
            break;
        case 13:
            distancia = DISTANCIA_LISBOA_PORTALEGRE;
            strcpy(cidade, "Portalegre");
            break;
        case 14:
            distancia = DISTANCIA_LISBOA_BEJA;
            strcpy(cidade, "Beja");
            break;
        case 15:
            distancia = DISTANCIA_LISBOA_EVORA;
            strcpy(cidade, "Évora");
            break;
        case 16:
            distancia = DISTANCIA_LISBOA_FARO;
            strcpy(cidade, "Faro");
            break;
        case 17:
            distancia = DISTANCIA_LISBOA_SETUBAL;
            strcpy(cidade, "Setúbal");
            break;
        default:
            system("cls");
            printf("Opção inválida! Tente novamente.\n\n");
            system("pause");
            escolhaDoDestino(horario);
            return;
    }

    system("cls");
    escolhaLugar(utilizadores[countDeUtilizadores - 1].nomeUtilizador, cidade, distancia, horario);
}

 
//------------------------------------------------------------------------------------
//                            MENU DE DESCONTO
//------------------------------------------------------------------------------------
void menuDeDesconto(char *cidade, int distancia, int numeroLugar, float preco, char *horario) {
    system("cls");
    char escolha;
    bool valid = false;
 
    titulo3();
    printf("Tem código de desconto? (s/n)\n");
    printf(": ");
 
    while (!valid) {
        scanf(" %c", &escolha);
 
        switch (escolha) {
            case 's':
                checkDesconto(preco, cidade, distancia, numeroLugar, horario);
                valid = true;
                break;
            case 'n':
                menuFinalSemDesconto(preco, cidade, distancia, numeroLugar, horario);
                valid = true;
                break;
            default:
                system("cls");
                printf("Opção inválida! Por favor escolha apenas 's' ou 'n'.\n\n");
                menuDeDesconto(cidade, distancia, numeroLugar, preco, horario);
        }
    }
}
 
 
 
//------------------------------------------------------------------------------------
//                           VERIFICADOR DO CÓDIGO DE DESCONTO
//------------------------------------------------------------------------------------
void checkDesconto(float preco, char *cidade, int distancia, int numeroLugar, char *horario) {
    Ticket myTicket;

    codigoDesconto codigo[] = {{"ROCHABUS", 20.0}, {"ROCHATIKTOKBUS", 15.0}};
    int codigoDescontoCount = sizeof(codigo) / sizeof(codigo[0]);

    char codigoUtilizador[20];
    float novoPreco = preco;

    printf("\nInsira o código de desconto: ");
    scanf("%19s", codigoUtilizador);

    bool valid = false;

    for (int i = 0; i < codigoDescontoCount; i++) {
        if (strcmp(codigo[i].codigo, codigoUtilizador) == 0) {  // Alterado 'codigoUtilizador' para 'codigo'
            novoPreco = preco * (1.0 - codigo[i].desconto / 100.0);  // Alterado 'codigoUtilizador' para 'desconto'
            system("cls");
            printf("\nDesconto aplicado com sucesso!\nPreço anterior: %.2f\nPreço com desconto: %.2f€\n\n", preco, novoPreco);
            valid = true;
            break;
        }
    }

    if (valid == false) {
        system("cls");
        printf("Código de desconto inválido!\n\n");
        system("pause");
        menuDeDesconto(cidade, distancia, numeroLugar, preco, horario);  // Retirado o selectHorario() e usado 'horario'

    }

    system("pause");
    menuFinalComDesconto(novoPreco, cidade, distancia, numeroLugar, horario);
}
 
 
//------------------------------------------------------------------------------------
//                            ESCOLHA DO LUGAR
//------------------------------------------------------------------------------------
void autocarro() {

    printf("\033[33m");
    printf("AUTOCARRO:\n\n");
    printf("\033[0m");

    printf(" _porta_______0___________________0_________\n");
    printf("|       | 1 | 5 |  9 | 13 | 15 | 19 |  21  |\n");
    printf("|       | 2 | 6 | 10 | 14 | 16 | 20 |  22  |\n");
    printf("|------------------------------------- 23  |\n");
    printf("|------------------------------------- 24  |\n");
    printf("| motorista| 3 | 7 | 11 | 17 ||  WC || 25  |\n");
    printf("|__________|_4_|_8_|_12_|_18_||_____||_____|\n");
    printf("             0                   0\n\n");
}
 
bool lugares[MAX_LUGARES] = {false};

void escolhaLugar(char *nomeUtilizador, char *cidade, int distancia, char *horario) {
    int numeroLugar;

    autocarro();

    printf("\033[33m");
    printf("\nESCOLHA O SEU LUGAR: ", MAX_LUGARES);
    printf("\033[0m");
    scanf("%d", &numeroLugar);

    while (numeroLugar < 1 || numeroLugar > MAX_LUGARES || lugares[numeroLugar - 1]) {
        printf("Lugar inválido ou já reservado!\n\nEscolha outro lugar (1-%d): ", MAX_LUGARES);
        fflush(stdin);
        scanf("%d", &numeroLugar);
    }

    lugares[numeroLugar - 1] = true;
    printf("\nLugar reservado com sucesso!\n");

    float preco = 0.0;
    if (distancia < 100) {
        preco = 4.50;
    } else if (distancia <= 200) {
        preco = 7.50;
    } else if (distancia <= 300) {
        preco = 9.99;
    } else if (distancia <= 350) {
        preco = 14.99;
    } else if (distancia > 350) {
        preco = 16.99;
    }

    system("cls");
    menuDeDesconto(cidade, distancia, numeroLugar, preco, horario);  // Passar parâmetros corretos
}

 
 
//------------------------------------------------------------------------------------
//                            MENUS FINAIS
//------------------------------------------------------------------------------------
void menuFinalSemDesconto(float preco, char *cidade, int distancia, int numeroLugar, char *horario){
    system("cls");
    ficheiroBilhetesSemDesconto(utilizadores[countDeUtilizadores - 1].nomeUtilizador, cidade, distancia, numeroLugar, preco, horario);
    printf("\033[33m");
    printf("OBRIGADO POR ESCOLHER VIAJAR COM A LISBON BUS VOYAGE!\033[0m\n\nDesejamos-lhe uma ótima viagem.\nPode ver o seu bilhete no ficheiro 'tickets.txt'.\n\n");
    system("pause");
    menuCompra();
}
 
void menuFinalComDesconto(float novoPreco, char *cidade, int distancia, int numeroLugar, char *horario) {
    system("cls");
    ficheiroBilhetesComDesconto(utilizadores[countDeUtilizadores - 1].nomeUtilizador, cidade, distancia, numeroLugar, novoPreco, horario);
    printf("\033[33m");
    printf("OBRIGADO POR ESCOLHER VIAJAR COM A LISBON BUS VOYAGE!\033[0m\n\nDesejamos-lhe uma ótima viagem.\nPode ver o seu bilhete no ficheiro 'tickets.txt'.\n\n");
    system("pause");
    menuCompra();
}