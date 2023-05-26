#ifndef CAT3DCylinderRep_H
#define CAT3DCylinderRep_H

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1997
//
//******************************************************************************
//  Abstract:
//  ---------
//    This is the representation of a cylinder. It's defined with two vertices,
//    the first being the center of the base of the cylinder, the other being
//    the center of the top face of the cylinder.
//    A cylinder representation should be defined with an accuracy parameter,
//    but even if there's none given, the representation chooses a standard
//    value.
//
//******************************************************************************
//  Usage:   
//  ------
//    Arguments are float arrays of coordinates. An argument like float *pt
//    means that we are to access to pt[0], pt[1], pt[2].
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DCylinderRep
//                  CAT3DRep
//                    CATExtend (SYSTEM framework) 
//
//******************************************************************************
//  Main Methods:
//  -------------
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CAT3DCylinderGP.h"

class CAT3DLineGP;
class CAT3DCylinderGP;
class CATMathPointf;
class CATOutlineBuilder;
class CATDrawableHolder;
class CATDelegateRender;


class ExportedBySGInfra CAT3DCylinderRep : public CAT3DRep
{

  friend class CATMarshallable3DCylinderRep;
  friend class CATDmuStream3DCylinderRep;
  friend class CATVrmlMaker3DCylinderRep;
  friend class CATVrml2Maker3DCylinderRep;
  friend class CATConvertToSurfacicRep;
  friend class vImplDrawable_CAT3DCylinderRep;
  friend class SGCGRStreamerForCylinderRep;
  friend class SGCGRNodesFactoryA;

  CATDeclareClass;


public:

  // Construction and destruction methods:
  // -------------------------------------
  //   When sag=NULL, we automatically choose one for the display of the
  //   representation.
  static CAT3DCylinderRep* CreateRep();
  static CAT3DCylinderRep* CreateRep(const CATMathPointf& iFirst_pt,
    const CATMathPointf& iSecond_pt,
    float iRadius,
    float* iSag = NULL);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCylinderRep(void);
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCylinderRep(CATModelIdentificator& iId,
    void* iCtrl,
    CATMathPointf& iFirst_pt,
    CATMathPointf& iSecond_pt,
    float iRadius,
    float* iSag = NULL);
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DCylinderRep(const CATMathPointf& iFirst_pt,
    const CATMathPointf& iSecond_pt,
    float iRadius,
    float* iSag = NULL);

  virtual ~CAT3DCylinderRep(void);

public:
  virtual HRESULT __stdcall QueryInterface(const IID& iIID, void** oPPV);


  // Data access:
  // ------------

  inline CAT3DCylinderGP* GeomCylinder(void);
  inline float            GeomSag(void);
  inline float GetGeomSag(int index);

  // Drawing:
  // --------

// AZX: (A2X migration) Making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  // Modification:
  // -------------

  void Modify(const CATMathPointf& iFirst_pt,
    const CATMathPointf& iSecond_pt,
    float iRadius,
    float* iSag = NULL);


  // Managing texture coordinates:
  // -----------------------------

  virtual void UpdateTextureCoordinates(CATMappingOperator* iOperator = NULL);


  // Managing outlines:
  // ------------------

  CATOutlineBuilder* GetOutlineBuilder(void);

  /** @nodoc */
  virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

  /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  inline int GetNumLod();

  CATGraphicPrimitive* GetCurvedGeomElement(int iIndice);

  CAT3DLineGP* GetLastLod() const;

protected:

  // Computing accuracy (for the original geometry):
  // -----------------------------------------------
  //   Sag can be choosen by the representation, or be given as a parameter
  //   during the construction.

  void ComputeSag(float iradius);
  void ComputeSag(float iSag_init, float iRadius);

  virtual const vDrawInformation* GetDrawInformation();

  // Geometric information (faces):
  // ------------------------------
  //   _NbLod is the total number of lods (0: Original cylinder), including
  //   the line which is the last representation of the cylinder.

  int               _NbLod;
  float* _Sag;
  CAT3DCylinderGP** _Lod;
  CAT3DLineGP* _LastLod;

  // Definition of outlines:
  // -----------------------

  CATOutlineBuilder* _builder;             // Outline generator.


private:

  // Internal building method:
  // -------------------------

  void Build(float* iFirst_pt, float* iSecond_pt, float iRadius, float* iSag);

  void DrawShading_Legacy(CATRender& iRender, CATDelegateRender& iDelRender, int inside);
  void DrawPath_Legacy(CATRender& render, CATDelegateRender& iDelRender, int inside, CATRepPath& path);
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline CAT3DCylinderGP* CAT3DCylinderRep::GeomCylinder(void)
{
  return _Lod[0];
}


inline float CAT3DCylinderRep::GeomSag(void)
{
  return _Sag[0];
}

inline float CAT3DCylinderRep::GetGeomSag(int index)
{
  return _Sag[index];
}

inline int CAT3DCylinderRep::GetNumLod()
{
  return _NbLod;
}

#endif
