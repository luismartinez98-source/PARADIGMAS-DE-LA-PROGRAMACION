##actualizacion a polimorfismo
class Vehiculo:
    def __init__(self, placas, tipo):
        self._placas = placas
        self._tipo = tipo

    def get_placas(self):
        return self._placas

    def get_tipo(self):
        return self._tipo
    
    def calcular_tarifa(self, horas):
        raise NotImplementedError

class Car (Vehiculo):
    def __init__(self, placas):
        super().__init__(placas, "Carro")

    def calcular_tarifa(self, horas):
        return horas*20    

class Moto(Vehiculo):
    def __init__(self, placas):
        super().__init__(placas, "Motocicleta")   

    def calcular_tarifa(self, horas):
        return horas*10

class Electric(Car):
    def __init__(self, placas):
        super().__init__(placas)
        
    def calcular_tarifa(self, horas):
        return horas*15                      

        