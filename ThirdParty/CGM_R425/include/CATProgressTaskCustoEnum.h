
#ifndef CATProgressTaskCustoEnum_H
#define CATProgressTaskCustoEnum_H

// COPYRIGHT Dassault Systemes 2010

/**
* Progress task mode.
* <br>The default mode is Finite, the existing Progress task.
* <br>Infinite, the Progress task is infinite.
* this enum lists the possible values of the progress mode.
* <br> Finite will display the finite task(@see CATIProgressTaskUI)
* <br> Infinite will display the infinite progress task.
*/
enum CATAfrProgressTaskMode{ Finite  = 0, 
                             Infinite = 1 };

/**
* Progress task panel mode.
* <br>The default mode is Modal, the existing Progress task.
* <br>NoModal, the panel is no modal.
* this enum lists the possible values of the mode.
* <br> Modal will display the panel in modal mode.
* <br> NoModal will display the panel in no modal mode.
*/
enum CATAfrProgressTaskWindMode{ Modal  = 0, 
                                 NoModal = 1 };

/**
* Progress task panel type.
* <br>The default mode is Popup, the existing Progress task.
* <br>Popup, the classic panel.
* this enum lists the possible values of the mode.
* <br> Popup will display the panel in classic mode(MFC,...)
* <br> Immersive will display the panel in CID mode. Automaticly, the panel is in no modal mode
*/
enum CATAfrProgressTaskPanelStyle{ Popup  = 0, 
                                   Immersive = 1 };

/**
* Position of the infinite immersive Progress task.
* <br>The default mode is ScreenCenter, the progress task is diplayed in the center of the screen.
* <br> ScreenCenter will display the infinite task in the middle of the screen
* <br> BottomCenter will display the infinite progress task Above the PLM Compass.
*/
enum CATAfrProgressTaskPosition{ ScreenCenter  = 0, 
                                 BottomCenter  = 1 };

/**
* Type of the infinite immersive Progress task.
* <br>The default mode is Linear, the progress task is diplayed in the linear mode.
* <br> Linear will display the infinite linear task.
* <br> Circular will display the infinite Circular progress task.
*/
enum CATAfrProgressTaskCIDType{ Linear   = 0, 
                                Circular = 1, 
                                CAfrProgressTask = 2 };


#endif
