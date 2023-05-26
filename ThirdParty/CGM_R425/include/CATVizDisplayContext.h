#ifndef CATVizDisplayContext_H
#define CATVizDisplayContext_H

// COPYRIGHT DASSAULT SYSTEMES 2002
#define NB_VISU_LINETYPE 63

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class ExportedBySGInfra CATVizDisplayContext : public CATBaseUnknown
{
   public:
   
     /**
      *  Constructor.
      */
      CATVizDisplayContext();
      
     /**
      *  Destructor.
      */
      virtual ~CATVizDisplayContext();
      
      
     /** 
      * Set the display and print values for line thickness.
      *  @param  iPixel      Array of 55 weight's values in pixel for each index.
      *  @param  iMM         Array of 55 weight's values in millimeter for each index.
      *  @param  iVisibility Array of 55 weight's values visibility for each index.
      */ 
      void SetThicknessTable(unsigned short iPixel[55], float iMM[55], unsigned short iVisibilty[55]);
      
     /**
      * Returns the weight's value in pixel for the given index.
      *  @param iIndex Weight index.
      */
      unsigned short GetThicknessInPixel(int iIndex);
      
     /**
      * Returns the weight's value in millimeter for the given index.
      *  @param iIndex Weight index.
      */
      float GetThicknessInMM(int iIndex);
      
     /**
      * Returns the combo weight's visibility for the given index.
      *  @param iIndex Weight index.
      */
      unsigned short GetThicknessVisibility(int iIndex);
      

      void GetLineTypeTable(unsigned int oPattern[NB_VISU_LINETYPE],
                            unsigned int oRatio[NB_VISU_LINETYPE],
                            unsigned int oType[NB_VISU_LINETYPE],
                            unsigned short oLineTypeVis[NB_VISU_LINETYPE]);

      void SetLineTypeTable(unsigned int iPattern[NB_VISU_LINETYPE],
                            unsigned int iRatio[NB_VISU_LINETYPE],
                            unsigned int iType[NB_VISU_LINETYPE],
                            unsigned short iLineTypeVis[NB_VISU_LINETYPE]);

      void GetLinetype(const int iIndex, unsigned short *oPattern, unsigned short *oRatio, unsigned short *oType);
      void SetLinetype(const int iIndex, unsigned short  iPattern, unsigned short  iRatio, unsigned short  iType);

      void GetLinetypeSegments(const int iIndex, unsigned int *oNbSeg, float **oSeg);
      void SetLinetypeSegments(const int iIndex, const unsigned int iNbSeg, const float * iSeg);

      unsigned short GetLineTypeVisibility(int iIndex);
      void SetLineTypeVisibility(int iIndex, unsigned short iVis);

      void GetLineTypeFontName(CATUnicodeString & oFontName, CATUnicodeString & oFontDir);
      void SetLineTypeFontName(const CATUnicodeString & iFontName, const CATUnicodeString & iFontDir);

      static CATUnicodeString currentLineTypeFont;

   private:
      
      void InitLineType();

      /** @nodoc */
      CATVizDisplayContext * _VDC;
      
      CATUnicodeString _LineTypeFontName;
      CATUnicodeString _LineTypeFontDir;

      /** @nodoc */
      float _MM[63];
      
      /** @nodoc */
      unsigned short _Pixel[63];
      
      /** @nodoc */
      unsigned short _Visibility[63];

      unsigned short _LTVis[NB_VISU_LINETYPE];
      unsigned int   _LTPat[NB_VISU_LINETYPE];
      unsigned int   _LTRat[NB_VISU_LINETYPE];
      unsigned int   _LTTyp[NB_VISU_LINETYPE];
      unsigned int   _NbSeg[NB_VISU_LINETYPE];
      float          _DefSeg[NB_VISU_LINETYPE][20];

};
#endif


