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
import signal
from re import search, compile
from sys import stdin

total_files = 0
total_filesize = 0
stats = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}


def deca_do():
    print("File size: ", total_filesize)
    for key, value in stats.items():
        print(key, ": ", value)


if __name__ == "__main__":
    try:
        for line in stdin:
            RE_pattern = (r"(\d{3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - "
                          r"(\[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{6}\]) "
                          r'("GET \/projects\/260 HTTP\/1.1") '
                          r"(\d{3}) (\d+)")
            result = search(RE_pattern, line)
            if result:
                total_files += 1
                status_code = result.group(4)
                total_filesize += int(result.group(5))
            else:
                continue
            for key, value in stats.items():
                if status_code == key:
                    stats[key] += 1
            if (total_files % 10) == 0 and total_files > 1:
                deca_do()
    except KeyboardInterrupt:
        deca_do()
