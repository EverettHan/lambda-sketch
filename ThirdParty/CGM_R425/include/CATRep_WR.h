/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2002
#ifndef CATRep_WR_h
#define CATRep_WR_h

#ifndef NULL
#define NULL 0
#endif

#include "SGInfra.h"
class CATRepWeakRef;
class CATRep;

/**
 * Handler on a @href CATRepWeakRef. 
 * This is designed to make easier the use of the weak references on the @href CATRep.
 */
class ExportedBySGInfra CATRep_WR
{
public:

  CATRep_WR( CATRep * iRep=NULL );
  CATRep_WR( const CATRep_WR & iwrRep );
  ~CATRep_WR( void );

  const CATRep_WR & operator =( const CATRep_WR & iwrRep );
  const CATRep_WR & operator =( CATRep * iRep );
  int operator !( void ) const;
  int operator ==( CATRep * iRep ) const;
  int operator !=( CATRep * iRep ) const;

/**
 * Returns the referenced rep. 
 * Returns NULL if the rep was destroyed.
 * Lifecycle deviation: Release isn't to be called on the returned @href CATRep.
 * @return
 * Un <tt>CATRep *</tt>
 */
  CATRep * GiveRep( void ) const;

private:

  CATRepWeakRef * _WeakRef;
};
#endif
