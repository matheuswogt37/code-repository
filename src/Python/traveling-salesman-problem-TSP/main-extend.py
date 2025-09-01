import random
import numpy
import matplotlib.pyplot as plt

# DATA

# distances between cities
roadmapCords = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
roadmap = [
    [0, 12, 3, 23, 1, 17, 35, 44, 28, 50],
    [12, 0, 9, 18, 3, 22, 30, 33, 27, 49],
    [3, 9, 0, 89, 56, 40, 31, 20, 25, 60],
    [23, 18, 89, 0, 45, 55, 67, 48, 52, 70],
    [1, 3, 56, 45, 0, 36, 29, 39, 21, 41],
    [17, 22, 40, 55, 36, 0, 26, 31, 38, 45],
    [35, 30, 31, 67, 29, 26, 0, 20, 24, 32],
    [44, 33, 20, 48, 39, 31, 20, 0, 19, 25],
    [28, 27, 25, 52, 21, 38, 24, 19, 0, 30],
    [50, 49, 60, 70, 41, 45, 32, 25, 30, 0]
]

manyCities = 10 # how many cities had this problem
manyIndividuals = 25 # how many indiviuals in a population
maxGens = 100 # max number of gens that can run
tournamentSize = 5 # how many individuals will be in Tournament
mutationRate = 0.1 # mutation chance

def initPopulation():
    population = []
    for i in range(manyIndividuals):
        chromosomes = roadmapCords.copy()
        numpy.random.shuffle(chromosomes)
        population.append(chromosomes)
    return population

def calcFitness(population):
    fitness = []
    for i in range(manyIndividuals):
        tempFitness = 0
        for j in range((manyCities - 1)):
            tempFitness+=roadmap[population[i][j]][population[i][j+1]]
        if tempFitness == 0:
            print(population)
            print(tempFitness)
        fitness.append(1/tempFitness)
    return fitness

def crossover(parent1, parent2):
    size = manyCities
    start, end = sorted(random.sample(range(size), 2))
    child = [None] * size
    child[start:end+1] = parent1[start:end+1]

    fill = [gene for gene in parent2 if gene not in child]
    idx = 0
    for i in range(size):
        if child[i] is None:
            child[i] = fill[idx]
            idx += 1
    return child

def mutation(child):
    if random.random() < mutationRate:
        i, j = random.sample(range(manyCities), 2)
        child[i], child[j] = child[j], child[i]
    return child

def tournament(population):
    select = random.sample(population, tournamentSize)
    select = sorted(select, key=lambda x: x[1], reverse=True)
    return select[0][0]

def roulette(population):
    totalFitness = sum(fitness for _, fitness in population)
    pick = random.uniform(0, totalFitness)
    current = 0
    for individual, fitness in population:
        current += fitness
        if current >= pick:
            return individual
    return population[-1][0]

def ranking(population):
    sortedPopulation = sorted(population, key=lambda x: x[1], reverse=True)
    
    ranks = list(range(len(sortedPopulation), 0, -1)) 
    totalRank = sum(ranks)
    
    pick = random.uniform(0, totalRank)
    current = 0
    for i in range(len(sortedPopulation)):
        current += ranks[i]
        if current >= pick:
            return sortedPopulation[i][0]
    return sortedPopulation[-1][0] 


