/**
 * @fullreview CMG-ERS 02:07:11
 * @error MISC  Y manque class CATString
 * @error MISC  N #include "CATCommandSet" a remplacer par class.
 * @error MISC  Y pas de constructeur par copie et pas d'operateur =
*/
#ifndef __CATECommandSet_h
#define __CATECommandSet_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATCommandSet.h"

class CATString;

extern ExportedByCATAfrFoundation IID IID_CATECommandSet;

class ExportedByCATAfrFoundation CATECommandSet : public CATBaseUnknown {
	
  CATDeclareClass;
  
public:

	CATECommandSet ();

	virtual ~CATECommandSet ();
	
	virtual HRESULT EnumTopics    (
		CATListOfCATString     & ioTopics
		);
	
	virtual HRESULT GetCommandSet (
		const CATString  &  iTopic,
		CATCommandSet    ** oSet
		);
  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATECommandSet (const CATECommandSet &);
  CATECommandSet & operator= (const CATECommandSet &);
	
};


#endif
