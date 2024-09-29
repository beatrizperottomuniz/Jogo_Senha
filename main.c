
// bibliotecas
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> //funções rand() e srand()
#include <string.h>
#include <time.h> //necessário p/ função time()
// cabeçalho funções
int regra1(char[]);
int regra2(char[]);
int regra3(char[]);
int regra4(char[]);
int regra5(char[]);
int regra6(char[]);
int regra7(char[], char[]);
int regra8(char[]);
int regra9(char[]);
int regra10(char[]);

int main(void) {
  char *regras[] = {"Regra 1: Sua senha precisa ter pelo menos 5 caracteres",
                    "Regra 2 : Sua senha precisa incluir um número",
                    "Regra 3 : Sua senha precisa incluir uma letra maiúscula",
                    "Regra 4 : Sua senha precisa incluir um caractere especial",
                    "Regra 5 : A soma dos números da senha deve ser igual a 25",
                    "Regra 6 : Sua senha precisa incluir uma algarismo romano",
                    "Regra 7 : Sua senha precisa incluir esse número",
                    "Regra 8 :  tem que ter todas as vogais",
                    "Regra 9 : tem que ter um mês",
                    "Regra 10 :  O tamanho da sua senha deve ser um número "
                    "impar"}; // vetor de ponteiros de vetores de char-um
                              // equivalente do vetor de string no py
  char senha[250];
  int c = 1, i;
  char sorteio[2];
  int numero;
  srand(time(NULL));
  // o numero sorteado vai ser um por rodada, sorteado então fora do loop
  // sorteio ,será colocado em char para podermos procurar na string
  for (i = 0; i < 2; i++) {
    numero = 1 + rand() % 9;
    sorteio[i] = numero + '0'; // numero mais o codigo do numero 0
  }
  // começa o jogo
  printf("---------------------JOGO DA SENHA---------------------");
  printf("\nDigite as senhas seguindo as regras indicadas, clique <ENTER> para "
         "checar a senha\n");

  while (c <= 10) {
    senha[0] = '\0'; // limpa a string
    c = 1; // reinicia o contador pois se errar no 10,eu preciso que reveja
           // todas as senhas

    // receber a senha
    printf("\nDigite uma senha:");
    scanf("%s",
          &senha[0]); // https://pt.stackoverflow.com/questions/260041/fun%C3%A7%C3%A3o-recebe-como-par%C3%A2metro-um-vetor-de-strings
                      // - passamos o endereço de onde começa o vetor de char.

    // checa/mostra as regras
    printf("\n%s", regras[0]);
    if (c >= 1) { // checa a regra 1 , se continua=True, continua aumentando c ,
                  // mostra a regra 2 e que vc acertou a anterior, caso
                  // contrário, volta para while e pede senha novamente
      if (regra1(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[1]);
      }
    }
    if (c >= 2) {
      if (regra2(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[2]);
      }
    }
    if (c >= 3) {
      if (regra3(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[3]);
      }
    }
    if (c >= 4) {
      if (regra4(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[4]);
      }
    }
    if (c >= 5) {
      if (regra5(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[5]);
      }
    }
    if (c >= 6) {
      if (regra6(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[6]);
        printf(" %c%c", sorteio[0], sorteio[1]);
      }
    }
    if (c >= 7) {
      if (regra7(senha, sorteio)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[7]);
      }
    }
    if (c >= 8) {
      if (regra8(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[8]);
      }
    }
    if (c >= 9) {
      if (regra9(senha)) {
        c++;
        printf("\nVocê cumpriu a regra");
        printf("\n%s", regras[9]);
      }
    }
    if (c == 10) {
      if (regra10(senha)) {
        c++;
        printf("\nVocê cumpriu a regra\nFIM DE JOGO");
      }
    }
  }
  return 0;
}

int regra1(char input[250]) {
  if (strlen(input) >= 5) {
    return 1;
  }
  return 0;
}

int regra2(char input[250]) {
  int c = 0;
  while (!(input[c] == '\0')) {
    if (isdigit(input[c])) {
      return 1;
    }
    c++;
  }
  return 0;
}

int regra3(char input[250]) {
  int c = 0;
  while (!(input[c] == '\0')) {
    if (isupper(input[c])) {
      return 1;
    }
    c++;
  }
  return 0;
}

int regra4(char input[250]) { // vamos testar se o carcter é numero ou letra, se
                              // não for vai ser carctere especial
  int c = 0;
  while (!(c == strlen(input))) {
    if (!isalnum(input[c])) {
      return 1;
    }
    c++;
  }
  return 0;
}

int regra5(char input[250]) {
  int c = 0;
  int soma = 0;
  int num = 0;
  while (!(input[c] == '\0')) {
    if (isdigit(input[c])) { 
      num = input[c] - '0';
      soma = soma + num;
    }
    c++;
  }
  if (soma == 25) {
    return 1;
  }
  return 0;
}

int regra6(char input[250]) {
  int c = 0;
  int i;
  char romanos[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  while (!(input[c] == '\0')) {
    for (i = 0; i < 7; i++) {
      if (input[c] == romanos[i]) {
        return 1;
      }
    }
    c++;
  }
  return 0;
}

int regra7(char input[250], char sorteio[]) {
  int c = 0;
  while (!(input[c] == '\0')) {
    if (isdigit(input[c])) {
      if (input[c] == sorteio[0] && input[c + 1] == sorteio[1]) {
        return 1;
      }
    }
    c++;
  }
  return 0;
}

int regra8(char input[250]) {
  int c = 0;
  int i;
  char vogais[] = {'a', 'e', 'i', 'o', 'u'};
  int quant_vogal[5] = {0};
  while (!(input[c] == '\0')) {
    for (i = 0; i < 5; i++) {
      if (tolower(input[c]) == vogais[i]) {
        quant_vogal[i]++;
      }
    }
    c++;
  }
  for (i = 0; i < 5; i++) {
    if (quant_vogal[i] == 0) {
      return 0;
    }
  }
  return 1;
}

int regra9(char input[250]) {
  int i;
  int c = 0;
  char senha_min[250];
  char mes[20];
  char *ocorrencia;
  char *meses[] = {"janeiro",  "fevereiro", "marco",    "abril",
                   "maio",     "junho",     "julho",    "agosto",
                   "setembro", "outubro",   "novembro", "dezembro"};
  strcpy(senha_min, input);      // copia a string para outro vetor
  while (senha_min[c] != '\0') { // deixa toda a senha em minusculo
    senha_min[c] = tolower(senha_min[c]);
    c++;
  }
  for (i = 0; i < 12; i++) {
    mes[0] = '\0';
    strcpy(mes, meses[i]);
    ocorrencia = strstr(senha_min, mes); // procura ocorrencia da string (nome
                                         // do mes) na string senha em minusculo
    if (ocorrencia != NULL) {
      return 1;
    }
  }
  return 0;
}

int regra10(char input[250]) {
  int tamanho = strlen(input);
  if (tamanho % 2 != 0) {
    return 1;
  }
  return 0;
}
