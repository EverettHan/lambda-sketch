/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//========================================================================
// Class CATUuidTable
//------------------------------------------------------------------------
// June 99   Creation                           hag
//========================================================================
#ifndef CATUuidTable_h
#define CATUuidTable_h

/**
 * @level Private
 * @usage U1
 */

#include "AD0XXBAS.h"
#include "CATIUuidTable.h"
#include "CATSysSimpleHashTable.h"

#include "CATUuid.h"

class ExportedByAD0XXBAS CATUuidTable : public CATIUuidTable {
  class Couple  {
      public:
      	Couple(const CATUuid& input, const CATUuid& output);
	inline ~Couple() {}
	inline const CATUuid &GetInputUuid() { return In; }
	inline const CATUuid &GetOutputUuid() { return Out; }
	void InverseCouple();
      private:
	  Couple();
	  CATUuid In;
	  CATUuid Out;
    };
  class Map : public CATSysSimpleHashTable {
    public:
	Map(unsigned sz);
	~Map();
	void ApplyDelete();
    private:
      static unsigned  int HashIt (void*    iObj) ;
      static int HashCompare(void*   iObj1,void*   iObj2);
      Map(const Map &forbidden);
      Map&operator =(const Map &forbidden);
    };
  friend class CATUuidTable::Map;

  public:
	  CATDeclareClass;

	  CATUuidTable();
	  virtual ~CATUuidTable();

	  HRESULT LoadFromBinary(unsigned char *iBuffer, int iLength);
	  HRESULT SaveToBinary(unsigned char **oBuffer, int &oLength);

	  // Interface CATIUuidTable
	  // =============================================================================
	  virtual HRESULT AddUuidsInTable(const CATUuid& oldUuid, const CATUuid& newUuid);
	  virtual HRESULT GetNewUuid(const CATUuid& oldUuid, CATUuid& newUuid) const;
	  virtual HRESULT InverseTable();
  private:
	  Map _dico;
};
#endif
