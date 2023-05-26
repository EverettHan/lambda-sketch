#ifndef CATWBEditor_H
#define CATWBEditor_H

//
// Debug Editor Services for WB
//
//
//   03/12/2008     Creation                     KJD

#include "WhiteBoxUtilities.h"
#include "CATWBValue.h"
#include "CATCDSBoolean.h"
class  CATWBVariable;
class CATWBFactory;
class CATWBEquation;

class ExportedByWhiteBoxUtilities CATWBEditor
{
public:

  /* Edit a CATWBValue */
	static void EditWBValue(const CATWBValue & iValue);

   /* Edit CATWBEquation Type */
	static void EditWBEquationType(const CATWBEquation * iEqu);
	
  /* Edit a CATWBVariable */
	static void EditWBVariable(const CATWBVariable * ipVariable, CATCDSBoolean WithName =FALSE);


/* Edit all CATWBVariable  of a factory*/
	static void EditAllWBVariable(const CATWBFactory * ipFactory, CATCDSBoolean WithName =FALSE , const int NbOfEltByRow =1);

private:
  CATWBEditor();
  CATWBEditor(const CATWBEditor &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATWBEditor &);
};

#endif

