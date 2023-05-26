#ifndef CATLISTOFCATVIZMIPMAPPIXELIMAGE_H
#define CATLISTOFCATVIZMIPMAPPIXELIMAGE_H

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @collection CATLISTP(CATVizMipMapPixelImage)
 * Collection class for pointers to <tt>CATVizMipMapPixelImage</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATVizMipMapPixelImage
 */

#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Swap

#include "CATVizMipMapPixelImage.h"
#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATVisTextureObjects

CATLISTP_DECLARE(CATVizMipMapPixelImage);

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy

#endif
