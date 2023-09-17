#pragma once

#include <Types.h>
#include <SDL2/SDL.h> // Include SDL for SDL keycodes

namespace Gengine {
    using KeyCode = int32;

    namespace Key {
        enum : KeyCode {
            MySpace = 2000,
            MyApostrophe,
            MyComma,
            // Add more custom keycodes here if needed.

            // Map custom keycodes to SDL keycodes.
            Space = SDLK_SPACE,
            Apostrophe = SDLK_QUOTE,
            Comma = SDLK_COMMA,
            Minus = SDLK_MINUS,
            Period = SDLK_PERIOD,
            Slash = SDLK_SLASH,
            Semicolon = SDLK_SEMICOLON,
            Equal = SDLK_EQUALS,

            // Alphanumeric keys
            A = SDLK_a,
            B = SDLK_b,
            C = SDLK_c,
            D = SDLK_d,
            E = SDLK_e,
            F = SDLK_f,
            G = SDLK_g,
            H = SDLK_h,
            I = SDLK_i,
            J = SDLK_j,
            K = SDLK_k,
            L = SDLK_l,
            M = SDLK_m,
            N = SDLK_n,
            O = SDLK_o,
            P = SDLK_p,
            Q = SDLK_q,
            R = SDLK_r,
            S = SDLK_s,
            T = SDLK_t,
            U = SDLK_u,
            V = SDLK_v,
            W = SDLK_w,
            X = SDLK_x,
            Y = SDLK_y,
            Z = SDLK_z,

			// Numeric keys
            D0 = SDLK_0,
            D1 = SDLK_1,
            D2 = SDLK_2,
            D3 = SDLK_3,
            D4 = SDLK_4,
            D5 = SDLK_5,
            D6 = SDLK_6,
            D7 = SDLK_7,
            D8 = SDLK_8,
            D9 = SDLK_9,

            // Add more custom keycodes here if needed.

            // Arrow keys
            Left = SDLK_LEFT,
            Right = SDLK_RIGHT,
            Up = SDLK_UP,
            Down = SDLK_DOWN,

            // Numeric keypad
            KP0 = SDLK_KP_0,
            KP1 = SDLK_KP_1,
            KP2 = SDLK_KP_2,
            KP3 = SDLK_KP_3,
            KP4 = SDLK_KP_4,
            KP5 = SDLK_KP_5,
            KP6 = SDLK_KP_6,
            KP7 = SDLK_KP_7,
            KP8 = SDLK_KP_8,
            KP9 = SDLK_KP_9,
            KPDecimal = SDLK_KP_PERIOD,
            KPDivide = SDLK_KP_DIVIDE,
            KPMultiply = SDLK_KP_MULTIPLY,
            KPSubtract = SDLK_KP_MINUS,
            KPAdd = SDLK_KP_PLUS,
            KPEnter = SDLK_KP_ENTER,
            KPEqual = SDLK_KP_EQUALS,

            // Add more custom keycodes here if needed.

            // Function keys
            F1 = SDLK_F1,
            F2 = SDLK_F2,
            F3 = SDLK_F3,
            F4 = SDLK_F4,
            F5 = SDLK_F5,
            F6 = SDLK_F6,
            F7 = SDLK_F7,
            F8 = SDLK_F8,
            F9 = SDLK_F9,
            F10 = SDLK_F10,
            F11 = SDLK_F11,
            F12 = SDLK_F12,
            F13 = SDLK_F13,
            F14 = SDLK_F14,
            F15 = SDLK_F15,
            F16 = SDLK_F16,
            F17 = SDLK_F17,
            F18 = SDLK_F18,
            F19 = SDLK_F19,
            F20 = SDLK_F20,
            F21 = SDLK_F21,
            F22 = SDLK_F22,
            F23 = SDLK_F23,
            F24 = SDLK_F24,

            // Additional keys
            CapsLock = SDLK_CAPSLOCK,
            ScrollLock = SDLK_SCROLLLOCK,
            NumLock = SDLK_NUMLOCKCLEAR,
            PrintScreen = SDLK_PRINTSCREEN,
            Pause = SDLK_PAUSE,
            Escape = SDLK_ESCAPE,
            Enter = SDLK_RETURN,
            Tab = SDLK_TAB,
            Backspace = SDLK_BACKSPACE,
            Insert = SDLK_INSERT,
            Delete = SDLK_DELETE,
            PageUp = SDLK_PAGEUP,
            PageDown = SDLK_PAGEDOWN,
            Home = SDLK_HOME,
            End = SDLK_END,


            // Mouse buttons (custom mappings)
            LeftMouseButton = 1000,
            RightMouseButton,
            MiddleMouseButton,
            // Add more custom mouse button mappings here if needed.
        };
    }
}