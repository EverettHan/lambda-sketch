// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVizDiagnosis
//
//===================================================================
//
// December 2010  Creation: NDO
//===================================================================
#ifndef CATPolyBodyVizDiagnosis_H
#define CATPolyBodyVizDiagnosis_H

#include "PolyVizAdapters.h"
#include "CATPolyBodyRepDiagnosis.h"

class CATVizPrimitive;


/**
Class used for logging errors occurring during construction of a CATPolyBody from visualization reps.
*/
class ExportedByPolyVizAdapters CATPolyBodyVizDiagnosis : public CATPolyBodyRepDiagnosis
{

public:

  /**
   * Constructor.
   */
  CATPolyBodyVizDiagnosis ();

  ~CATPolyBodyVizDiagnosis ();

public:

  /**
   * Logs an error for a primitive.
   * The methods may be called several times for the same primitive if different errors are encountered.
   */
  HRESULT LogError (CATVizPrimitive* iPrimitive, Error iError);

public:

  /**
   * Returns the error code associated to the primitive.
   */
  int GetError (CATVizPrimitive* iPrimitive) const;

public:

  /**
   * Iterator.  
   * Cycles through all the errors that are logged.
   */
  class ExportedByPolyVizAdapters Iterator
  {
  public:
    Iterator (const CATPolyBodyVizDiagnosis& iDiagnosis) : _It (iDiagnosis._PrimitiveToError) {}
    ~Iterator () {}

    /**
     * Given an iterator, returns a CATVizPrimitive.
     */
    CATVizPrimitive* GetPrimitive () const;

    /**
     * Given an iterator, returns an error.
     */
    int GetError () const;

    /**
     */
    Iterator& Begin () {_It.Begin (); return *this;}

    /**
     */
    CATBoolean End () const {return _It.End ();}

    /**
     */
    Iterator& operator++ () {++_It; return *this;}

  private:
    CATMapOfPtrToInt::Iterator _It;
  };

  friend class Iterator;

public:

  CATPolyBodyVizDiagnosis* CastAsVizPrimitiveDiagnosis ();
  const CATPolyBodyVizDiagnosis* CastAsVizPrimitiveDiagnosis () const;

  CATPolyBodyGPDiagnosis* CastAsGraphicPrimitiveDiagnosis ();
  const CATPolyBodyGPDiagnosis* CastAsGraphicPrimitiveDiagnosis () const;

};

#endif // !CATPolyBodyVizDiagnosis_H
