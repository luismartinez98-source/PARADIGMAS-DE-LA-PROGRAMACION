from models.vehicle import Car, Moto, Electric
from models.spot import ParkingSpot
from models.parking_lot import ParkingLot
from models.rates import SimpleRatePolicy

spots = [
    ParkingSpot("A1", "Carro"),
    ParkingSpot("A2", "Carro"),
    ParkingSpot("M1", "Motocicleta")
]
parking = ParkingLot(spots, SimpleRatePolicy())

while True:
    print("\n1. Entrada")
    print("2. Salida")
    print("3. Ver ocupacion")
    print("4. Ver tickets")
    print("5. Salir")

    opcion = input("Opcion: ")
    if opcion == "1":
        placas = input("Placas: ")
        tipo = input("Tipo ([1] Carro /[2] Motocicleta): ")

        if tipo == "1":
            subtipo = input("[1] Combustible o [2] Electrico")
            if subtipo == "1":
                v = Car(placas)
            elif subtipo == "2":
                v = Electric(placas)
            else:
                print("Opcion incorrecta")
                continue    

        elif tipo == "2":
            v = Moto(placas)
        else:
            print("Opcion incorrecta")
            continue

        parking.registrar_entrar(v)

    elif opcion == "2":
        ticket_id = int(input("Ticket ID: "))
        parking.registrar_salida(ticket_id)

    elif opcion == "3":
        parking.ver_ocupacion()

    elif opcion == "4":
        parking.ver_tickets()

    elif opcion == "5":
        break
