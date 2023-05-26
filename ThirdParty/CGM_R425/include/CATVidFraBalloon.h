#ifndef CATVidFraBalloon_h
#define CATVidFraBalloon_h

// COPYRIGHT Dassault Systemes 2011

// VisuImmersiveDialog framework
#include "VisuDialog.h"
#include "CATVidFraLabel.h"

class CATVidWidget;
class CATString;

/**
 * Deprecated class. Please use directly the CATVidFraLabel class.
 */
class ExportedByVisuDialog CATVidFraBalloon : public CATVidFraLabel
{
  CATDeclareClass;

  public:

    /**
    * Constructs a CATVidFraBalloon
    * @param i_pParent
    * Parent command
    * @param i_pIdentifier
    * Balloon identifier
    */
    CATVidFraBalloon(CATCommand *i_pParent, const CATString& i_pIdentifier);

    /**
    * Default constructor, used internally.
    */
    CATVidFraBalloon();

  protected:

    virtual ~CATVidFraBalloon();

  private:

    // Copy constructor and equal operator
    // -----------------------------------
    CATVidFraBalloon (CATVidFraBalloon &);
    CATVidFraBalloon& operator=(CATVidFraBalloon&);
};

#endif
