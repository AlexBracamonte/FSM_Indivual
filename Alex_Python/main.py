import threading
import os
from time import time
import logging


logging.basicConfig(
    level=logging.DEBUG,
    format='[%(levelname)s] - %(threadName)-10s : %(message)s',)


class Manejador:
    def __init__(self, _dir: str):
        self.dir = _dir
        self.files = []

    def get_files(self):
        self.files = os.listdir(self.dir)
        print(f"The files are: {self.files}")

    def command(self):
        for valor in self.files:
            print(f"Comando: python FMS.py{valor[:-5]}")
            os.system(f"python FMS.py {valor[:-5]}")


class ThreadsClass:
    def __init__(self):
        self.threads = list()

    @staticmethod
    def commad_by_thread(file_name: str):
        logging.debug('Start - %s', file_name)
        os.system(f"python FMS.py {file_name}")
        logging.debug('Finish - %s', file_name)


if __name__ == '__main__':
    start_time = time()

    process = ThreadsClass()
    test = Manejador(_dir="Tablas")

    test.get_files()

    for file in test.files:
        t = threading.Thread(target=process.commad_by_thread, args=(file[:-5],))
        process.threads.append(t)
        t.start()

    elapsed_time = time() - start_time
    print("Elapsed time: %0.10f seconds." % elapsed_time)
