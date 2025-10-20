# Arduino 7-Segment Calculator

This project is a *simple calculator* using *two 7-segment displays* and a *3x3 keypad*.  
It allows the user to input *two single-digit numbers* and shows their *sum* on the displays.

---

## Features

- Input two digits via a 3x3 keypad
- Display single and double-digit sums on 7-segment displays
- Simple scanning routine for keypad input
- Visual feedback while entering numbers

---

## Hardware Requirements

- Arduino board (Uno, Mega, etc.)
- Two 7-segment displays
- 3x3 Keypad (3 rows × 3 columns)
- Resistors for 7-segment pins (if needed)
- Jumper wires
- Breadboard

---

## Connections

| Component         | Arduino Pin |
|------------------|-------------|
| Left 7-segment    | 7           |
| Right 7-segment   | 6           |
| 7-segment data pins (common cathode/anode) | 8, 9, 10, 11 |
| Keypad Rows       | 0, 1, 2     |
| Keypad Columns    | 3, 4, 5     |

---

## How It Works

1. The program waits for the first button press on the keypad (Scankey() function).
2. The first number is displayed on the left 7-segment display.
3. The program waits for the second button press.
4. Both numbers are displayed on the two displays.
5. The sum() function calculates the sum and handles display logic.
6. If the sum is less than 10, it shows only on the right display.  
   If the sum is ≥10, the tens and units are displayed separately.

---

## Circuit Image

Here is a visual representation of the calculator circuit:

![Arduino Calculator](https://raw.githubusercontent.com/DvirC892/projectPhotos/main/%D7%A6%D7%99%D7%9C%D7%95%D7%9D%20%D7%9E%D7%A1%D7%9A%202025-10-20%20194213.png)

Click the image to open it in full size.

---

## License

MIT License – free to use and modify.
