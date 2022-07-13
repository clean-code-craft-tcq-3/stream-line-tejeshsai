import random


class ChargeSensor:
    def __init__(self, charge_level):
        self.charge_level = charge_level

    def get_value(self):
        return self.charge_level


class HeatSensor:
    def __init__(self,  temperature_value):
        self.temperature = temperature_value

    def get_value(self):
        return self.temperature


def send_params(sensor1, sensor2, receiver, no_of_samples):
    """
    Printing the values on console
    """
    charge_stream = []
    heat_stream = []
    for i in range(no_of_samples):  # creating 50 readings:
        attribute1 = random.randint(60, 80)
        attribute2 = random.randint(0, 60)
        charge_sensor = sensor1(attribute1)
        heat_sensor = sensor2(attribute2)
        charge_stream.append(charge_sensor.get_value())
        heat_stream.append(heat_sensor.get_value())

    receiver(charge_stream, heat_stream)


def print_on_console(charge_stream, heat_stream):
    print("Charge")
    for i in charge_stream:
        print(i, end=",")
    print()
    print("Heat")
    for i in heat_stream:
        print(i, end=",")


if __name__ == "__main__":
    send_params(ChargeSensor, HeatSensor, print_on_console, 50)
