//===================================================================
// COPYRIGHT Dassault Systemes 2020/11/25
//===================================================================
// CATVidLayDepthLayer.h
// Header definition of classes
// CATVidLayDepthLayer and CATVidLayDepthLayerConstraints
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2020/11/25 Creation: GX2
//===================================================================

#ifndef CATVidLayDepthLayer_H
#define CATVidLayDepthLayer_H

#include <VisuDialog.h>

#include <CATVidLayCollection.h>
#include <CATVidLayConstraints.h>

//-----------------------------------------------------------------------

class ExportedByVisuDialog CATVidLayDepthLayer : public CATVidLayCollection
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidLayDepthLayer();
  CATVidLayDepthLayer(CATCommand* i_pParent, const CATString& i_pIdentifier);
  virtual ~CATVidLayDepthLayer();

protected:

  /** @copydoc CATVidLayCollection#Layout */
  virtual void Layout() override;

  /** @copydoc CATVidLayCollection#CreateConstraints */
  virtual CATVidLayConstraints* CreateConstraints() override;

  /** @copydoc CATVidLayCollection#UpdateComputedMinimumDimension */
  virtual void UpdateComputedMinimumDimension() override;

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLayDepthLayer(CATVidLayDepthLayer&);
  CATVidLayDepthLayer& operator=(CATVidLayDepthLayer&);
};

//-----------------------------------------------------------------------

class ExportedByVisuDialog CATVidLayDepthLayerConstraints : public CATVidLayConstraints
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidLayDepthLayerConstraints();
  CATVidLayDepthLayerConstraints(const float& i_depth);
  virtual ~CATVidLayDepthLayerConstraints();

  /** @copydoc CATVidLayConstraints#Clone */
  virtual CATVidLayDepthLayerConstraints* Clone() const override;

  /** @copydoc CATVidLayConstraints#IsEqualTo */
  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const override;

  /** @copydoc CATVidLayConstraints#CopyFrom */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints) override;

  /**  Sets the depth of the layout. */
  INLINE float GetDepth() const { return _depth; }

  /** @return the depth of the layout. */
  INLINE void SetDepth(const float& i_depth) { _depth = i_depth; }

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLayDepthLayerConstraints(const CATVidLayDepthLayerConstraints& i_original);
  CATVidLayDepthLayerConstraints& operator=(const CATVidLayDepthLayerConstraints&);

  float _depth;
};

//-----------------------------------------------------------------------

extern "C" ExportedByVisuDialog
HRESULT CATSYPCATVidLayDepthLayerConstraintsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

#endif
