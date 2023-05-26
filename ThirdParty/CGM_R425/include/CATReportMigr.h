/**
 * @level Protected
 * @usage U1
 */
#ifndef CATReportMigr_H
#define CATReportMigr_H

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "AC0CATNAV.h"

class ExportedByAC0CATNAV CATReportMigr : public CATBaseUnknown
{
 public:
//  CATDeclareClass ;
  
  CATReportMigr(); // Default constructor
  virtual ~CATReportMigr(); // Destructor
  
  // ------------------------------------------------------------------------
  // Implementations de l interface CATIReportableInterface
  // ------------------------------------------------------------------------
	// Le char* rendu a ete alloue par un new char[73]
	// Il faut donc faire un delete[] des que possible
  virtual char* GetName(void) ;

  virtual CATUnicodeString GetType();
  virtual char* GetId(void);
  // Dot Not Overload 
  CATListOfCATUnicodeString  GetResult();
  void SetResult( CATListOfCATUnicodeString ListOfResult );
  CATListOfCATUnicodeString  GetMoreInfo();
  void SetMoreInfo( CATListOfCATUnicodeString ListOfInfo );

 private:
  // Resultat de la migration V4->V5
  CATListOfCATUnicodeString _ListOfResult;
  // Informations dans le cas ou il y a eu un probleme durant la migration
  CATListOfCATUnicodeString _ListOfInfo;

}; 

//==================================================================
//
#endif
