FILE(GLOB_RECURSE hdrs "*.h" "../common/*.h")
FILE(GLOB_RECURSE srcs "*.cpp" "../common/*.cpp")

SET(LLVM_EXPORTED_SYMBOL_FILE ${CMAKE_CURRENT_SOURCE_DIR}/CustomCSARuleCategory1.exports)
ADD_LIBRARY(CustomCSARuleCategory1 MODULE ${srcs})

IF (LLVM_ENABLE_PLUGINS AND (WIN32 OR CYGWIN))
    TARGET_LINK_LIBRARIES(CustomCSARuleCategory1 PRIVATE
            clangAnalysis
            clangAST
            clangStaticAnalyzerCore
            LLVMSupport
            )
ENDIF ()