// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// AfrMePreferenceLightDocument
//
//=============================================================================

#ifndef AfrMePreferenceLightDocument_H
#define AfrMePreferenceLightDocument_H

//---------------------------------------------------------------------- Dialog
#include "CATDlgDocument.h"
#include "CATAfrPreferenceModel.h"

class AfrMePreferenceLightDocument;
extern AfrMePreferenceLightDocument* pMonDoc;

class CATViewer;
class CATNavigation3DViewer;

class ExportedByCATAfrPreferenceModel AfrMePreferenceLightDocument : public CATDlgDocument
{
  public:
    AfrMePreferenceLightDocument( CATInteractiveApplication* ipFather );
    ~AfrMePreferenceLightDocument();

    CATViewer* GetViewer( );

  private:
    // must not be implemented for data extension
    AfrMePreferenceLightDocument (AfrMePreferenceLightDocument &);
    AfrMePreferenceLightDocument& operator=(AfrMePreferenceLightDocument&);

    void CreateFrmContext( );
    void Initialize( );
    void CreateViewer( );

    CATNavigation3DViewer*           _p3DViewer;
};

#endif
