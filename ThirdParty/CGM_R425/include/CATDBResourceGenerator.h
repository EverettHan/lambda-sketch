#ifndef CATDBResourceGenerator_H
#define CATDBResourceGenerator_H
// COPYRIGHT DASSAULT SYSTEMES 1997
//===========================================================================
//
// class CATDBResourceGenerator
//
//===========================================================================
//
// Usage Notes:
//
//===========================================================================
// Feb. 99  Creation     PWR
// Jul. 00  Modification SCA : size_t _length (64 bits)
//===========================================================================
#include "DI0BUILD.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATDlgUtility.h"

class CATUnicodeString;
class CATDBDialog;

//---------------------------------------------------------------------------
class ExportedByDI0BUILD CATDBResourceGenerator
{
 public:

   CATDBResourceGenerator ();
   virtual ~CATDBResourceGenerator ();

   const char *GenerateHeader      (CATDBDialog *iRep) ;
   const char *GenerateDestructor  (CATDBDialog *iRep) ;
   const char *GenerateCode        (CATDBDialog *iRep) ;
   const char *GenerateNLSResource (CATDBDialog *iRep) ;
   const char *GenerateRSCResource (CATDBDialog *iRep) ;
   const char *GenerateSaveFormat  (CATDBDialog *iRep) ;

 private:

   void ManageComponentLayout  (CATDBDialog* rep);
   void ManageContainerLayout  (CATDBDialog* rep);

   void SetResourceName     (CATDBDialog* rep);
   void BuildItem           (CATDBDialog* rep);
   void BuildDocument       (CATDBDialog* rep);
   void BuildDialog         (CATDBDialog* rep);
   void BuildNotify         (CATDBDialog* rep);
   void BuildFile           (CATDBDialog* rep);
   void BuildContainer      (CATDBDialog* rep);
   void BuildSplitter       (CATDBDialog* rep);
   void BuildTabContainer   (CATDBDialog* rep);
   void BuildTabPage        (CATDBDialog* rep);
   void BuildFrame          (CATDBDialog* rep);
   void BuildIconBox        (CATDBDialog* rep);
   void BuildBlackBox       (CATDBDialog* rep);
   void BuildToolBar        (CATDBDialog* rep);
   void BuildStatusBar      (CATDBDialog* rep);
   void BuildBarMenu        (CATDBDialog* rep);
   void BuildSubMenu        (CATDBDialog* rep);
   void BuildContextualMenu (CATDBDialog* rep);
   void BuildPushItem       (CATDBDialog* rep);
   void BuildRadioItem      (CATDBDialog* rep);
   void BuildCheckItem      (CATDBDialog* rep);
   void BuildSeparatorItem  (CATDBDialog* rep);
   void BuildSeparator      (CATDBDialog* rep);
   void BuildLabel          (CATDBDialog* rep);
   void BuildProgress       (CATDBDialog* rep);
   void BuildPushButton     (CATDBDialog* rep);
   void BuildRadioButton    (CATDBDialog* rep);
   void BuildCheckButton    (CATDBDialog* rep);
   void BuildSelectorList   (CATDBDialog* rep);
   void BuildMultiList      (CATDBDialog* rep);
   void BuildCombo          (CATDBDialog* rep);
   void BuildEditor         (CATDBDialog* rep);
   void BuildSpinner        (CATDBDialog* rep);
   void BuildSlider         (CATDBDialog* rep);
   void BuildScrollBar      (CATDBDialog* rep);
   void BuildCustomComponent(CATDBDialog* rep);

   void GenerateNew               (CATDBDialog* rep);
   void GenerateEnd               (CATDBDialog* rep = NULL);
   void GenerateTitle             (CATDBDialog* rep);
   void GenerateMnemonic          (CATDBDialog* rep);
   void GenerateAccelerator       (CATDBDialog* rep);
   void GenerateHelp              (CATDBDialog* rep);
   void GenerateShortHelp         (CATDBDialog* rep);
   void GenerateLongHelp          (CATDBDialog* rep);
   void GenerateIconNames         (CATDBDialog* rep);
   void GenerateBtnTitles         (CATDBDialog* rep);
   void GenerateBtnDefault        (CATDBDialog* rep);
   void GenerateBtnLabels         (CATDBDialog* rep);
   void GenerateText              (CATDBDialog* rep);
   void GenerateRectDimensions    (CATDBDialog* rep);
   void GenerateVisibleTextHeight (CATDBDialog* rep);
   void GenerateVisibleLineCount  (CATDBDialog* rep);
   void GenerateVisibleTextWidth  (CATDBDialog* rep);
   void GenerateMultiColumnTitles (CATDBDialog* rep);
   void GenerateMultiColumnVisibility (CATDBDialog* rep);
   void GenerateMultiColumnTextWidth  (CATDBDialog* rep);
   void GenerateMaxCharacterWidth (CATDBDialog* rep);
   void GenerateProgressRange     (CATDBDialog* rep);
   void GenerateSpinnerRange      (CATDBDialog* rep);
   void GenerateSliderRange       (CATDBDialog* rep);
   void GenerateScrollBarRange    (CATDBDialog* rep);
   void GenerateMagnitude         (CATDBDialog* rep);
   void GenerateCustomCode        (CATDBDialog* rep);
   void Concat ( char * );
   void BuildHeader      (CATDBDialog *iRep) ;
   void BuildDestructor  (CATDBDialog *iRep) ;
   void BuildCode        (CATDBDialog *iRep) ;
   void BuildNLSResource (CATDBDialog *iRep) ;
   void BuildRSCResource (CATDBDialog *iRep) ;
   void BuildSaveFormat  (CATDBDialog *iRep) ;

   int ProcessCustomCode (CATDBDialog * iRep, CATUnicodeString & CustomCode, CATUnicodeString & oProcessedString);

   char * _Buffer;
   // Jul. 00  Modification SCA : size_t _length (64 bits)
   size_t _length;
   int    _Alloc;
   int    _code;
   int    _nlsResource;
   int    _rscResource;
   int    _save;
   int    _CatalogLoaded;
   CATString _ResourcePrefix;
   CATString _DialogName;
};
#endif
