#!/usr/bin/python3
"""lockboxes"""


def canUnlockAll(boxes):
    """Open all boxes with keys from other boxes. Keys and boxes are represented
       as numbers: #1 key opens #1 box"""
    key_chain = [0]  # Always have key to box-0
    opened_boxes = []
    if not boxes:
        return False

    while key_chain:  # While there are unused keys
        key = key_chain.pop()  # Remove top key
        if key not in opened_boxes:  # If not a duplicate, use key
            opened_boxes.append(key)  # Track it's used
            for i in boxes[key]:  # For key in opend box
                if i < len(boxes):  # Check the range is valid
                    key_chain.append(i)  # Add to keychain
    if len(opened_boxes) == len(boxes):
        return True  # All boxes have been opened
    else:
        return False  # Boxes left without keys
