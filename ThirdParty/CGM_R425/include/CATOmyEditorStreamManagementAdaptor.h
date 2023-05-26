/* -*-c++-*- */

#ifndef CATOmyEditorStreamManagementAdaptor_h
#define CATOmyEditorStreamManagementAdaptor_h

/**
 * @level Protected
 * @usage U2
 */

#include "CATIOmyEditorStreamManagement.h"

/**
 * Adaptor class for @href CATIOmyEditorStreamManagement
 */

class ExportedByCATOMYBaseSession CATOmyEditorStreamManagementAdaptor : public CATIOmyEditorStreamManagement
{
 public :
  CATOmyEditorStreamManagementAdaptor();
  virtual ~CATOmyEditorStreamManagementAdaptor();
  
  /**
   * @see CATIOmyEditorStreamManagement#PrepareEditorStreaming
   */
  virtual HRESULT PrepareEditorStreaming();

};


#endif
