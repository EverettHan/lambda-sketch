//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/07/29
//===================================================================
//  2010/07/29 Creation: jov
//===================================================================
#ifndef CATVidPalette_H
#define CATVidPalette_H

#include <VisuDialog.h>
#include <CATVidRGB.h>
#include <CATSYPHashMap.h>
#include <CATSYPEnumBitField.h>
#include <CATSYPDeclareEnumFactory.h>
#include <CATSYPArray.h>

// To be able to remove #include <CATSYPEnumFactory.h> to prevent include of <nlohmann/json.hpp>
// following include is mandatory else a lot of client fws do not compile...
#include <CATBasicBoxing.h>

//-----------------------------------------------------------------------
/**
 * Value class that specify a palette sheet on a widget tree. 
 * This class use implicit sharing, that means that it can be passed
 * directly by value to method and functions without any costly copy 
 * constructor overhead.
 */
class ExportedByVisuDialog CATVidPalette
{
public:
  /**
   * The color role defining the logical colors. 
   */
  enum ColorRole
  {
    /** No role, indicating that the color is physical */
    NoRole                   = 0,
    /** Used in background of window */
    WindowBackground,
    /** Used in foreground of window*/
    WindowForeground,
    /** Used in background of list for example*/
    BaseBackground,
    /** Used in list to alternate background color*/
    AlternateBaseBackground,
    /** Used in foreground of list*/
    BaseForeground,
    /** Used in background of plain buttons */
    ButtonBackground,
    /** Used in foreground of plain buttons */
    ButtonForeground,
    /** Used in background of tooltip */
    TooltipBackground,
    /** Used in foreground of tooltip */
    TooltipForeground,
    /** Used for text that need to be enlighted, for example for pressed push button.*/
    BrightForeground,
    /** Used in background to indicate a selected list item */
    HighlightBackground,
    /** Used in foreground to indicate a selected list item */
    HighlightForeground,
    /** Used in background for a preselected list item */
    PreHighlightBackground,
    /** Used in foreground to indicate a preselected list item */
    PreHighlightForeground,
    /** Used in background for a list item hovered during drag-and-drop */
    DnDHighlightBackground,
    /** Used in foreground for a list item hovered during drag-and-drop */
    DnDHighlightForeground,
    /** Used for unvisted hyperlinks */
    LinkForeground,
    /** Used for visted hyperlinks */
    LinkVisitedForeground,
    /** Used for editor background*/
    EditBackground,
    /** Used for editor foreground*/
    EditForeground,
    /** Used for selected text background in an editor*/
    EditHighlightBackground,
    /** Used for selected text in an editor*/
    EditHighlightForeground,
    /** Used in background of window title*/
    WindowTitleBackground,
    /** Used in background of window title*/
    WindowActivatedTitleBackground,
    /** Used in foreground of window title*/
    WindowTitleForeground,

    FirstLayerBackground,
    FirstLayerStroke,
    FirstLayerInnerShadow,
    FirstLayerOuterShadow,
    FirstLayerText,
    FirstLayerSelected,
    FirstLayerSelectionBackground,
    FirstLayerSelectionStroke,
    FirstLayerSelectionInnerShadow,

    FirstLayerHoverBackground,
    FirstLayerHoverStroke,
    FirstLayerHoverInnerShadow,
    FirstLayerHoverOuterShadow,
    FirstLayerHoverText,
    FirstLayerHoverSelected,
    FirstLayerHoverSelectionBackground,
    FirstLayerHoverSelectionStroke,
    FirstLayerHoverSelectionInnerShadow,

    LastLayerBackground,
    LastLayerStroke,
    LastLayerInnerShadow,
    LastLayerOuterShadow,
    LastLayerText,
    LastLayerSelected,
    LastLayerSelectionBackground,
    LastLayerSelectionStroke,
    LastLayerSelectionInnerShadow,

    LastLayerHoverBackground,
    LastLayerHoverStroke,
    LastLayerHoverInnerShadow,
    LastLayerHoverOuterShadow,
    LastLayerHoverText,
    LastLayerHoverSelected,
    LastLayerHoverSelectionBackground,
    LastLayerHoverSelectionStroke,
    LastLayerHoverSelectionInnerShadow,

