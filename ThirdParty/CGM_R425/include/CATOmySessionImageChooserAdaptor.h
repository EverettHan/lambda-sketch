/* -*-c++-*- */

/**
 * @level Protected
 * @usage U2
 */

/**
 * Adaptor for CATIOmySessionImageChooser
 */

#ifndef CATOmySessionImageChooserAdaptor_h
#define CATOmySessionImageChooserAdaptor_h

#include "CATIOmySessionImageChooser.h"

class CATListPtrCATOmySessionImageDescriptor;
class CATIOmySessionImageSelection;


class ExportedByCATOMYBaseSession CATOmySessionImageChooserAdaptor : public CATIOmySessionImageChooser
{
 public :
  CATOmySessionImageChooserAdaptor();
    virtual ~CATOmySessionImageChooserAdaptor();

  virtual HRESULT ChooseImage(const CATListPtrCATOmySessionImageDescriptor &iList,  CATIOmySessionImageSelection * iImageOpener);
};

#endif
