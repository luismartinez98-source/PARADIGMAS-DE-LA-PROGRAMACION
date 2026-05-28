from models.ticket import Ticket

class ParkingLot:
    def __init__(self, spots, rate_policy):
        self._spots = spots
        self._tickets_activos = []
        self._rate_policy = rate_policy

    def registrar_entrar(self, vehicle):
        for spot in self._spots:
            if spot.esta_libre() and spot.get_tipo() == vehicle.get_tipo():
               spot.ocupar()
               ticket = Ticket(vehicle, spot)
               self._tickets_activos.append(ticket)
               print(f"Entrada: {vehicle.get_placas()} -> Ticket #{ticket.get_id()}")
               return

        print("No hay lugares disponibles")

    def registrar_salida(self, ticket_id):
        for ticket in self._tickets_activos:
            if ticket.get_id() == ticket_id:
                ##ticket.cerrar_ticket()
                horas = float(input("Horas estacionado: "))
                costo = ticket.get_vehicle().calcular_tarifa(horas) ##nuevo costo por vehiculo
                
                ticket.get_spot().liberar()
                self._tickets_activos.remove(ticket)

                print(f"Salida: Ticket {ticket_id} -> ${round(costo,2)}")
                return
            
        print("Ticket no encontrado")
    def ver_ocupacion(self):
        ocupados = sum(not s.esta_libre() for s in self._spots)
        libres = len(self._spots) - ocupados
        print(f"Ocupados: {ocupados}, Libres: {libres}")

    def ver_tickets(self):
        for t in self._tickets_activos:
            print(f"Ticket #{t.get_id()} - {t.get_vehicle().get_placas()}")