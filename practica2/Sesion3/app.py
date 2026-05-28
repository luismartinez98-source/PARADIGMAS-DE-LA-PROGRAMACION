from flask import Flask, render_template, request, redirect
from models.vehicle import Car, Moto, Electric
from models.spot import ParkingSpot
from models.parking_lot import ParkingLot

app = Flask(__name__)

# Inicializar tu sistema (igual que en CLI)
spots = [
    ParkingSpot("A1", "Carro"),
    ParkingSpot("A2", "Carro"),
    ParkingSpot("M1", "Motocicleta")
]

parking = ParkingLot(spots, None)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/entrada", methods=["POST"])
def entrada():
    placas = request.form["placas"]
    tipo = request.form["tipo"]

    if tipo == "carro":
        subtipo = request.form["subtipo"]

        if subtipo == "combustible":
            v = Car(placas)
        else:
            v = Electric(placas)

    elif tipo == "moto":
        v = Moto(placas)

    parking.registrar_entrar(v)
    return redirect("/")


@app.route("/salida", methods=["POST"])
def salida():
    ticket_id = int(request.form["ticket"])
    horas = float(request.form["horas"])

    parking.registrar_salida(ticket_id, horas)
    return redirect("/")


@app.route("/ocupacion")
def ocupacion():
    ocupados = sum(not s.esta_libre() for s in parking._spots)
    libres = len(parking._spots) - ocupados

    return f"Ocupados: {ocupados}, Libres: {libres}"


if __name__ == "__main__":
    app.run(debug=True)