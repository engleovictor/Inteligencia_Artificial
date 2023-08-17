other_path = '/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest'

import sys
sys.path.append(other_path)

from graphComMelhorEscolha import graphMelhorEscolha
from edge import edge

Romenia = graphMelhorEscolha()

with open(f"{other_path}/Cidades_Romenia.txt","r") as f:
    l = f.read().splitlines()

    for re in l:
        e = re.split(" ")
        Romenia.addEdge(edge(*e))

way = Romenia.mostrarMelhorCaminho('Arad', 'Bucharest')

print("Caminho com menor quantidade de cidades:")
print(f"Cidades: {way.__len__()}")
for i in range(way.__len__() - 1):
    print(f"{way[i]:<10} --> {way[i + 1]}")
print()