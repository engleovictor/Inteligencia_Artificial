from edge import edge

class graph():
    def __init__(self):
        self.edges = set()
        self.verts = {}

    def __len__(self):
        return self.verts.__len__()
        

    def addEdge(self, new_edge: edge):
        self.edges.add(new_edge)
        
        if new_edge.vert1 in self.verts:
            self.verts[new_edge.vert1].add(new_edge)
        else:
            self.verts[new_edge.vert1] = set()
            self.verts[new_edge.vert1].add(new_edge)

        if new_edge.vert2 in self.verts:
            self.verts[new_edge.vert2].add(new_edge)
        else:
            self.verts[new_edge.vert2] = set()
            self.verts[new_edge.vert2].add(new_edge)

    def mostrarCaminhoDePara(self, vert1: str, vert2: str) -> list:
        qverts = []
        # alrverts = set{}
        qverts.append([vert1,[]])

        nv = None
        av = None

        while nv != vert2:
            nv = qverts[0][0]
            av = qverts[0][1].copy()
            qverts.pop(0)

            # if nv in alrverts:
            #     continue

            # alrverts.add(nv)

            av.append(nv)

            for e in self.verts[nv]:
                if nv == e.vert1:
                    qverts.append([e.vert2,av])
                else:
                    qverts.append([e.vert1,av])
            

        return av
