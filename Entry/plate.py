import itertools
import threading
import serial

class Plate:

    def __init__(self, baudrate=115200, port="COM3"):
        # unique seq counter
        self.seq = itertools.count()
        # serial communication driver
        self.ser = serial.Serial()
        self.ser.baudrate = baudrate
        self.ser.port = port
        self.ser.open()
        # serial recive thread run
        self.run_receive_thread()

    def run_receive_thread(self):
        task_receive = threading.Thread(target=self.__recv_data, name="serial_recv_task")
        task_receive.setDaemon(True)
        task_receive.start()

    def __recv_data(self):
        while True:
            data = bytearray(self.ser.read())
            print(data)

    def set_led(self, state):
        cmd = []
        cmd.append(1 if state else 0)
        self.ser.write(bytearray(cmd))