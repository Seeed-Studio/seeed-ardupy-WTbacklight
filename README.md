# Wio Terminal Ardupy Backlight [![Build Status](https://api.travis-ci.com/Seeed-Studio/seeed-ardupy-WTbacklight.svg?branch=main)](https://travis-ci.com/github/Seeed-Studio/seeed-ardupy-WTbacklight)

## Introduction

This is the ArduPy library for controlling the brightness of the LCD on the Wio Terminal. This library was originally written for Arduino by [Kenta IDA](https://github.com/ciniml) and all credit goes to him for the Arduino Library.


## How to bind with ArduPy
- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)
- Build firmware with Seeed ArduPy DHT
```shell
aip install Seeed-Studio/seeed-ardupy-WTbacklight/archive/main.zip
aip build
```
- Flash new firmware to you ArduPy board
```shell
aip flash
#aip flash [path of the new firmware]
```
For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).

## Usage

```python
# include libraries  
from arduino import wt_lcdbacklight
from machine import LCD
import time

lcd = LCD() # initialize LCD
backlight = wt_lcdbacklight() # initialize backlight

def main(): # main function 
    lcd.fillScreen(lcd.color.RED) # fill background 
    brightness = 0 # set brightness variable

    while True: # while loop
        maxBrightness = backlight.getMaxBrightness # obtain max brightness
        brightness += 1 # incriment brightness by 1

        if (brightness > maxBrightness): # set brightness to 0 if brightness value equals maxBrightness value
            brightness = 0
        backlight.setBrightness(brightness) # turn on backlight with brightness  
        time.sleep_ms(50)

if __name__ == "__main__": # check whether this is run from main.py
    main() # execute function
```

## API Reference

- **getBrightness** : Obtain LCD brightness
```python
 backlight.getBrightness
```

- **getMaxBrightness**: Obtain LCD maximum brightness
```python
 backlight.getMaxBrightness
```

- **setBrightness()**: Set LCD brightness 
```python
 backlight.setBrightness(50)
```

- **setMaxBrightness()**: Set LCD maximum brightness
```python
 backlight.setMaxBrightness(100)
```
----
## License
This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
