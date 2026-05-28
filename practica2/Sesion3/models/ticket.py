import time 
class Ticket:
    _contador = 1

    def __init__(self, vehicle, spot):
        self._id = Ticket._contador
        Ticket._contador +=1

        self._vehicle = vehicle
        self._spot = spot
        self._hora_entrada = time.time()
        self._hora_salida = None

    def cerrar_ticket(self):
        self._hora_salida = time.time()

    def get_id(self):
        return self._id 

    def get_vehicle(self):
        return self._vehicle
    
    def get_spot(self):
        return self._spot

    def calcular_horas(self):
        if self._hora_salida:
            return (self._hora_salida - self._hora_entrada)/3600
        return 0       