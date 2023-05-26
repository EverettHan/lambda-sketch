/**
 * @fullreview ERS-CVE 01:09:06
 * @error MISC N err_1 const par defaut, copy constr et operateur = manquent
 * @error MISC Y err_2 includes CATString
*/

#ifndef CATCommandHeaderWithEditor_h
#define CATCommandHeaderWithEditor_h
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: Special header giving the availability of commands 
//           This header subscribes to the Editor existence to
//           show the Command availability 
//-----------------------------------------------------------------------------
// Inheritance: CATCommandHeaderWithEditor
//                CATCommandHeader
//                  CATCallbackManager (System framework)
//-----------------------------------------------------------------------------
#include "CATAfrFoundation.h"
#include "CATCommandHeader.h"

#include "CATString.h"

class CATFrmLayout;

class ExportedByCATAfrFoundation CATCommandHeaderWithEditor : public CATCommandHeader

{
  CATDeclareKindOf;

 public:
  

  CATCommandHeaderWithEditor (const CATString & HeaderID,
		              int state = CATFrmAvailable);

  CATCommandHeaderWithEditor (const CATString & HeaderID,
	   	              const CATString & loadName,
		              int state = CATFrmAvailable);

  CATCommandHeaderWithEditor (const CATString & HeaderID,
	   	              const CATString & loadName,
		              const CATString & argument,
		              int state = CATFrmAvailable);

  CATCommandHeaderWithEditor (const CATString & HeaderID,
	   	              const CATString & loadName,
		              const CATString & classname,
			      void * argument,
		              int state = CATFrmAvailable);

  
  virtual ~CATCommandHeaderWithEditor ();
  
  virtual CATCommandHeader * Clone ();

  virtual void CheckEditor() ;
  
 protected:

  CATCommandHeaderWithEditor (CATCommandHeader * header);
  
 private:

//  void CheckEditorCB(CATCallbackEvent , void * , CATNotification * ,
//                        CATSubscriberData , CATCallback);

  void Init();

  CATFrmLayout *_frmLayout;
  
  CATDeclareHeaderResources;
};

#endif
