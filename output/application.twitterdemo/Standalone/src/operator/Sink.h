// eJydj9FKAzEQRZlXP6P4oA9utqWFGkVoBaF1V4WwHxDd0B2aTcJk4rp_175LafoAMDNzLcOfcGGyRGC3yKOVziux7KPPMYVYUgsdgxNbsB6rVcfGq5u_0V8ouxcbVar0Md73dVvfSqGb7f0O5JHbabanfcpFXRzXIMiM73RkQm3fbohNWfUfCAzIbuAnqmi2pN70WrWYPzzmSEEjB44usS1Ecl5X9AAIEyiZQ54yW5L0bvopTNuXggdGzdzd_0z24crgCWkaAhoIkd3AKundRadjh3rycTIj_0lkPgGbH76clL_0ySHAU


#ifndef SPL_OPER_INSTANCE_SINK_H_
#define SPL_OPER_INSTANCE_SINK_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.h"


#define MY_OPERATOR Sink$OP
#define MY_BASE_OPERATOR Sink_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5 IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    
    
    
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const {
    }
    void restoreStateVariables(NetworkByteBuffer & opstate) {
    }
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:
   MY_OPERATOR() {}
   
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_SINK_H_

