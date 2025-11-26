#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
    // 1. Cria lista vazia de cidades e carrega dados do arquivo
    Cidades *listaCidades = criaListaVazia();
    carregarDados(&listaCidades);

    // 2. Lista as cidades e suas atrações
    printf("Cidades e atrações carregadas:\n");
    listarCidadesComAtracoes(listaCidades);

    // 3. Aplica questionnaire para definir preferências
    int natureza = 0, cultural = 0, festivo = 0, relaxante = 0;
    aplicarQuestionario(&natureza, &cultural, &festivo, &relaxante);

    // 4. Escolhe uma cidade (ex: Belém) e aplica pontuação e ordenação
    const char *nomeCidade = "Belém";
    Cidades *cidadeEscolhida = buscarCidade(listaCidades, nomeCidade);
    if (cidadeEscolhida) {
        aplicarPontuacaoNasAtracoes(cidadeEscolhida->atracao,
                                    natureza, cultural, festivo, relaxante);
        ordenarAtracoesPontuacao(cidadeEscolhida->atracao);
    } else {
        printf("Cidade '%s' não encontrada.\n", nomeCidade);
        return 1;
    }

    // 5. Define uma viagem de 3 dias para a cidade escolhida
    Viagem viagem;
    definirViagem(&viagem, cidadeEscolhida, 3);

    // 6. Imprime o roteiro personalizado
    printf("\nROTEIRO PERSONALIZADO:\n");
    imprimeRoteiroPersonalizado(listaCidades, &viagem);

    // 7. (Opcional) liberar memória das estruturas antes de encerrar
    // liberarTodasAsCidades(listaCidades);

    return 0;
}
