#ifndef CGMPartIncrementalOpen_h
#define CGMPartIncrementalOpen_h

// COPYRIGHT DASSAULT SYSTEMES  2001
#include "CGMV5Interop.h"
#include "CGMIncrementalOpen.h"
#include "CATCGMNewArray.h"
#include "CATWTypes.h"

class CATStorage;
class CATUnicodeString;
class CATCGMStream;
class CATStreamArea;

//===================================================================================================
//  Le proxy d'implementation du fichier NCGM
//===================================================================================================
class ExportedByCGMV5Interop CGMPartIncrementalOpen : public CGMIncrementalOpen
{
public :
  CGMPartIncrementalOpen(const char iFilename[]); // Bidouille
  CGMPartIncrementalOpen(CATGeoFactory* iFactory, const char  iFilename[]); // Bidouille

  // Officiel pour gestion Light Brep Mode en chargement du Dual
  CGMPartIncrementalOpen(CATGeoFactory* iFactory, CATStreamArea *iPartStreamArea);

  virtual ~CGMPartIncrementalOpen();
  CATCGMNewClassArrayDeclare;

  virtual void Open  ( CATGeoFactory* &ioFactory, CATCGMListOfCATULONGPTR &ioObjects );
  virtual void Append( CATGeoFactory*  iFactory,  CATCGMListOfCATULONGPTR &ioObjects );

private :

  void CommonBidouille( const char iFilename[], CATGeoFactory* &ioFactory, CATCGMListOfCATULONGPTR &ioObjects );

  int SearchOpen(CATUnicodeString         &StreamName, 
                 CATStorage*               storage, 
                 DWORD                     Open_Mode, 
                 CATUnicodeString         &curName, 
                 CATGeoFactory*           &ioFactory,
                 CATCGMListOfCATULONGPTR  &ioObjects,
                 int                      &iCommonReadIsOkay);

  CATStreamArea *_PartStreamAreaToDelete;

};

#endif
