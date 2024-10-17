# Relatório

Este código visa resolver o problema lúdico: \
Crescer N colônias de bactérias de acordo com R taxa de crescimento e T tempo, cada colônia precisa de dois recursos para crescer:

1. Espaço
2. Comida

Sendo cada recurso tendo X quantidades, em que cada recurso unitário só pode ser utilizado por uma colônia de cada vez, quando essa colônia deixar esse recurso ele pode ser utilizado por outra colônia. \
O problema está em programar com que as colônias consigam pegar os dois recursos necessários para que então possa realizar o crescimento, a questão é que após pegar um recurso ele não o soltara até que cresça, portanto se um dos recursos estiverem disponíveis e o outro não então o primeiro recurso será pego e travado até que o segundo recurso estiver disponível, caso o segundo nunca fique disponível então o primeiro sempre permanecerá travado. Nesta definição inicial as colônias não pegam o mesmo recurso na mesma ordem, isso é definido pelo programador qual a ordem porém ela não deve ser fixa.

## Problema técnico

Cada colônia vai ser executada por uma thread portanto serão executadas simultâneamente com um delay pequeno entre o começo da execução de cada uma, e a depender do hardware e/ou atual utilização da CPU, nesse ínfimo espaço de tempo pode ser que a thread adquira os dois recursos antes de que a próxima requisite, portanto para fins didáticos no código foi implementado um sleep randômico entre 2 e 7 segundos, vale mencionar que para os testes de desempenho o sleep será desativado pois por ser randômico pode influenciar os resultados. \
Portanto os recursos serão pegos de forma simultânea e um recurso de cada vez, nesse caso pode ocorrer um problema chamado deadlock, exemplo:

-   X = 1
-   Colonia 1 pega o espaço 1
-   Colonia 2 pega a comida 1
-   Colonia 1 quer pegar a comida 1 mas ela está ocupada então ela vai esperar desocupar
-   Colonia 2 quer pegar o espaço 1 mas ele está ocupado então ela vai esperar desocupar

Nesse caso os recursos nunca vão ser liberados pois estão sendo segurados por threads que estão esperando, logo o programa ficará travado infinitamente. \
Para resolver a solução escolhida foi: **Prevenção por Ordenação de Recursos**

## Solução

**Prevenção por Ordenação de Recursos** diz: _Todas as colônias devem adquirir os recursos na mesma ordem._ \
Traduzindo para o contexto do código: Todas as colônias vão tentar pegar primeiro o espaço e somente quando conseguirem poderão tentar pegar a comida, para tal só foi preciso retirar a parte do código que explicita qual recurso cada colônia terá que pegar primeiro, assim deixando a ordem fixa.

### Sem prevenção

Cada thread recebe um id (data->id) que é um inteiro, se ele for par então pegara primeiro o espaço e depois a comida, se for impar ocorrerá o contrário, dessa forma existe uma ordem não fixa
Código:

```C
if (0 == (data->id % 2)) {
        // get resource space
        while (1 == cond) {  // while not get space continue trying
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resSpace[i])) {   // try lock into this mutex, if ok then enter the if, if not then continue until check all the mutexes
                    sleep(rand() % 5 + 2);                        // sleep random betweeen 2 and 7
                    printf("id %d get %d space\n", data->id, i);  // print to know what is going on
                    indexSpace = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {                                       // enter mutex queueSpace
                printf("id %d enter in queue space\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueSpace);
            }
        }
        // get resource food
        cond = 1;
        while (1 == cond) {
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resFood[i])) {
                    sleep(rand() % 5 + 2);                       // sleep random betweeen 2 and 7
                    printf("id %d get %d food\n", data->id, i);  // print to know what is going on
                    indexFood = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {
                printf("id %d enter in queue food\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueFood);
            }
        }
    } else {
        // get resource food
        while (1 == cond) {
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resFood[i])) {
                    sleep(rand() % 5 + 2);                       // sleep random betweeen 2 and 7
                    printf("id %d get %d food\n", data->id, i);  // print to know what is going on
                    indexFood = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {
                printf("id %d enter in queue food\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueFood);
            }
        }
        // get resource space
        cond = 1;
        while (1 == cond) {  // while not get space continue trying
            for (int i = 0; i < nr; i++) {
                if (0 == pthread_mutex_trylock(&resSpace[i])) {   // try lock into this mutex, if ok then enter the if, if not then continue until check all the mutexes
                    sleep(rand() % 5 + 2);                        // sleep random betweeen 2 and 7
                    printf("id %d get %d space\n", data->id, i);  // print to know what is going on
                    indexSpace = i;
                    cond = 0;
                    break;
                }
            }
            if (1 == cond) {                                       // enter mutex queueSpace
                printf("id %d enter in queue space\n", data->id);  // print to know what is going on
                pthread_mutex_lock(&waitQueueSpace);
            }
        }
    }
```

