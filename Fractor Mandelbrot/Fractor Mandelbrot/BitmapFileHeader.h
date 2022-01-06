#pragma once
//Make sure that int is a 32bit number
#include <cstdint>

//to disable the data alignment, auto padding false infomation in C++
#pragma pack(2)

namespace programming {
	struct BitmapFileHeader
	{
		char header[2]{ 'B', 'M' }; //format that ivoke a file is a bitmap file
		int32_t fileSize;
		int32_t reserved{ 0 };
		int32_t dataOffset;

	};
}

#pragma pack(pop)