class edge():
    def __init__(self, vert1: str, vert2: str, weight: int):
        if vert1 < vert2:
            self.vert1 = vert1
            self.vert2 = vert2
        else:
            self.vert1 = vert2
            self.vert2 = vert1