/* -*-C++-*-*/
#ifndef CATHLRDebugDomain_H
#define CATHLRDebugDomain_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRDebugDomain 
//
// DESCRIPTION :
/**
 * Stream for the debug of a data.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Mar. 1998   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

#include "CATDataType.h"
// For Windows NT
#include "HLRDebug.h"

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class ExportedByHLRDebug CATHLRDebugDomain
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRDebugDomain();

//=============================================================================
// METHODS
//=============================================================================
/** Set and get the ostream used for the output.
 */
  inline ostream & GetStream() const;
  inline void SetStream(ostream * iStream);

/** Get level of debug.
 */
  inline CATLONG32 GetLevel() const;
  inline void SetLevel(CATLONG32 iLevel);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
  ostream * _Stream;
  CATLONG32      _Level;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline ostream & CATHLRDebugDomain::GetStream() const
{
  return * _Stream;
}

inline void CATHLRDebugDomain::SetStream(ostream * Stream)
{
  _Stream = Stream;
}

inline CATLONG32 CATHLRDebugDomain::GetLevel() const
{
  return _Level;
}

inline void CATHLRDebugDomain::SetLevel(CATLONG32 Level)
{
  _Level = Level;
}

#endif
