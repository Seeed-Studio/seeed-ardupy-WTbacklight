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


//needed header files from micropython
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"

//include previously defined functions from wrapper
void common_hal_lcdbacklight_construct(abstract_module_t *self);
void common_hal_lcdbacklight_deinit(abstract_module_t *self);
uint8_t common_hal_lcdbacklight_get_brightness(abstract_module_t *self);
uint8_t common_hal_lcdbacklight_get_maxbrightness(abstract_module_t *self);
uint8_t common_lcdbacklight_set_brightness(abstract_module_t *self, uint8_t brightness);
uint8_t common_lcdbacklight_set_maxbrightness(abstract_module_t *self, uint8_t maxBrightness);

extern const mp_obj_type_t wt_lcdbacklight_type; //declaration of initial module type 

//initialize module 
m_generic_make(lcdbacklight) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_lcdbacklight_construct(self);
    return self;
}

//object attributes 
void lcdbacklight_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    abstract_module_t *self = (abstract_module_t *)self_in;
    uint8_t number; //define number as int data type

    if (dest[0] == MP_OBJ_NULL) //load attributes 
    {
        if (attr == MP_QSTR_getBrightness) //MP_QSTR_[Function-name] & Function-name used for ArduPy calling 
        {
            number = common_hal_lcdbacklight_get_brightness(self); //call previously defined function
            dest[0] = mp_obj_new_int(number); //this is the Micropython int type and should match with the data type 
            return;
        }
        else if (attr == MP_QSTR_getMaxBrightness)
        {
            number = common_hal_lcdbacklight_get_maxbrightness(self);
            dest[0] = mp_obj_new_int(number);
            return;
        }
    }
    generic_method_lookup(self_in, attr, dest);
}

//object attributes for functions that take parameters 
mp_obj_t lcdbacklight_set_brightness(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint8_t brightness = mp_obj_get_int(pos_args[1]);
    common_lcdbacklight_set_brightness(self, brightness);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(lcdbacklight_set_brightness_obj, 1, lcdbacklight_set_brightness);

mp_obj_t lcdbacklight_set_maxbrightness(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint8_t maxBrightness = mp_obj_get_int(pos_args[1]);
    common_lcdbacklight_set_maxbrightness(self, maxBrightness);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(lcdbacklight_set_maxbrightness_obj, 1, lcdbacklight_set_maxbrightness);


//look-up table 
const mp_rom_map_elem_t lcdbacklight_locals_dict_table[] = {
    //instance methods
    {MP_ROM_QSTR(MP_QSTR_deinit), MP_ROM_PTR(&lcdbacklight_deinit_obj)},
    {MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj)},
    {MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&lcdbacklight_obj___exit___obj)},
    {MP_ROM_QSTR(MP_QSTR_setBrightness), MP_ROM_PTR(&lcdbacklight_set_brightness_obj)}, //add the function with parameters
    {MP_ROM_QSTR(MP_QSTR_setMaxBrightness), MP_ROM_PTR(&lcdbacklight_set_maxbrightness_obj)}, //add the function with parameters
};
MP_DEFINE_CONST_DICT(lcdbacklight_locals_dict, lcdbacklight_locals_dict_table);

//initial module type 
const mp_obj_type_t wt_lcdbacklight_type = {
    {&mp_type_type},
    .name = MP_QSTR_wt_lcdbacklight,
    .make_new = lcdbacklight_make_new,
    .locals_dict = (mp_obj_t)&lcdbacklight_locals_dict,
    .attr = lcdbacklight_obj_attr,
};