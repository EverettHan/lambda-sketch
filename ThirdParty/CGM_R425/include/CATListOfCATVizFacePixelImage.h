#ifndef CATLISTOFCATVIZFACEPIXELIMAGE_H
#define CATLISTOFCATVIZFACEPIXELIMAGE_H

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @collection CATLISTP(CATVizFacePixelImage)
 * Collection class for pointers to <tt>CATVizFacePixelImage</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATVizFacePixelImage
 */

#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Swap

#include "CATVizFacePixelImage.h"
#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATVisTextureObjects

CATLISTP_DECLARE(CATVizFacePixelImage);

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy

#endif
