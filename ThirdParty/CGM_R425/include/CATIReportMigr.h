/**
 * @level Protected
 * @usage U5
 */
//==================================================================
//
//  Interface: CATIReportMigr
//
//  scz - decembre 1999
//      Interface pour la migration des elements V4
//
//
//==================================================================
//
#ifndef _CATIReportMigr_H
#define _CATIReportMigr_H
//
//==================================================================
// 1. Heritage
#include "CATBaseUnknown.h"
//
// 2. Pour NT 
#include "AC0CATNAV.h"
//
// 3. Les parametres des methodes
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
//
//==================================================================

extern ExportedByAC0CATNAV IID IID_CATIReportMigr;

class ExportedByAC0CATNAV CATIReportMigr : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Returns the name of the element. 
  virtual char* GetName() const = 0;
  
  // Returns the type of the element.
  virtual CATUnicodeString GetType () const = 0;
  
  // Returns the identificator of the element.
  virtual char* GetId() const = 0;

  // Returns the result of migration
  virtual CATListOfCATUnicodeString GetResult() const = 0;
 
   // Store the result of migration
  virtual void SetResult( CATListOfCATUnicodeString ListOfResult ) const = 0;

  // Returns Informations in case of problems during migration
  virtual CATListOfCATUnicodeString GetMoreInfo() const = 0;
 
   // Store Informations in case of problems during migration
  virtual void SetMoreInfo( CATListOfCATUnicodeString ListOfInfo ) const = 0;
};
CATDeclareHandler(CATIReportMigr,CATBaseUnknown);

#endif





