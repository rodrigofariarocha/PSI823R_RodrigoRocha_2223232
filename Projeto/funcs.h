void ficheiroBilhetesComDesconto(char *nome, char *cidade, int distancia, int numeroLugar, float novoPreco, char *horario);
 
void ficheiroBilhetesSemDesconto(char *nome, char *cidade, int distancia, int numeroLugar, float preco, char *horario);
 
 
bool loadUtilizador();
 
void saveUtilizador();
 
void titulo();
 
void titulo2();
 
void titulo3();
 
void menu();
 
void registo();
 
void login();
 
 
void escolhaDoDestino(char *horario);
 
void menuDeDesconto(char *cidade, int distancia, int numeroLugar, float preco, char *horario);
 
void menuCompra();

void checkDesconto(float preco, char *cidade, int distancia, int numeroLugar, char *horario);
 
void autocarro();
 
void escolhaLugar(char *nomeUtilizador, char *cidade, int distancia, char *horario);
 
void menuFinalSemDesconto(float preco, char *cidade, int distancia, int numeroLugar, char *horario);
 
void menuFinalComDesconto(float novoPreco, char *cidade, int distancia, int numeroLugar, char *horario);
 
int main();

void escolherHoraDaViagem();