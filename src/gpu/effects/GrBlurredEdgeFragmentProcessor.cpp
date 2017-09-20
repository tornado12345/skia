/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrBlurredEdgeFragmentProcessor.fp; do not modify.
 */
#include "GrBlurredEdgeFragmentProcessor.h"
#if SK_SUPPORT_GPU
#include "glsl/GrGLSLColorSpaceXformHelper.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLBlurredEdgeFragmentProcessor : public GrGLSLFragmentProcessor {
public:
    GrGLSLBlurredEdgeFragmentProcessor() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrBlurredEdgeFragmentProcessor& _outer =
                args.fFp.cast<GrBlurredEdgeFragmentProcessor>();
        (void)_outer;
        fragBuilder->codeAppendf(
                "half factor = half(1.0 - float(%s.w));\n@switch (%d) {\n    case 0:\n        "
                "factor = half(exp(float(float(-factor * factor) * 4.0)) - "
                "0.017999999999999999);\n        break;\n    case 1:\n        factor = "
                "half(smoothstep(1.0, 0.0, float(factor)));\n        break;\n}\n%s = "
                "half4(factor);\n",
                args.fInputColor ? args.fInputColor : "half4(1)", _outer.mode(), args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrBlurredEdgeFragmentProcessor::onCreateGLSLInstance() const {
    return new GrGLSLBlurredEdgeFragmentProcessor();
}
void GrBlurredEdgeFragmentProcessor::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                           GrProcessorKeyBuilder* b) const {
    b->add32(fMode);
}
bool GrBlurredEdgeFragmentProcessor::onIsEqual(const GrFragmentProcessor& other) const {
    const GrBlurredEdgeFragmentProcessor& that = other.cast<GrBlurredEdgeFragmentProcessor>();
    (void)that;
    if (fMode != that.fMode) return false;
    return true;
}
GrBlurredEdgeFragmentProcessor::GrBlurredEdgeFragmentProcessor(
        const GrBlurredEdgeFragmentProcessor& src)
        : INHERITED(src.optimizationFlags()), fMode(src.fMode) {
    this->initClassID<GrBlurredEdgeFragmentProcessor>();
}
std::unique_ptr<GrFragmentProcessor> GrBlurredEdgeFragmentProcessor::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrBlurredEdgeFragmentProcessor(*this));
}
#endif
