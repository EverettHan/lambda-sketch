#pragma once

#include "BasisUniversalWrapper.h"
#include <string>

namespace basisu {
	class image;
}

class ExportedByBasisUniversalWrapper VisBasisCompWrapper {

public:
	enum class SourceFormat {
		RGBA = 0, //
		RGB
	};

	static bool load_png_from_bytearray(const unsigned char* byteArray, int srcDataSize, basisu::image& img);
	static bool load_jpg_from_bytearray(const unsigned char* byteArray, int srcDataSize, basisu::image& img);
	static int CompressRGBABufferToBasis(void* data, int width, int height, std::string iFileName, SourceFormat iFormatInputData = SourceFormat::RGBA, int iQuality = 255, bool iUseLinearColorSpace = false, bool iKTX2 = false, bool iFlipY = false);
	static int CompressImageToBasis(const basisu::image& imgToCompress, std::string outputFilename, int iQuality, bool iUseLinearColorSpace, bool iKTX2 = false, bool iFlipY = false, char** outputBasisData = NULL, int* outputBasisDataSize = NULL);
};
