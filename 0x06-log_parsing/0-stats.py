#!/usr/bin/python3
"""Log parsing"""


import sys
satus_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}

file_size = 0

try:
    for x, line in enumerate(sys.stdin, 1):
        sp_line = line.strip().split()
        line_len = len(sp_line)
        file_size += int(sp_line[line_len - 1])
        status = sp_line[line_len - 2]
        if status in satus_code:
            satus_code[str(status)] += 1
        if x % 10 == 0:
            print("File size: {}".format(file_size))
            for i in sorted(satus_code):
                if satus_code[i] > 0:
                    print("{}: {}".format(i, satus_code[i]))
except KeyboardInterrupt:
    pass
print('File size: {:d}'.format(file_size))
for key in sorted(satus_code.keys()):
    print("{}: {:d}".format(key, satus_code[key]))
