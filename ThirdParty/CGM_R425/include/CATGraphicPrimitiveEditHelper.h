#ifndef CATGraphicPrimitiveEditHelper_H_
#define CATGraphicPrimitiveEditHelper_H_

#include "SGInfra.h"
#include <cstdlib>

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Base class for Graphic Primitive EditHelper
//------------------------------------------------------------------------------

class CATRep;
class CATRepWeakRef;
class CATGraphicPrimitive;
class CATGraphicPrimitiveEditHelper;

enum GPEditAuthorization
{
  //OK, edition is possible
  eGPEditOK,
  //Edition is possible only on the indices (Case CAT3DFaceGP, when the VertexBuffer is shared with other faces)
  eGPEditOKOnlyIndices,
  //One mandatory parameter is NULL (either GP or Rep, if ShareCount==1)
  eGPEditNullParams,
  //The given rep does not contain the GraphicPrimitive
  eGPEditWrongRep,
  //The graphic primitive is aggregated in more than one compiled rep
  eGPEditMultipleAggregation,
  //The SurfacicRep is stripped, therefore edition is impossible
  eGPEditStripped,
  //The graphic primitive is currently in Edition in a EditHelper Instance.
  eGPEditInEdition,
  //Generic error, should not be possible to get this value
  eGPEditError
}; 

class ExportedBySGInfra CATGraphicPrimitiveEditHelper
{
public:

protected:

  /**
   * @nodoc
   */
  CATGraphicPrimitiveEditHelper();
  
  /**
   * @nodoc
   */
  ~CATGraphicPrimitiveEditHelper();

  /**
   * @nodoc
   */
  void BeginEdition(CATGraphicPrimitive& iGP, CATRep* iRep);

  /**
   * @nodoc
   */
  void EndEdition(CATGraphicPrimitive& iGP);

protected:
  CATRepWeakRef* m_CurrentContext;
private:

  CATGraphicPrimitiveEditHelper(CATGraphicPrimitiveEditHelper const&);
  CATGraphicPrimitiveEditHelper& operator=(CATGraphicPrimitiveEditHelper const&);

  void ClearDrawInfo(CATRep& iRep);

#ifndef _AIX_SOURCE // Syntaxe non supportée sous AIX.
  static void* operator new(size_t);
  static void* operator new[](size_t);
  static void* operator new(size_t, void*);
  static void* operator new[](size_t, void*);

  static void  operator delete(void*);
  static void  operator delete[](void*);
  static void  operator delete(void*,void*);
  static void  operator delete[](void*,void*);
#endif

};

#endif
