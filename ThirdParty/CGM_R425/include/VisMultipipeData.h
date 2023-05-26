#ifndef VISMULTIPIPEDATA_H_
#define VISMULTIPIPEDATA_H_

#include "CATVisFoundation.h"
#include "CATVizBaseIUnknown.h"
#include "list.h"
#include "CATUnicodeString.h"
class CATGraphicWindow;
class CATViewpoint;
class VisMultipipeConfiguration;
class VisMultipipeManager;
class CAT3DRep;
class CATGraphicMaterial;


class ExportedByCATVisFoundation VisMultipipeData : public CATVizBaseIUnknown
{
public :

  // data of one support for multipipe scenario
  VisMultipipeData (CATGraphicWindow* ipGW);

  virtual ~VisMultipipeData ();

  // activate the multipipe
  virtual void SetMultipipeMode(const int iOnOff=1);
  virtual int IsMultipipeActivated();
  virtual void Reset();

  // set the multipipe configuration used for slave graphic windows creation
  virtual void SetMultipipeConfiguration(const VisMultipipeConfiguration& iMultipipeConfiguration);
  virtual void GetMultipipeConfiguration(VisMultipipeConfiguration*& opMultipipeConfiguration);

  // manage virtual graphic window
  virtual int IsVirtualWindow() const;
  virtual void AddSlaveWindow(CATGraphicWindow* ipSlaveGW);
  virtual void RemoveSlaveWindow(CATGraphicWindow* ipSlaveGW);
  virtual void RemoveAllSlaveWindows();
  virtual int GetNbSlaveWindow() const;
  virtual CATGraphicWindow* GetSlaveWindow(int iIndex) const;
  virtual int IsSlaveWindow(CATGraphicWindow* ipSlaveGW) const;

  // manage slave graphic windows
  virtual int IsSlaveWindow() const;
  virtual void SetVirtualWindow(CATGraphicWindow* ipVirtualGW);
  virtual const CATGraphicWindow* GetVirtualWindow() const;
  virtual CATGraphicWindow* GetVirtualWindow();

  // mGPU slave and virtual windows viewpoints management
  virtual void RegisterSlaveWindow(int iDisplayId, CATGraphicWindow* ipSlaveGraphicWindow);
  virtual void RegisterSlaveViewpoint(CATGraphicWindow* ipSlaveGraphicWindow, CATViewpoint* ipVirtualViewpoint, CATViewpoint* ipSlaveViewpoint);
  virtual CATViewpoint* GetVirtualViewpoint(const CATViewpoint* ipSlaveViewpoint);
  virtual void GetSlaveViewpoint(const CATViewpoint* ipVirtualViewpoint, int iDisplayId, CATViewpoint*& opSlaveViewpoint);
  virtual CATGraphicWindow* GetSlaveWindowFromDisplayId(int iDisplayId);
  virtual int GetDisplayIdFromSlaveWindow(CATGraphicWindow* ipSlaveGraphicWindow);
//  virtual void GetSlaveViewpoint(const CATViewpoint* ipVirtualViewpoint, CATViewpoint*& opSlaveViewpoint);
  virtual void GetVirtualViewpoint(const CATViewpoint* ipSlaveViewpoint, CATViewpoint*& opVirtualViewpoint);
  
  // manage slave graphic index
  virtual void ReInitSlaveWindowIndex();
  virtual int GetSlaveWindowIndex();

  // mGPU cloned slave windows viewpoints management during draw
  virtual void GetCloneSlaveViewpoint(const CATViewpoint* ipCloneVirtualViewpoint, CATViewpoint*& opCloneSlaveViewpoint);

  // manage slave graphic window position
  virtual void SetInitialPosition(int iDisplayXPosition, int iDisplayYPosition);
  virtual int GetInitialDisplayXPosition() const;
  virtual int GetInitialDisplayYPosition() const;

  // manage HMD VR distorsion post effect
  virtual int UseOffscreenFrameBuffer(unsigned int& oTargetWidth, unsigned int& oTargetHeight) const;
  virtual int UseOffscreenFrameBuffer() const;

