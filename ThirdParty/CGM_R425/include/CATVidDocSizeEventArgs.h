//===================================================================
// COPYRIGHT Dassault Systemes 2014-08-27
//===================================================================
// 2014-08-27 Creation: D6K
//===================================================================

#ifndef CATVidDocSizeEventArgs_H
#define CATVidDocSizeEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>

class ExportedByVisuDialog CATVidDocSizeEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidDocSizeEventArgs(CATSYPEvent* i_pEvent, const int i_docWidth, const int i_docHeight);
  ~CATVidDocSizeEventArgs();

  void GetDocumentSize(int& o_docWidth, int& o_docHeight) const;

private:
  CATVidDocSizeEventArgs();
  CATVidDocSizeEventArgs(const CATVidDocSizeEventArgs&);
  CATVidDocSizeEventArgs& operator=(const CATVidDocSizeEventArgs&);

  const int _documentWidth;
  const int _documentHeight;
};

#endif
