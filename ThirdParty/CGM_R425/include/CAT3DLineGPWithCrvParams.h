#ifndef CAT3DLineGPWithCrvParams_H
#define CAT3DLineGPWithCrvParams_H

// COPYRIGHT DASSAULT SYSTEMES 2007



#include "SGInfra.h"
#include "CAT3DLineGP.h"
#include "CATVizMacForMetaClass.h"


class CAT3DLineGPEditHelper;
class CATStreamer;

/**
 * Class to create the graphic primitive of a 3D edge.
 * <b>Role</b>:
 *    Representation of an edge on an element, generally an exact solid.
 *    The edge shares the data of the two faces it belongs to (in fact, only
 *    the vertices of the first face are being used).
 *    The adresses of the faces are stored to complete the topological informa-
 *    tion on the element.
 *    It is designed to be used by the CATSurfacicRep.
 *    The edge is a 3d polyline, with chained vertices references.
 */
class ExportedBySGInfra CAT3DLineGPWithCrvParams : public CAT3DLineGP
{

  CATDeclareClass;
  CATVizDeclareClass;
  
  friend class CAT3DLineGPEditHelper;
  
  public:
    
   /**
   * @nodoc
   */
    CAT3DLineGPWithCrvParams (void);

   /**
   * @nodoc
   */
    CAT3DLineGPWithCrvParams (const float iPoints[], const int iNbPoints=2, 
                const int iAlloc=ALLOCATE, const int iLineType = LINES, float const* iCrvParams = NULL);

   /**
   * @nodoc
   */
   void GetReadOnly (float const**oPoints, int *oNbPoints,int *oLineType, float const**oCrvParams)const;
    
   /**
   * @nodoc
   */
  virtual HRESULT GetCrvParamsReadOnly(float const**oCrvParams);

   /**
   * @nodoc
   */
   virtual HRESULT GetTangentsReadOnly(float const**tangents)const;

   /**
   * @nodoc
   */

  protected:
   virtual HRESULT SetTangents(float *tangents, int copy);
    
    // Destruction:
    // ------------
    
    virtual ~CAT3DLineGPWithCrvParams (void);
    
  /**
  * @nodoc
  */
  
  float *_crvParams;
  float *_tangents;
};


#endif
