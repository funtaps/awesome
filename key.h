/*
 * key.h - Keybinding helpers
 *
 * Copyright © 2009 Julien Danjou <julien@danjou.info>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef AWESOME_KEYBINDING_H
#define AWESOME_KEYBINDING_H

#include "luaa.h"

typedef struct keyb_t
{
    LUA_OBJECT_HEADER
    /** Key modifier */
    uint16_t mod;
    /** Keysym */
    xcb_keysym_t keysym;
    /** Keycode */
    xcb_keycode_t keycode;
    /** Lua function to execute on press */
    void *press;
    /** Lua function to execute on release */
    void *release;
} keyb_t;

DO_ARRAY(keyb_t *, key, DO_NOTHING)
LUA_OBJECT_FUNCS(keyb_t, key, "key")

bool key_press_lookup_string(xcb_keysym_t, char *, ssize_t);
xcb_keysym_t key_getkeysym(xcb_keycode_t, uint16_t);

void luaA_key_array_set(lua_State *, int, int, key_array_t *);
int luaA_key_array_get(lua_State *, int, key_array_t *);

int luaA_pushmodifiers(lua_State *, uint16_t);
uint16_t luaA_tomodifiers(lua_State *L, int ud);

#endif
