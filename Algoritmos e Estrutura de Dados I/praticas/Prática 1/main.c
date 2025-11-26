#include <stdio.h>
#include "funcoes.h"

int main() {

    int num1, num2, dia, mes, ano;
    char* mesExt;  // Variável que vai armazenar o nome do mês

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    int resultado = mdc(num1, num2);

    printf("O MDC dos dois números é: %d\n", resultado);

    printf("Digite a data em números (XX/XX/XXXX):\n");
    scanf("%d%d%d", &dia, &mes, &ano);
    mesExtenso(mes, &mesExt);  // Passando o endereço de mesExt para a função

    printf("A data por extenso é:\n %d de %s de %d\n", dia, mesExt, ano);

    return 0;
}
