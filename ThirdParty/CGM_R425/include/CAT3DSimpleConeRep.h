#ifndef CAT3DSimpleConeRep_H
#define CAT3DSimpleConeRep_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	A 3D representation representing a cone
//------------------------------------------------------------------------------
// Usage :	Construc a cone with
//		- 1 point for the center of the base disk
//		- 1 point for the pointing extremity
//		- the radius of the disk
//		( the disk is orthogonal to the 2-points direction)
//------------------------------------------------------------------------------
// Main methods :
//------------------------------------------------------------------------------
// Class :	CAT3DSimpleConeRep
//		  CAT3DRep
//		    CATRep
//------------------------------------------------------------------------------
#include "SGInfra.h"

#include "CAT3DRep.h"

class CATRender;
class CAT3DFaceGP;

class ExportedBySGInfra CAT3DSimpleConeRep : public CAT3DRep
{
  CATDeclareClass;

//------------------------------------------------------------------------------
  public:

    /** Constructs a CAT3DSimpleConeRep */
    static CAT3DSimpleConeRep* CreateRep(const CATMathPointf &iCenter, const CATMathPointf &iPeak, const float iRadius, const int iFactor = 16);

    /** @deprecated R422 CAT3DSimpleConeRep::CreateRep */
    CAT3DSimpleConeRep(const CATMathPointf &iCenter, const CATMathPointf &iPeak, const float iRadius, const int iFactor = 16);

    virtual ~CAT3DSimpleConeRep();

    virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);

    void Modify (const CATMathPointf &, const CATMathPointf &, const float);

    //  Draw
    virtual void DrawShading(CATRender &, int) FUNC_OVERRIDE_FINAL;

    /** @nodoc */
    virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

    /** @nodoc */
    virtual int GetGeomIndex(const CATGraphicPrimitive * gp);

//------------------------------------------------------------------------------
  protected:

    CAT3DFaceGP *BuildFaces(const CATMathPointf &, const CATMathPointf &, const float);
    int	factor_;
    CAT3DFaceGP *cone_;
};


#endif









