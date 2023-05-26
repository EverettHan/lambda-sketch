#ifndef CATVIZCREATETEXTUREFROMDDSBUFFER_H
#define CATVIZCREATETEXTUREFROMDDSBUFFER_H

//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
// Abstract : This provides services around DDS buffer
//------------------------------------------------------------------------------
//  Usage : 
//
//   CreateTextureFromDDSBuffer:
//   A texture is created from Microsoft DirectDraw Surface buffer.
//   This texture could be a simple texture or a volume texture or a cubic environment map.
//   Both with or without mipmaps.
//------------------------------------------------------------------------------

// Local Framework
#include "CATVisTextureObjects.h"
// Visualization Framework
#include "CATPixelImage.h"
#include "CATTexturePixelImage.h"

	/**
	 * Creates a texture from a DDS buffer.
	 * @param ipDDSBuffer
	 *   The buffer to create the texture from.
	 *   <br>Recognized formats are : DDS.
	 * @param iDDSBufferSize
	 *   The buffer size.
	 * @param iReadState
	 *   The <tt>ReadOnly</tt> state of the new texture.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATTexturePixelImage</tt>.</dt>
	 * </dl>
	 */
	extern "C" ExportedByCATVisTextureObjects CATTexturePixelImage* CreateTextureFromDDSBuffer(const char* ipDDSBuffer, const int iDDSBufferSize, CATReadOnlyState iReadState = NotReadOnly);

#endif

