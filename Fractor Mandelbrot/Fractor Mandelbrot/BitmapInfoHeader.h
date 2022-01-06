#pragma once
#include <cstdint>
#pragma pack(2)

namespace programming {
	struct BitmapInfoHeader
	{
		int32_t headerSize{ 40 };//the size of this struct equal 40 bytes
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };//short, layer
		int16_t bitsPerPixel{ 24 };//8bits per colors, 3 colors in 1 pixel RGB
		int32_t compression{ 0 };//compression data
		int32_t dataSize{ 0 };
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };

	};
}
#pragma pack(pop)