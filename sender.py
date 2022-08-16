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


def write_to_file(charge_stream, heat_stream):
    fileName = "./output.txt"
    with open(fileName, "w") as file_object:
        file_object.write("Charge\n")
        charge_values = ",".join([str(value) for value in charge_stream])
        file_object.write(charge_values)

        file_object.write("\n")

        file_object.write("Heat\n")
        heat_values = ",".join([str(value) for value in heat_stream])
        file_object.write(heat_values)

        file_object.close()


if __name__ == "__main__":
    send_params(ChargeSensor, HeatSensor, write_to_file, 50)
