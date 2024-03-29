// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATVizVoxelRep.h
// Header definition of CATVizVoxelRep
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: Code generated by the CAA wizard  svq
//===================================================================
#ifndef CATVizVoxelRep_H
#define CATVizVoxelRep_H

#include "SGInfra.h"
#include "CAT3DRep.h"

#include "CATVizVoxelGP.h"
class CATMathPointf;

//-----------------------------------------------------------------------

/**
 * Describe your class here.
 * <p>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedBySGInfra CATVizVoxelRep : public CAT3DRep
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
 /** Constructs a CATVizVoxelRep*/
  static CATVizVoxelRep* CreateRep();

  /** Constructs a CATVizVoxelRep*/
  static CATVizVoxelRep* CreateRep(const CATMathPointf& center, int halfSize, const CATVizPtrList<CATVizVoxelLevel>& levels);

  /** @deprecated R422 CATVizVoxelRep::CreateRep */
  CATVizVoxelRep();
  /** @deprecated R422 CATVizVoxelRep::CreateRep */
  CATVizVoxelRep(const CATMathPointf& center, int halfSize, const CATVizPtrList<CATVizVoxelLevel>& levels);

  virtual ~CATVizVoxelRep();

  // Draw
  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  // Stream / UnStream
  virtual void Stream(CATStreamer& oStream, int iSaveType = 0);
  virtual void UnStream(CATStreamer& str);

  unsigned int GetCurrentNbLevels() { return _gp->GetCurrentNbLevels(); };
  unsigned int GetNbLevels() { return  _gp->GetNbLevels(); };
  void AddLevel(CATVizVoxelLevel* level);
  void ClearAllLevels();
  void ClearLastLevel();
  unsigned int ComputeStreamSize() const;

  inline CATVizVoxelGP* GetVoxelGP();

  CATVizVoxelLevel* UnstreamLevel(CATStreamer* streamer, unsigned int number);

  static int Intersection(CATVizVoxelRep* iVoxelRep1, CATVizVoxelRep* iVoxelRep2, float iClearance = 0.0f, const CAT4x4Matrix* iMatrixRep1 = NULL, const CAT4x4Matrix* iMatrixRep2 = NULL);
  static int Intersection(CATVizVoxelRep* iVoxelRep, float iPlane[4], float iClearance = 0.0f, const CAT4x4Matrix* iMatrixRep = NULL);

protected:
  virtual const vDrawInformation* GetDrawInformation();

  CATVizVoxelGP* _gp;

private:

  // Copy constructor and equal operator
  // -----------------------------------
  CATVizVoxelRep(CATVizVoxelRep&);
  CATVizVoxelRep& operator=(CATVizVoxelRep&);
};

//-----------------------------------------------------------------------
inline CATVizVoxelGP* CATVizVoxelRep::GetVoxelGP()
{
  return _gp;
}

#endif
