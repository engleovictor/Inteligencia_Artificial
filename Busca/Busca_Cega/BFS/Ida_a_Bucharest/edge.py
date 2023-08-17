class edge():
    def __init__(self, vert1: str, vert2: str, weight: float):
        
        if vert1 < vert2:
            self.vert1 = vert1
            self.vert2 = vert2
        
        else:
            self.vert1 = vert2
            self.vert2 = vert1
        
        self.weight = weight
    
    def __gt__(self,oedge):
        return self.weight > oedge.weight

    def __lt__(self,oedge):
        return self.weight < oedge.weight
    
    def __str__(self):
        return self.vert1 + " " + self.vert2 + " " + str(self.weight)
    
    def __repr__(self):
        return self.__str__()
        