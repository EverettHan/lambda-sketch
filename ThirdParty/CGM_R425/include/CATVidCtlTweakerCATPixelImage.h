// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidCtlTweakerCATPixelImage.h
// Header definition of CATVidCtlTweakerCATPixelImage
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2008  Creation: jov
//===================================================================
#ifndef CATVidCtlTweakerCATPixelImage_H
#define CATVidCtlTweakerCATPixelImage_H

#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

class CATPixelImage;

class ExportedByVisuDialogEx CATVidCtlTweakerCATPixelImage: public CATVidCtlTweaker
{
  CATDeclareClass;
public:
  // Standard constructors and destructors
  // -------------------------------------
   CATVidCtlTweakerCATPixelImage ();

   void SetIconPixelImage(const CATPixelImage* i_pPixel );
   CATPixelImage* GetIconPixelImage() const;
   void SetTweakerData(const CATPixelImage* i_pPixel );
   CATPixelImage* GetTweakerData() const;

   virtual CATBaseUnknown_var GetData() const;
   virtual HRESULT SetData(const CATBaseUnknown_var& i_spData);

  protected:
    virtual ~CATVidCtlTweakerCATPixelImage ();

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATVidCtlTweakerCATPixelImage (CATVidCtlTweakerCATPixelImage &);
    CATVidCtlTweakerCATPixelImage& operator=(CATVidCtlTweakerCATPixelImage& original);

    CATPixelImage* _pTweakerData;
};
//-----------------------------------------------------------------------

#endif
