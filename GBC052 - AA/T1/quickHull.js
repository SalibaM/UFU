function encontrarLado(p1, p2, p){
	let val = (p[1] - p1[1]) * (p2[0] - p1[0]) -
	(p2[1] - p1[1]) * (p[0] - p1[0]); O(1)
	
	if (val > 0) return 1;
	
	if (val < 0) return -1;
	return 0;
}

function distanciaLinha(p1, p2, p) {
	
	return Math.abs ((p[1] - p1[1]) * (p2[0] - p1[0]) -
	(p2[1] - p1[1]) * (p[0] - p1[0]));
}

function quickHull(a, n, p1, p2, lado) {
	
	let ind = -1;
	let max_dist = 0;
	
	for (let i=0; i<n; i++){
	
		let temp = distanciaLinha(p1, p2, a[i]);

		if ((encontrarLado(p1, p2, a[i]) == lado) && (temp > max_dist)){
		ind = i;
		max_dist = temp;
		}
	}
	
	if (ind == -1) {
		hull.add(p1);
		hull.add(p2);
		return;
	}
	
	quickHull(a, n, a[ind], p1, -encontrarLado(a[ind], p1, p2));
	quickHull(a, n, a[ind], p2, -encontrarLado(a[ind], p2, p1));
}
