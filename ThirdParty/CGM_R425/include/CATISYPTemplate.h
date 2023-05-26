// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef CATISYPTemplate_h
#define CATISYPTemplate_h
// System framework
#include <CATBaseUnknown.h>
#include <CATStyleProcessor.h>

class CATUnicodeString;
class CATSYPTemplateData;

extern ExportedByCATStyleProcessor IID IID_CATISYPTemplate;
/**
 * This interface provide the template name and variation name that will
 * be used by the style processor to find and build a template of an introspectable object.
 * Any object that must be processed with a corresponding template by CATSYPStyleProcessor 
 * must implement this interface.
 * @see CATSYPStyleProcessor
 */
class ExportedByCATStyleProcessor CATISYPTemplate : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * The style processor will use this name to recover a template, associated to
   * the variation name and the IsA value of the implementation.
   * It can be called on an object before to process it with the style processor, 
   * or it can be called directly by the style processor.
   * or can be called by application, before to process an object by the style processor.
   * @param i_templateName the name of the template to associate to the object.
   */
  virtual void SetTemplateName(const CATUnicodeString& i_templateName) = 0;
  /**@return the template name*/
  virtual const CATUnicodeString& GetTemplateName() const = 0;
  /**
   * The style processor will use this name to recover a template, associated to
   * the template name and the IsA value of the implementation.
   * This property is used to define variations of a same template. For example a slider
   * can be horizontal or vertical. So for a same look (corresponding to a template name), 
   * to templates will have to be defined. This variation name have to be setted by the Object, 
   * and is a part of its model. In a slider, a SetOrientation method will internally modify the 
   * variation name if its representation, and refresh it.
   * Note that an templated object must declare its variation, so people creating its representation template
   * can create all the required variations.
   * Note that if no variation name is assigned, a default template will be used.
   * @param i_variationName the name of the variation of the template to associate to the object.
   */
  virtual void SetVariationName(const CATUnicodeString& i_variationName) = 0;
  /** @return the variation name */
  virtual const CATUnicodeString& GetVariationName() const = 0;
  /**
   * Sets the view representing the template. This view has been build by the styleprocessor, 
   * on the implementation instance of the object. 
   * Note that this view is connected by introspection to some properties of the implementation extended 
   * by this interface.
   * Sets the template instance data. 
   * Called by the style processor. It will release the i_pTemplateData.
   * Note that the destruction of the input CATBaseUnknown_var will involve the call of Release on the view.
   * @param i_spView
   * @param i_pTemplateData the template data
   * @see CATSYPTemplateData
   */
  virtual void SetTemplatedView(CATBaseUnknown_var& i_spView, CATSYPTemplateData* i_pTemplateData)=0;
};

CATDeclareHandler(CATISYPTemplate, CATBaseUnknown);

#endif // CATISYPTemplate_h
