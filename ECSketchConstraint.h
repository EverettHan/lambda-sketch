#ifndef ECSketchConstraint_H
#define ECSketchConstraint_H

#include "SWXSvSolver.h"
#include "ECSketchEntity.h"

class ECSketchConstraint : public ECSketchEntity
{
public:
	ECSketchConstraint(	svConstraintType typeIn, 
						std::shared_ptr<ECSketchEntity> ent1, std::shared_ptr<ECSketchEntity> ent2 = nullptr,
						std::shared_ptr<ECSketchEntity> ent3 = nullptr, std::shared_ptr<ECSketchEntity> ent4 = nullptr,
						double valueIn = 0.0, svConstraintChirality chiralityIn = svChiralityNotSpecified)
	:	m_eConstraintType(typeIn),
		m_dConstrintValue(valueIn),
		m_eConstraintChirality(chiralityIn),
		m_constraintSolveStatus(svConstraintStatus::svNotSolved)
	{
		m_vecEntities.push_back(ent1);
		m_vecEntities.push_back(ent2);
		m_vecEntities.push_back(ent3);
		m_vecEntities.push_back(ent4);
		setTypeString("Constraint");
	}

	svConstraintType getConstraintType() const {return m_eConstraintType;}
	bool getConstraintValue(double& valueOut) const {valueOut = m_dConstrintValue; return true;}
	svConstraintChirality getConstraintChirality() const {return m_eConstraintChirality;}
	bool getEntitieIDs(SWXUtUniqueId& ent1,  SWXUtUniqueId& ent2, SWXUtUniqueId& ent3, SWXUtUniqueId& ent4)
	{
		int count = 1;
		for (auto & anEnt : m_vecEntities) 
		{		
			if (count == 1) ent1 = anEnt->getSolverEntityID();
			if (count == 2) ent2 = anEnt->getSolverEntityID();
			if (count == 3) ent3 = anEnt->getSolverEntityID();
			if (count == 4) ent4 = anEnt->getSolverEntityID();
			++count;
		}
		return count !=1 ? true : false;
	}
	int getEntitieNames(std::string& ent1,  std::string& ent2, std::string& ent3, std::string& ent4)
	{
		int count = 0;
		for (auto & anEnt : m_vecEntities) 
		{		
			if (count == 0) ent1 = anEnt->getName();
			if (count == 1) ent2 = anEnt->getName();
			if (count == 2) ent3 = anEnt->getName();
			if (count == 3) ent4 = anEnt->getName();
			++count;
		}
		return count;
	}

	
	svConstraintStatus getConstraintSolveStatus() const { return m_constraintSolveStatus; }
	void setConstraintSolveStatus(svConstraintStatus& newStatus) { m_constraintSolveStatus = newStatus; }

protected:


private:
	svConstraintType 		m_eConstraintType;
	double 					m_dConstrintValue;
	svConstraintChirality 	m_eConstraintChirality;
	std::vector<std::shared_ptr<ECSketchEntity>> m_vecEntities;	
	svConstraintStatus 		m_constraintSolveStatus;
};


#endif