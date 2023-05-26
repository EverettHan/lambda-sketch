#ifndef CATRemoveFacesInShell_h
#define CATRemoveFacesInShell_h

// COPYRIGHT DASSAULT SYSTEMES  2003

#include "PrimitivesLight.h"
#include "CATTopOperator.h"
#include "ListPOfCATCell.h"
#include "CATMathDef.h"
#include "CATMathInline.h"

class CATGeoFactory;
class CATBody;
class CATCGMJournalList;
class CATTopData;


/** 
* Class representing the operator that creates a shell body from a list of faces
* Moreover, the operator allows the faces to have inside loops (holes).
* <br>To use the CATRemoveFacesInShell :
* <ul><li>Create the <tt>CATCreateRemoveFacesInShell</tt> global function. 
* <li>If needed, tune some parameters with the <tt>SetXxx</tt> methods. In particular, closure or internal
* loops can be described at this time.
* <li> <tt>Run</tt> the operator
* <li>Retrieve the created body (frozen by default) with the <tt>GetResult</tt> method. 
* <li>Delete with the usual C++ <tt>delete</tt> operator after use.</ul>
*/

class ExportedByPrimitivesLight CATRemoveFacesInShell : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATRemoveFacesInShell);
public:

  /**
  * @nodoc
  */
  CATRemoveFacesInShell( CATGeoFactory *iFactory,
    CATTopData * iData,
    CATBody * iBody,
    ListPOfCATCell *iFacesToRemove );

  /**
  * @nodoc
  */	
  ~CATRemoveFacesInShell();

  /**
  * @nodoc
  * Do not use, because of the instability of the result shell orientation.
  */	
  INLINE void SetUsingOrientationOFF();

  /** 
  * Runs <tt>this</tt> operator.
  */
  virtual int Run();

  /** @nodoc*/
  INLINE void SetInitialBody(CATBody * iBody);

  /** @nodoc */
  INLINE void SetFacesToRemove(ListPOfCATCell &iFacesToRemove);

  /** @nodoc @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  const CATString * GetOperatorId();

  /** @nodoc @nocgmitf */
  static const CATString *GetDefaultOperatorId() { return &_OperatorName; }

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& os ) ;

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void ReadInput(CATCGMStream  & ioStream, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual int RunOperator();


private :
  // Operator generic name for the CGMReplay
  static CATString _OperatorName;

  // data
  CATBody *_InitialBody;
  CATLISTP(CATCell) _FacesToRemove;

  CATBoolean _UsingOrientation;
};

/**
* Creates an operator to build a new shell from an initial shell and a list of faces to remove.
* @param iFactory
* The pointer to the factory of the geometry.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside the
* configuration is <tt>NULL</tt>, it is not filled. 
* @param iBody
* The pointer to the 2D body containing the shell with faces to remove
* @param iFacesToRemove
* The pointer to the list of faces to remove in the initial shell.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/

ExportedByPrimitivesLight CATRemoveFacesInShell * CATCreateRemoveFacesInShell(
  CATGeoFactory * iFactory, 
  CATTopData    * iTopData, 
  CATBody * iBody, 
  ListPOfCATCell *iFacesToRemove );

INLINE void CATRemoveFacesInShell::SetInitialBody(CATBody * iBody) {
  _InitialBody = iBody;}

INLINE void CATRemoveFacesInShell::SetFacesToRemove(ListPOfCATCell &iFacesToRemove) {
  _FacesToRemove.Append(iFacesToRemove );}

INLINE void CATRemoveFacesInShell::SetUsingOrientationOFF() {
  _UsingOrientation = FALSE; }

#endif
