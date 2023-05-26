// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CAT3DLodBagRep_h
#define CAT3DLodBagRep_h

#include "CAT3DBagRep.h"
#include "CATVizPtrList.h"

class CATRender;
class CATRepPath;

/**
 * The CAT3DLodBagRep adds Hierarchical Level of Detail to Bag Reps.
 *
 * <b>Role</b>:
 * A CAT3DLodBagRep is a special type of CAT3DBagRep that allows you to associate Lod reps with it.
 * According to a SAG based quality criteria, the CAT3DLodBagRep will render either its children Reps
 * or one of the associated Lod Reps.
 */
class ExportedBySGInfra CAT3DLodBagRep : public CAT3DBagRep
{
  CATDeclareClass;

public:

  static CAT3DLodBagRep* CreateRep();
  
protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DLodBagRep();

  virtual ~CAT3DLodBagRep();

public:

  /**
   * Returns the number of associated Lod Reps.
   */
  unsigned GetLodRepCount() const;

  /**
   * Returns the Lod Rep at iIndex position.
   */
  CAT3DRep* GetLodRep(unsigned iIndex) const;

  /**
   * Returns the SAG of the Lod Rep at iIndex position.
   */
  float GetLodRepSag(unsigned iIndex) const;

  /**
   * Adds ipRep as Lod Rep with a SAG of iSag.
   * CAT3DLodRep takes ownership of ipRep, i.e. it will automatically delete it
   * in its destructor.
   */
  void AddLodRep(CAT3DRep* ipRep, float iSag);

  /**
   * Removes Lod Rep at iIndex position.
   * This gives ownership of the Lod Rep to the caller.
   */
  void RemoveLodRep(unsigned iIndex);

  /**
   * Removes ipRep from the Lod Rep List.
   * This gives ownership of ipRep to the caller.
   */
  void RemoveLodRep(CAT3DRep* ipRep);

  /**
   * Clear the Lod Reps list and delete Lod Reps
   */
  void RemoveAllLodReps();

  /**
   * Reimplemented from CAT3DBagRep
   */
  virtual void DrawShading(CATRender& ioRender, int iInside) override final;

  /**
   * Reimplemented from CAT3DBagRep
   */
  virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;

  // AZX: (A2X migration) Making draw functions final 
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /**
   * Reimplemented from CAT3DBagRep
   */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

private:
  unsigned _lodCount;

  float* _sags;
  CAT3DRep** _reps;

  CAT3DLodBagRep(const CAT3DLodBagRep&);
  void operator = (const CAT3DLodBagRep&);
};

#endif  // CAT3DLodBagRep_h
