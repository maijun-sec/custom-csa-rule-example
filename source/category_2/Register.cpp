#include "clang/StaticAnalyzer/Frontend/CheckerRegistry.h"

#include "CheckerOptionHandling.h"

using namespace clang;
using namespace ento;

// Register plugin!
extern "C"
#ifdef _WINDOWS
_declspec(dllexport)
#endif
void clang_registerCheckers(CheckerRegistry &registry) {
    registry.addChecker(registerMyChecker, shouldRegisterMyChecker,
                        "example.MyChecker", "Example Description",
                        "example.mychecker.documentation.nonexistent.html",
            /*isHidden*/false);

    registry.addCheckerOption(/*OptionType*/ "bool",
            /*CheckerFullName*/ "example.MyChecker",
            /*OptionName*/ "ExampleOption",
            /*DefaultValStr*/ "false",
            /*Description*/ "This is an example checker opt.",
            /*DevelopmentStage*/ "released");
}

extern "C"
#ifdef _WINDOWS
_declspec(dllexport)
#endif
const char clang_analyzerAPIVersionString[] =
        CLANG_ANALYZER_API_VERSION_STRING;