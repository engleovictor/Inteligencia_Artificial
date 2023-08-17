import sys
sys.path.append('/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest')

from graph import graph

class graphComDFS(graph):
   
    def buscaComDFS(self, vert1: str, vert2: str):
        return self.DFS(vert1,vert2,[[vert1,[vert1]]]).copy()


    def DFS(self, nv: str, dv: str, stack: list) -> list:

        nv = stack[-1][0]
        vv = stack[-1][1]

        stack.pop()
        
        #edges = [e for e in self.verts[nv]]

        #edges = sorted(edges)

        #for e in edges:
        for e in self.verts[nv]:
            ov = None

            if e.vert1 == nv:
                ov = e.vert2
            else:
                ov = e.vert1

            if ov in vv:
                continue
            else:
                stack.append([ov,[*vv, ov]])

        
        if nv == dv:
            return vv.copy()
        else:
            return self.DFS(nv,dv,stack)
