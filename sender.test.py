from sender import *
import unittest
import mock


class senderTest(unittest.TestCase):
    def test_charge(self):
        charge_sensor = ChargeSensor(50)
        self.assertTrue(charge_sensor.get_value() == 50)

    def test_temperature(self):
        temperature_sensor = HeatSensor(70)
        self.assertTrue(temperature_sensor.get_value() == 70)

    def test_send_params(self):
        mock_charge_sensor = mock.Mock()
        mock_heat_sensor = mock.Mock()
        mock_receiver = mock.Mock()
        no_of_samples = 50
        send_params(mock_charge_sensor, mock_heat_sensor,
                    mock_receiver, no_of_samples)
        # reciever is called 1 time
        self.assertTrue(mock_receiver.call_count == 1)


if __name__ == '__main__':
    unittest.main()
