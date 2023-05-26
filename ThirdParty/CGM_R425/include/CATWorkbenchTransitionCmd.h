/**
 * @fullreview ERS-CVE 02:02:12
 * @error MISC Y manque include CATString et class CATNotification
 * @error UDOO Y pas de constructeur par defaut, par copie, pas d'operateur =
 */
#ifndef __CATWorkbenchTransitionCmd_h
#define __CATWorkbenchTransitionCmd_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATAfrFoundation.h"
#include "CATCommand.h"
#include "CATListOfCATUnicodeString.h"
#include "CATString.h"

class CATNotification;

/** 
 * 
 * Command to perform a workbench transtion.
 * <b>Role:</b>
 * Its constructor expects the name of a target
 * workbench. 
 */

class ExportedByCATAfrFoundation CATWorkbenchTransitionCmd: public CATCommand {

  /** @nodoc */
  CATDeclareClass;

public:

  /**
   * Constructor with the passed target workbench.
   * @aparam iWorkbenchName
   *  Name of the target workbench 
   */
  CATWorkbenchTransitionCmd (const CATString & iWorkbenchName);

  virtual ~CATWorkbenchTransitionCmd ();


   /** 
   * @nodoc 
   * Do the workbench transition
   */
  virtual CATStatusChangeRC Activate (CATCommand *,CATNotification *);

protected:
   /** 
   * @nodoc 
   */
  CATString  _workbenchName;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATWorkbenchTransitionCmd ();
  CATWorkbenchTransitionCmd (const CATWorkbenchTransitionCmd &);
  CATWorkbenchTransitionCmd & operator= (const CATWorkbenchTransitionCmd &);

};

#endif//__CATWorkbenchTransitionCmd_h
