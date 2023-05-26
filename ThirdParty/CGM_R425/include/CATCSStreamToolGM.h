#ifndef CATCSStreamToolGM_h
#define CATCSStreamToolGM_h

#include "CATCDSVirtual.h"
#include "StreamGM.h"
#include "CATCSStreamTool.h"
#include "CATCDSString.h"

class CATCDSStream;
class CATCSCurve;
class CATCSSkin;
class CATCSSkinParam;

// section names generated in the replay
static char const * const chStreamObjectsSection = "#!STREAMOBJECTS";
static char const * const chStreamParametersSection = "#!STREAMPARAMETERS";

class ExportedByStreamGM CATCSStreamToolGM : public CATCSStreamTool
{
public :
  CATCSStreamToolGM(CATCDSBoolean iCATICDSMode = FALSE, CATCDSStreamMode iMode = smSTREAM);
  virtual ~CATCSStreamToolGM();

  CATCDSStreamMode GetStreamMode() CATCDSOverride {return _StreamMode;};
  void ForceDataFileName(const char * iaDataFileName);

  void BeginStream(const char * iaReplayName) CATCDSOverride;
  void BeginStream(CATCDSStream & ioStream, const char * iaReplayName) CATCDSOverride; 
  void EndStream() CATCDSOverride;

  unsigned int Stream2DCurve(CATCSCurve2D * ipCurve, unsigned int & oType) CATCDSOverride;
  unsigned int Stream3DCurve(CATCSCurve * ipCurve, unsigned int & oType) CATCDSOverride;
  unsigned int StreamSkin(CATCSSkin * ipSkin, unsigned int & oType) CATCDSOverride;
  unsigned int StreamSkinParam(CATCSSkinParam * ipSkinParam, unsigned int & oType) CATCDSOverride;
  unsigned int StreamEquation(CATCSEquation * ipEquation, unsigned int & oType) CATCDSOverride;
  unsigned int StreamSurface(CATCSSurface * ipSurface, unsigned int & oType) CATCDSOverride;

protected:
  void ClearInternalData();
  void InitializeFilenameAndPath(const char * iaReplayName);
  void GenerateDataFileName(unsigned int & iIndex, const char* iExtension, CATCDSString & oFileName);

private:
  CATCDSStreamMode _StreamMode;

  // specific smSTREAM mode
  // ----------------------
  
  void DeleteLists();

  CATCDSStream * _pStream;
  CATCDSLISTP(CATCDSString) _ListObjName;
  CATCDSLISTP(CATCDSString) _ListObjType;
  CATCDSLISTP(CATCDSString) _ListObjStr;
  CATCDSLISTP(CATCDSString) _ListParamStr;

  // specific smFILE mode
  // --------------------

  //const char * _ForcedReplayName;
  const char * _ForcedDataFileName;
  char * _FileName;
  char * _Path;
  int _3DCurveIdx;
  int _2DCurveIdx;
  int _SurfaceIdx;
  int _SkinIdx;
  int _SkinParamIdx;
  CATCDSBoolean _CATICDSMode;
};

#endif