  // manage HMD VR distorsion post effect
  virtual CATBoolean IsHMDCompositorDistorsionActivated () const;
  virtual CATBoolean IsHMDSideBySideDistorsionActivated () const;
  virtual void SetHMDCompositorDistorsionActivation (CATBoolean iActivated);
  virtual void SetHMDSideBySideDistorsionActivation (CATBoolean iActivated);
  virtual void GetRenderTargetSize(unsigned int& oTargetWidth, unsigned int& oTargetHeight) const;
  virtual void SetRenderTargetSize(unsigned int iTargetWidth, unsigned int iTargetHeight);
  virtual void GetDistorsionLeftMesh(CAT3DRep*& opLeft3DRep, CATGraphicMaterial*& opLeftMaterial) const;
  virtual void GetDistorsionRightMesh(CAT3DRep*& opRight3DRep, CATGraphicMaterial*& opRightMaterial) const;
  virtual void SetDistorsionLeftMesh(CAT3DRep* ipLeft3DRep, CATGraphicMaterial* ipLeftMaterial);
  virtual void SetDistorsionRightMesh(CAT3DRep* ipRight3DRep, CATGraphicMaterial* ipRightMaterial);

protected :
  CATGraphicWindow* _pGW;

private :
  // not allowed
  VisMultipipeData ();
  VisMultipipeData (const VisMultipipeData &);
  VisMultipipeData& operator=(const VisMultipipeData&);
};

class VisVirtualMultipipeData : public VisMultipipeData
{
public :

  // data of one virtual support for multipipe scenario
  VisVirtualMultipipeData (CATGraphicWindow* ipGW);

  ~VisVirtualMultipipeData ();

  // activate the multipipe
  void SetMultipipeMode(const int iOnOff=1);
  int IsMultipipeActivated();
  void Reset();

  // set the multipipe configuration used for slave graphic windows creation
  void SetMultipipeConfiguration(const VisMultipipeConfiguration& iMultipipeConfiguration);
  void GetMultipipeConfiguration(VisMultipipeConfiguration*& opMultipipeConfiguration);

  // manage virtual graphic window
  int IsVirtualWindow() const;
  void AddSlaveWindow(CATGraphicWindow* ipSlaveGW);
  void RemoveSlaveWindow(CATGraphicWindow* ipSlaveGW);
  void RemoveAllSlaveWindows();
  int GetNbSlaveWindow() const;
  CATGraphicWindow* GetSlaveWindow(int iIndex) const;
  int IsSlaveWindow(CATGraphicWindow* ipSlaveGW) const;

  // mGPU slave and virtual windows viewpoints management
  void RegisterSlaveWindow(int iDisplayId, CATGraphicWindow* ipSlaveGraphicWindow);
  void RegisterSlaveViewpoint(CATGraphicWindow* ipSlaveGraphicWindow, CATViewpoint* ipVirtualViewpoint, CATViewpoint* ipSlaveViewpoint);
  CATViewpoint* GetVirtualViewpoint(const CATViewpoint* ipSlaveViewpoint);
  void GetSlaveViewpoint(const CATViewpoint* ipVirtualViewpoint, int iDisplayId, CATViewpoint*& opSlaveViewpoint);
  CATGraphicWindow* GetSlaveWindowFromDisplayId(int iDisplayId);
  int GetDisplayIdFromSlaveWindow(CATGraphicWindow* ipSlaveGraphicWindow);
  
  // manage HMD VR distorsion post effect
  CATBoolean IsHMDCompositorDistorsionActivated () const;
  CATBoolean IsHMDSideBySideDistorsionActivated () const;
  void SetHMDCompositorDistorsionActivation (CATBoolean iActivated);
  void SetHMDSideBySideDistorsionActivation (CATBoolean iActivated);
  void GetRenderTargetSize(unsigned int& oTargetWidth, unsigned int& oTargetHeight) const;
  void SetRenderTargetSize(unsigned int iTargetWidth, unsigned int iTargetHeight);
  void GetDistorsionLeftMesh(CAT3DRep*& opLeft3DRep, CATGraphicMaterial*& opLeftMaterial) const;
  void GetDistorsionRightMesh(CAT3DRep*& opRight3DRep, CATGraphicMaterial*& opRightMaterial) const;
  void SetDistorsionLeftMesh(CAT3DRep* ipLeft3DRep, CATGraphicMaterial* ipLeftMaterial);
  void SetDistorsionRightMesh(CAT3DRep* ipRight3DRep, CATGraphicMaterial* ipRightMaterial);

private :
  // not allowed
  VisVirtualMultipipeData ();
  VisVirtualMultipipeData (const VisVirtualMultipipeData &);
  VisVirtualMultipipeData& operator=(const VisVirtualMultipipeData&);

private :

