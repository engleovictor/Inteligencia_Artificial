import sys
import heapq
from way import way

sys.path.append('/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest')

from graph import graph
from edge import edge

class graphComBuscaUniforme(graph):
    def mostrarCaminhoDePara(self, vert1: str, vert2: str) -> list:
        ways = []
        # alrverts = set()
        heapq.heappush(ways,way(vert1,[],0.))

        nv = None
        av = None
        pc = None

        while nv != vert2:
            nv, av, pc = ways[0].pegarVertCitiesWeight()
            #ways.pop(0)
            heapq.heappop(ways)

            # if nv in alrverts:
            #     continue

            # alrverts.add(nv)

            av.append(nv)

            for e in self.verts[nv]:
                if nv == e.vert1:
                    #ways.append(way(e.vert2,av,pc+e.weight))
                    heapq.heappush(ways, way(e.vert2,av,pc+e.weight))
                else:
                    #ways.append(way(e.vert1,av,pc+e.weight))
                    heapq.heappush(ways, way(e.vert1,av,pc+e.weight)) 

        return av, pc
        
        
        
        