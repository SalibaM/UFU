function explicarAgenda(trabalhos, agenda) {
    let usados = new Set();
    for (let i = 0; i < agenda.length; i++) {
        const id = agenda[i];
        if (id !== -1 && !usados.has(id)) {
            const t = trabalhos.find(t => t.id === id);
            console.log(`Trabalho ${id} agendado (lucro=${t.lucro}, prazo=${t.prazo}, tempo=${t.tempo})`);
            usados.add(id);
            console.log(`Agenda atual: [${agenda.join(", ")}]`);
        }
    }
}
