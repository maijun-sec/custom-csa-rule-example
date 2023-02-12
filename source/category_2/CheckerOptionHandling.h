#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"

using namespace clang;
using namespace ento;

struct MyChecker : public Checker<check::BeginFunction> {
    void checkBeginFunction(CheckerContext &Ctx) const {}
};


void registerMyChecker(CheckerManager &Mgr);

bool shouldRegisterMyChecker(const CheckerManager &mgr);
