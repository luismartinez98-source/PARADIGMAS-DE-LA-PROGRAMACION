class RatePolicy:
    def calcular(self, horas, vehicle):
        raise NotImplementedError
    
class SimpleRatePolicy(RatePolicy):
    def calcular(self, horas, vehicle):
        return horas * 20    