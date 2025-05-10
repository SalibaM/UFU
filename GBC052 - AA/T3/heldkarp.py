import itertools
import random
import time
import sys


def held_karp(dists):
  
    n = len(dists)

    C = {}

    for k in range(1, n):
        C[(1 << k, k)] = (dists[0][k], 0)

    for subset_size in range(2, n):
        for subset in itertools.combinations(range(1, n), subset_size):

            bits = 0
            for bit in subset:
                bits |= 1 << bit

            for k in subset:
                prev = bits & ~(1 << k)

                res = []
                for m in subset:
                    if m == 0 or m == k:
                        continue
                    res.append((C[(prev, m)][0] + dists[m][k], m))
                C[(bits, k)] = min(res)


    bits = (2**n - 1) - 1

    res = []
    for k in range(1, n):
        res.append((C[(bits, k)][0] + dists[k][0], k))
    opt, parent = min(res)

    path = []
    for i in range(n - 1):
        path.append(parent)
        new_bits = bits & ~(1 << parent)
        _, parent = C[(bits, parent)]
        bits = new_bits


    path.append(0)

    return opt, list(reversed(path))


def generate_distances(n):
    dists = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            dists[i][j] = dists[j][i] = random.randint(1, 99)

    return dists


def read_distances(filename):
    dists = []
    with open(filename, 'rb') as f:
        for line in f:
            # Skip comments
            if line[0] == '#':
                continue

            dists.append(map(int, map(str.strip, line.split(','))))

    return dists


if __name__ == '__main__':

    n_cidades = 24

    dists = generate_distances(n_cidades)

    print("Matriz de distâncias:")
    for row in dists:
        print(''.join([str(n).rjust(4, ' ') for n in row]))

    print("\nResultado do Held-Karp:")
    start = time.time()
    custo, caminho = held_karp(dists)
    elapsed = time.time() - start
    print(f"Custo mínimo: {custo}")
    print(f"Caminho ótimo: {caminho}")
    print(f"Tempo de execução: {elapsed:.4f} segundos")
