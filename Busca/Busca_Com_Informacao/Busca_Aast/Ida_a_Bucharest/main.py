other_path = '/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest'

import sys
sys.path.append(other_path)

from graphAast import graphAast
from edge import edge

Romenia = graphAast()

with open(f"{other_path}/Cidades_Romenia.txt","r") as f:
    l = f.read().splitlines()

    for re in l:
        e = re.split(" ")
        Romenia.addEdge(edge(e[0],e[1],float(e[2])))

way = Romenia.mostrarMelhorCaminho('Arad', 'Bucharest', "../../Busca_Pela_Melhor_Escolha/Ida_a_Bucharest/Bucharest.txt")

print("Caminho com menor quantidade de cidades:")
print(f"Cidades: {way.__len__()}")
for i in range(way.__len__() - 1):
    print(f"{way[i]:<10} --> {way[i + 1]}")
print()