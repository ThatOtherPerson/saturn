#include <sstream>
#include <iostream>

#ifndef __BLOCK_DEVICE_HPP
#define __BLOCK_DEVICE_HPP

namespace galaxy {
    namespace saturn {
//        namespace device {
            class block_device {
            protected:
            public:
//                void write_out_image(std::array<uint16_t> image);
                void read_in_image(char* file_data_array, int image_filesize);
            };
  //      }
    }
}

#endif
