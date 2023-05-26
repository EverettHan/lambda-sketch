#ifndef CATICkeRelationForwards_h
#define CATICkeRelationForwards_h

// COPYRIGHT DASSAULT SYSTEMES 1998
   
/** 
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/*  CAA2Reviewed by FRH */

// module definition
#include "CATLifSpecs.h"

// forwards declaration
class CATICkeRelation_var;
class CATICkeRelationExp_var;
class CATICkeParm_var;
class CATICkeParmFactory_var;
class CATICkeUnit_var;
class CATICkeMKSUnit_var;
class CATICkeMagnitude_var;
class CATIParmManipulator_var;
class CATIParmFormat_var;
class CATICkeNaming_var;
class CATICkeExpression_var;
class CATIDesignTable_var;
class CATICkeSheet_var;




/**
 * Possible values for defining panel ParamFrame.
 * <br><b>Legal values</b>:
 * <tt>CATCkeLabel</tt> default style: with a label.
 * <tt>CATCkeNoLabel</tt> no label
 * <tt>CATCkeNoFormula</tt> if you do not want formulas in contextual menu.
 * <tt>CATCkeWithSpinner</tt> if you wish a spinner instead of an editor
 * <tt>CATCkeNoTolerance</tt> if you do not want tolerance
 * <tt>CATCkeNoRange</tt> if you do not want ranges
 * <tt>CATCkeNoCxtMenu</tt> if you do not want contextual menus at all
 * <tt>CATCkeNoCtxMenuEdit</tt> if you do not want the "Edit..." contextual menu
 * <tt>CATCkeNoCxtMenuMultipleValues</tt> if you do not want the "Multiple Values" contextual menu
 * <tt>CATCkeNoJournaling</tt> if you do not want journaling of parameter modification
 * <tt>CATCkeRightAttachment</tt> if you want a right attachement
 * <tt>CATCkeNoMeasure</tt> if you don't want the Measure contextual menu
 * <tt>CATCkeDTConfigFirstOutParameter</tt> when editing a design table configuration, shows the first associated parameter
 * <tt>CATCkeRelationButtonDisabled</tt> if the parameter has a relation, the button appears but is disabled
 * <tt>CATCkeEditMultipleForVolatile</tt> if a contextual menu for editing multiple values for volatile parameters is required
 * <tt>CATCkeKeepCxtMenuWhenDisable</tt> if you want to keep the contextual menu even when the ParamFrame is disable
 * <tt>CATCkeWithUnsetMenu</tt> if you want,in contextual menu, the capability to unset the parameter value.
 */
typedef unsigned long CATCkeFrameStyle;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeLabel;         
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoLabel;      
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoFormula;     
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeWithSpinner;  
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoRename;      
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeLiteralShared; 
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoTolerance;   
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoRange;      
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoCxtMenu;     
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoCxtMenuEdit;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoCxtMenuMultipleValues;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoJournaling;  
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeRightAttachment; 
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoMeasure;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeDTConfigFirstOutParameter;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeRelationButtonDisabled;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeNoBitmap;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeEditMultipleForVolatile;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeKeepCxtMenuWhenDisable;
extern ExportedByCATLifSpecs const CATCkeFrameStyle  CATCkeWithUnsetMenu;


// listes
#include "CATICkeForwards.h"

/** 
 * List of relations. 
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfRelation;

/** 
 * List of parameters. 
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead. 
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfParm;

/** 
 * List of units. 
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfUnit;

/** 
 * List of magnitudes.
 * WARNING: This typedef may generate misunderstanding. Use the CATLISTV(CATBaseUnknown_var)* directly instead.
 */
typedef class CATLISTV(CATBaseUnknown_var)* CATCkeListOfMagnitude;



#endif

