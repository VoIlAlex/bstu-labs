import os
import ctypes
import numpy as np

def get_free_space():
    dir_name = os.path.dirname(__file__)
    free_bytes = ctypes.c_ulonglong(0)
    ctypes.windll.kernel32.GetDiskFreeSpaceExW(ctypes.c_wchar_p(dir_name), None, None, ctypes.pointer(free_bytes))
    return int(free_bytes.value)

free_space = get_free_space()
print(free_space)
tresh_file = open('trash', 'w+')
for i in range(free_space - 500 * 1025):
    if i % 50 == 0 and i != 0:
        print('\n', end='', file=tresh_file)
    else:
        print('1' if np.random.randint(0, 2) % 2 == 0 else '0', end='', file=tresh_file)

