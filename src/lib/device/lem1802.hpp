/*

This file is part of libsaturn.

libsaturn is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

libsaturn is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libsaturn.  If not, see <http://www.gnu.org/licenses/>.

Your copy of the GNU Lesser General Public License should be in the
file named "LICENSE-LGPL.txt".

*/

#ifndef LEM1802_HPP
#define LEM1802_HPP

#include <libsaturn.hpp>
#include <device.hpp>

#include <cstdint>

namespace galaxy {
    namespace saturn {
        /**
         * represents a single pixel
         */
        struct pixel {
            std::uint8_t r, g, b;
        };

        /**
         * represents a lem1802 hardware device
         */
        class lem1802 : device {
        protected:
            /// points to the 384-word segment of video ram
            std::uint16_t vram_pointer;

            /// points to the 256-word segment of font ram ram
            std::uint16_t fram_pointer;

            /// points to the 16-word segment of palette ram
            std::uint16_t pram_pointer;

            /// the index of the border color in the palette
            std::uint8_t border_color;

            /// when this is true, cells set to blink will be displayed, when it is false, they won't be displayed
            bool blink_on;

            /// set to true when the monitor has been changed
            bool monitor_updated;

            /// number of cycles since blink was last changed
            std::uint32_t cycles;

            /// the default font of the LEM1802
            static const std::array<std::uint16_t, 256> default_font;

            /// the default palette of the LEM1802
            static const std::array<std::uint16_t, 16> default_palette;

        public:
            /// initialize the device to values specified by the spec
            lem1802() : device(0x7349f615, 0x1c6c8b36, 0x1802, "LEM1802 - Low Energy Monitor"),
                        vram_pointer(0), fram_pointer(0), pram_pointer(0), border_color(0),
                        blink_on(false), monitor_updated(false), cycles(0) {}

            virtual void interrupt();
            virtual void cycle();

            /// returns true if the screen has been updated since last called, false otherwise
            bool updated();
        };
    }
}

#endif
