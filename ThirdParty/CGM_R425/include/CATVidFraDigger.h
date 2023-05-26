#ifndef CATVidFraDigger_h
#define CATVidFraDigger_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidFraLabel.h>
#include <CATVidColor.h>

class CATString;

/**
 * @ingroup VIDFrame
 */
class ExportedByVisuDialog CATVidFraDigger : public CATVidFraLabel
{
  CATDeclareClass;

  public:

    /**
     * Constructs a CATVidFraDigger
     * @param i_pParent
     * Parent command
     * @param i_pIdentifier
     * Label identifier
     */
    CATVidFraDigger(CATCommand *i_pParent, const CATString& i_pIdentifier);

    /**
     * Default constructor, used internally.
     */
    CATVidFraDigger();

    /**
     * Sets the length of the attached line base (used in the case the attachment is a triangle).
     * By default, the AttachedLineBaseLength property is set to 10.
     */
    void SetAttachedLineBaseLength(float i_attachedLineBaseLength);

    /**
     * Returns the length of the attached line base (used in the case the attachment is a triangle).
     */
    float GetAttachedLineBaseLength() const;

    /**
     * Sets the margin of the attached line base.
     * The margin corresponds to the distance between the attached line base 
     * and the window side on which the anchor point is attached.
     * By default, the AttachedLineBaseMargin property is set to 0.
     * Note that this margin can be negative if you want the attached line to overlap the window.
     */
    void SetAttachedLineBaseMargin(float i_attachedLineBaseMargin);

    /**
     * Returns the margin of the attached line base.
     */
    float GetAttachedLineBaseMargin() const;

    
  protected:

    virtual ~CATVidFraDigger();
    
    void BuildDefaultProperties();

  private:

    // Copy constructor and equal operator
    // -----------------------------------
    CATVidFraDigger (CATVidFraDigger &);
    CATVidFraDigger& operator=(CATVidFraDigger&);
};

#endif // CATVidFraDigger_h
