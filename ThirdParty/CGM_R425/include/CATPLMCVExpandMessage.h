#ifndef _CATPLMCVEXPANDMESSAGE_H__
#define _CATPLMCVEXPANDMESSAGE_H__

#include "GUIDCATPLMIndexInterfaces.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"


class ExportedByGUIDCATPLMIndexInterfaces CATPLMCVExpandMessage
{
public:
    CATPLMCVExpandMessage();

	void Reset();
		
    void SetDepth(int iDepth = -1);
	void SetConfigFilter(const CATUnicodeString& iHexaFilter);
		
		
	void SetRootId(const CATUnicodeString& iPhysicalidStr);
	void SetRootELLQLQuery(const CATUnicodeString& iELLQLStr);
		
	void AddMinorOverload(const CATUnicodeString& iMajorId, const CATUnicodeString& iMinorPhyId);

	//à raffiner
	void SetTypeFilter(const CATListOfCATUnicodeString& iTypesToKeep);
	void SetTypeFilterELLQLQuery(const CATUnicodeString& iEllqlStr);
		
	void GetQueryString(CATUnicodeString& oELLQLQuery);
		
		
	//add ELLQL attribute filter (post-filter)
	//void addPostFilter(CATUnicodeString type, CATUnicodeString ellql);

private:
    int                 _depth;
    CATUnicodeString    _configFilter;
    CATUnicodeString    _rootQuery;
    CATUnicodeString    _typeQuery;
    CATListOfCATUnicodeString _overloadedMajor;
    CATListOfCATUnicodeString _overloadMinor;
   
private:
    static CATUnicodeString ATTRGRAPH_QUERY;

    static CATUnicodeString PHYID_QUERY;;
    static CATUnicodeString END_ALPHANUM_QUERY;
    static CATUnicodeString MAJID_QUERY;

    static CATUnicodeString TYPES_QUERY;
    static CATUnicodeString TYPES_END_QUERY;

    static CATUnicodeString OR_QUERY;
    static CATUnicodeString END_QUERY;
    static CATUnicodeString COMMA;

    static CATUnicodeString DEFAULT_INST_QUERY;
    static CATUnicodeString DEFAULT_REFREP_QUERY;
    static CATUnicodeString DEFAULT_CFGSECU_QUERY;
    static CATUnicodeString DEFAULT_MINMAJ_QUERY;
};

#endif