    DisabledBackground,
    DisabledStroke,
    DisabledInnerShadow,
    DisabledOuterShadow,
    DisabledText,
    DisabledSelected,
    DisabledSelectionBackground,
    DisabledSelectionStroke,
    DisabledSelectionInnerShadow,

    EditorBackground,
    EditorInnerShadow,
    EditorText,

    BoxBackground,
    BoxStroke,
    BoxInnerShadow,
    BoxOuterShadow,

    WidgetBackground,
    WidgetHeader,
    WidgetStroke,
    WidgetText,
    WidgetSelection,
    DashboardBackground,

    PanelInactiveTabBackground,
    PanelInactiveTabGradient,
    PanelInactiveTabInnerShadow,
    PanelInactiveTabText,

    PanelInactiveTabHoverBackground,
    PanelInactiveTabHoverGradient,
    PanelInactiveTabHoverInnerShadow,
    PanelInactiveTabHoverText,

    PanelActiveTabBackground,
    PanelActiveTabGradient,
    PanelActiveTabInnerShadow,
    PanelActiveTabText,

    PanelActiveTabHoverBackground,
    PanelActiveTabHoverGradient,
    PanelActiveTabHoverInnerShadow,
    PanelActiveTabHoverText,

    PanelPinnedTabBackground,
    PanelPinnedTabGradient,
    PanelPinnedTabInnerShadow,
    PanelPinnedTabText,

    PanelPinnedTabHoverBackground,
    PanelPinnedTabHoverGradient,
    PanelPinnedTabHoverInnerShadow,
    PanelPinnedTabHoverText,

    PanelHeaderBackground,
    PanelHeaderGradient,
    PanelStroke,
    PanelHeaderOuterShadow,
    PanelTopHeaderBackground,

    ColorBackgroundGray,
    ColorIconGray,
    ColorCopyGray,
    ColorDarkGray,
    Color3DSCorporateSteelBlue,
    ColorDarkBlue,
    ColorMediumBlue,
    ColorLightSteel,
    ColorSteelBlue,
    ColorDarkSteel,
    ColorDarkGreen,
    ColorMediumGreen,
    ColorMediumOrange,
    ColorDarkOrange,
    ColorDarkRed,
    ColorMediumRed,
    ColorDarkCyan,
    ColorMediumCyan,
    ColorFooterGray,
    ColorOutlineGray,
    ColorOutlineDarkGray,
    ColorSectionGray,

    DarkBackground,
    DarkImportantBackground,
    DarkHighlighted,
    DarkTintColor,
    DarkImportantLabel,
    DarkLabel,
    DarkUIGlyph,
    LightBackground,
    LightImportantBackground,
    LightHighlighted,
    LightTintColor,
    LightImportantLabel,
    LightLabel,
    LightUIGlyph
  };
  CATSYP_DECLARE_ENUM_BIT_FIELD(ColorRoleBitField, ColorRole);

  /**
   * Constructor.
   */
  CATVidPalette ();
  /**
   * Destructor.
   */
  virtual ~CATVidPalette ();
  /**
   * Copy constructor.
   */
  CATVidPalette (const CATVidPalette & i_palette);
  /**
   * Equal operator.
   */
  CATVidPalette& operator=(const CATVidPalette& i_palette);
  /**
   * == operator.
   */
  int operator==(const CATVidPalette &) const;
  /**
   * Associates a color to a role on the palette.
   */
  void SetColor(CATVidPalette::ColorRole i_role, const CATVidRGB& i_color);
  /**
   * Gets a color associated to a role, if it has been set directly on it.
   * @param i_role the logical role from which the color is retrieved.
   * @param o_color the color to retrieve.
   * @return 1 if the logical role has been defined on this palette, 0 otherwise.
   */
  int GetColor(CATVidPalette::ColorRole i_role, CATVidRGB& o_color) const;

  void GetDefinedColorRolesAndColors(CATSYPDynArray<CATVidPalette::ColorRole>& o_colorRolesArray, CATSYPDynArray<CATVidRGB>& o_colorsArray) const;
private:
  CATSYPHashMap<int, CATVidRGB> _colors;
};
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidPalette__ColorRole);
//-----------------------------------------------------------------------

#endif
