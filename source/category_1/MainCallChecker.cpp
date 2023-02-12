#include "MainCallChecker.h"

using namespace clang;
using namespace ento;

void MainCallChecker::checkPreStmt(const CallExpr *CE,
                                   CheckerContext &C) const {
    const Expr *Callee = CE->getCallee();
    const FunctionDecl *FD = C.getSVal(Callee).getAsFunctionDecl();

    if (!FD)
        return;

    // Get the name of the callee.
    IdentifierInfo *II = FD->getIdentifier();
    if (!II) // if no identifier, not a simple C function
        return;

    if (II->isStr("main")) {
        ExplodedNode *N = C.generateErrorNode();
        if (!N)
            return;

        if (!BT)
            BT.reset(new BugType(this, "call to main", "example analyzer plugin"));

        auto report =
                std::make_unique<PathSensitiveBugReport>(*BT, BT->getDescription(), N);
        report->addRange(Callee->getSourceRange());
        C.emitReport(std::move(report));
    }
}
