/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

char subtrai_modulo_alfabeto(char senha, char codigo){
    char senha0, codigo0, original0;
    if(codigo >= 'A' && codigo <= 'Z'){
        senha0 = 'A' - senha;
        codigo0 = 'A' - codigo;

        original0 = 'A' + (('Z'-'A'+ 1 + senha0 - codigo0)%('Z'-'A'+1));
        return original0;    
    }else return codigo;
    
}


int main() {
    int i=0, j=0;
    /* Leitura da entrada */
    fgets(buffer_entrada, TAM_BUFFER, stdin);
    
    for(i = 0; (i < TAM_BUFFER) && (buffer_entrada[i] != '\0') && (buffer_entrada[i] != '\n'); i++){
        buffer_saida[i] = subtrai_modulo_alfabeto(senha[j], buffer_entrada[i]);
        j++;
        if(senha[j] == '\0') j = 0;
    }
    buffer_saida[i] = '\0';


    /* Escrever saida na tela */
    printf("%s\n", buffer_saida);

  return 0;
}
