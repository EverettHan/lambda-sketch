#ifndef CATVidLayStackConstraints_h
#define CATVidLayStackConstraints_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidLayConstraints.h>
#include <CATBoolean.h>

/**
 * @ingroup VIDLayout
 * Layout constraints used by the CATVidLayStack class.
 * @see CATVidLayStack
 */
class ExportedByVisuDialog CATVidLayStackConstraints : public CATVidLayConstraints
{
  CATDeclareClass;
public:

  // Standard constructors and destructors
  CATVidLayStackConstraints ();
  virtual ~CATVidLayStackConstraints ();

  // Copy constructor and equal operator
  CATVidLayStackConstraints (const CATVidLayStackConstraints& i_original);
  CATVidLayStackConstraints& operator=(const CATVidLayStackConstraints& i_original);

  enum Attachment
  {
    NoAttachment = 0, 
    StretchAttachment
  };

  /**
   * Specifies the attachment policy of the associated widget.
   * Possible values for the Attachment property :
   *   - NoAttachment : no influence on the widget dimension
   *   - StretchAttachment : the widget is stretched vertically if the CATVidLayStack 
   * orientation is set to CATVid::Horizontal, or horizontally if the orientation is set
   * to CATVid::Vertical. The StretchAttachment policy is taken into account whatever the CompactFlag
   * property value is.
   * By default, the Attachment property is set to NoAttachment.
   */
  void SetAttachment(CATVidLayStackConstraints::Attachment i_attachment);
  CATVidLayStackConstraints::Attachment GetAttachment() const;

  /**
   * Specifies whether the associated widget must take all the remaining space of the CATVidLayStack or not.
   * By default the FillingFlag property is set to FALSE.
   * There can be only one widget per CATVidLayStack with the FillingFlag property set to TRUE.
   */
  void SetFillingFlag(CATBoolean i_fillingFlag);
  CATBoolean GetFillingFlag() const;

  virtual CATVidLayConstraints* Clone() const; 
  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const;

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);

private:

  Attachment _attachment;
  CATBoolean _fillingFlag;
};

#endif // CATVidLayStackConstraints_h
