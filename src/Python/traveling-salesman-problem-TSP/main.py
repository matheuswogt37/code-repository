import random
import numpy

# DATA

# distances between cities
# A: 0
# B: 1
# C: 2
# D: 3
# E: 4
roadmapCords = [0, 1, 2, 3, 4]
roadmap = [
    [0, 12, 3, 23, 1],
    [12, 0, 9, 18, 3],
    [3, 9, 0, 89, 56],
    [23, 18, 89, 0, 45],
    [1, 3, 56, 45, 0]
]

manyCities = 5 # how many cities had this problem
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

def allAlgorithms(elitismo):
    population = initPopulation() # init population

    # tournament
    new_population = population.copy()
    for i in range(maxGens):
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
    pop = []
    for j in range(len(population)):
        pop.append((population[j], fitness[j]))
    select = sorted(pop, key=lambda x: x[1], reverse=True)
    bestTournament = select[0]
    # roullete


    # ranking


    return bestTournament

def main():
    print("Resolving traveling-salesman-problem-TSP")
    print(allAlgorithms(True))

if __name__ == '__main__':
    main()