// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPPath.h
//
//===================================================================
//
// Usage notes: A configuration path in the nD Path Planning solver
// CATPolyPathPlanningSolver. Made of a list of configurations
// (positions of one or many objects in a space). These configurations
// can be valid (no clash between any coupl of objects in the scene)
// or not, depending on a clash solver.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
//===================================================================

#ifndef CATPolyPPPath_HH
#define CATPolyPPPath_HH

#include <string>

#include "PolyPathPlanning.h"
#include "CATListPV.h"
#include "CATMathInline.h"

#include "CATPolyPPPosition.h"


/** Class designed to store a list of CATPolyPPPosition's, that is, a
 *  list of configurations that define a path (a track) in the Path
 *  Planning solver.
 */
class ExportedByPolyPathPlanning CATPolyPPPath
{
public:
  CATPolyPPPath();

  CATPolyPPPath( const CATPolyPPPath& iOther );

  ~CATPolyPPPath();

  /** Gives the size of the list, that is the number of configurations
   *  contained in the path.
   * @return The size of the list of configuration.
   */
  INLINE int Size() const;
  /** Append a configuration at the end of the path. A reference is
   *  added inside allowing the user to release it outside.
   * @param iPosition: The configuration to append to the list.
   */
  INLINE void Append(CATPolyPPPosition * iPosition);
  /** Insert a configuration in the list at the given position,
   *  starting at 1 and ending at Size(). A reference is added inside
   *  allowing the user to release it outside.
   * @param iPosition: The configuration to append to the list.
   * @param iPos: the position where the configuration must be in the
   * list after the insertion.
   */
  INLINE void Insert(CATPolyPPPosition * iPosition, unsigned int iPos);
  /** Remove the configuration at the given position in the list.
   * @param iPos: the current position of the configuration to
   * remove. The configuration is deleted at the same time.
   */
  void Remove(unsigned int iPos);
  /** Empty the list. Deletes all the configurations in it.
   */
  void Empty();

  /** Access to a configuration in the list.
   * @param iPos: position, in the range [1;Size()], of the
   * configuration one want to access.
   * @return The configuration at position iPos.
   */
  INLINE CATPolyPPPosition *& operator [](unsigned int iPos);
  /** Read only access to a configuration in the list.
   * @param iPos: position, in the range [1;Size()], of the
   * configuration one want to access.
   * @return The configuration at position iPos.
   */
  INLINE const CATPolyPPPosition * operator [](unsigned int iPos) const;

private:

    CATPolyPPPath& operator=( const CATPolyPPPath& iOther );

  CATListPV _Positions;
};

INLINE int CATPolyPPPath::Size() const
{
  return _Positions.Size();
}

INLINE void CATPolyPPPath::Append(CATPolyPPPosition * iPosition)
{
  if (iPosition) {
    iPosition->AddRef();
    _Positions.Append((void *) iPosition);
  }
}

INLINE void CATPolyPPPath::Insert(CATPolyPPPosition * iPosition, unsigned int iPos)
{
  if (iPosition) {
    iPosition->AddRef();
    _Positions.InsertAt(iPos, (void *) iPosition);
  }
}

INLINE CATPolyPPPosition *& CATPolyPPPath::operator [](unsigned int iPos)
{
  return (CATPolyPPPosition *&) _Positions[iPos];
}

INLINE const CATPolyPPPosition * CATPolyPPPath::operator [](unsigned int iPos) const
{
  return (const CATPolyPPPosition *) _Positions[iPos];
}


//__________________________________________________________________________________________________
//services associate to PPPath
class DSYSysJSONValue;

void DSYExport CATPolyPPPathLoadFromJson(std::string filename,CATPolyPPPath & ioPathToFill,const CATPolyPPCartesianProduct &iSpace);
void DSYExport CATPolyPPPathLoadFromJson(DSYSysJSONValue &json,CATPolyPPPath & ioPathToFill,const CATPolyPPCartesianProduct &iSpace);
void DSYExport CATPolyPPPathSaveToJson(DSYSysJSONValue &oJson,const CATPolyPPPath & iPathToSave);
void DSYExport CATPolyPPPathSaveToJson( std::string iJsonfile, const CATPolyPPPath &iPathToSave);

#endif
