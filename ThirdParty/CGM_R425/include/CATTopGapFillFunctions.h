#ifndef CATTopGapFillFunctions_H
#define CATTopGapFillFunctions_H

#include  "CATBasicTopologicalOpe.h"

class CATGeoFactory;
class CATBody;
class CATTopData;
class CATFace;


extern "C" ExportedByCATBasicTopologicalOpe CATBody* CATTopGapFillFunctionBSD(CATGeoFactory* iFactory,
							                                            CATTopData *  iTopData,
                                                          CATBody*       iBody, 
                                                          CATBody*       iParting, 
                                                          CATFace*           iFace1,
                                                          CATFace*           iFace2);    




#endif








