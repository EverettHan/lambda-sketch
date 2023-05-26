#ifndef CATTopNonLinearTransformation_H
#define CATTopNonLinearTransformation_H

// COPYRIGHT DASSAULT SYSTEMES  2000


//Windows compatibility
#include "BODYNOPE.h"

#include "CATTopOperator.h"

class CATGeoFactory;
class CATTopData;
class CATGeometry;
class CATSurface;
class CATCurve;
class CATMathTransformation2D;
class CATMathTransformation1D;

/**
* Class representing the topological operator that transforms a CATBody.
* <br>
* It follows the use frame of all operator and satisfies to the smart mechanism: the
* input body is not modified. A new resulting body is created, 
* possibly sharing data with the input one.
*/
class ExportedByBODYNOPE CATTopNonLinearTransformation: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopNonLinearTransformation);
public:
  /**
  * Virtual constructor.<br>
  * Cannot be called. Use the <tt>CATCreateTopNonLinearTransformation</tt> global function
  * to create a CATTopNonLinearTransformation.
  */
  CATTopNonLinearTransformation(CATGeoFactory* iContainer, CATTopData* iData);

  /**
   * Deprecated
   * Cannot be called. Use the <tt>CATCreateTopNonLinearTransformation</tt> global function
   * to create a CATTopNonLinearTransformation.
   */
  CATTopNonLinearTransformation(CATGeoFactory* iContainer, CATCGMJournalList* iJournal=NULL);

  /**
   * Destructor.
   */
  virtual ~CATTopNonLinearTransformation();

  /** 
   * @nodoc
   * Adds a CATGeometry to transform with <tt>this</tt> CATTopNonLinearTransformation.
   *<br>All the added objects must belong
   * to the same factory.
   * @param iObjectToTransform
   * A pointer to the CATGeometry to add to the CATTopNonLinearTransformation.
   * @param iTransformedObject
   * If not NULL, it forces the transformation of <tt>iObjectToTransform</tt> to be
   * the object <tt>iTransformedObject</tt>. This must be compatible with the
   * given transformation of the CATTopNonLinearTransformation.
   */
  virtual void Add(CATGeometry * iObjectToTransform    ,
                   CATGeometry * iTransformedObject = 0) = 0;

  /** 
   * @nodoc
   */
  virtual void Add(CATSurface              * iSurfaceToTransform,
                   CATSurface              * iTransformedSurface,
                   CATMathTransformation2D * iTransfo2D = 0) = 0;

  /** 
   * @nodoc
   */
  virtual void Add(CATCurve                * iCurveToTransform,
                   CATCurve                * iTransformedCurve,
                   CATMathTransformation1D * iTransfo1D = 0) = 0;

  /**
   * @nodoc
   * Returns whether all the surfaces of the resulting body are valid
   * @return
   * The result of the test.
   */
  virtual CATBoolean CheckSurfacesOfResultBody() = 0;

};
#endif
