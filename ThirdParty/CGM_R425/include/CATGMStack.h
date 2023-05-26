// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : QF2
//
// DESCRIPTION  : Parent Class for all CATGMStack objects
//
//=============================================================================
// Creation QF2 June 2022
//=============================================================================

//
// Classe de structure de données de type LIFO (Last In, First Out).
// Se comporte comme un std::stack standard. 
// Chaque nouvel element est empilé sur la stack,
// on accède toujours au dernier element empilé (top). 
//
// Template afin d'éviter la multiplication du code.
//
//=============================================================================
//

#ifndef CATGMStack_H
#define CATGMStack_H

// #include "CATCGMVirtual.h"
// #include "CATListPV.h"
#include "CATGMCollection.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"
#include "CATDataType.h"

class CATCGMStream;
class CATCGMOutput;



/**
 * Class to implement a mutable list of <tt>T *</tt> pointers.
 * <b>Role</b>: The purpose of this class is to let C++ classes easily pass and
 * receive lists of <tt>T *</tt> pointers. The class handles all the low-level
 * memory allocation tasks such as reallocating the list once it capacity has
 * been exceeded. It also provides high level operations such as sorting,
 * comparison, etc... The first element has index 1.
 */

// ------------------------------------------------
// Moved and rename "CATGMStack"
// ------------------------------------------------
template <class T> 
class CATGMStack : public CATGMCollection<T> // CATCGMVirtual
{

public:  

  /*   ~ Official Constuctor ~   */
  CATGMStack();
  /* Constructor from Array */
  CATGMStack ( T * const iArray[], CATULONG32 iSize, CATBoolean iAcceptNull=TRUE);
  /* Constructor from CATLISTP)  */
  template <class CATLISTP>
  explicit CATGMStack (const CATLISTP & iListPOf, CATBoolean iAcceptNull=TRUE);
  /* Copy constructor  */
  CATGMStack(const CATGMStack<T> & iOther);

  /*   ~ Detructor     */
  virtual ~CATGMStack();
  

 /**
  *  Element access 
  * -------------------------------------------------- */
  
  // Get a pointer on the top element on the stack.
  T * Top() const;


 /**
  *  Modifiers
  * -------------------------------------------------- *
  * Pushes the given element to the top of the stack. 
  * @param iElem 
  *   The pointer value of the element to push. 
  * @param iAcceptNull
  *   <tt>iElem</tt> can be null. 
  * @return 
  *   0 if success, 1 otherwise.
  */
#if __cplusplus >= 201103L // if C++11
  virtual int Push(T * iElem, CATBoolean iAcceptNullPointer=TRUE) override; 
#else
  virtual int Push(T * iElem, CATBoolean iAcceptNullPointer=TRUE); 
#endif

  /* To benefit from CATGMCollection::Push(...) */
  using CATGMCollection<T>::Push;

 /** Removes the top element from the stack
  *  @return 
  *     the removed <tt>T *</tt> element - it can be null.
  */
  virtual T * Pop(); // overload



// ------------------------------------------------------------------------------------
// Debug && Stream methods
// ------------------------------------------------------------------------------------ 

  // Open Write/Read
  HRESULT Write(CATCGMStream & ioStr, HRESULT(*iFunct_Write)(CATCGMStream &, const T *) ) const;
  HRESULT Read (CATCGMStream & iStr,  HRESULT(*iFunct_Read)(CATCGMStream &, T **) );

  // Dump 
  void    Dump(CATCGMOutput &ioOut, void(*iFunct_Dump)(CATCGMOutput &ioOut, const T *iElem), const char * iListName="GMStack") const;


private :
  
  // restricted use
  CATGMStack & operator = (const CATGMStack & iOther);

};

#include "CATGMStack.hxx"


#endif