def allAlgorithms(elitismo):
    copyInitPopulation = initPopulation() # init population

    # tournament
    population = copyInitPopulation
    new_population = population.copy()
    averageTournament = []
    bestOnGenTournament = []
    for i in range(maxGens):
        temp = 0
        fitness = calcFitness(new_population)
        new_population = []
        
        pop = []
        for j in range(len(population)):
            pop.append((population[j], fitness[j]))
        if elitismo:
            population = sorted(population, key=lambda x: x[1], reverse=True)
            new_population.append(population[0])
            max = manyIndividuals - 1
        else:
            max = manyIndividuals
        for j in range(max):
            father = tournament(pop)
            mother = tournament(pop)
            child = crossover(father, mother)
            child = mutation(child)

            new_population.append(child)
        population = new_population.copy()
        for j in range(manyIndividuals):
            temp+=population[j][1]
        averageTournament.append(temp/manyIndividuals)
        bestOnGenTournament.append(min(pop, key=lambda x: x[1])[1])
    pop = []
    for j in range(len(population)):
        pop.append((population[j], fitness[j]))
    select = sorted(pop, key=lambda x: x[1], reverse=True)
    bestTournament = select[0]
    
    # roullete
    population = copyInitPopulation
    new_population = population.copy()
    averageRoullete = []
    bestOnGenRoullete = []
    for i in range(maxGens):
        temp = 0
        fitness = calcFitness(new_population)
        new_population = []
        
        pop = []
        for j in range(len(population)):
            pop.append((population[j], fitness[j]))
        if elitismo:
            population = sorted(population, key=lambda x: x[1], reverse=True)
            new_population.append(population[0])
            max = manyIndividuals - 1
        else:
            max = manyIndividuals
        for j in range(max):
            father = roulette(pop)
            mother = roulette(pop)
            child = crossover(father, mother)
            child = mutation(child)

            new_population.append(child)
        population = new_population.copy()
        for j in range(manyIndividuals):
            temp+=population[j][1]
        averageRoullete.append(temp/manyIndividuals)
        bestOnGenRoullete.append(min(pop, key=lambda x: x[1])[1])
    pop = []
    for j in range(len(population)):
        pop.append((population[j], fitness[j]))
    select = sorted(pop, key=lambda x: x[1], reverse=True)
    bestRoullete = select[0]

    # ranking
    population = copyInitPopulation
    new_population = population.copy()
    averageRanking = []
    bestOnGenRanking = []
    for i in range(maxGens):
        temp = 0
        fitness = calcFitness(new_population)
        new_population = []
        
        pop = []
        for j in range(len(population)):
            pop.append((population[j], fitness[j]))
        if elitismo:
            population = sorted(population, key=lambda x: x[1], reverse=True)
            new_population.append(population[0])
            max = manyIndividuals - 1
        else:
            max = manyIndividuals
        for j in range(max):
            father = ranking(pop)
            mother = ranking(pop)
            child = crossover(father, mother)
            child = mutation(child)

            new_population.append(child)
        population = new_population.copy()
        for j in range(manyIndividuals):
            temp+=population[j][1]
        averageRanking.append(temp/manyIndividuals)
        bestOnGenRanking.append(min(pop, key=lambda x: x[1])[1])
    pop = []
    for j in range(len(population)):
        pop.append((population[j], fitness[j]))
    select = sorted(pop, key=lambda x: x[1], reverse=True)
    bestRanking = select[0]

    return bestTournament, bestRoullete, bestRanking, averageTournament, averageRoullete, averageRanking, bestOnGenTournament, bestOnGenRoullete, bestOnGenRanking

def main():
    print("Resolving traveling-salesman-problem-TSP")
    
    bestTournament, bestRoullete, bestRanking, averageTournament, averageRoullete, averageRanking, bestOnGenTournament, bestOnGenRoullete, bestOnGenRanking = allAlgorithms(True)

    print(f"Tournament route: {bestTournament[0][0]}->{bestTournament[0][1]}->{bestTournament[0][2]}->{bestTournament[0][3]}->{bestTournament[0][4]}")
    print(f"Roullete route: {bestRoullete[0][0]}->{bestRoullete[0][1]}->{bestRoullete[0][2]}->{bestRoullete[0][3]}->{bestRoullete[0][4]}")
    print(f"Ranking route: {bestRanking[0][0]}->{bestRanking[0][1]}->{bestRanking[0][2]}->{bestRanking[0][3]}->{bestRanking[0][4]}")

    print("Average fitness per gen: ")
    print("-----Tournament-----")

    x = numpy.arange(1, 101, 1)

    yTournamentAverage = averageTournament
    yTournamentBest = bestOnGenTournament
    plt.plot(x, yTournamentAverage, color='blue')
    plt.plot(x, yTournamentBest, color='orange')
    plt.savefig('TournamentPlot.png')
    plt.clf()

    yRoulleteAverage = averageRoullete
    yRoulleteBest = bestOnGenRoullete
    plt.plot(x, yRoulleteAverage, color='blue')
    plt.plot(x, yRoulleteBest, color='orange')
    plt.savefig('RoulletePlot.png')
    plt.clf()

    yRankingAverage = averageRanking
    yRankingBest = bestOnGenRanking
    plt.plot(x, yRankingAverage, color='blue')
    plt.plot(x, yRankingBest, color='orange')
    plt.savefig('RankingPlot.png')
    plt.clf()

if __name__ == '__main__':
    main()