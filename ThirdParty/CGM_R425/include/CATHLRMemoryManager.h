/* -*-C++-*-*/
#ifndef CATHLRMemoryManager_H
#define CATHLRMemoryManager_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRMemoryManager 
//
// DESCRIPTION :
/**
  * This object handle the allocations of all the temporary objects for the hlr.
  * All these objects are deleted with this object, so that it flushes the memory
  * with all the temporary objects.
  * <BR> This file contains also an overloaded form of the operator new that uses
  * a CATHLRMemoryManager to obtain its datas.
  * <BR> The method Reset() might be used when the object has been finished used.
  * The ojbects that have allready been allocated are then lost, and the memory
  * is reused for further allocations. 
  */
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Dec. 97 JCH Creation            
// Sep. 99 HLK Added the manager name
// Juin 2002 TPD amelioration du Dump de "CATHLRMemoryManager"
// Jan. 2005 TPD On calcule le VRAI point sur l'edge (RI489565)
//
//=============================================================================

//=============================================================================
// System include
//-----------------------------------------------------------------------------
#include <stddef.h>

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRTools.h"

#include "CATCGMNewArray.h"
#include "CATDataType.h"

//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATHLRBlockAllocated;

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

struct CATHLRHeader;

//=============================================================================
// CLASS DEFINITION
//=============================================================================
class ExportedByHLRTools CATHLRMemoryManager
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default Constructor
 */
  CATHLRMemoryManager(const char *iName = "Unknown");

/**
 * Destructor
 */
  virtual ~CATHLRMemoryManager();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  //=============================================================================
  // ALLOCATION METHODS
  //=============================================================================
  /** Returns a pointer on a block of the appropriated size.
  * @iSizeInBytes : size of the block. The type size_t is defined in "stddef.h". 
  */
  virtual void * GiveBuffer(size_t iSizeInBytes);
    
  /** Resets the memory manager.
 * <BR> All the objects that have been allready allocated are lost( as deleted).
 * The memory they took is used to allocates the new objects.
 */
  void Reset();


/** For debug: dumps the informations in a stream.
 */
  void DumpStream(ostream & iStream, CATLONG32 iLevel = 0, CATLONG32 iSpace = 0);


/** For debug: dumps the informations in a the standard output.
 */
  void Dump(CATLONG32 iLevel = 0, CATLONG32 iSpace = 0);

  inline const char * GiveName() const;
  void SetName( const char * iName );
//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected :

  // First buffer.
  CATHLRHeader * _FirstBlock;

  // Current Memory Size of Allocator
  size_t   _CurrentSize;

  // Name of allocator
  char     _ManagerName[24];

};

#if defined ( _WINDOWS_SOURCE )
#define CATHLRMemoryManagerWithDelete
#else
#undef  CATHLRMemoryManagerWithDelete
#endif

//------------------------------------------------------------
// Overloaded operator new to use the CATHLRMemoryManager to 
// allocate the objects.
//------------------------------------------------------------
inline ExportedByHLRTools void * operator new (size_t iSize, CATHLRMemoryManager * iMemoryManager);
inline void * operator new (size_t Size, CATHLRMemoryManager * MemoryManager)
{
  return MemoryManager->GiveBuffer(Size);
}

//=============================================================================
// Uniquement pour eviter la TETANISATION par des message de Warning
//=============================================================================
#if defined (CATHLRMemoryManagerWithDelete )
inline  ExportedByHLRTools void operator delete (void *iBuffer, CATHLRMemoryManager * iMemoryManager);

inline void operator delete (void *iBuffer, CATHLRMemoryManager * iMemoryManager)
{
}
#endif

//=============================================================================
// For Class
//=============================================================================
#if defined ( CATHLRMemoryManagerWithDelete )

#define CATHLRMemoryManagerNewDel \
inline void * operator new (size_t Size, CATHLRMemoryManager * MemoryManager) \
{ return MemoryManager->GiveBuffer(Size); }; \
inline void operator delete (void *iBuffer, CATHLRMemoryManager * iMemoryManager) {}

#else

#define CATHLRMemoryManagerNewDel \
inline void * operator new (size_t Size, CATHLRMemoryManager * MemoryManager) \
{ return MemoryManager->GiveBuffer(Size); }

#endif

inline const char * CATHLRMemoryManager::GiveName() const
{
  return _ManagerName;
}
#endif
