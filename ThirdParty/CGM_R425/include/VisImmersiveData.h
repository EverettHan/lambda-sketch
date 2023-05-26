#ifndef VISIMMERSIVEDATA_H_
#define VISIMMERSIVEDATA_H_

#include "CATVisFoundation.h"
#include "CATVizBaseIUnknown.h"
class CATGraphicWindow;


class ExportedByCATVisFoundation VisImmersiveData : public CATVizBaseIUnknown
{
public :

  // data of one support for multipipe scenario
  VisImmersiveData (CATGraphicWindow* ipGW);

  ~VisImmersiveData ();

  // activate the mirroring
  bool IsHMDMirroringActivated() const;
  void SetHMDMirroringActivation(bool activated);

  // activate the mirroring
  bool IsHMDMirroringSideBySideActivated() const;
  void SetHMDMirroringSideBySideActivation(bool activated);

  // activate the watermark
  bool IsWatermarkActivated() const;
  void SetWatermarkActivation(bool activated);
  unsigned int GetWatermarkVOffset() const;
  void SetWatermarkVOffset(unsigned int iVOffset);

  // activate the highlight
  bool IsHighlightActivated() const;
  void SetHighlightActivation(bool activated);

  // activate the prehighlight
  bool IsPreHighlightActivated() const;
  void SetPreHighlightActivation(bool activated);

  // activate openXR
  bool IsOpenXRActivated() const;
  void SetOpenXRActivation(bool activated);

protected :
  CATGraphicWindow* _pGW;

private :

  bool _hmdMirroringSideBySide = false;
  // mirroring
  bool _hmdMirroringActivation;

  // watermark
  bool _watermarkActivation;
  unsigned int _watermarkVOffset;

  // highlight
  bool _highlightActivation;

  // prehighlight
  bool _prehighlightActivation;

  // openXR
  bool _openXRActivation;

  // not allowed
  VisImmersiveData ();
  VisImmersiveData (const VisImmersiveData &);
  VisImmersiveData& operator=(const VisImmersiveData&);
};


#endif /* VisImmersiveData_H_ */
