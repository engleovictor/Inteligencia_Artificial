class way():
    def __init__(self,vert: str, past_cities: list, weight: float):
        self.vert = vert
        self.past_cities = past_cities.copy()
        self.weight = weight

    def __gt__(self,oway):
        return self.weight > oway.weight

    def __lt__(self,oway):
        return self.weight < oway.weight
    
    def pegarVertCitiesWeight(self):
        return self.vert, self.past_cities.copy(), self.weight 