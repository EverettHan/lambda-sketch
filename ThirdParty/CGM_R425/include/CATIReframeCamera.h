#ifndef CATIREFRAMECAMERA_H
#define CATIREFRAMECAMERA_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

//===========================================================================
// An extention of CATICamera for reframe
//===========================================================================
#include "CATVisItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATIReframeCamera;
#else
extern "C" const IID IID_CATIReframeCamera;
#endif
/**
 * Interface to make camera reframed automatically.
 * <b>Role</b>:
 * Any camera implementing this interface 
 * can reframe the viewpoint automatically when applied.
 * @see CATICamera
 */
class  ExportedByCATVisItf CATIReframeCamera : public CATBaseUnknown
{
   CATDeclareInterface;

   public:
/**
 * Sets or unsets the automatic reframe ability.
 * @param iReframe
 *    automatic reframe ability.
 *   <br><b> Legal values</b>:
 *   <li><tt>0</tt> no automatic reframe</li>
 *   <li><tt>1</tt> automatic reframe</li>.
 */
      virtual void          SetReframe(int iReframe) =0;
/**
 * Returns the automatic reframe ability status.
 * @return
 *   <li><tt>0</tt> no automatic reframe</li>
 *   <li><tt>1</tt> automatic reframe</li>.
 */
      virtual int GetReframe()=0;
/** @nodoc */
      virtual void   Set2DBoundingBox(const float xmin, const float xmax,
                                      const float ymin, const float ymax)=0;
/** @nodoc */
      virtual void   Get2DBoundingBox(float * xmin, float * xmax,
                                      float * ymin, float * ymax)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATIReframeCamera, CATBaseUnknown);

#endif
