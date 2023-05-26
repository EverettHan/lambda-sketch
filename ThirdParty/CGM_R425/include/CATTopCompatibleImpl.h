/**
 * @COPYRIGHT DASSAULT SYSTEMES 2007
 */

/* -*-C++-*- */

#ifndef __CATTopCompatibleImpl_H__
#define __CATTopCompatibleImpl_H__

// COPYRIGHT DASSAULT SYSTEMES 2007

//===========================================================================
// Operator for compatible boolean union of two bodies.
//===========================================================================

#include "ExportedByPBELight.h"
#include "CATTopCompatible.h"
#include "CATTopCompatibleCGM.h"

#include "CATCGMVirtualMacros.h"
#include "CATDataType.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATTopCompatibleCGM;

/**
 * Class representing the topological operator which performs a compatible Boolean union of bodies.
 * <ul>
 * <li>Create it with the <tt>CATCreateTopCompatibleForCGM</tt> or <tt>CATCreateTopCompatibleForCVM</tt> global function.
 * <li>Run it ( only one time ).
 * <li>Get the resulting body with the <tt>GetResult</tt> method. 
 * If you do not want to keep this resulting body, 
 * use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 * <li>Delete it after use with the usual C++ delete operator. 
 * </ul>
*/
class ExportedByPBELight CATTopCompatibleImpl : public CATTopCompatible
{
  CATCGMVirtualDeclareClass(CATTopCompatibleImpl);
public:

  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopCompatibleForCGM</tt>  or <tt>CATCreateTopCompatibleForCVM</tt> to create a
  * <tt>CATTopCompatible</tt>.
  */
  CATTopCompatibleImpl(CATGeoFactory * iFactory,
									 CATTopData    * iTopData,
                   CATTopCompatibleCGM * iExtensible);

  /**
  * Destructor.
  */
  virtual ~CATTopCompatibleImpl();

  /**
   * Activates suppress mode : in the case of a failure to integrate a body,
   * the operation continues with the remaining bodies. Any bodies which were
   * not integrated on the first pass get integrated together (where possible)
   * The results are returned as multiple bodies, with their own journals.
   * <br> This option is not activated by default. If activated, NonManifold
   * results <b>must</b> be authorised.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> Throw an error if a compatible operation fails.
   *     <dt><tt>1</tt><dd> Continue on error, and return multiple bodies</dl>
   */
  virtual void SetSuppressMode(int iSuppressMode = 1);

  /**
  * Returns the suppress mode.
  * @return
  * <br><b>Legal values</b>:
  * <dl><dt><tt>0</tt><dd> suppress mode not active.
  *     <dt><tt>1</tt><dd> suppress mode is active.</dl>
  */
  virtual int  GetSuppressMode() const ;
  
  /**
  * @nodoc
  * Activate or deactivate  the imprint follow up mode.
  */
  virtual void SetImprintFollowUpMode(CATBoolean iImprintFollowUpMode);

  /**
  * @nodoc
  * Check if the imprint follow up mode is active or not.
  */
  virtual CATBoolean GetImprintFollowUpMode() const;

  /**
  * @nodoc
  * Activate or deactivate the volume journal mode.
  */
  virtual void SetVolumeJournalMode(CATBoolean iVolumeJournalMode);

  /**
  * @nodoc
  * Check if the volume journal mode is active or not.
  */
  virtual CATBoolean GetVolumeJournalMode() const;

  /** @nodoc  */
  virtual CATCellManifoldsManager* CreateCellManifoldsManager(ListPOfCATBody& iListOfCopyInputBodies, ListPOfCATBody& iListOfNoCopyInputBodies,
    CATBody* iOutputBody, CATCGMJournalList* iTopOpJournal);

  //=========================
  // methods for CGM Replay 
  //=========================
  static const CATString* GetDefaultOperatorId() {return  CATTopCompatibleCGM::GetDefaultOperatorId(); }
  //=========================
  //  Stream
  //=========================
  void AuthoriseInvalidResults(CATBoolean);
  void DoCheckValidityOfResultBodies(CATBoolean);
//  CATLONG32 GetNumCur();
  void SetOldSubdivide(int iOld);
protected :

  //========================================================
  // Methods for CGM Replay.
  //========================================================

  int                RunOperator();

  const  CATString* GetOperatorId();

  CATExtCGMReplay* IsRecordable(short& LevelOfRuntime, short& VersionOfStream);


};

#endif
