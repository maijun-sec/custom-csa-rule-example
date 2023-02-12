#ifndef CUSTOM_CSA_RULE_EXAMPLE_MAINCALLCHECKER_H
#define CUSTOM_CSA_RULE_EXAMPLE_MAINCALLCHECKER_H

#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"

using namespace clang;
using namespace ento;

class MainCallChecker : public Checker<check::PreStmt<CallExpr>> {
    mutable std::unique_ptr<BugType> BT;

public:
    void checkPreStmt(const CallExpr *CE, CheckerContext &C) const;
};

#endif //CUSTOM_CSA_RULE_EXAMPLE_MAINCALLCHECKER_H
