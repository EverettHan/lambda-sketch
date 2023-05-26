#ifndef CATUnicornLevel_h
#define CATUnicornLevel_h

// COPYRIGHT Dassault Systemes 2010

#include "CATLifSpecs.h"
#include "CATBoolean.h"
#include "IUnknown.h"
class CATUnicodeString;

/**        
* Global services dealing with Unicorn.
*/   

class ExportedByCATLifSpecs CATUnicornLevel
{      
public  :  

  /**
  * Unicorn Step 1 corresponds to the access to ER (Entity Relationship) based model in V6 rich client.
  * It is limited to some modeler (ex: Document modeler and Requirement modeler).
  * It is a replacement of Polar Bear mechanism for navigation on ER models.
  * It is an extension of Polar bear to support the authoring of ER based models on the V6 rich client.
  * Polar bear is still valid for other modelers than document and requirement.
  * Returns TRUE if Step1 is activated. 
  * - it will be activated in V6R2012x
  * - it will be activated in V6R2012 by activating environment variable UNICORN=1
  */
  static CATBoolean  Step1();

  /**
  * NewTyping corresponds to the possibility of having objects defined with new typing principles.
  * - association of a deployment extension instead of a custo type (deduced from the context)
  * - ability to define sub types (functional specialization) and propose them at creation time
  * - disciplines becoming types
  * Note that the activation of new typing doesn't mean that objects are always defined with this new typing.
  * Old mechanism is still valid if chosen by the customer.
  * This service only indicates that it becomes possible
  * Returns TRUE if NewTyping is possible. 
  * - it will be activated in V6R2013x
  * - it will be activated in V6R2013 by activating environment variable CKE_TYPING_VERSION=2
  */
  static CATBoolean  NewTyping();

  /**
  * In NewTyping context, some services shall not be used. 
  * This method is used to send an error message in the CNEXTOUTPUT, and then call CATAssert.
  * The test of new typing is done inside the method so you can use it whenever you arrive in a situation that is not 
  * valid in new typing
  */
  static void  AssertWithMessage(const CATUnicodeString &iErrorMessage);

  /**
  * This corresponds to the activation of Requirement in V6R2012x.
  * Returns TRUE if it is activated. 
  * - it will be activated in V6R2013
  * - it will be activated by customers in LA
  * - it will be activated in V6R2012x by activating environment variable RMT_UNICORN=1
  */
  static CATBoolean  RequirementActive();

  /**
  * This corresponds to the activation of EngineeringCentral in V6R2013.
  * Returns TRUE if it is activated. 
  * - it will be activated in V6R2013x
  * - it will be activated by customers in LA in V6R2013
  * - it will be activated in V6R2012x by activating environment variable UNICORN_EC=1
  */
  static CATBoolean  EngineeringCentralActive();

  /**
  * This corresponds to the activation of DesignerCentral in V6R2013x.
  * Returns TRUE if it is activated. 
  * - it will be activated in V6R2014
  * - it will be activated by customers in LA in V6R2013x
  * - it will be activated in V6R2013 by activating environment variable UNICORN_DEC=1
  */
  static CATBoolean  DesignerCentralActive();

  /** 
  * In E4ALL, we will have both Unicorn & PolarBear metadata. If a particular variable is set, we need to skip Polar Bear
  * This method indicates if we need to skip a particular PolarBear metadata. 
  * iUnicornMetadataName is the name of the UNICORN Metadata (the question is asked on this metadata)
  */
  static CATBoolean  ForgetPolarBear (const CATUnicodeString &iUnicornMetadataName);

  /**
  * NewUI corresponds to the move to the new PLM New UI command and integration protocol
  * Returns TRUE if NewUI is activated. 
  * - it will be activated in V6R2013x
  * - it will be activated in V6R2013 by activating environment variable UNICORN_NEWUI=1
  */
  static CATBoolean  NewPLMNewUI();

  /** 
  * Converts a Polar bear type to the Unicorn one.
  * Returns S_FALSE if the polar bear type was not found.
  */
  static HRESULT  TransformPolarBearIntoUnicorn (const CATUnicodeString &iPolarBearTypeName,CATUnicodeString &iUnicornTypeName);

  /** 
  * Converts a Polar bear type (identified by triplet) to the Unicorn one.
  * Returns S_FALSE if the polar bear type was not found.
  */
  static HRESULT  TransformPolarBearTripletIntoUnicorn (const CATUnicodeString &iCoreName,
    const CATUnicodeString &iMetadataModelerName,
    const CATUnicodeString &iMetadataCustoName,
    CATUnicodeString &iUnicornTypeName);



  /**
  * OBSOLETE NOT USED
  */
  static CATBoolean MustRaiseAnError ();


  /**
  * OBSOLETE: STILL USED
  */
  static CATBoolean RaceAvailableWithNewTyping () ;


  /**
  * For ODT only. Indicates if in ODT context we don't want to activate OCDX behavior
  * @return
  *  <ol>
  * 	 <li> TRUE 
  * 	 <li> FALSE
  *  </ol>
  */
  static CATBoolean PreventOCDXExperienceInODT () ;

  /** 
  * Indicates if the mapping concerning basic attributes is suppressed
  * Service that can not be used by dictionary, since it requires the dictionary to be loaded.
  */
  static CATBoolean BasicsMappingSuppressed ();

  /** 
  * Indicates if the mapping concerning Instance Types is suppressed
  * Service that can not be used by dictionary, since it requires the dictionary to be loaded.
  */
  static CATBoolean InstanceTypeMappingSuppressed ();

  /**
  * Indicates if we are in UnifiedExperience
  * @return
  *  <ol>
  * 	 <li> TRUE 
  * 	 <li> FALSE
  *  </ol>
  */
  static CATBoolean UnifiedExperience () ;


  /** 
  * Indicates if the path are saved with their right path type
  */
  static CATBoolean PathTypeMappingSuppressed ();

  /** 
  * Indicates if the role and category are replaced by PathType
  */
  static CATBoolean RoleAndCategoryReplaced ();

  /**
  * Indicates if the mapping concerning basic attributes is suppressed
  * To be used only by providers:: determines by the UNICORN_NOBASICSMAPPING variable that the basics mapping is suppressed
  */
  static CATBoolean BasicsMappingSuppressedForProviders ();


  /** 
  * Indicates if the mapping concerning Instance Types is suppressed
  * To be used only by providers:: determines by the UNICORN_NOINSTANCETYPEMAPPING variable that the instance type mapping is suppressed
  */
  static CATBoolean InstanceTypeMappingSuppressedForProviders ();

  /*
   * Use with caution
   * If odt mode and if project attribute mapping is activated, mapped attribute are replaced in XML by not mapped attribute.
   * If not odt or if level>=418 or if project attribute mapping is not activated, we return the same string has the string received (iQueryFilterStreamedInXML).
   * @DEPRECATED level R418
  */
  static CATUnicodeString ApplyAttributeMappingForOdt(const CATUnicodeString& iQueryFilterStreamedInXML);

  /**
  * Pure Unified Typing corresponds to the possibility of having objects defined with new typing principles and also the fact that there is no former typing object in the database.
  * Returns TRUE if Pure Unified Typing is the current usage of the 3D Experience. 
  * - it will be activated by default on the cloud, or on premise starting from R2014x, or on premise with a migrated database
  * - it will be activated in ODT by activating the environment variable PureUnifiedTyping=1
  */
  static CATBoolean  PureUnifiedTyping();

private:
};

#endif // CATUnicornLevel_h

