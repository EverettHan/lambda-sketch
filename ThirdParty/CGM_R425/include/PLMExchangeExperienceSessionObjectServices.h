// *****************************************************************
// COPYRIGHT DASSAULT SYSTEMES 2016
// *****************************************************************
//
//   Identification :
//   ----------------
//
//      RESPONSIBLE : Mangesh MULEY
//      FUNCTION    : Common service class for exchange experience
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description : 
//   -------------
//      This class is to provide common services for exchange experience
//
// *****************************************************************
//
//   Remark :
//   --------
//
/**
  * @level Private
  * @usage U1
  */
//
// *****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  January  2016  (OYG) Initial Revision for V6R2016x
//
// ****************************************************************


#ifndef PLMExchangeExperienceSessionObjectServices_H
#define PLMExchangeExperienceSessionObjectServices_H

#include "PLMIExchangeExperienceSessionObject.h"

class ExportedByPLMExchangeInterfaces PLMExchangeExperienceSessionObjectServices
{
public:
   
   /**
   * <b> GetSessionObjectRepNature :</b> Get the nature of the rep. 
   * Method to check the Nature of Rep object.
   *
   * @param ipSessionObject (in)
   * input pointer on a PLMIExchangeExperienceSessionObject which will be used to chcek the rep nature.
   * The given session object must be of type rep ref.
   *
   * @param oRepNature (Out)
   * output value for Rep Nature.
   *    Legal values:
   *                oRepNature == 1 : Mandatory rep (3DPart ie)
   *                oRepNature == 2 : Aggregated rep 
   *                oRepNature == 3 : Shared rep 
   *                oRepNature == 4 : Private rep 
   *
   * @return
   *    Legal values:  S_OK,
   *                   E_FAIL  
   */
   static HRESULT GetSessionObjectRepNature(PLMIExchangeExperienceSessionObject * & ipSessionObject , int & oRepNature);

   /**
   * <b> GetSessionObjectRepUsage :</b> Get the Usage of the rep. 
   * Method to check the Usage of Rep object.
   *
   * @param ipSessionObject (in)
   * input pointer on a PLMIExchangeExperienceSessionObject which will be used to check the rep usage.
   * The given session object must be of type rep ref.
   *
   * @param oRepUsage (Out)
   * output value for Rep usage
   *    Legal values:
   *                oRepNature == 1 : 3DPart/3DShape.
   *                oRepNature == 2 : Deafult value."Not 3D Shape"
   *
   * @return
   *    Legal values:  S_OK,
   *                   E_FAIL  
   */
   static HRESULT GetSessionObjectRepUsage(PLMIExchangeExperienceSessionObject * & ipSessionObject , int & oRepUsage);

   /**
   * <b> IsSelectedObject3DPart :</b> To check the selected session object is of type "3DPart".
   *
   * @param ipSessionObject  [in]
   * input session object.
   *
   * @param obFlag  (out)
   * output flag 
   *    Legal values:  TRUE  if the input session object is of "3DPart " type     
   *                   FALSE if the input session object is not of "3DPart " type 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL 
   */  
   static HRESULT IsSelectedObject3DPart(PLMIExchangeExperienceSessionObject* &ipSessionObject, CATBoolean &obFlag);

   /**
   * <b> IsSelectedObjectMandatoryRep :</b> To check the selected session object is of type "3DPart".
   *
   * @param ipSessionObject  [in]
   * input session object.
   *
   * @param obFlag  (out)
   * output flag
   *    Legal values:  TRUE  if the input session object is of mandatory rep nature "i.e.3DPart " type
   *                   FALSE if the input session object is not of mandatory rep nature "i.e.3DPart " type
   *
   * @return
   *    Legal values:  S_OK if the method succeeds
   *                   E_FAIL
   */
   static HRESULT IsSelectedObjectMandatoryRep(PLMIExchangeExperienceSessionObject* &ipSessionObject, CATBoolean &obFlag);
};



#endif
