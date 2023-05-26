#ifndef CATCommandHeaderWithCSO_h
#define CATCommandHeaderWithCSO_h
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: Special header giving the availability of commands 
//           This header subscribes to the CSO modification to
//           show the Command availability 
//-----------------------------------------------------------------------------
// Inheritance: CATCommandHeaderWithCSO
//                CATCommandHeader
//                  CATCallbackManager (System framework)
//-----------------------------------------------------------------------------
#include "CATAfrFoundation.h"
#include "CATCommandHeader.h"
#include "CATCSO.h"

class ExportedByCATAfrFoundation CATCommandHeaderWithCSO : public CATCommandHeader

{
  CATDeclareKindOf;

 public:
  

  CATCommandHeaderWithCSO(const CATString & HeaderID,
			  int state = CATFrmAvailable);

  CATCommandHeaderWithCSO(const CATString & HeaderID,
			  const CATString & loadName,
			  int state = CATFrmAvailable);

  CATCommandHeaderWithCSO(const CATString & HeaderID,
			  const CATString & loadName,
			  const CATString & argument,
			  int state = CATFrmAvailable);

  CATCommandHeaderWithCSO(const CATString & HeaderID,
			  const CATString & loadName,
			  const CATString & classname,
			  void * argument,
			  int state = CATFrmAvailable);

  
  virtual ~CATCommandHeaderWithCSO ();
  
  virtual CATCommandHeader * Clone ();

  virtual void CheckCSO(CATCSO *) ;
  
 protected:

  CATCommandHeaderWithCSO (CATCommandHeader * header);
  
 private:

  void CheckCSOCB(CATCallbackEvent , void * , CATNotification * ,
                        CATSubscriberData , CATCallback);

  void Init();

  CATCSO *_CSO;
  
  CATDeclareHeaderResources;
};

#endif
