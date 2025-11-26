

//FUNÇÃO QUE CALCULA O MDC ENTRE DOIS VALORES
int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

//FUNÇÃO QUE CONVERTE A DATA POR EXTENSO
//UTILIZANDO PONTEIROS, CONSIGO MANIPULAR MELHOR O MÊS ESCOLHIDO, FAZENDO COM QUE EVITE TER CÓPIAS DE TODOS OS MESES JA ARMAZENADOS
//POSSO SIMPLESMENTE ALTERAR O VALOR DE ACORDO COM O MES ESCOLHIDO.
void mesExtenso(int mes, char** mesExt){   

    switch(mes){
        case 1: *mesExt="Janeiro"; break;
        case 2: *mesExt="Fevereiro"; break;
        case 3: *mesExt="Março"; break;
        case 4: *mesExt="Abril"; break;
        case 5: *mesExt="Maio"; break;
        case 6: *mesExt="Junho"; break;
        case 7: *mesExt="Julho"; break;
        case 8: *mesExt="Agosto"; break;
        case 9: *mesExt="Setembro"; break;
        case 10: *mesExt="Outubro"; break;
        case 11: *mesExt="Novembro"; break;
        case 12: *mesExt="Dezembro"; break;
    }
}
