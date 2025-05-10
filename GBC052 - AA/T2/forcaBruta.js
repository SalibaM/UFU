function getPermutations(arr) {
    if (arr.length === 0) return [[]];

    const result = [];

    for (let i = 0; i < arr.length; i++) {
        const current = arr[i];
        const remaining = arr.slice(0, i).concat(arr.slice(i + 1));
        const remainingPerms = getPermutations(remaining);

        for (const perm of remainingPerms) {
            result.push([current, ...perm]);
        }
    }

    return result;
}

function lucroMaximoBruto(trabalhos) {
    const permutacoes = getPermutations(trabalhos);
    let melhorLucro = 0;
    let melhorOrdem = [];

    for (const ordem of permutacoes) {
        let tempoAtual = 0;
        let lucroTotal = 0;

        for (const trabalho of ordem) {
            const [id, t, p, d] = trabalho;
            tempoAtual += t;
            if (tempoAtual <= d) {
                lucroTotal += p;
            }
        }

        if (lucroTotal > melhorLucro) {
            melhorLucro = lucroTotal;
            melhorOrdem = ordem;
        }
    }

    return {
        lucro: melhorLucro,
        ordem: melhorOrdem.map(t => t[0])
    };
}

// Exemplo de uso:
const trabalhos = [
    ["a1", 2, 50, 4], // [id, tempo, lucro, prazo]
    ["a2", 1, 10, 1],
    ["a3", 3, 40, 6]
];

const resultado = lucroMaximoBruto(trabalhos);

console.log("Lucro máximo:", resultado.lucro);
console.log("Melhor ordem:", resultado.ordem);
