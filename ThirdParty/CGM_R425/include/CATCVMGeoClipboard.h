/* -*-C++-*- */

#ifndef CATCVMGeoClipboard_h 
#define CATCVMGeoClipboard_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATCVMGeoClipboard :
// Classe g�n�rique permettant la gestion du clipboard
//
//=============================================================================
// mars    2007  Cr�ation                    Etienne Bartholomot
//=============================================================================

#include "CATCVMGeoObjects.h"
#include "CATCVMGeoExtractData.h"

class ExportedByCATCVMGeoObjects CATCVMGeoClipboard 

{
  public:
  static HRESULT SetExtractData(CATCVMGeoExtractData * iExtractData);

  public:
  static CATCVMGeoExtractData * GetExtractData();

  public:
  static void Delete();

  private:
  CATCVMGeoClipboard();

  private:
	CATCVMGeoClipboard(const CATCVMGeoClipboard &);//Necessary to prevent unwanted automatic creation by compiler
	void operator = (const CATCVMGeoClipboard &);


};
#endif

