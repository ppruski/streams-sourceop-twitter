// eJy1kmFLwzAQhslfKX7QD0u6WWEWEbYPwmY7hWw_14NrFNVualOS62X9vXNlKFQaKkkC44_0W5e3MHVaVkDiiNjuPlQSIKy01tc0HC4xmSgFKGTSXYVMwPNuW70TMfviTcjJqVTvl4XKXufpakkeGrw34h1dzyzXSSzHaT_0o4WwRGiJF6FhL8mcWwdWqk3hBBWmFIwH8K6lJopyBzDtodBJQ3ac7QWpWFrQCDaaEFuSa7AuQWUwrN71H6R6wA6g7TnL7ghE_1SirEbxZIVokYnMLNiGRJep_1kvaK8tKsS3sgWVSf0P_0gKFkdnIbbQfgGp0PIhrSId2C_1Ttwbqz4D67XCCgvkN_0k8sqv0zotRl_17uTAhMZWx56X5ze6Rklg_1yNr5up0nBf7pwgJcgbDxfTh8qNv0o8_0jeMdOFn4ATvoEBr

#include <SPL/Toolkit/JavaOp.h>


#ifndef SPL_OPER_INSTANCE_TWITTERSOURCE_OUT_H_
#define SPL_OPER_INSTANCE_TWITTERSOURCE_OUT_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.h"


#define MY_OPERATOR TwitterSource_out$OP
#define MY_BASE_OPERATOR TwitterSource_out_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$className$0;
    SPL::rstring param$classLibrary$0;
    SPL::rstring param$classLibrary$1;
    SPL::rstring param$classLibrary$2;
    SPL::rstring param$classLibrary$3;
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
  // constructor
  MY_OPERATOR();

  // destructor
  virtual ~MY_OPERATOR(); 

  // notify port readiness
  void allPortsReady(); 

  // notify termination
  void prepareToShutdown(); 

  // processing for source and threaded operators   
  void process(uint32_t idx);
    
  // tuple processing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // punctuation processing
  void process(Punctuation const & punct, uint32_t port);
private:
  // members
  
  /** How we invoke actions on the Java Operator implementation */
  SPL::JNI::JNIBridgeInvoker* _bi;
  
  /* The instance of the JNIBridge used to wrap the Java Operator implementation */
  jobject _bridge;

  typedef void (*FP)(SPL::JNI::JNIBridgeInvoker&, jobject, NativeByteBuffer &, uint32_t);
  FP _fp;
  
  bool hasTupleLogic;
  
public:
    
  // handle byte buffers being send as is
  virtual void processRaw(NativeByteBuffer & buffer, uint32_t port)
  {
     (*_fp)(*_bi, _bridge, buffer, port);
  }
  
  //Java operators handle byte buffers directly
  virtual bool sendRawBufferData() { return !hasTupleLogic; }
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TWITTERSOURCE_OUT_H_


