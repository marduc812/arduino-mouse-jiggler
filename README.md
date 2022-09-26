## ArduMouseJiggler

This is a simple script used to made the arduino act as a mouse and mouse the cursor, preventing your screen from locking. 
The mouse moves in random directions, keeping in mind a specific range that can be set. 
On the first lines of the file those variables are defined.

| variable | purpose | default value |
| --- | --- | --- |
| randomMoveRange | Max range in a single move (px) | 500 |
| maxMoveRange | Max range where the mouse is allowed to move in general (px) | 600 |
| randomDelayTimer | Max range of teh random time interval (ms) | 20000 |

### How to flash it

Just paste the code to your Arduino IDE and you are good to go.


#### note

The mouse will never click on anything and it's purpose is just to keep your laptop's screen on. 
I haven't test it for Microsoft teams, but it should also keep you on during all the time. 