  friend class VisSlaveMultipipeData;

  int _isMultipipe;
  VisMultipipeConfiguration* _pMultipipeConfiguration;
  VisMultipipeManager* _pMultipipeManager;
  list<CATGraphicWindow>    _listSlaveWindow;
  int _distorsionActivation;
  int _compositorActivation;
  unsigned int _renderTargetWidth, _renderTargetHeight;
  CAT3DRep* _pLeft3DRep;
  CATGraphicMaterial* _pLeftMaterial;
  CAT3DRep* _pRight3DRep;
  CATGraphicMaterial* _pRightMaterial;
};

class VisSlaveMultipipeData : public VisMultipipeData
{
public :

  // data of one slave support for multipipe scenario
  VisSlaveMultipipeData (CATGraphicWindow* ipGW);

  ~VisSlaveMultipipeData ();

  // activate the multipipe
  int IsMultipipeActivated();

  // manage slave graphic windows
  int IsSlaveWindow() const;
  void SetVirtualWindow(CATGraphicWindow* ipVirtualGW);
  const CATGraphicWindow* GetVirtualWindow() const;
  CATGraphicWindow* GetVirtualWindow();

  // mGPU slave and virtual windows viewpoints management
//  void GetSlaveViewpoint(const CATViewpoint* ipVirtualViewpoint, CATViewpoint*& opSlaveViewpoint);
  void GetVirtualViewpoint(const CATViewpoint* ipSlaveViewpoint, CATViewpoint*& opVirtualViewpoint);

  // manage slave graphic index
  void ReInitSlaveWindowIndex();
  int GetSlaveWindowIndex();

  // manage slave graphic window position
  void SetInitialPosition(int iDisplayXPosition, int iDisplayYPosition);
  int GetInitialDisplayXPosition() const;
  int GetInitialDisplayYPosition() const;

  // manage HMD VR distorsion post effect
  CATBoolean IsHMDCompositorDistorsionActivated () const;
  void SetHMDCompositorDistorsionActivation (CATBoolean iActivated);
  CATBoolean IsHMDSideBySideDistorsionActivated () const;
  void SetHMDSideBySideDistorsionActivation (CATBoolean iActivated);
  void GetRenderTargetSize(unsigned int& oTargetWidth, unsigned int& oTargetHeight) const;
  void SetRenderTargetSize(unsigned int iTargetWidth, unsigned int iTargetHeight);
  void GetDistorsionLeftMesh(CAT3DRep*& opLeft3DRep, CATGraphicMaterial*& opLeftMaterial) const;
  void GetDistorsionRightMesh(CAT3DRep*& opRight3DRep, CATGraphicMaterial*& opRightMaterial) const;
  void SetDistorsionLeftMesh(CAT3DRep* ipLeft3DRep, CATGraphicMaterial* ipLeftMaterial);
  void SetDistorsionRightMesh(CAT3DRep* ipRight3DRep, CATGraphicMaterial* ipRightMaterial);

private :
  // not allowed
  VisSlaveMultipipeData ();
  VisSlaveMultipipeData (const VisVirtualMultipipeData &);
  VisSlaveMultipipeData& operator=(const VisSlaveMultipipeData&);

private :

  CATGraphicWindow* _pVirtualGW;
  int _slaveWindowIndex;
  int _initialDisplayXPosition;
  int _initialDisplayYPosition;
  int _distorsionActivation;
  int _compositorActivation;
  unsigned int _renderTargetWidth, _renderTargetHeight;
  CAT3DRep* _pLeft3DRep;
  CATGraphicMaterial* _pLeftMaterial;
  CAT3DRep* _pRight3DRep;
  CATGraphicMaterial* _pRightMaterial;
};

#endif /* VISMULTIPIPEDATA_H_ */
