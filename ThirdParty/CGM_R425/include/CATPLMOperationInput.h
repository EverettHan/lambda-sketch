#ifndef CATPLMOPERATIONINPUT_H_
#define CATPLMOPERATIONINPUT_H_
/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATPLMID.h"
#include "CATSysBoolean.h"
#include "CATOmxKeyString.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATPLMID_Simple.h"

class CATComponentId;
class CATIPLMRecordRead;
class CATProxySpace;

/**
* Class representing the input for the various query operations provided by the CATPLMOperationContext API.
*
* The various operations that can be performed throug the CATPLMOperationContext API can be specified down
* to the discipline of the object on which to apply the operation. In the 'New Typing' system, the discipline
* is written directly in the type of the component. Unfortunatly, in the 'Old Typing' system, the discipline
* is saved on an attribute of the object. This attribute should be queried to get its value.
*
* Its main purpose is to associate a component (identified through its CATPLMID) to its discipline attribute.
* It can save an additionnal query if you already have queried the discipline attribute (or if you know it for
* sure by other means). If not provided, the discipline attribute will be queried for the database.
*/
class ExportedByCATPLMModelBuilder CATPLMOperationInput
{
public:
  // default constructor
  CATPLMOperationInput();

  // constructor for simple inputs
  CATPLMOperationInput(const CATPLMID_Simple& iPlmidSimple);
  CATPLMOperationInput(const CATPLMID_Simple& iPlmidSimple, const CATOmxKeyString& iDiscipline);

  // constructor for complex inputs (path)
  CATPLMOperationInput(const CATOmxArray<CATPLMID_Simple>& iPath);
  CATPLMOperationInput(const CATOmxArray<CATPLMID_Simple>& iPath, const CATOmxKeyString& iDiscipline);

  // hybrid constructors (for simple and complex inputs)
  CATPLMOperationInput(const CATPLMID& iPlmid);
  CATPLMOperationInput(const CATPLMID& iPlmid, const CATOmxKeyString& iDiscipline);
  CATPLMOperationInput(const CATComponentId& iCID);

  // deprecated constructors
#ifdef CATIAR424
  OMX_DEPRECATED("This method is deprecated.")
    CATPLMOperationInput(const CATLISTV(CATPLMID)& iPath);
#else
  CATPLMOperationInput(const CATLISTV(CATPLMID)& iPath);
#endif

#ifdef CATIAR424
  OMX_DEPRECATED("This method is deprecated.")
    CATPLMOperationInput(const CATLISTV(CATPLMID)& iPath, const CATOmxKeyString& iDiscipline);
#else
  CATPLMOperationInput(const CATLISTV(CATPLMID)& iPath, const CATOmxKeyString& iDiscipline);
#endif

  // copy constructor
  CATPLMOperationInput(const CATPLMOperationInput& iInput);

  /**
  * Construit un CATPLMID+discipline a partir d'un record avec un petit tweak tres utile :
  * pour le cas des navreps vieille sauce qui sont typees sur le PLMExternalId,
  * on dit qu'elles ont la discipline des nouvelles nav reps, type sur la discipline.
  */
  CATPLMOperationInput(const CATIPLMRecordRead* iRecordRead);
  CATPLMOperationInput& operator =(const CATPLMOperationInput& iInput);

  /**
  * Redirections on the underlying CATPLMID
  */
  inline const CATPLMID& GetPLMID() const { return m_plmid; }
  CATPLMID_Simple GetLastPlmid() const;
  CATPLMID_Simple GetFirstPlmid() const;
  inline int GetSize() const { return m_plmid.Size(); }
  CATBoolean IsComplex() const;
  inline CATPLMIDRangeForAdapter begin() const { return m_plmid.begin(); }
  inline CATPLMIDRangeForAdapter end() const { return m_plmid.end(); }
  HRESULT DefineComplex(const CATOmxArray<CATPLMID_Simple>& iPath);
  inline HRESULT Append(const CATPLMID_Simple& iSimple) { return m_plmid.Append(iSimple); }
  HRESULT Append(const CATPLMID& iComplex);
  HRESULT RemoveFirstElement();
  HRESULT RemoveLastElement();

  /**
  * Retrieves a discipline attribute. Note that if the discipline has not been given
  * and it has not already been queried, an irrelevant value will be retrieved. This
  * case should be tested through IsDisciplineValuated();
  */
  inline const CATOmxKeyString& GetDiscipline() const { return m_discipline; }

  /**
  * Tells if the discipline has been set or queried.
  */
  CATBoolean IsDisciplineValuated() const;

  /**
  * Valuate the discipline attribute.
  *   If already set with the same value, nothing happens.
  *   If already set with a different value, asserts.
  */
  void SetDiscipline(const CATOmxKeyString& iDiscipline);

  /**
  * Valuate the discipline attribute from the component in session if necessary.
  * @returns
  *   S_OK if the discipline is now valuated (even if the discipline was already valuated and nothing was done)
  *   S_FALSE if the component with its discipline information wasn't available in session
  *   E_* in other unexpected behaviour that may happen...
  */
  HRESULT UpdateDisciplineFromSession();

  /**
  * Valuate the discipline attribute from the component in the proxy space if necessary.
  * @returns
  *   S_OK if the discipline is now valuated (even if the discipline was already valuated and nothing was done)
  *   S_FALSE if the component with its discipline information wasn't available in the proxy space
  *   E_* in other unexpected behaviour that may happen...
  */
  HRESULT UpdateDisciplineFromProxySpace(const CATProxySpace& iSpace);

  /**
  * Valuate the discipline attribute from the component in session if necessary.
  * @returns
  *   S_OK if the discipline is now valuated (even if the discipline was already valuated and nothing was done)
  *   S_FALSE if the discipline wasn't available on the component
  *   E_INVALIDARG if the component doesn't correspond to the internal PLMID.
  *   E_* in other unexpected behaviour that may happen...
  */
  HRESULT UpdateDisciplineFromComponent(const CATComponentId& iCID);

  HRESULT SetDisciplineFromComponent(const CATComponentId& iCID);

  /**
   * Retrieves a usage attribute.
   */
  inline const CATOmxKeyString& GetUsage() const { return m_usage; }

  /**
 * Retrieves the input id.
 */
  inline unsigned int GetInputId() const { return m_inputid; }
  void SetInputId(unsigned int iInputId) { m_inputid = iInputId; };

private:

  CATPLMID            m_plmid;
  CATOmxKeyString     m_discipline;
  CATOmxKeyString     m_usage;
  unsigned int        m_inputid;

  static unsigned int m_count;

  const CATOmxKeyString& UnknownDisciplineValue() const;

};

/* Collection manager for CATOmxCollection apis. */
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMOperationInput>::manager();

#endif /* CATPLMOPERATIONINPUT_H_ */
