other_path = '/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest'

import sys
sys.path.append(other_path)

from edge import edge
from graphComDFS import graphComDFS

Romenia = graphComDFS()

with open(f"{other_path}/Cidades_Romenia.txt","r") as f:
    l = f.read().splitlines()

    for re in l:
        e = re.split(" ")
        Romenia.addEdge(edge(e[0],e[1],float(e[2])))

way = Romenia.buscaComDFS('Arad', 'Bucharest')

print("Busca com DFS:")
print(f"Cidades: {way.__len__()}")
for i in range(way.__len__() - 1):
    print(f"{way[i]:<20} --> {way[i + 1]}")
print()