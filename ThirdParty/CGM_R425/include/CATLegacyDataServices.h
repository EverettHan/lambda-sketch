
#ifndef CATLegacyDataServices_H
#define CATLegacyDataServices_H

#include "CATIAV5Level.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByXPDMServices.h"

#include "CATOmxDefaultCollecManager.h"
#include "CATOmxArray.h"
typedef CATOmxArray< CATUnicodeString, CATOmxDefaultCollecManager< CATUnicodeString >::manager > ArrayOfCUS;
typedef CATOmxArray< ArrayOfCUS, CATOmxDefaultCollecManager< ArrayOfCUS >::manager > ArrayOfArrayOfCUS;

class ExportedByXPDMServices CATLegacyDataServices
{
public:

	CATLegacyDataServices();
	~CATLegacyDataServices();
	
  // Function for string encryption to support unicity output with MBCS input 
  //  imessage: input. The string to encrypt
  //  oShaID: output. The encrypted result
  static HRESULT ComputeIDfromString(const CATUnicodeString imessage, CATUnicodeString & oShaID);

  //  Function to compute the legacy behavior for value encryption
  //  Beware: it does not provide unicity with MBCS input (not unique due to all MBCS caracters replacement by "?" ) !!
  //  imessage: input. The string to encrypt
  //  oShaID: output. The encrypted result
  static HRESULT ComputeLegacyIDfromString(const CATUnicodeString imessage, CATUnicodeString & oShaID);

  // compute the possible legacy values from an input string, this would provide 2 values foe a MBCS string (the MBCS and the SBCS converted with the "?" characters) 
  // the input value is always added in output, and if another string is got due to SBCS conversion, it is also added in output, to take into account both values for compbination computation
  // input: the input string that can contain SBCS and MBCS characters
  // oOutputValues: the array of posible values
  static HRESULT BuildPossibleValuesFromUnicodeUserText(CATUnicodeString& input, ArrayOfCUS &oOutputValues);

  //Recursive/iterative function to build the combinations of the value stored in the iFieldsValue array of array of values
  // Here an example to illustrate the iFieldsValue content of 5 fields
  //    field 1 values:  "val11 val12 val13"
  //    field 2 values:  "val21"
  //    field 3 values:  "" (ie: no vlaue)
  //    field 4 values:  "val41 val42"
  //    field 5 values:  "" (ie: no vlaue)
  // Here an illustration of the iFieldsValue displayed as A array of array
  // A=   "val11 val12 val13"
  //      "val21"
  //      ""
  //      "val41 val42"
  //      ""
  // The combination of all fields is a string computed by concatenation of all fields: A[1, 1..n1] A[2, 1..n2] A[3, 1..n3] A[4, 1..n4] A[5, 1..n5]
  // in the above example the combination are (pipe is added to separate the fields for better clarity:
  // C1   "val11|val21||val41||"
  // C2   "val11|val21||val42||"
  // C3   "val12|val21||val41||"
  // C4   "val12|val21||val42||"
  // C5   "val13|val21||val41||"
  // C6   "val13|val21||val42||"
  //
  // iApplySHA CATTrue :the combination Ci are encrypted with SHA256 otherwise the result is the raw concatenated fields
  // iValIndex : is the index of line of the A matrix: ie the index of the field
  // iFieldsValue : the array of fields
  // ioCombination : the result each line of the array is a combination (Ci) of the fields
  static HRESULT AddSringValueCombination(CATBoolean &iApplySHA, CATUnicodeString &iStartChain, int &iValIndex, ArrayOfArrayOfCUS &iFieldsValue, ArrayOfCUS &ioCombination);

  // Starter function to proceed the recursive computation of all fields combination
  // iApplySHA CATTrue :the combination Ci are encrypted with SHA256 otherwise the result is the raw concatenated fields
  // ioCombination : the result each line of the array is a combination (Ci) of the fields. eware the result is not cleared before computation
  static HRESULT BuildCombination(CATBoolean &iApplySHA, ArrayOfArrayOfCUS &iFieldsValue, ArrayOfCUS &ioCombination);
};
#endif
