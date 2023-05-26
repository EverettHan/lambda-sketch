#ifndef _CATVidBoxing_H
#define _CATVidBoxing_H

#include <CAT4x4Matrix.h>
#include <CATGraphicAttributeSet.h>
#include <CATSYPDeclareBoxing.h>
#include <CATVidBorder.h>
#include <CATVidColor.h>
#include <CATVidFontDescription.h>
#include <CATVidHyperlink.h>
#include <CATVidImageBlender.h>
#include <CATVidLayDockConstraints.h>
#include <CATVidLayGridConstraints.h>
#include <CATVidLayGridWeight.h>
#include <CATVidLaySideAttachConstraints.h>
#include <CATVidMargin.h>
#include <CATVidMinMax.h>
#include <CATVidPalette.h>
#include <CATVidRGB.h>
#include <CATVidRGBA.h>
#include <CATVidRGBAGradient.h>
#include <CATVidRectangle.h>
#include <CATVidTextSelection.h>
#include <CATVidURL.h>
#include <CATVidVectorImageRenderParams.h>
#include <VisuDialog.h>
inline int operator == (const CAT4x4Matrix &i_matrix1, const CAT4x4Matrix &i_matrix2)
{
	float pValues1[16];
	i_matrix1.GetMatrixInFloat(pValues1);
	float pValues2[16];
	i_matrix2.GetMatrixInFloat(pValues2);
  return (pValues1[0]==pValues2[0] && pValues1[1]==pValues2[1] && pValues1[2]==pValues2[2] && pValues1[3]==pValues2[3] && pValues1[4]==pValues2[4] && pValues1[5]==pValues2[5] && pValues1[6]==pValues2[6] && pValues1[7]==pValues2[7] && pValues1[8]==pValues2[8] && pValues1[9]==pValues2[9] && pValues1[10]==pValues2[10] && pValues1[11]==pValues2[11] && pValues1[12]==pValues2[12] && pValues1[13]==pValues2[13] && pValues1[14]==pValues2[14] && pValues1[15]==pValues2[15]);
}


CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidRGB );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidRGBA );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidColor );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidFontDescription );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidLayGridWeight );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATGraphicAttributeSet );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CAT4x4Matrix );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidLaySideAttachConstraints );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidLayGridConstraints );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidImageBlender );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidMargin );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidTextSelection );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidMinMax );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidURL );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidHyperlink );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidRectangle );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidPalette );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidBorder );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidLayDockConstraints );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidVectorImageRenderParams );
CATSYP_DECLARE_BOXING( ExportedByVisuDialog, CATVidRGBAGradient );

#endif
