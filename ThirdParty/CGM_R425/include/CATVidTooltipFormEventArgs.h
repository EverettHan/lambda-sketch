#ifndef CATVidTooltipFormEventArgs_h
#define CATVidTooltipFormEventArgs_h

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATVid.h>
#include <CATMathPoint2Df.h>
#include <CATBoolean.h>

class CATSYPTemplateData;
class CATSYPEvent;

class ExportedByVisuDialog CATVidTooltipFormEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL.
   * @param i_eForm the form of tooltip concerned by the event (short or long 
   * tooltip).
   * @param i_pTemplateData the template data of the tooltip.
   * @param i_iDim the dimension of the tooltip frame.
   */
  CATVidTooltipFormEventArgs(CATSYPEvent * i_pEvent, 
    CATVid::TooltipForm i_eForm, 
    CATSYPTemplateData * i_pTemplateData, 
    const CATMathPoint2Df& i_iDim);

  /** Destroy this class. */
  virtual ~CATVidTooltipFormEventArgs();

  /**
   * @return the form of the tooltip concerned by the event (short or long 
   * tooltip).
   */
  CATVid::TooltipForm GetTooltipForm() const;
  /**
   * @return the template data of the tooltip.
   */
  CATSYPTemplateData * GetTooltipTemplateData() const;
  /**
   * @return the dimension of the tooltip frame.
   */
  CATMathPoint2Df GetTooltipDimension() const;

  /**
   * Specifies whether the tooltip must be displayed or not.
   * By default, the DisplayTooltipFlag property is set to TRUE.
   */
  void SetDisplayTooltipFlag(CATBoolean i_displayTooltipFlag);

  /**
   * Returns TRUE if the tooltip must be displayed, FALSE otherwise.
   */
  CATBoolean GetDisplayTooltipFlag() const;

private:

  /** Copy constructor. */
  CATVidTooltipFormEventArgs (CATVidTooltipFormEventArgs &);
  /** Assignment operator. */
  CATVidTooltipFormEventArgs& operator=(CATVidTooltipFormEventArgs&);

 /** 
  * The form of the tooltip (short or long tooltip).
  */
  const CATVid::TooltipForm _eForm;
  /**
   * The template data of the tooltip (short or long).
   */
  CATSYPTemplateData * _pTemplateData;
  /**
   * The dimension of the tooltip.
   */
  CATMathPoint2Df _pDimension;
  CATBoolean _displayTooltipFlag;

};

#endif // CATVidTooltipFormEventArgs_h
