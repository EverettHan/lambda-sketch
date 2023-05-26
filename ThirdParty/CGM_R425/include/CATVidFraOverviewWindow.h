#ifndef CATVidFraOverviewWindow_h
#define CATVidFraOverviewWindow_h

// COPYRIGHT Dassault Systemes 2014

// VisuImmersiveDialog framework
#include "VisuDialog.h"
#include "CATVidFraWindow.h"

class CATString;
class CATVidLaySideAttachConstraints;

/**
 * Class representing a top floating window.
 * 
 * Warning : the CATVidFraOverviewWindow class usage is restricted, please do not use it without authorization.
 * @ingroup VIDFrame
 */
class ExportedByVisuDialog CATVidFraOverviewWindow : public CATVidFraWindow
{
  CATDeclareClass;

  public:

    /**
     * Constructs a CATVidFraOverviewWindow
     * @param i_pParent
     * Parent command
     * @param i_pIdentifier
     * Label identifier
     */
    CATVidFraOverviewWindow(CATCommand *i_pParent, const CATString& i_pIdentifier);

    /**
     * Default constructor, used internally.
     */
    CATVidFraOverviewWindow();

    /**
     * Sets the float constraints used to position the window. 
     * If the constraints has a compact flag equal to TRUE, this method
     * will set the compact flag of the window to TRUE.
     * To recover a non compact window, SetCompactFlag(FALSE) must excplicitely be called.
     */
    void SetFloatConstraints(const CATVidLaySideAttachConstraints& i_constraints);

    /**
     * Returns the float constraints used to position the window. 
     */
    const CATVidLaySideAttachConstraints& GetFloatConstraints() const;

  protected:

    virtual ~CATVidFraOverviewWindow();
    
    void BuildDefaultProperties();

  private:

    virtual void Build();

    // Copy constructor and equal operator
    // -----------------------------------
    CATVidFraOverviewWindow (CATVidFraOverviewWindow &);
    CATVidFraOverviewWindow& operator=(CATVidFraOverviewWindow&);
};

#endif // CATVidFraOverviewWindow_h
