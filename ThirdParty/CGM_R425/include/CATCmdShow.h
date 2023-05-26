#ifndef CATCmdShow_H
#define CATCmdShow_H

/**
*  @quickReview  WV3 QJO 17:09:14 IR-533933: Added a variable to check collab session.
*  @quickReview  FBJ 02:07:17
*  @quickReview  CDT 02:08:02
*/


// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
// Class  :     CATCmdShow
// Author :     CDT
// Date   :     March 1999
//------------------------------------------------------------------------------
// Abstract:    This command puts objects in show/noshow
//
// Info:        this command is Action/Object or Object/Action
//          
// Algorithm :   
//      
// History :
//      March 99 -- creation
//      Nov   99 -- add specific behavior depending on the Workbench
//------------------------------------------------------------------------------

#include "CATVisCommands.h"

#include "CATStateCommand.h"
#include "CATShowAttribut.h"
#include "CATShowAttribut.h"

#include "CATIAV5Level.h"

// IR 394262 10 Aug 16 To check V5 data in V6 
#include "CATBoolean.h"
#include "CATOmbRepRefSessionService.h"
#include "CATDocument.h"
#include "CATOmbAccessV5INV6Data.h"

class CATCommandGlobalUndo;
class CATPathElementAgent;
class CATSO;
class CATVisDataForShowNoshowUndo;
class CATPathElement;
class CATISelectShow;
class CATIVisProperties;
class CATProcessShowData;

class ExportedByCATVisCommands CATCmdShow : public CATStateCommand
{
  CATDeclareClass;
  DeclareResource(CATCmdShow, CATStateCommand)

public:

  /**
  * Constructor
  * iType = input string 
  *   "contextual" = use this type if show/noshow cmd is triggered by the MB3 action.
  *   "batch"      = use this type when using this command for non interactive purpose
  */
  CATCmdShow(CATString* iType);

  /** Destructor */
  virtual ~CATCmdShow();

  /** Sets the informations for non interactive use of the command
  * iSo = set of CATPathElement
  * iShowAttribut = requested show/noshow State
  */
  void SetPathAndState(CATSO *iSo, CATShowAttribut iShowAttribut);

  CATCommandGlobalUndo * GetGlobalUndo ();
  static void Undo( void * );
  static void Redo( void * );
  static void Clean( void *);

  virtual CATStatusChangeRC Cancel( CATCommand * iFromClient,CATNotification * iNotification);

  void RepeatCommand();


private:
  struct CATProcessShowData
  {
    CATBaseUnknown*     _elem; 
    CATPathElement*     _path; 
    CATISelectShow*     _ptrToSS;
    CATIVisProperties*  _ptrToVP;
    CATBaseUnknown*     _elemPLMObj; // for Feature otherwise NULL;
    int                 _postProcessFlag;
    int                 _indexDirty;
  };

  void BuildGraph();
  boolean Select(void *);

  void InitWithWorkShop(IID& oIIDSelectShow, 
    IID& oIIDSelectShowUIActive,
    int& oSendNotifOptim);

  void GenerateVB(CATCmdShow::CATProcessShowData* iShowAttributes, int iSize, CATShowAttribut iShowAtt,
    HRESULT iRcEdit, CATListOfInt& iIsEditable);

  int IsDirtyElem(CATBaseUnknown* iElem) const;

  // IR 394262 10 Aug 16 To check V5 data in V6 
  CATBoolean IsFeatureFromV5Native(const CATILinkableObject_var & iSpec);

  /**
  * @param oRepRef [out, IUnknown#Release]
  */
  HRESULT GetRepRefFromFeature(CATBaseUnknown * ipUnkObject, CATBaseUnknown *& oRepRef);

  // trace
  static void TraceBeginShow(CATPathElement* iPath);
  static void TraceBeginUndo();
  static void TraceStateShow( const CATShowAttribut& iShowAttr);
  static void TraceElemShow(CATBaseUnknown* iElem, const CATShowAttribut& iShowAttr);
  static void TraceNotifShow(CATBaseUnknown* iPtrToModelEvents);

  //data which hold in the pathelements we have changed : useful for Undo/Redo
  CATVisDataForShowNoshowUndo* _undoData;
  CATPathElementAgent*         _objectAct;

  CATPathElement*         _pathElement;
  // set of PathElement that you can pass to the command. 
  // this data set is to be used for non interactive command.
  CATSO *                 _pSetOfPath;
  // the state to which objects have to be turned into from user request.
  CATShowAttribut         _RequestedShowState;
	CATBoolean              _CollabSession;
};


#endif
