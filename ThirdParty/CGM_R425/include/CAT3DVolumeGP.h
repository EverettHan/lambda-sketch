#ifndef CAT3DVolumeGP_H
#define CAT3DVolumeGP_H

// COPYRIGHT DASSAULT SYSTEMES 2013

//------------------------------------------------------------------------------
// Inheritance: CAT3DVolumeGP
//                 CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//------------------------------------------------------------------------------

#include "SGInfra.h"

#include "CAT3DFaceGP.h"
#include "CATGraphicPrimitive.h"
#include "CATVizPtrList.h"

class CATStreamer;

class ExportedBySGInfra CAT3DVolumeGP : public CATGraphicPrimitive
{
 CATDeclareClass;
 CATVizDeclareClass;

public :

  /**
   * Default constructor.
   */
   explicit CAT3DVolumeGP (unsigned char initialCapacity=0);

   /**
    * Append a Face to the Volume
    */
   inline int AppendFace(CAT3DFaceGP *iFace) {
     if (iFace) {
       iFace->AddRef();
       _faces.AddTail(iFace);
       return 1;
     }
     return 0;
   };

   /**
    * Returns list of faces
    */
   inline const CATVizPtrList<CAT3DFaceGP>& GetFaceList() const {return _faces;};

   //CATBoolean Contains(const CAT3DFaceGP *iFace) const;

  /**
   * @nodoc
   * Streaming
   */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);

  /**
   * @nodoc
   * Streaming
   */  
  virtual void UnStream(CATStreamer& iStr);

 /**
   * @nodoc
   * Skips the unstreaming of a 3D Volume.
   * <br><b>Role:</b>: This method can be used when you do not want
   * to unstream a volume. It is used like this :<br>
   * CAT3DVolumeGP::Skip(str);
   * @param iStr
   *   The streamer used to unstream the 3D Volumes.
   */
  static void Skip(CATStreamer & iStr);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the 3D lines.
   * @param iRender
   *    The render through wich the 3D line is drawn.
   */
   virtual void Draw (CATRender &iRender) GP_FUNC_OVERRIDE_FINAL;
    
  /**
   * @nodoc
   */
   virtual int DetailCulling(CATRender *render);
   
  /**
   * @nodoc
   */
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

 protected :

   virtual ~CAT3DVolumeGP();

 private :

   //copy constructor and = operator
   CAT3DVolumeGP (const CAT3DVolumeGP &gp);
   CAT3DVolumeGP& operator=(const CAT3DVolumeGP &gp);
   
   
   CATVizPtrList<CAT3DFaceGP> _faces;
};

#endif
