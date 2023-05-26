#ifndef CATVizCursor_h_
#define CATVizCursor_h_
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
        
/* COPYRIGHT DASSAULT SYSTEMES 2002 */


#include "CATVisFoundation.h"

// JOV pour enlever des erreurs chez les clients, dues a VizCursor.
#define CATVIEWPOINTEDITOR_NODIALOG

class ExportedByCATVisFoundation CATVizCursor 
{
public :
  enum CATVizStyle
  {
    CATNorthWestArrow                  =1,
    CATCross                           =2,
    CATNorthHand                       =3,
    CATNorthWestHand                   =4,
    CATNoArrow                         =5,
    CATMoveArrow                       =6,
    CATNorthSouthArrow                 =7,
    CATTarget                          =8,
    CATForward                         =9,
    CATBackward                        =10,
    CATOpenedHand                      =11,
    CATMagnifier                       =12,
    CATClosedHand                      =13,
    CATNoEntry                         =14,
    CATMeasureItemSeek                 =15,
    CATMeasureItemOnTarget             =16,
    CATMeasureItemOnTargetPlus         =17,
    CATMeasureItemOnTargetMinus        =18,
    CATMeasureBetweenOnFirstTarget     =19,
    CATMeasureBetweenOnSecondTarget    =20,
    CATMeasureThreePointsOnFirstPoint  =21,
    CATMeasureThreePointsOnSecondPoint =22,
    CATMeasureThreePointsOnThirdPoint  =23,
    CATEastWestArrow                   =24,
    CATEastArrow                       =25,
    CATNorthWestSmallArrow             =26,
    CATNorthWestSmallArrowWithPoint    =27,
    CATNorthWestSmallArrowWithEdge     =28,
    CATNorthWestSmallArrowWithFace     =29,
    CATNorthWestContextualArrow        =30        
  };

  CATVizCursor() {};
  virtual ~CATVizCursor();

  virtual CATVizStyle ChangeCursor(CATVizStyle);
};


#endif
