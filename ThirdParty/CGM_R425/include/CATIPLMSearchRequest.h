/**
 * @quickReview vlt4 2020-29-10 fix uninitialized native type fields in struct CATIPLMAnswerStatus
 *					default constructor generated by c++11 compiler will not init native type fields.
 *					also I noticed we use the generated default constructor for struct (C compatibility), this may
 *					not work on old levels (let's say : maybe before c++11).
 */
#ifndef _CATIPLMSearchRequest_h_
#define _CATIPLMSearchRequest_h_

// Includes
#include "GUIDCATPLMIndexInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

extern ExportedByGUIDCATPLMIndexInterfaces const IID IID_CATIPLMSearchRequest;

class CATIPLMIndexResultProcessor;

/**
 * FedSearch answer statuses.
 * This struct is used in several place with a copy constructor, without any of it defined
 * this relies on c++ feature which provide a default copy constructor for struct (backward C compatibility)
 * compiler will generate copy constructor and other methods. (also gives a default constructor).
 * Still, we need to avoid unintialized value for integer.
 *
 * Note that the above is may not be true in older levels.
 */
struct CATIPLMAnswerStatus {
	// bad that some people rely on the order of these fields ... (one since october 2020)
	int nresults;
	int nhits;
	CATUnicodeString version;
	CATUnicodeString next_start;
	boolean status;
	int time;
	CATUnicodeString error_code;
	CATUnicodeString error_message;
	// default constructor makes list init (ie a = {a,b,c,d} KO (seems list init relies on default cons)
	/*CATIPLMAnswerStatus() {
		nresults = -1;
		nhits = -1;
		time = -1;
		version = "";
		next_start = "";
		status = false;
	}*/
};

class ExportedByGUIDCATPLMIndexInterfaces CATIPLMSearchRequest : public CATBaseUnknown
{
    CATDeclareInterface;

public:
	//Example json for 3DSpace source when interested only in physicalids with pages of size 1000 (use next_start for next pages) : 
	//{"query":"...","label":"...","select_predicate":["resourceid"],"with_synthesis":false,"with_synthesis_attribute":false,"select_file":[],"source":["3dspace"],"nresults":1000}
	virtual HRESULT SetJSON(const CATUnicodeString &iJson) = 0;
	virtual HRESULT RunQuery(CATIPLMIndexResultProcessor &ioProcessor, CATIPLMAnswerStatus &status) = 0;

	/**
	 * INTERNAL / DEBUG use only
	 * Do not use for standart purpose, does not do any http call, only does parsing of a JSON answer from federatedSearch,
	 * and put results in the 
	 * provided processor.
	 *
	 * Do not call it, RunQuery already does everything (connection, http call, then parsing)
	 * this only parses an *already available* json answer iJSONOutput from federatedSearch, for example
	 * to be used for debug purposes in *test* code.
	 * iJSONOutput is *NOT* deleted from this debug/utility function */
	virtual HRESULT RunParsingFromJsonOutput(char *iJSONOutput, CATIPLMIndexResultProcessor &ioProcessor, CATIPLMAnswerStatus &ioStatus) = 0;
};

CATDeclareHandler(CATIPLMSearchRequest, CATBaseUnknown);

#endif
