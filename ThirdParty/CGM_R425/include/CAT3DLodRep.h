#ifndef CAT_3D_LOD_REP_H
#define CAT_3D_LOD_REP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

 //******************************************************************************

 //******************************************************************************
 //  Inheritance:
 //  ------------
 //                CAT3DLodRep
 //                  CAT3DRep
 //                    CATRep
 //                      CATExtend (SYSTEM framework) 
 //
 //******************************************************************************


#include "SGInfra.h"
#include "CAT3DRep.h"



/**
 * Class to define several representations, each of a different accuracy, to visualize
 * the same object.
 * <b>Role</b>: This representation introduces the concept of Levels Of Details within the
 * visualization of a scene. It manages a list of representations, that are
 * supposed to be of the same element, at different accuracy levels.
 * Representations of the element with a low accuracy level are supposed to
 * take less time to be drawn.
 * When the representation is requested to Draw itself, it chooses the best
 * of it's representations to draw, that is the representation whose accuracy
 * fits the pixel resolution of the element (size of a pixel onto the
 * object).
 * The CAT3DLodRep behaves as a CAT3DBagRep for which the children would be
 * a same representation computed at different accuracy levels.
 * Methods are provided, once the representation has been created, to add
 * Levels Of Detail (Lods). A Lod is added with a given accuracy (sag), that
 * will determine when it has to be drawn (at which distance from the eye)
 * instead of the original geometry.
 * The first Lod is considered as the 'original' geometry defining the
 * element.
 * The used bounding element is the one of the first Lod. Any other Lod
 * should fit in this bounding element.
 * At the representation destruction, every Lod is being deleted, including
 * the original geometry itself. A call to SuppressLod deletes the targetted
 * representation.
 */
class ExportedBySGInfra CAT3DLodRep : public CAT3DRep
{
  friend class CATDmuStream3DLodRep;
  friend class CATVrmlMaker3DLODRep;
  CATDeclareClass;

public:

  // Construction and destruction methods:
  // -------------------------------------

/**
 * Default constructor.
 */
  static CAT3DLodRep* CreateRep();

protected:

  /** @nodoc :deprecated R417 : Use CreateRep instead.*/
  CAT3DLodRep(void);

public:

  /**
   * Destructor.
   */
  virtual ~CAT3DLodRep(void);


  // Managing Levels Of Detail (Lods):
  // ---------------------------------
  //   - AddLod: Each Lod MUST be given a sag that determines it's own drawing
  //     field, replacing in this case the first Lod.

/**
 * Gets the number of different representations
 * used to represent the same object at different accuracy
 * levels.
 */
  inline int NbLods(void);

  /**
   * Adds a representation as a new level of detail.
   * @param iLod
   *   The 3D representation that would be
   *   used to visualize the object at the
   *   associated accuracy.
   * @param iSag
   *   The sag used to tessellate
   *   the associated representation, expressed
   *   in millimeters.
   *   This sag is used to determine which LOD
   *   is the most appropriated to represent the
   *   object at a certain distance, and with a certain
   *   session sag, fixed thanks to the CATIA
   *   Tools > Options > Performance menu.
   */
  int AddLod(CAT3DRep* iLod, float iSag);

  /**
   * Supresses a given representation
   * from the list of representations used
   * as levels of details. The supressed representation
   * is destroyed.
   * @param iNumLod
   *   The index of the LOD you want to
   *   supress.
   */
  void SuppressLod(int iNumLod);

  /**
   * Gets the representation of a given LOD.
   * @param iNumLod
   *   The index of the LOD which
   *   representation is retrieved.
   */
  inline CAT3DRep* GetLod(int iNumLod);

  /**
   * Gets the sag associated to the representation of a given LOD.
   * @param iNumLod
   *   The index of the LOD which
   *   sag is retrieved.
   */
  inline float GetLodSag(int iNumLod);


  // Draw method:
  // ------------
  // AZX: (A2X migration) Making draw functions final 
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 06072022 " __FILE__ " Stop overriding Drawxxx functions" )
#endif

#ifdef CATIAR426
  /**
   * @nodoc
   */
  virtual void Draw(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;

  /**
   * @nodoc
   */
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) FUNC_OVERRIDE_FINAL;
#endif

  /**
   * @nodoc
   */
  virtual void DrawShading(CATRender& iRender, int iInside) FUNC_OVERRIDE_FINAL;

  /**
   * @nodoc
   */
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iPath) FUNC_OVERRIDE_FINAL;


protected:
  /** @nodoc */
  virtual const vDrawInformation* GetDrawInformation();

  // Internal Lod definition and storage parameters:
  // -----------------------------------------------

  int         _nb_lod;        // Number of lods currently stored.
  CAT3DRep** _lod;           // Levels Of Detail list.
  float* _sag;           // List of Lod's accuracy.


private:

};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline int CAT3DLodRep::NbLods(void)
{
  return _nb_lod;
}


inline CAT3DRep* CAT3DLodRep::GetLod(int num_lod)
{
  return _lod[num_lod];
}


inline float CAT3DLodRep::GetLodSag(int num_lod)
{
  return _sag[num_lod];
}


#endif
