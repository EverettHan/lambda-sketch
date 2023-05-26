// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyGPDiagnosis
//
//===================================================================
//
// December 2010  Creation: NDO
//===================================================================
#ifndef CATPolyBodyGPDiagnosis_H
#define CATPolyBodyGPDiagnosis_H

#include "PolyVizAdapters.h"
#include "CATPolyBodyRepDiagnosis.h"

class CATGraphicPrimitive;


/**
Class used for logging errors occurring during construction of a CATPolyBody from visualization reps.
*/
class ExportedByPolyVizAdapters CATPolyBodyGPDiagnosis : public CATPolyBodyRepDiagnosis
{

public:

  /**
   * Constructor.
   */
  CATPolyBodyGPDiagnosis ();

  ~CATPolyBodyGPDiagnosis ();

public:

  /**
   * Logs an error for a primitive.
   * The methods may be called several times for the same primitive if different errors are encountered.
   */
  HRESULT LogError (CATGraphicPrimitive* iPrimitive, Error iError);

public:

  /**
   * Returns the error code associated to the primitive.
   */
  int GetError (CATGraphicPrimitive* iPrimitive) const;

  void Dump (CATCGMOutput &iWhereToWrite) const;

public:

  /**
   * Iterator.  
   * Cycles through all the errors that are logged.
   */
  class ExportedByPolyVizAdapters Iterator
  {
  public:
    Iterator (const CATPolyBodyGPDiagnosis& iDiagnosis) : _It (iDiagnosis._PrimitiveToError) {}
    ~Iterator () {}

    /**
     * Given an iterator, returns a CATGraphicPrimitive.
     */
    CATGraphicPrimitive* GetPrimitive () const;

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

#endif // !CATPolyBodyGPDiagnosis_H
