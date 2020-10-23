/**
 * The MIT License (MIT)
 *
 * Author: Lakshantha Dissanayake (lakshanthad@seeed.cc)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#include "Arduino.h" 
#include "Wio_Terminal_Backlight/lcd_backlight.hpp" //include dependent Arduino library

extern "C" //tell compiler to use the C naming and calling conventions 
{
    //needed header files from micropython
    #include "py/mphal.h"
    #include "py/nlr.h"
    #include "py/objtype.h"
    #include "py/runtime.h"
    #include "shared-bindings/util.h"
}

//initialize module 
#define lcdbacklight (*(LCDBackLight *)self->module)
void *operator new(size_t, void *);

//map functions from dependent Arduino library 
extern "C"
{
    void common_hal_lcdbacklight_construct(abstract_module_t *self) //initializing function to create an object
    {
        self->module = new (m_new_obj(LCDBackLight)) LCDBackLight();
        lcdbacklight.initialize(); //initialize backlight  
    }
    void common_hal_lcdbacklight_deinit(abstract_module_t *self) //deinitializing function
    {
        lcdbacklight.~LCDBackLight();
    }
    uint8_t common_hal_lcdbacklight_get_brightness(abstract_module_t *self) //function to obtain brightness
    {
        return lcdbacklight.getBrightness();
    }  
    uint8_t common_hal_lcdbacklight_get_maxbrightness(abstract_module_t *self) //function to obtain maximum brightness
    {
        return lcdbacklight.getMaxBrightness();
    } 
    uint8_t common_lcdbacklight_set_brightness(abstract_module_t *self, uint8_t brightness) //function to set brightness
    {
        lcdbacklight.setBrightness(brightness);
    }
    uint8_t common_lcdbacklight_set_maxbrightness(abstract_module_t *self, uint8_t maxBrightness) //function to set maximum brightness
    {
        lcdbacklight.setMaxBrightness(maxBrightness);
    }    
            
}

