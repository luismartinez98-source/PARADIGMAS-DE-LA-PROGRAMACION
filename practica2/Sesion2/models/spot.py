class ParkingSpot:
    def __init__(self, spot_id, tipo_permitido):
        self._spot_id = spot_id
        self._tipo_permitido = tipo_permitido
        self._ocupado = False

    def esta_libre(self):
        return not self._ocupado

    def ocupar(self):
        self._ocupado = True

    def liberar(self):
        self._ocupado = False

    def get_id(self):
        return self._spot_id

    def get_tipo(self):
        return self._tipo_permitido
    
                