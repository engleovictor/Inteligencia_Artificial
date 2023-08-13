from graph import graph
from edge import edge

Romenia = graph()

with open("Cidades_Romenia.txt","r") as f:
    l = f.read().splitlines()

    for re in l:
        e = re.split(" ")
        Romenia.addEdge(edge(*e))

way = Romenia.mostrarCaminhoDePara('Arad', 'Bucharest')

print("Caminho com menor quantidade de cidades:")
print(f"Cidades: {way.__len__()}")
for i in range(way.__len__() - 1):
    print(f"{way[i]:<10} --> {way[i + 1]}")
print()