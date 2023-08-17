import sys
sys.path.append('/home/laplace/Projects/Inteligencia_Artificial/Busca/Busca_Cega/BFS/Ida_a_Bucharest')

from graph import graph

class graphComDFS(graph):
    # def buscaComDFS(self, vert1: str, vert2: str):
        
    #     alrverts = set()
        
    #     qverts = [[vert1,[]]]

    #     av = None
    #     nv = None

    #     while nv != vert2:
    #         nv = qverts[-1][0]
    #         av = qverts[-1][1].copy()
    #         qverts.pop()

    #         if av.__len__() >= self.__len__():
    #             return av.append(vert2 == av[-1])
            
    #         if nv in alrverts:
    #             continue
    #         else:
    #             alrverts.add(nv)

    #         av.append(nv)

    #         for e in self.verts[nv]:
    #             if e.vert1 == nv:
    #                 qverts.append([e.vert2,av])
    #             else:
    #                 qverts.append([e.vert1,av])
            
    #     return av            

    def buscaComDFS(self, vert1: str, vert2: str):
        vv = [vert1]
        return self.DFS(vert1,vert2,vv).copy()


    def DFS(self, nv: str, dv: str, vv: list) -> list:
        for e in self.verts[nv]:
            
            ov = None
            if e.vert1 == nv:
                ov = e.vert2
            else:
                ov = e.vert1
            
            if dv == ov:
                vv.append(dv)
                return vv.copy()
            
            elif ov not in vv:
                vv.append(ov)
                return self.DFS(ov,dv,vv.copy())

