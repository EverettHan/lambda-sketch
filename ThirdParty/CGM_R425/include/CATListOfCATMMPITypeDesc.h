/*
*  CATMMPISpec.h
*
*  Created by o1x on 01/03/2013.
*  Copyright 2013 Dassault Systemes. All rights reserved.
*
*/
#ifndef CATListOfCATMMPITypeDesc_H
#define CATListOfCATMMPITypeDesc_H

#include "CATMMediaPixelImage.h"

struct CATMMPITypeDesc;

#include "CATLISTP_Clean.h"

#define CATLISTP_Append

#define CATLISTP_Size

#define CATLISTP_ReSize

#define CATLISTP_AppendList

#define CATLISTP_InsertAt

#define CATLISTP_Locate

#define CATLISTP_NbOccur

#define CATLISTP_RemovePosition

#define CATLISTP_RemoveAll

#define CATLISTP_Intersection

#include "CATLISTP_Declare.h"

/*

#undef CATCOLLEC_ExportedBy

#define CATCOLLEC_ExportedBy

#define CATCOLLEC_ExportedBy ExportedByCATMMediaPixelImage
*/

CATLISTP_DECLARE(CATMMPITypeDesc);

/*
#undef CATCOLLEC_ExportedBy

#define CATCOLLEC_ExportedBy
*/
#endif
