/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef sharedSequence_octet_h
#define sharedSequence_octet_h

/**
 * @level Protected 
 * @usage U1
 */

#ifndef SHAREDSEQUENCE
#define SHAREDSEQUENCE(X) _SHAREDSEQUENCE_##X
#include "sequence.h"
#include "CATDataType.h"
#endif
#include "sequence_octet.h"	

class _SHAREDSEQUENCE_octet : public _SEQUENCE_octet 
  { 
  public: 
    _SHAREDSEQUENCE_octet () 
    { 
      max_ = 0 ; 
      length_ = 0 ; 
      buffer_ = 0 ;
    } 
    _SHAREDSEQUENCE_octet (CATLONG32 max, void* data) 
    { 
      max_ = max ; 
      length_ = max ; 
      buffer_ = data ; 
    } 
  
    _SHAREDSEQUENCE_octet (const _SEQUENCE_octet& from) 
    { 
      max_ = from.max() ; 
      length_ = from.length() ; 
      buffer_ = (void*) &from[0] ; 
    } 
  
    _SHAREDSEQUENCE_octet (const _SHAREDSEQUENCE_octet& from) 
    { 
      max_ = from.max_ ; 
      length_ = from.length_ ; 
      buffer_ = from.buffer_ ; 
    } 
  
    ~_SHAREDSEQUENCE_octet () 
    { 
      buffer_ = 0 ; 
    } 
  
    _SHAREDSEQUENCE_octet& operator= (const _SEQUENCE_octet& from) 
    { 
      max_ = from.max() ; 
      length_ = from.length() ; 
      buffer_ = (void*) &from[0] ; 
      return *this ; 
    } 
  
    _SHAREDSEQUENCE_octet& operator= (const _SHAREDSEQUENCE_octet& from) 
    { 
      if(&from!=this) 
      { 
        max_ = from.max_ ; 
        length_ = from.length_ ; 
        buffer_ = from.buffer_ ; 
      } 
      return *this ; 
    } 
  
    void initialize (CATLONG32 max, void* data) 
    { 
      max_ = max ; 
      length_ = max ; 
      buffer_ = data ; 
    } 
  
    CATLONG32 max(CATLONG32 newMax); 
  };

#endif


