#ifndef _CATVIZUVRREP_
#define _CATVIZUVRREP_

#include "SGInfra.h"
#include "CAT3DRep.h"
#include "CATUnicodeString.h"
class CATViz3DBox;

enum CATUVRLoadState
{
  NOT_LOADED,
  LOADING,
  LOADED
};

class ExportedBySGInfra CATVizUVRRep : public CAT3DRep
{
  CATDeclareClass;
public:
  static CATVizUVRRep* CreateRep();
  static CATVizUVRRep* CreateRep(const char *url /*, CATViz3DBox *box*/);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CATVizUVRRep();
  /** @deprecated R417 : Use CreateRep instead.*/
  CATVizUVRRep(const char *url /*, CATViz3DBox *box*/);

public:

  ~CATVizUVRRep();

  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawShading(CATRender&, int) override final;
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;
  
  void SetUVRRep(CATRep *uvrRep) {_uvrRep = uvrRep;};
  const char *GetUrl() {return _url;};
  void SetState(CATUVRLoadState loadState) {_loadState = loadState;};
  CATUVRLoadState GetState() {return _loadState;};
  CATRep *_uvrRep;
  void Stream(CATStreamer & str);
  void UnStream(CATStreamer & str);
protected:
  virtual const vDrawInformation* GetDrawInformation();
  //CATViz3DBox *_box;
  char *_url;
  CATUVRLoadState _loadState;
};

#endif
