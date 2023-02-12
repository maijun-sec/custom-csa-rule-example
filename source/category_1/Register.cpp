#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"

#include "MainCallChecker.h"

using namespace clang;
using namespace ento;

// Register plugin!
extern "C"
#ifdef _WINDOWS
_declspec(dllexport)
#endif
void clang_registerCheckers(CheckerRegistry &registry) {
    registry.addChecker<MainCallChecker>(
            "example.MainCallChecker", "Disallows calls to functions called main",
            "");
}

extern "C"
#ifdef _WINDOWS
_declspec(dllexport)
#endif
const char clang_analyzerAPIVersionString[] =
        CLANG_ANALYZER_API_VERSION_STRING;