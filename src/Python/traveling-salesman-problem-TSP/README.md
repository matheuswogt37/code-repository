# Tarefa Prática - Problema do caixeiro viajante

Você é um viajante e deseja visitar todas as cidades de um país. Você tem um mapa com as distâncias entre todas as cidades. O problema é determinar a rota mais curta que começa em uma cidade, visita todas as outras cidades exatamente uma vez e retorna à cidade de origem. Implemente um algoritmo genético para resolver esse problema.

## Representação das distâncias

Considere um país com 5 cidades nomeadas de A a E. O mapa de distâncias entre as cidades é dado pela matriz abaixo:

|   | A | B | C | D | E |
|---|---|---|---|---|---|
| A | 0 | 12 | 3 | 23 | 1 |
| B | 12 | 0 | 9 | 18 | 3 |
| C | 3 | 9 | 0 | 89 | 56 |
| D | 23 | 18 | 89 | 0 | 45 |
| E | 1 | 3 | 56 | 45 | 0 |

## Instruções Adicionais

Para resolver o problema, será necessário:

 - Considerar a matriz de distâncias fornecida acima.
 - Inicializar a população de soluções de forma aleatória (cada indivíduo é uma permutação das cidades).
 - Implementar a função *fitness* para calcular a distância total percorrida por um indivíduo. Use a função inversa da distância total do percurso como função de *fitness*.
 - Implementar a função de seleção de pais por torneio para escolher os indivíduos que irão gerar a próxima geração.
 - Implementar a função de cruzamento para gerar novos indivíduos a partir dos pais selecionados. Utilize o operador de cruzamento de ordem ou outro operador de cruzamento adequado.
 - Implementar a função de mutação para alterar aleatoriamente um indivíduo da população. Use um valor de probabilidade de mutação adequado.
 - (opcional) Implementar a função de elitismo para manter os melhores indivíduos da população atual na próxima geração.