from sender import *
import mock


def test_charge():
    charge_sensor = ChargeSensor(50)
    assert(charge_sensor.get_value() == 50)


def test_temperature():
    temperature_sensor = HeatSensor(70)
    assert(temperature_sensor.get_value() == 70)


def test_send_params():
    mock_charge_sensor = mock.Mock()
    mock_heat_sensor = mock.Mock()
    mock_receiver = mock.Mock()
    send_params(mock_charge_sensor, mock_heat_sensor, mock_receiver)
    # reciever is called 50 times
    assert(mock_receiver.call_count == 50)


test_charge()
test_temperature()
test_send_params()
