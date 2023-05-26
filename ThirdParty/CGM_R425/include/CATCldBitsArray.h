//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2003
//==============================================================================================================
// CATCldBitsArray :
// Bits array management.
//==============================================================================================================
// 12-May-2016 : JLH : Changement d'include "memory.h -> string.h" pour la déclaration de 'memset'.
//                     Suppression de l'include de "stddef.h" car NULL est aussi défini dans "string.h"
// 14-Dec-2005 : JLH : Changement d'include "string.h -> stddef.h" pour la définition de NULL.
// 16-Dec-2003 : TTD : On remplace Status par State dans GetBitState (pb compile unix !?)
// 04-Sep-2003 : JLH : Ajout des services : GetSize, SetAllBistState, Next et Prev.
//                     Toutes les variables en "unsigned".
// 10-Apr-2003 : JLH : Creation.
//==============================================================================================================

#ifndef CATCldBitsArray_H
#define CATCldBitsArray_H

/**
 * DSECAAFutureExposure_Level L1
 * DSECAAFutureExposure_Usage U3
 */

#include "ExportedByCATCloudBasicResources.h"

#include "CATBooleanDef.h"
#include "string.h" // For NULL definition et 'memset' declaration.

class ExportedByCATCloudBasicResources CATCldBitsArray
{
public:

  CATCldBitsArray() ;

  virtual ~CATCldBitsArray() ;

  /**
   * Allocates and initializes the internal bits array.
   * @param iSize
   * The number of bits to manage.
   * @param iInitState
   * The initial state for all the bits.
   * @return
   * <ul>
   * <li><tt>TRUE</tt> : the allocation has been successful.
   * <li><tt>FALSE</tt> : otherwise.
   * </ul>
   */
  inline boolean SetSize (const unsigned int iSize, const boolean iInitState = FALSE) ;

  /**
   * Gets the size of the bits array.
   * @return
   * The size of the bits array.
   */
  inline unsigned int GetSize () ;

  /**
   * Sets all the bits to the given state.
   * @param iState
   * The state for all the bits.
   */
  inline void SetAllBitsState (const boolean iState = FALSE) ;

  /**
   * Sets the state of the <tt>iNoBit</tt>'th bit.
   * @param iNoBit
   * The bit number to set. It must be in the range <tt>[1,Size]</tt>.
   * @param iState
   * The desired state :
   * <ul>
   * <li><tt>TRUE</tt> : sets the bit value to <tt>1</tt>.
   * <li><tt>FALSE</tt> : sets the bit value to <tt>0</tt>.
   * </ul>
   */
  inline void SetBitState (const unsigned int iNoBit, const boolean iState = TRUE) ;

  /**
   * Gets the state of the <tt>iNoBit</tt>'th bit.
   * @param iNoBit
   * The bit number to get. It must be in the range <tt>[1,Size]</tt>.
   * @return
   * <ul>
   * <li><tt>TRUE</tt> : if the bit value is <tt>1</tt>.
   * <li><tt>FALSE</tt> : if the bit value is <tt>0</tt>.
   * </ul>
   */
  inline boolean GetBitState (const unsigned int iNoBit) ;

  /**
   * Gets the next bit set to the given state after the <tt>iNoBit</tt>'th bit.
   * @param iNoBit
   * The bit number from which the research begin.<br>
   * If <tt>0</tt> , it searchs for the first bit.
   * @return
   * <ul>
   * <li>The number of the bit which has the given state.
   * <li><tt>0</tt> if there is no more bit set to this state.
   * </ul>
   */
  unsigned int Next (const unsigned int iNoBit, const boolean iState = TRUE) ;

  /**
   * Gets the previous bit set to the given state before the <tt>iNoBit</tt>'th bit.
   * @param iNoBit
   * The bit number from which the research begin.<br>
   * If <tt>Size+1</tt>, it searchs for the last bit.
   * @return
   * <ul>
   * <li>The number of the bit which has the given state.
   * <li><tt>0</tt> if there is no more bit set to this state.
   * </ul>
   */
  unsigned int Prev (const unsigned int iNoBit, const boolean iState = TRUE) ;

private:

  unsigned char* _Bits ;
  unsigned int   _Size ;

} ;

//--------------------------------------------------------------------------------------------------------------
// Function : SetSize
// Purpose  : Allocates and initializes the internal bits array.
//--------------------------------------------------------------------------------------------------------------

inline boolean CATCldBitsArray::SetSize (const unsigned int iSize, const boolean iInitState)
{
  if (_Bits) {
    delete [] _Bits ;
    _Bits = NULL ;
  }
  _Size = iSize ;
  if (_Size > 0) {
    unsigned int Size = _Size/8 + 1 ;
    _Bits = new unsigned char [Size] ;
    if (!_Bits) return FALSE ;
    unsigned char State = iInitState ? 0xFF : 0x00 ;
    memset (_Bits, State, Size * sizeof (unsigned char)) ;
  }
  return TRUE ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetSize
// Purpose  : The size of the bits array.
//--------------------------------------------------------------------------------------------------------------

inline unsigned int CATCldBitsArray::GetSize ()
{
  return _Size ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetAllBitsState
// Purpose  : Sets all the bits to the given state.
//--------------------------------------------------------------------------------------------------------------

inline void CATCldBitsArray::SetAllBitsState (const boolean iState)
{
  if (_Bits && _Size > 0) {
    unsigned int Size = _Size/8 + 1 ;
    unsigned char State = iState ? 0xFF : 0x00 ;
    memset (_Bits, State, Size * sizeof (unsigned char)) ;
  }
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetBitState
// Purpose  : Sets the state of the iNoBit'th bit.
//--------------------------------------------------------------------------------------------------------------

inline void CATCldBitsArray::SetBitState (const unsigned int iNoBit, const boolean iState)
{
  if (!_Bits)                       return ;
  if (iNoBit < 1 || iNoBit > _Size) return ;

  int NoBit = iNoBit - 1 ;
  if (iState) {
    _Bits[NoBit/8] |=  (1<<(NoBit%8)) ;
  } else {
    _Bits[NoBit/8] &= ~(1<<(NoBit%8)) ;
  }
}

//--------------------------------------------------------------------------------------------------------------
// Function : GetBitState
// Purpose  : Gets the state of the iNoBit'th bit.
//--------------------------------------------------------------------------------------------------------------

inline boolean CATCldBitsArray::GetBitState (const unsigned int iNoBit)
{
  if (!_Bits)                       return FALSE ;
  if (iNoBit < 1 || iNoBit > _Size) return FALSE ;

  boolean State = FALSE ;
  int NoBit = iNoBit - 1 ;
  State = (_Bits[NoBit/8] & (1<<(NoBit%8))) == 0 ? FALSE : TRUE ;
  return State ;
}

#endif
