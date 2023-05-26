//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002
//==============================================================================================================
// Class CATCloudFilterOperator
//==============================================================================================================
// Usage Notes:
//==============================================================================================================
// 20-Mar-2003 - JLH - Ajout des points "graines".
// 10-Dec-2002 - JLH - Introduction des points ignores dans le calcul.
// 12-Nov-2002 - JLH - Creation. Factorization of several methods and data between the two operators of
//                               homogeneous and adaptative filtering.
//==============================================================================================================

#ifndef CATCloudFilterOperator_H
#define CATCloudFilterOperator_H

#include "ExportedByCATCloudBasicResources.h"
//#include "CATBooleanDef.h"
//#include "CATErrors.h"

typedef void (*IncrementFunction) () ; // ProgressBar bar

/**
 * Error class.
 */
//class CATCloudFilterOperatorError : public CATError
//{
//public:
//  CATDeclareError (CATCloudFilterOperatorError, CATError)
//} ;

/**
 * Root class for the filtering operator.
 */
class ExportedByCATCloudBasicResources CATCloudFilterOperator
{
public:

  /**
   * Constructor.<br>
   * By default, all the points are considered as filtered.
   * @param iNbPoints
   * The number of points to proceed.
   * @param iCoords
   * Their coordinates.
   * @param iMin
   * Bounding box low extremity.
   * @param iMax
   * Bounding box high extremity.
   */
  CATCloudFilterOperator (const int    iNbPoints,
                          const float* iCoords,
                          const double iMin[3],
                          const double iMax[3]) ;
  
  virtual ~CATCloudFilterOperator () ;

  /**
   * Sets the <tt>iIdx</tt>'th point as a seed ie it will set as non-filtered.
   */
  inline void SetPointAsASeed (const int iIdx) ;

  /**
   * Sets the <tt>iIdx</tt>'th point as not a seed.
   */
  inline void SetPointAsNotASeed (const int iIdx) ;

  /**
   * Is the <tt>iIdx</tt>'th point a seed or not ?
   */
  //inline boolean PointIsASeed (const int iIdx) ;
  inline int PointIsASeed (const int iIdx) ;

  /**
   * Sets the <tt>iIdx</tt>'th point as ignored ie it will not be considered during the computation.
   */
  inline void SetPointAsIgnored (const int iIdx) ;

  /**
   * Sets the <tt>iIdx</tt>'th point as non-ignored ie it will be considered during the computation.
   */
  inline void SetPointAsUnignored (const int iIdx) ;

  /**
   * Is the <tt>iIdx</tt>'th point ignored or not ?
   */
  //inline boolean PointIsIgnored (const int iIdx) ;
  inline int PointIsIgnored (const int iIdx) ;

  /**
   * Sets the increment function.
   */
  void SetIncrementFunction (IncrementFunction iIncrFnct) ;

  /**
   * Sets all the points as filtered (the default).
   */
  inline void ReInitialize() ;

  /**
   * Sets the <tt>iIdx</tt>'th point as filtered.
   */
  inline void SetPointAsFiltered (const int iIdx) ;

  /**
   * Sets the <tt>iIdx</tt>'th point as unfiltered.
   */
  inline void SetPointAsUnfiltered (const int iIdx) ;

  /**
   * Runs the computation.
   */
  virtual void Run () = 0 ;

  /**
   * Is the <tt>iIdx</tt>'th point filtered or not ?
   */
  //inline boolean PointIsFiltered (const int iIdx) ;
  inline int PointIsFiltered (const int iIdx) ;

protected:

  class ProgressBar {
  public:
    ProgressBar (int iMin, int iMax, int iNbIncr) ;
    ~ProgressBar () ;
    void Increment (const int iStep) ;
    static IncrementFunction _IncrFnct ;
  private:
    int _Min, _Max, _NbIncr, _Delta ;
  } ;

  void ImpossibleAllocation () ;

  int    _NbPoints ;
  float* _Coords ;
  double _Min[3] ;
  double _Max[3] ;
  int    _Size ;
  char*  _ToKeep ;
  char*  _Ignored ;
  char*  _Seed ;
} ;

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsASeed
// Purpose  : Sets the iIdx'th point as a seed.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsASeed (const int iIdx)
{
  if (!_Seed) {
    if (_NbPoints < 1) return ;
    _Seed = new char [_Size] ;
    if (_Seed == NULL) ImpossibleAllocation() ;
    // By default, all the points are selected.
    memset (_Seed, 0, _Size * sizeof (char)) ;
  }
  _Seed[iIdx/8] |= (1<<(iIdx%8)) ;
  SetPointAsUnfiltered (iIdx) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsNotASeed
// Purpose  : Sets the iIdx'th point as not a seed.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsNotASeed (const int iIdx)
{
  if (_Seed) _Seed[iIdx/8] &= ~(1<<(iIdx%8)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : PointIsASeed
// Purpose  : Is the iIdx'th point a seed or not ?
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudFilterOperator::PointIsASeed (const int iIdx)
{
  if (_Seed) {
    return ((_Seed[iIdx/8] & (1<<(iIdx%8))) != 0 ? 1 : 0) ;
  } else {
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsIgnored
// Purpose  : Sets the iIdx'th point as ignored.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsIgnored (const int iIdx)
{
  if (!_Ignored) {
    if (_NbPoints < 1) return ;
    _Ignored = new char [_Size] ;
    if (_Ignored == NULL) ImpossibleAllocation() ;
    // By default, all the points are selected.
    memset (_Ignored, 0, _Size * sizeof (char)) ;
  }
  _Ignored[iIdx/8] |= (1<<(iIdx%8)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsUnignored
// Purpose  : Sets the iIdx'th point as non-ignored.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsUnignored (const int iIdx)
{
  if (_Ignored) _Ignored[iIdx/8] &= ~(1<<(iIdx%8)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : PointIsSelected
// Purpose  : Is the iIdx'th point ignored or not ?
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudFilterOperator::PointIsIgnored (const int iIdx)
{
  if (_Ignored) {
    return ((_Ignored[iIdx/8] & (1<<(iIdx%8))) != 0 ? 1 : 0) ;
  } else {
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------------------
// Function : ReInitialize
// Purpose  : Sets all the points as filtered.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::ReInitialize ()
{
  memset (_ToKeep, 0, _Size * sizeof (char)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsFiltered
// Purpose  : Sets the iIdx'th point as filtered.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsFiltered (const int iIdx)
{
  _ToKeep[iIdx/8] &= ~(1<<(iIdx%8)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetPointAsUnfiltered
// Purpose  : Sets the iIdx'th point as unfiltered.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterOperator::SetPointAsUnfiltered (const int iIdx)
{
  _ToKeep[iIdx/8] |= (1<<(iIdx%8)) ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : PointIsFiltered
// Purpose  : Is the iIdx'th point filtered or not ?
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudFilterOperator::PointIsFiltered (const int iIdx)
{
  return ((_ToKeep[iIdx/8] & (1<<(iIdx%8))) == 0 ? 1 : 0) ;
}

#endif
