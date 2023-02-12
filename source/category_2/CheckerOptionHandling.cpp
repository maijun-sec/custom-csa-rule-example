#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"

#include "CheckerOptionHandling.h"

using namespace clang;
using namespace ento;


void registerMyChecker(CheckerManager &Mgr) {
    MyChecker *Checker = Mgr.registerChecker<MyChecker>();
    llvm::outs() << "Example option is set to "
                 << (Mgr.getAnalyzerOptions().getCheckerBooleanOption(
                         Checker, "ExampleOption")
                     ? "true"
                     : "false")
                 << '\n';
}

bool shouldRegisterMyChecker(const CheckerManager &mgr) { return true; }