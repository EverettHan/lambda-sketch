//===================================================================

//===================================================================
// SWXUtJournalFixInfo.cpp
// Header definition of class SWXUtJournalFixInfo
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/04/04 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtJournalFixInfo_H
#define SWXUtJournalFixInfo_H

#include "SWXUtJournal.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------

class ExportedBySWXUtJournal SWXUtJournalFixInfo
{
	public:
	
		SWXUtJournalFixInfo();
		virtual ~SWXUtJournalFixInfo();

	public:

		void ResetFlags();

		unsigned int GetFlags() const;
		void SetFlags( unsigned int iFlags );

		bool GetFixAnything() const;

		bool GetFixMassProperties() const;
		bool GetFixModelStructure() const;
		bool GetFixFeatureName() const;
		bool GetFixFeatureAlias() const;
		bool GetFixFeatureVisibility() const;
		bool GetFixFeatureSuppression() const;
		bool GetFixSketchPointCount() const;
		bool GetFixSketchCurveCount() const;
		bool GetFixSketchObjectCount() const;
		bool GetFixSketchConstraintCount() const;
		bool GetReplaceCustomValidationEntries() const;
		bool GetAddCustomValidationEntries() const;
		bool GetAddPerformanceEntries() const;
		// Interop Fixes
		bool GetAddBodyCountEntries() const;
		bool GetUpdateNodeAttr(CATUnicodeString &oNodeName, CATListOfCATUnicodeString  &oListAttri) const;
		bool GetAddPSFileFromSW() const;

		void SetFixMassProperties( bool iState );
		void SetFixModelStructure( bool iState );
		void SetFixFeatureName( bool iState );
		void SetFixFeatureAlias( bool iState );
		void SetFixFeatureVisibility( bool iState );
		void SetFixFeatureSuppression( bool iState );
		void SetFixSketchPointCount( bool iState );
		void SetFixSketchCurveCount( bool iState );
		void SetFixSketchObjectCount( bool iState );
		void SetFixSketchConstraintCount( bool iState );
		void SetReplaceCustomValidationEntries( bool iState );
		void SetAddCustomValidationEntries( bool iState );
		void SetAddPerformanceEntries( bool iState );		

	private:

		enum FixFlagBits_e
		{
			Bit_MassProperties = 0,
			Bit_ModelStructure = 1,
			Bit_FeatureName = 2,
			Bit_FeatureAlias = 3,
			Bit_FeatureVisibility = 4,
			Bit_FeatureSuppression = 5,
			Bit_SketchPointCount = 6,
			Bit_SketchCurveCount = 7,
			Bit_SketchObjectCount = 8,
			Bit_ConstraintCount = 9,
			Bit_CustomValidationReplace = 10,
			Bit_CustomValidationAdd = 11,
			Bit_Performance = 12,
			Bit_BodyCountAdd = 13,
			Bit_UpdateNodeAttr = 14,
			Bit_GetPSFileFromSW = 15
		};

	private:

		bool GetState( FixFlagBits_e iBit ) const;
		void SetState( FixFlagBits_e iBit, bool iState );

	private:

		SWXUtJournalFixInfo( SWXUtJournalFixInfo& );
		SWXUtJournalFixInfo& operator=( SWXUtJournalFixInfo& );

	private:

		unsigned int mFlags;
};

//-----------------------------------------------------------------------

#endif