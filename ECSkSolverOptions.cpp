#include "ECSkSolverOptions.h"
#include <cassert>


ECSkSolverOptions::ECSkSolverOptions()
:   m_dLinearTolerance(0.0001), 
    m_dAngularTolerance(1e-9),
    m_bRereadHelpParameters(true),
    m_bForceUsingSketch(false),
    m_bCheckUnsolvableConstraintsMode(false),
    m_bIncrementalMode(false),
    m_eDiagnosticsMode(DiagnosticsMode_e::OldAlways),
    m_eRigidSetDiagnosticsMode(RigidSetDiagnosticsMode_e::WithoutDOS),
    m_eOverdefinedDiagnosticsMode(OverdefinedDiagnosticsMode_e::Dimensional),
    m_eVariableDependencyMode(VariableDependencyMode_e::Never),
    m_eChiralityMode(ChiralityMode_e::Keep),
    m_ePartialSolvingMode(PartialSolvingMode_e::Always),
    m_eUpdateMode(UpdateMode_e::Evaluate),
    m_eSolvingMode(SolvingMode_e::Standard), 
    m_eContactsDiagnosticsMode(ContactsDiagnosticsMode_e::ClashDetected),
    m_eUpdateOutOfClashMode(UpdateOutOfClashMode_e::None)
{

}

void ECSkSolverOptions::setDiagnosticsMode(std::string valIn) 
{
    if(valIn == "NotSolved")
        m_eDiagnosticsMode = DiagnosticsMode_e::NotSolved;
    else if(valIn == "Always")
        m_eDiagnosticsMode = DiagnosticsMode_e::Always;
    else if(valIn == "NotOverdefined")
        m_eDiagnosticsMode = DiagnosticsMode_e::NotOverdefined;
    else if(valIn == "Never")
        m_eDiagnosticsMode = DiagnosticsMode_e::Never;
    else if(valIn == "Heal")
        m_eDiagnosticsMode = DiagnosticsMode_e::Heal;
    else if(valIn == "OldAlways")
        m_eDiagnosticsMode = DiagnosticsMode_e::OldAlways;
    else
        assert(0);
}

void ECSkSolverOptions::setRigidSetDiagnosticsMode(std::string valIn) 
{
    if(valIn == "WithoutDOS")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_e::WithoutDOS;
    else if(valIn == "Full")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_e::Full;
    else if(valIn == "ExtraDOF")
        m_eRigidSetDiagnosticsMode = RigidSetDiagnosticsMode_e::ExtraDOF;
    else
        assert(0);
}

void ECSkSolverOptions::setOverdefinedDiagnosticsMode(std::string valIn) 
{
    if(valIn == "Dimensional")
        m_eOverdefinedDiagnosticsMode = OverdefinedDiagnosticsMode_e::Dimensional;
    else if(valIn == "Full")
        m_eOverdefinedDiagnosticsMode = OverdefinedDiagnosticsMode_e::Full;
    else
        assert(0);
}

void ECSkSolverOptions::setVariableDependencyMode(std::string valIn) 
{
    if(valIn == "Never")
        m_eVariableDependencyMode = VariableDependencyMode_e::Never;
    else if(valIn == "Solved")
        m_eVariableDependencyMode = VariableDependencyMode_e::Solved;
    else
        assert(0);
}

void ECSkSolverOptions::setChiralityMode(std::string valIn) 
{
    if(valIn == "Free")
        m_eChiralityMode = ChiralityMode_e::Free;
    else if(valIn == "Keep")
        m_eChiralityMode = ChiralityMode_e::Keep;
    else
        assert(0);
}

void ECSkSolverOptions::setPartialSolvingMode(std::string valIn) 
{
    if(valIn == "Always")
        m_ePartialSolvingMode = PartialSolvingMode_e::Always;
    else if(valIn == "FailIfInconsistent")
        m_ePartialSolvingMode = PartialSolvingMode_e::FailIfInconsistent;
    else
        assert(0);
}


void ECSkSolverOptions::setUpdateMode(std::string valIn) 
{
    if(valIn == "Evaluate")
        m_eUpdateMode = UpdateMode_e::Evaluate;
    else if(valIn == "Reevaluate")
        m_eUpdateMode = UpdateMode_e::Reevaluate;
    else if(valIn == "EvalTransform")
        m_eUpdateMode = UpdateMode_e::EvalTransform;
    else
        assert(0);
}

void ECSkSolverOptions::setSolvingMode(std::string valIn) 
{
    if(valIn == "Standard")
        m_eSolvingMode = SolvingMode_e::Standard;
    else if(valIn == "MinimumMove")
        m_eSolvingMode = SolvingMode_e::MinimumMove;
    else
        assert(0);
}

void ECSkSolverOptions::setContactsDiagnosticsMode(std::string valIn) 
{
    if(valIn == "ClashDetected")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_e::ClashDetected;
    else if(valIn == "Always")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_e::Always;
    else if(valIn == "Never")
        m_eContactsDiagnosticsMode = ContactsDiagnosticsMode_e::Never;
    else
        assert(0);
}

void ECSkSolverOptions::setUpdateOutOfClashMode(std::string valIn) 
{
    if(valIn == "None")
        m_eUpdateOutOfClashMode = UpdateOutOfClashMode_e::None;
    else if(valIn == "Basic")
        m_eUpdateOutOfClashMode = UpdateOutOfClashMode_e::Basic;
    else
        assert(0);
}
    