function gerarTrabalhosAleatorios(n) {
    let trabalhos = [];
    for (let i = 1; i <= n; i++) {
        let lucro = Math.floor(Math.random() * 500) + 50;
        let prazo = Math.floor(Math.random() * 10) + 1;
        let tempo = Math.floor(Math.random() * Math.min(5, prazo)) + 1;
        trabalhos.push({ id: i, lucro, prazo, tempo });
    }
    return trabalhos;
}

function agendamentoDeTrabalhos(trabalhos) {
    console.time("Tempo de execução");

    const n = trabalhos.length;
    const maxTempo = Math.max(...trabalhos.map(t => t.prazo));
    
    // DP[i][t] = lucro máximo usando os i primeiros trabalhos e tempo total t
    const dp = Array.from({ length: n + 1 }, () => Array(maxTempo + 1).fill(0));

    for (let i = 1; i <= n; i++) {
        const { tempo, lucro, prazo } = trabalhos[i - 1];
        for (let t = 0; t <= maxTempo; t++) {
            dp[i][t] = dp[i - 1][t]; // não usar o trabalho i
            if (t >= tempo && t <= prazo) {
                dp[i][t] = Math.max(dp[i][t], dp[i - 1][t - tempo] + lucro);
            }
        }
    }

    // Reconstrução da solução ótima
    let t = maxTempo;
    const agenda = new Array(maxTempo).fill(-1);
    for (let i = n; i >= 1; i--) {
        const trabalho = trabalhos[i - 1];
        if (
            t >= trabalho.tempo &&
            dp[i][t] === dp[i - 1][t - trabalho.tempo] + trabalho.lucro
        ) {
            // Encontrar espaço livre na agenda
            for (let j = t - 1; j >= 0; j--) {
                let podeAgendar = true;
                for (let k = j; k > j - trabalho.tempo; k--) {
                    if (k < 0 || agenda[k] !== -1) {
                        podeAgendar = false;
                        break;
                    }
                }
                if (podeAgendar) {
                    for (let k = j; k > j - trabalho.tempo; k--) {
                        agenda[k] = trabalho.id;
                    }
                    t = j - trabalho.tempo;
                    break;
                }
            }
        }
    }

    const lucroMaximo = Math.max(...dp[n]);
    console.timeEnd("Tempo de execução");
    return { lucroMaximo, agenda };
}


// Exemplo de uso:
let trabalhos = gerarTrabalhosAleatorios(20);
console.table(trabalhos);
let resultado = agendamentoDeTrabalhos(trabalhos);
console.log("Lucro máximo:", resultado.lucroMaximo);
console.log("Agenda final:", resultado.agenda);
