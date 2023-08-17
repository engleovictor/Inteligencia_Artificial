import sys
sys.path.append('/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest')
sys.path.append('/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/UCS/Ida_a_Bucharest')

from graph import graph
from way import way
import heapq

class graphMelhorEscolha(graph):
    def __init__(self):
        super().__init__()
        self.heurist = {}

    def mostrarMelhorCaminho(self, vert1: str, vert2: str):
        
        self.heurist.clear()
        with open(f"./{vert2}.txt") as f:
            lines = f.read().splitlines()
            for line in lines:
                info = line.split(" ")
                self.heurist[info[0]] = float(info[1])

        ways = []
        heapq.heappush(ways,way(vert1,[],self.heurist[vert1]))

        # alrverts = set()

        nv = None
        av = None
        pc = None

        while nv != vert2:
            nv, av, pc = ways[0].pegarVertCitiesWeight()

            heapq.heappop(ways)

            # if nv in alrverts:
            #     continue

            # alrverts.add(nv)

            av.append(nv)

            for e in self.verts[nv]:
                if e.vert1 == nv:
                    heapq.heappush(ways, way(e.vert2,av,self.heurist[e.vert2]))
                else:
                    heapq.heappush(ways, way(e.vert1,av,self.heurist[e.vert1]))
            
        return av

        