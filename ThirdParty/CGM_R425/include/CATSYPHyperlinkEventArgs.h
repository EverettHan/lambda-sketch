// COPYRIGHT Dassault Systemes 2017
//===================================================================
#ifndef CATSYPHyperlinkEventArgs_H
#define CATSYPHyperlinkEventArgs_H
// Local
#include <VisuDialog.h>
#include <CATVidURL.h>
// IntrospectionInfrastructure
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
* Argument for CATVidCtlTextEditor::HyperlinkActivated event.
*
* The event is sent when an hyperlink is activated in the editor.
* The argument contain the URL of the hyperlink.
*/
class ExportedByVisuDialog CATSYPHyperlinkEventArgs : public CATSYPEventArgs
{
public:
  /**
  * Constructor
  */
  CATSYPHyperlinkEventArgs(CATSYPEvent *i_pEvent, const CATVidURL& i_url);
  /**
  * Destructor
  */
  ~CATSYPHyperlinkEventArgs();

  /**
  * @return the URL of the hyperlink.
  */
  const CATVidURL& GetURL()const{return _url;}
private:
  CATSYPHyperlinkEventArgs(CATSYPHyperlinkEventArgs&);
  CATSYPHyperlinkEventArgs& operator=(CATSYPHyperlinkEventArgs&);

  CATVidURL _url;
};

#endif // CATSYPHyperlinkEventArgs_H
