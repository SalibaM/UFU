class Ponto {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
}


function orientacao(p, q, r) {
    let val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

function convexHull(pontos, n) {
    if (n < 3) {
        console.log("Não é possível formar um fecho convexo.");
        return;
    }
    
    let hull = [];
    let l = 0;
    
    for (let i = 1; i < n; i++) {
        if (pontos[i].x < pontos[l].x) l = i;
    }

    let p = l, q;
    
    do {
        hull.push(pontos[p]);
        q = (p + 1) % n;
        
        for (let i = 0; i < n; i++) {
            if (orientacao(pontos[p], pontos[i], pontos[q]) == 2)
                q = i;
        }
        
        p = q;
    } while (p !== l);
    
    console.log("Fecho convexo:");
    hull.forEach(temp => console.log(`(${temp.x}, ${temp.y})`));
}
