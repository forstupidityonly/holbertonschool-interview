#!/usr/bin/python3
"""
read stdin line by line and compute metrics: After every 10 lines and/or a
keyboard interruption print these statistics from the beginning:
* total file size
* Number of lines by status code in accening order. <status code>: <number>
-------------------------------------------------------------------------------
Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

If other format, skip line.
-------------------------------------------------------------------------------
Input sapmles:
186.48.162.100 - [2021-09-02 13:51:36.730985] "GET /projects/260 HTTP/1.1"
 404 301

57.58.52.83 - [2021-09-02 13:51:32.078771] "GET /projects/260 HTTP/1.1" 405 86
-------------------------------------------------------------------------------
Output sample:
File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4
"""
from sys import stdin


codes = {'200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0}
size = 0


def print_info():
    print("File size: {}".format(size))
    for key, val in sorted(codes.items()):
        if val > 0:
            print("{}: {}".format(key, val))

if __name__ == '__main__':
    try:
        for i, line in enumerate(stdin, 1):
            try:
                info = line.split()
                size += int(info[-1])
                if info[-2] in codes.keys():
                    codes[info[-2]] += 1
            except:
                pass
            if not i % 10:
                print_info()
    except KeyboardInterrupt:
        print_info()
        raise
    print_info()
