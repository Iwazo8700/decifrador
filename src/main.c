/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

char subtrai_modulo_alfabeto(char senha, char codigo){
    char senha0, codigo0, original0;
    if(codigo >= 'A' && codigo <= 'Z'){
        senha0 = 'A' - senha;
        codigo0 = 'A' - codigo;
        /*subtraio o caractere da senha pelo do codigo pra gerar o caractere que buscamos
          ja que pra gerar a cifra somamos o caractere da senha pelo texto, a soma de 'Z'-'A'+1
          se da para que resultados negativos da subtracao sejam positivos(deslocamento em 'Z'-'A'+1 para direita)*/
        original0 = 'A' + (('Z'-'A'+ 1 + senha0 - codigo0)%('Z'-'A'+1));
        return original0;    
    }else return codigo;
    
}


int main() {
    int i=0, j=0;
    /* Leitura da entrada */
    fgets(buffer_entrada, TAM_BUFFER, stdin);
    
    for(i = 0; (i < TAM_BUFFER) && (buffer_entrada[i] != '\0') && (buffer_entrada[i] != '\n'); i++){
        /*coloca os caracteres para uppercase(mais pra testes do que pro lab mesmo pra poder entrar
          com caracteres em letra minuscula)*/
        buffer_entrada[i] = toupper(buffer_entrada[i]);
        /*Decodifica o codigo e coloca no buffer de saida*/
        buffer_saida[i] = subtrai_modulo_alfabeto(senha[j], buffer_entrada[i]);
        j++;
        /*rotacao da senha para ficar algo como SENHASECRETASENHASECRETA se o tamanho da entrada
          for maior que o tamanho da senha*/
        if(senha[j] == '\0') j = 0;
    }
    /*insere o caractere de fim de string na saida*/
    buffer_saida[i] = '\0';


    /* Escrever saida na tela */
    printf("%s\n", buffer_saida);

  return 0;
}
