#ifndef CATVIZCREATETEXTUREFROMDDSFILE_H
#define CATVIZCREATETEXTUREFROMDDSFILE_H

//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
// Abstract : This provides services around DDS files
//------------------------------------------------------------------------------
//  Usage : 
//
//   GetTextureFromFile:
//   A texture is created from Microsoft DirectDraw Surface file.
//   This texture could be a simple texture or a volume texture or a cubic environment map.
//   Both with or without mipmaps.
//------------------------------------------------------------------------------

// Local Framework
#include "CATVisTextureObjects.h"
// Visualization Framework
#include "CATPixelImage.h"
#include "CATTexturePixelImage.h"

	/**
	 * Creates a texture from a DDS file.
	 * @param iDDSFilePath
	 *   The file to create the texture from.
	 *   <br>Recognized formats are : DDS.
	 * @param iReadState
	 *   The <tt>ReadOnly</tt> state of the new texture.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATTexturePixelImage</tt>.</dt>
	 * </dl>
	 */
	extern "C" ExportedByCATVisTextureObjects CATTexturePixelImage* CreateTextureFromDDSFile(const CATUnicodeString& iDDSFilePath, CATReadOnlyState iReadState = NotReadOnly);

#endif

