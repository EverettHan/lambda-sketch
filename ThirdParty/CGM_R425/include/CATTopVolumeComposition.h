#ifndef CATTopVolumeComposition_h
#define CATTopVolumeComposition_h

//==========================================================================
// Operator for "join of volumes"
//==========================================================================
// 2022/10/11   DLR6
//              Class creation
//==========================================================================


#include "ExportedByBONEWOPE.h"

#include "CATTopOperator.h"
#include "CATTopDefine.h"

class CATExtTopVolumeComposition;
class CATCGMJournalList;
class CATBody;


/**
 * Interface representing an operator that assembles several volumic bodies.
 *
 * To use it:
 *<ul>
 * <li>Create it with the <tt>CATCreateVolumeComposition</tt> global function.
 * <li>Run it
 * <li>Get the resulting body with the <tt>GetResult</tt> method. If you do not want
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the
 * geometric factory, after the operator deletion.
 *<li>delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul>
 */
class CATTopVolumeComposition : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopVolumeComposition);
public:

  virtual ~CATTopVolumeComposition();

  /**
    * Returns the pointer to the resulting body.
    * The pointer to the journal of the operation.
    * @param iJournal
    * The pointer to the journal to fill.
    * @return
    * The pointer to the resulting body. If you do not want to keep it,
    * use the @href CATICGMContainer#Remove method to remove it from the
    * geometric factory.
    */
  CATBody *             GetResult(CATCGMJournalList * ioJournal);
  CATBody *             GetResult();

  virtual void SetForcePriorityToFirstBody(CATBoolean iDoThat) = 0;
  virtual void SetVolumeJournalMode(CATBoolean iDoThat) = 0;

protected:
  CATTopVolumeComposition(
      CATGeoFactory       * ipFactory,
      CATTopData          * ipTopData,
      CATExtTopOperator   * ipExtensible);

private:
  int                     _NbGetResult; // Number of times GetResult() was called

  friend class CATExtTopVolumeComposition;
};

/**
 * Creates a CATTopVolumeComposition.
 * @param iFactory
 * The pointer to the factory of the geometry for the creation of the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param ipBodiesList
 * List of volumic bodies to join to one another
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBONEWOPE CATTopVolumeComposition * CATCreateVolumeComposition(
    CATGeoFactory       * ipFactory,
    CATTopData          * ipTopData,
    CATListPtrCATBody   * ipBodiesList);

#endif