Desse jeito utilizando os sleeps é possível ver que não muitos segundos após a execução o programa para de imprimir quaisquer printf pois ele entrou no estado de deadlock, ex:

```bash
gcc -o growth_simulation_deadlock growth_simulation_deadlock.c -pthread -lm
./growth_simulation_deadlock -pi 10 -r 2 -t 5 -nc 5 -nr 1
id 3 enter in queue food
id 3 enter in queue food
id 2 enter in queue space
id 2 enter in queue space
id 4 enter in queue space
id 1 get 0 food
id 1 enter in queue space
id 0 get 0 space
id 0 enter in queue food
```

### Com prevenção (ordenação consistente)

Agora como a ordem é fixa não é necessário utilizar o data->id para "randomizar" qual recurso será pegado primeiro, portanto deixando o código menor

```C
// get resource space
    while (1 == cond) {  // while not get space continue trying
        for (int i = 0; i < nr; i++) {
            if (0 == pthread_mutex_trylock(&resSpace[i])) {   // try lock into this mutex, if ok then enter the if, if not then continue until check all the mutexes
                sleep(rand() % 5 + 2);                        // sleep random betweeen 2 and 7
                printf("id %d get %d space\n", data->id, i);  // print to know what is going on
                indexSpace = i;
                cond = 0;
                break;
            }
        }
        if (1 == cond) {                                       // enter mutex queueSpace
            printf("id %d enter in queue space\n", data->id);  // print to know what is going on
            pthread_mutex_lock(&waitQueueSpace);
        }
    }
    // get resource food
    cond = 1;
    while (1 == cond) {
        for (int i = 0; i < nr; i++) {
            if (0 == pthread_mutex_trylock(&resFood[i])) {
                sleep(rand() % 5 + 2);                       // sleep random betweeen 2 and 7
                printf("id %d get %d food\n", data->id, i);  // print to know what is going on
                indexFood = i;
                cond = 0;
                break;
            }
        }
        if (1 == cond) {
            printf("id %d enter in queue food\n", data->id);  // print to know what is going on
            pthread_mutex_lock(&waitQueueFood);
        }
    }
```

Output:

```bash
gcc -o growth_simulation growth_simulation.c -pthread -lm
./growth_simulation -pi 10 -r 2 -t 5 -nc 5 -nr 1
id 1 enter in queue space
id 1 enter in queue space
id 3 enter in queue space
id 2 enter in queue space
id 4 enter in queue space
id 0 get 0 space
id 0 get 0 food
id 0 init population 10                 final population 220264
id 1 get 0 space
id 1 get 0 food
id 1 init population 10                 final population 220264
id 3 get 0 space
id 3 get 0 food
id 3 init population 10                 final population 220264
id 2 get 0 space
id 2 get 0 food
id 2 init population 10                 final population 220264
id 4 get 0 space
id 4 get 0 food
id 4 init population 10                 final population 220264
End...
```

## Instruções de compilação e execução

Para compilar usar o seguinte comando em terminal:

```bash
gcc -o {file} {file}.c -pthread -lm
```

Para então executar como:

```bash
./{file} {FLAGS}
```

Para obter informações sobre quais flags devem ser usadas e como usar a flag **_-h_**

```bash
./{file} -h
```

## Testes

Seguintes testes foram realizados usando os dois arquivos: _growth_simulation_deadlock.c_ e _growth_simulation_consistent_order.c_. Para os testes não foram utilizados **sleep's** dado que o proprósito é analisar o desempenho. \
Para medir o desempenho vai ser utilizado o comando _time_
| Parâmetros | deadlock.c | consistent_order.c |
|---------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| -pi 10 -r 2 -t 5 -nc 5 -nr 1 | **ocorreu deadlock** | 0.00user 0.00system 0:00.00elapsed 133%CPU (0avgtext+0avgdata 2432maxresident)k 0inputs+0outputs (0major+121minor)pagefaults 0swaps |
| -pi 10 -r 2 -t 5 -nc 1000 -nr 5 | **5 em cada 10 ocorria deadlock** 0.00user 0.03system 0:00.03elapsed 120%CPU (0avgtext+0avgdata 10240maxresident)k 0inputs+0outputs (0major+2197minor)pagefaults 0swaps | 0.00user 0.03system 0:00.03elapsed 110%CPU (0avgtext+0avgdata 10112maxresident)k 0inputs+0outputs (0major+2195minor)pagefaults 0swaps |

## Considerações finais

A aplicação de prevenção é muito importante para que o sistema em sí não trave, principalmente quando há muitos consumidores e poucos recursos o deadlock é mais passível de ocorrer, e quando ocorrer especificamente nas soluções apresentadas por este projeto é necessário intervenção para que o programa pare de executar assim liberando recursos (memória e os próprios recursos utilizados)
