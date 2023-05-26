// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATVidVectorImageRenderParams.h
// Header definition of CATVidVectorImageRenderParams
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  2014 Creation: efm
//===================================================================
#ifndef CATVidVectorImageRenderParams_H
#define CATVidVectorImageRenderParams_H

#include <VisuDialog.h>
#include <CATMathPoint2Df.h>
#include <CATVidMargin.h>

class ExportedByVisuDialog CATVidVectorImageRenderParams
{
public:
  /** Constructor */
  CATVidVectorImageRenderParams ();
  /** Destructor */
  virtual ~CATVidVectorImageRenderParams ();
  /** Copy constructor*/
  CATVidVectorImageRenderParams (const CATVidVectorImageRenderParams &i_original);
  /** operator = */
  CATVidVectorImageRenderParams& operator=(const CATVidVectorImageRenderParams& i_original);
  /** operator == */
  CATBoolean operator==(const CATVidVectorImageRenderParams& i_right) const;
  /** operator != */
  CATBoolean operator!=(const CATVidVectorImageRenderParams& i_right) const;

  /**
  * The size applied to the Vector Image Renderer before image rasterization.
  * @param iSize
  */
  void SetSize(const CATMathPoint2Df& iSize);
  /**
  * @see SetSize
  */
  const CATMathPoint2Df& GetSize() const;
   /**
  * The document margins applied to the Vector Image Renderer before image rasterization.
  * @param iMargins
  */
  void SetMargins(const CATVidMargin& iMargins);
  /**
  * @see SetMargins
  */
  const CATVidMargin& GetMargins() const;
  /**
  * Specify if all strokes will be scaled based on the image size or not during rasterization.
  * @param iScalableStrokeWidth
  */
  void SetScalableStrokeWidth(const unsigned int iScalableStrokeWidth);
  /**
  * @see SetScalableStrokeWidth
  */
  const unsigned int GetScalableStrokeWidth() const;
  /**
  * Indicates if the related image will have to be recomputed during resize operations or not.
  * @param iDynamic
  */
  void SetIsDynamic(const unsigned int iDynamic);
  /**
  * @see SetIsDynamic
  */
  const unsigned int GetIsDynamic() const;
  /**
  * Serialize parameters to an output string
  * @param o_string the output serialized string
  */
  HRESULT Serialize(CATUnicodeString& o_string);
  
private:
  CATMathPoint2Df _size;
  CATVidMargin _margins;
  unsigned int _scalableStrokeWidth;
  unsigned int _dynamic;

};
//-----------------------------------------------------------------------

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidVectorImageRenderParamsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);


#endif
