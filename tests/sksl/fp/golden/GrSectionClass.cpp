

/**************************************************************************************************
 *** This file was autogenerated from GrSectionClass.fp; do not modify.
 **************************************************************************************************/
#include "GrSectionClass.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLSectionClass : public GrGLSLFragmentProcessor {
public:
    GrGLSLSectionClass() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrSectionClass& _outer = args.fFp.cast<GrSectionClass>();
        (void) _outer;
        fragBuilder->codeAppendf(
R"SkSL(%s = half4(1.0);
)SkSL"
, args.fOutputColor);
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
};
GrGLSLFragmentProcessor* GrSectionClass::onCreateGLSLInstance() const {
    return new GrGLSLSectionClass();
}
void GrSectionClass::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrSectionClass::onIsEqual(const GrFragmentProcessor& other) const {
    const GrSectionClass& that = other.cast<GrSectionClass>();
    (void) that;
    return true;
}
bool GrSectionClass::usesExplicitReturn() const {
    return false;
}
GrSectionClass::GrSectionClass(const GrSectionClass& src)
: INHERITED(kGrSectionClass_ClassID, src.optimizationFlags()) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrSectionClass::clone() const {
    return std::make_unique<GrSectionClass>(*this);
}
#if GR_TEST_UTILS
SkString GrSectionClass::onDumpInfo() const {
    return SkString();
}
#endif
