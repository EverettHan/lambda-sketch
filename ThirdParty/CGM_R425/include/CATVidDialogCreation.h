#ifndef CATVidDialogCreation_H
#define CATVidDialogCreation_H

// ----------------------------------------------------------------------------
// DEPRECATED FUNCTIONS. Use CATVidFraUtilities.h
// ----------------------------------------------------------------------------

#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATVidFraUtilities.h>
#include <CATVidEnum.h>

class CATVidModelWidget;
class CATVidLayConstraints;
class CATUnicodeString;
class CATVidFraDialogBox;
class CATVidLayDockConstraints;
class CATVidLaySideAttachConstraints;
class CATVizViewer;
class CATVidFraLayoutData;
class CATVidFraBoxProperties;

//++DEPRECATED
ExportedByVisuDialog 
CATVidFraDialogBox* CATVidCreateDialog(CATVidModelWidget* i_pApplicativeWidget // Applicative Widget created by user.
                        , CATVidLayConstraints* i_pConstraints  // Constraints to use when dialog is immersive
                        , const CATUnicodeString& i_iconName    // Name of the icon, located in the ressources
                        , CATVidDialogType i_dialogType         // immersive or extracted box
                        , CATVidLifeCycle i_dialogLifeCycle     // bind to application or document lifeCycle.
                        , CATVidStyle i_dialogStyle             // immersive dialog box properties
                        );

ExportedByVisuDialog 
CATVidFraDialogBox* CATVidCreateDialog(CATVidModelWidget* i_pApplicativeWidget // Applicative Widget created by user.
                        , CATVidLayConstraints* i_pConstraints  // Constraints to use when dialog is immersive
                        , const CATUnicodeString& i_title
                        , const CATUnicodeString& i_iconName    // Name of the icon, located in the ressources
                        , CATVidDialogType i_dialogType         // immersive or extracted box
                        , CATVidLifeCycle i_dialogLifeCycle     // bind to application or document lifeCycle.
                        , CATVidStyle i_dialogStyle             // immersive dialog box properties
                        );

ExportedByVisuDialog 
CATVidFraDialogBox* CATVidCreateDialog(CATVidModelWidget* i_pApplicativeWidget 
                        , CATVidLaySideAttachConstraints* i_pConstraints 
                        , CATVidLayDockConstraints* i_pDockConstraints  
                        , const CATUnicodeString& i_title       
                        , const CATUnicodeString& i_iconName 
                        , CATVidDialogType i_dialogType    
                        , CATVidLifeCycle i_dialogLifeCycle 
                        , CATVidStyle i_dialogStyle         
                        , CATVizViewer* i_pVizViewer = 0
                        );

//--DEPRECATED
#endif
