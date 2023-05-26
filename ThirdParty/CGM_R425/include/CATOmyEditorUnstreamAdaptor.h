/* -*-c++-*- */

/**
* @level Protected
* @usage U2
*/

/**
* Adaptor for CATIOmyEditorUnstream
*/

#ifndef CATOmyEditorUnstreamAdaptor_h
#define CATOmyEditorUnstreamAdaptor_h

#include "CATIOmyEditorUnstream.h"

class CATOmyEditor;

class ExportedByCATOMYBaseSession CATOmyEditorUnstreamAdaptor : public CATIOmyEditorUnstream
{
public :
  CATOmyEditorUnstreamAdaptor();
  virtual ~CATOmyEditorUnstreamAdaptor();

  /**
  * see CATIOmyEditorUnstream::UnstreamEditor
  */
  virtual HRESULT UnstreamEditorToRegistry(CATOmyEditorRegistry * iRegistry,
    unsigned char* iBuffer, CATLONG32& iNbCell, CATOmyEditor*& oEditor);

  /**
  * deprecated
  */
  virtual HRESULT UnstreamEditor(int& iEditorId,unsigned char* iBuffer,
    CATLONG32& iNbCell, CATOmyEditor*& oEditor);
};

#endif
