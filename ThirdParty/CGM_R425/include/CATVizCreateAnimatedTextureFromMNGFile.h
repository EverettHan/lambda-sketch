#ifndef CATVizCreateAnimatedTextureFromMNGFile_H
#define CATVizCreateAnimatedTextureFromMNGFile_H

//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
//------------------------------------------------------------------------------
// Abstract : This provides services around MNG files
//------------------------------------------------------------------------------
//  Usage : 
//
//   CreateAnimatedTextureFromMNGFile:
//   A animation is created from MNG file.
//------------------------------------------------------------------------------

// Local Framework
#include "CATVisTextureObjects.h"
//#include "CATVizCreateAnimationFromMNGFile.h"

//class CATVizPixelImageAnimation;
class CATVizAnimatedTexture;
// System Framework
#include "CATUnicodeString.h"
	
	/**
	 * Creates an animated texture from a MNG file.
	 * @param iMNGFilePath
	 *   The file to create the animation from.
	 *   <br>Recognized formats are : MNG.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATVizPixelImageAnimation</tt>.</dt>
	 * </dl>
	 */
	ExportedByCATVisTextureObjects CATVizAnimatedTexture* CreateAnimatedTextureFromMNGFile(const CATUnicodeString& iMNGFilePath);

#endif

