#ifndef CAT3DCurvedPipeRep_H
#define CAT3DCurvedPipeRep_H

//******************************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    Representation of a curved pipe. This representation just manages Levels
//    of detail for the CAT3DCurvedPipeGP.
//
//******************************************************************************
//  Usage:   
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DCurvedPipeRep
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
#include "CAT3DCurvedPipeGP.h"

class CATGraphicPrimitive;
class CATOutlineBuilder;
class CATDrawableHolder;
class CATDelegateRender;
class CAT3DLineGP;

class ExportedBySGInfra CAT3DCurvedPipeRep : public CAT3DRep
{
  
  friend class CATMarshallable3DCurvedPipeRep;
  friend class CATDmuStream3DCurvedPipeRep;
  friend class CATVrmlMaker3DCurvedPipeRep;
  friend class CATVrml2Maker3DCurvedPipeRep;
  friend class CATConvertToSurfacicRep;
  friend class vImplDrawable_CAT3DCurvedPipeRep;
  friend class SGCGRStreamerForCurvedPipeRep;
  friend class SGCGRNodesFactoryA;

  CATDeclareClass;
  
  
  public:
    
    // Construction and destruction methods:
    // -------------------------------------
    //   Lods must be added in the right order: Through increasing sags.
    static CAT3DCurvedPipeRep* CreateRep ();
    static CAT3DCurvedPipeRep* CreateRep (float iRadius, float iSag_init);

protected:

    /** @deprecated R417 : Use CreateRep instead.*/
    CAT3DCurvedPipeRep          (void);
    /** @deprecated R417 : Use CreateRep instead.*/
    CAT3DCurvedPipeRep          (float iRadius, float iSag_init);

    virtual ~CAT3DCurvedPipeRep (void);

public:
    virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);

    void AddLOD (int num_lod,CATGraphicPrimitive *lod);
    void Modify(CATGraphicPrimitive* iOldGP,CATGraphicPrimitive* iNewGP);	// XK7	 ZeroRender dev ++
     // Data access:
    // ------------
    
    inline CAT3DCurvedPipeGP *GeomCurvedPipe (void);
    inline float              GeomSag      (void);
    inline float GetGeomSag (int index);

	inline CATGraphicPrimitive ** GetLod();	 // XK7	 ZeroRender dev ++
	inline int GetNumLod(); 

    // Drawing:
    // --------
    // AZX: (A2X migration) Making draw functions final 
    virtual void Draw(CATRender& iRender, int iInside) override final;
    virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;
    virtual void DrawShading (CATRender &ioRender,int ioInside) override final;
    virtual void DrawPath(CATRender &render,int inside,CATRepPath &path) override final;
    
    // Managing texture coordinates:
    // -----------------------------
    
    virtual void UpdateTextureCoordinates (CATMappingOperator* iOperator = NULL);

    /** @nodoc */
    virtual CATGraphicPrimitive* GetGeomElement(int iIndice);

		  /** @nodoc */
	virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);
    
  CATGraphicPrimitive* GetCurvedGeomElement(int iIndice);
    
  CAT3DLineGP* GetLastLod() const;

  protected:

      /** @nodoc */
      virtual const vDrawInformation* GetDrawInformation();

    // Computing accuracy (for the original geometry):
    // -----------------------------------------------
    //   Sag can be choosen by the representation, or be given as a parameter
    //   during the construction.
    
    void ComputeSag (float iradius);
    void ComputeSag (float iSag_init,float iRadius);
    
    // Managing outlines:
    // ------------------
    
    CATOutlineBuilder      *GetOutlineBuilder (void);
    
    // Geometric information:
    // ----------------------
    
    int                  _NbLod;
    float               *_Sag;
    CATGraphicPrimitive **_Lod;

    
    // Definition of outlines:
    // -----------------------
    
    CATOutlineBuilder          *_builder;             // Outline generator.

private :
    
    void DrawShading_Legacy(CATRender& iRender, CATDelegateRender& iDelRender, int inside);
    void DrawPath_Legacy (CATRender &render, CATDelegateRender& iDelRender, int inside, CATRepPath &path);
};

//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline CAT3DCurvedPipeGP *CAT3DCurvedPipeRep::GeomCurvedPipe (void)
{
  return (CAT3DCurvedPipeGP *) _Lod[0];
}

inline float CAT3DCurvedPipeRep::GeomSag (void)
{
  return _Sag[0];
}

inline CATGraphicPrimitive ** CAT3DCurvedPipeRep::GetLod()
{
	return _Lod;
}

inline float CAT3DCurvedPipeRep::GetGeomSag (int index)
{
            return _Sag[index];
}

inline int CAT3DCurvedPipeRep::GetNumLod()
{ 
		return _NbLod;
}

#endif
