#ifndef CAT2DTo3DRep_H
#define CAT2DTo3DRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "SGInfra.h"
#include "CATMathPointf.h"
#include "CAT3DBagRep.h"

class CAT2DBagRep;
class CAT3DViewpoint;
class CAT4x4Matrix;
class CATGraphicWindow;

/**
  * Class to immerge a 2D Representation into a 3D Viewpoint.
  *
  * <b>Role</b>: This class adds 2DRep into a 3D rep tree
  * You can use this class to display 2D elements into a 3D vue.
  */
class ExportedBySGInfra CAT2DTo3DRep : public CAT3DBagRep
{
  friend class CATDmuStream2DTo3DRep;
  CATDeclareClass;

  public :

    /** Constructs an empty 2DTo3D graphic representation. */
    static CAT2DTo3DRep* CreateRep();

    /**
     * Constructs a CAT2Dto3DRep rep.
     *
     * @param ibag2D
     *   The CAT2DBagRep containing the CAT2DRep to display
     *
     * @param ipoint
     *   The position of the CAT2DBagRep inside the 3D view
     * 
     * @param idir_x
     *   The X direction inside the 3D view
     * 
     * @param idir_y
     *   The Y direction inside the 3D view
     * 
     * @param istatic_mode
     *   When this paramter is set to 0 (default value), the CAT2DBagRep will
     *   move according to the 3D View.
     *
     *   When this parameter is set to 1, CAT2DBagRep will be modified so that
     *   it will always be drawn in front of the screen.
     *   
     *   When this parameter is set to 2, CAT2DBagRep will move according to
     *   the 3D View but it will be drawn only if the scalar product between
     *   the 3D sight direction and (idir_x^idir_y) is negative.
     */
    static CAT2DTo3DRep* CreateRep(CAT2DBagRep *ibag2D, const CATMathPointf &ipoint, const CATMathDirectionf &idir_x, const CATMathDirectionf &idir_y, const int istatic_mode=0);

protected:

    /** @nodoc : deprecated R417 : Use CreateRep instead.*/
    CAT2DTo3DRep();

    /** @nodoc : deprecated R417 : Use CreateRep instead.*/
    CAT2DTo3DRep (CAT2DBagRep *ibag2D, const CATMathPointf &ipoint, const CATMathDirectionf &idir_x, const CATMathDirectionf &idir_y, const int istatic_mode=0);

public:

    virtual ~CAT2DTo3DRep();


    /** @nodoc */
    // Compute the BE for the Noshow space
    const CAT3DBoundingSphere &GetNoshowBoundingElement (int & ioIsOneRepNoshow) ;
  
    /** @nodoc */
    // Compute the BE for the Show space
    const CAT3DBoundingSphere &GetShowBoundingElement () ;

    /** @nodoc */
    virtual void SetGraphicMaterial (CATGraphicMaterial * iMat);

    /** Adds a child representation to the bag.
     * @param iRep
     * Child representation to be added.
     */
    virtual HRESULT AddChild(CATRep &iRep);

    /** Recalculates the bounding element.
     * @param iShowSpace
     */
    virtual void ComputeBoundingElement (int iShowSpace=1);

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif
    /** @nodoc */
    virtual void DrawShading(CATRender &ioRender, int iInside) FUNC_OVERRIDE_FINAL;

    /** @nodoc */
    virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath) FUNC_OVERRIDE_FINAL;

#ifdef CATIAR426
    /** @nodoc */
    virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;
    /** @nodoc */
    virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

    /** @nodoc */
    inline void SetStaticMode(int iOnOff);

    /** @nodoc */
     
    inline int GetStaticMode();

    /** @nodoc 
     *  make the static mode spherical
     */
    inline void SetSphericalMode(int iMode);

    /** @nodoc
     *  make the static mode spherical
     */
    inline int GetSphericalMode();

     /** @nodoc 
     *  enable/disable the ZDepth mode
     */
    inline void Set2DPriorityAsZ(int iMode);

    /** @nodoc
     *  Get the Zdepth mode
     */
    inline int Get2DPriorityAsZ();

     /** @nodoc 
     *  enable/disable the priority
     */
    inline void Set2DAdvancedPriority(int iPriority);

    /** @nodoc
     *  Get the Priority
     */
    inline int Get2DAdvancedPriority();

    /** @nodoc
     *  Get the AttachPoint
     */
    inline const CATMathPointf& GetAttachPoint() const;


  protected:

    /** @nodoc */
    int _staticMode;
          
    /** @nodoc */
    int _zdepthMode;
          
    /** @nodoc */
    int _advancedPriority;

    /** @nodoc */
    int _sphericalMode;

    /** @nodoc */
    CATMathPointf _attachPoint;

  private :

    /** @nodoc */
    int ComputeSphericalMatrix(CAT4x4Matrix* oMat,CAT3DViewpoint* iVp,CATMathPointf& iAttachPoint);

};

inline void CAT2DTo3DRep::SetStaticMode(int iOnOff)
{
  _staticMode = iOnOff;
}

inline int CAT2DTo3DRep::GetStaticMode()
{
  return _staticMode;
}

inline void CAT2DTo3DRep::SetSphericalMode(int iMode)
{
  _sphericalMode = iMode;
}

inline int CAT2DTo3DRep::GetSphericalMode()
{
  return _sphericalMode;
}

inline void CAT2DTo3DRep::Set2DPriorityAsZ(int iOnOff)
{
  _zdepthMode = iOnOff;
}

inline int CAT2DTo3DRep::Get2DPriorityAsZ()
{
  return _zdepthMode;
}

inline void CAT2DTo3DRep::Set2DAdvancedPriority(int iOnOff)
{
  _advancedPriority = iOnOff;
}

inline int CAT2DTo3DRep::Get2DAdvancedPriority()
{
  return _advancedPriority;
}

inline const CATMathPointf& CAT2DTo3DRep::GetAttachPoint() const
{
  return _attachPoint;
}
#endif 
