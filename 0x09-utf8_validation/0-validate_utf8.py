#!usr/bin/python3
"""
    data: will be represented by a list of integers
    Return: True if data is a valid UTF-8 encoding, else return False
"""


def validUTF8(data):
    """
    https://codereview.stackexchange.com/questions/159814/utf-8-validation
    A character in UTF8 can be from 1 to 4 bytes long, subjected to the
    following rules: For 1-byte character, the first bit is a 0, followed
    by its unicode code. For n-bytes character, the first n-bits are all one's,
    the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being
    10. Given an array of integers representing the data, return whether it is
    a valid utf-8 encoding. Note: The input is an array of integers. Only the
    least significant 8 bits of each integer is used to store the data. This
    means each integer represents only 1 byte of data.

    Sure being able to solve
    this on my own would be cool but look it wont be this good and real dev's
    roll their sleeves up and get shit done im not a function printer im a
    problem solver this time i found one, so be it
    """
    successive_10 = 0
    for b in data:
        b = bin(b).replace('0b', '').rjust(8, '0')
        if successive_10 != 0:
            successive_10 -= 1
            if not b.startswith('10'):
                return False
        elif b[0] == '1':
            successive_10 = len(b.split('0')[0]) - 1
    return True
