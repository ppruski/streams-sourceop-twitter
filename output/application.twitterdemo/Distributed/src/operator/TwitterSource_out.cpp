// eJy1kmFLwzAQhslfKX7QD0u6WWEWEbYPwmY7hWw_14NrFNVualOS62X9vXNlKFQaKkkC44_0W5e3MHVaVkDiiNjuPlQSIKy01tc0HC4xmSgFKGTSXYVMwPNuW70TMfviTcjJqVTvl4XKXufpakkeGrw34h1dzyzXSSzHaT_0o4WwRGiJF6FhL8mcWwdWqk3hBBWmFIwH8K6lJopyBzDtodBJQ3ac7QWpWFrQCDaaEFuSa7AuQWUwrN71H6R6wA6g7TnL7ghE_1SirEbxZIVokYnMLNiGRJep_1kvaK8tKsS3sgWVSf0P_0gKFkdnIbbQfgGp0PIhrSId2C_1Ttwbqz4D67XCCgvkN_0k8sqv0zotRl_17uTAhMZWx56X5ze6Rklg_1yNr5up0nBf7pwgJcgbDxfTh8qNv0o8_0jeMdOFn4ATvoEBr


#include "./TwitterSource_out.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR TwitterSource_out_Base
#define MY_OPERATOR TwitterSource_out$OP






#include <dlfcn.h>

#include <SPL/Toolkit/JavaOp.h>
#include <SPL/Toolkit/RuntimeException.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
  /* Get a handle to the Java virtual machine */
  size_t vmOptionsCount = 0;
SPL::rstring vmOptions[vmOptionsCount];


  jboolean startedJVM;
  const std::string javaOpDir = getenv("STREAMS_INSTALL") ? std::string(getenv("STREAMS_INSTALL")) + "/toolkits/spl/spl/utility/JavaOp" : "/opt/ibm/InfoSphereStreams/toolkits/spl/spl/utility/JavaOp";

  SPL::JNI::JVMControl *jvmControl = SPL::JNI::JVMControl::getJVM(
     javaOpDir.c_str(), vmOptions, vmOptionsCount, &startedJVM);
   
  /* Attach to the JVM  for the duration of the initialization */
  JNIEnv * env = jvmControl->attach();

  /* How we invoke methods against an OperatorSetup instance */
  SPL::JNI::OpSetupInvoker* osi = jvmControl->getOpSetupInvoker();

  /* OperatorSetup instance specific to this operator */
  jobject setup = osi->newSetup(env, this); 

  /* SPL kind of operator being executed - added in 3.0 */
     osi->setParameter(env, setup, "[kind]", SPL::rstring("application::TwitterSource"));

   
  /**
     Pass the parameters into my OperatorSetup instance.
  */
     osi->setParameter(env, setup, "className", SPL::rstring("application.TwitterSource"));
   osi->setParameter(env, setup, "classLibrary", "../../../impl/java/bin");
   osi->setParameter(env, setup, "classLibrary", "../../../impl/lib/twitter4j-async-4.0.1.jar");
   osi->setParameter(env, setup, "classLibrary", "../../../impl/lib/twitter4j-core-4.0.1.jar");
   osi->setParameter(env, setup, "classLibrary", "../../../impl/lib/twitter4j-stream-4.0.1.jar");
   osi->setParameter(env, setup, "filter", lit$0);


  /**
    Pass input port information into the Java operator.
 
    Are logic clauses present.
   
    Pass the windowing information for each port as
    a list of values for the parameter '[window].N' where
    N is the index of the windowed input port.
  */
   hasTupleLogic = false;


  
  /* At this point all the initialization information has been
     passed to OperatorSetup. Create a JNIBridge instance object
     we use to communicate with the user's Operator implementation
     at runtime.
  */
  
  _bi = jvmControl->getBridgeInvoker();
  _bridge = _bi->newBridge(env, this, setup, startedJVM, (jboolean) false);
        
  /* Completed Java initialization, detach from the JVM */
  jvmControl->detach();

  _bi->construct();

  void * handle = dlopen("libstreams-stdtk-javaop.so", RTLD_LAZY);
  if (!handle) {
    const FormattableMessage& m = SPL_APPLICATION_RUNTIME_EXCEPTION("libstreams-stdtk-javaop.so");
    THROW_STRING(SPLRuntimeJavaOperator, m);
  }
  _fp = (FP) dlsym(handle, "callProcessTupleWithNativeByteBuffer");
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
    _bi->destruct();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
    _bi->allPortsReady(_bridge);
    createThreads(1);
}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
   _bi->shutdown(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
   _bi->complete(_bridge);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
   _bi->processTuple(_bridge, tuple, port);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
   _bi->processPunctuation(_bridge, punct, port);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("TwitterSource_out",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    PE & pe = PE::instance();
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    param$className$0 = SPL::rstring("application.TwitterSource");
    addParameterValue ("className", SPL::ConstValueHandle(param$className$0));
    param$classLibrary$0 = SPL::rstring("../../../impl/java/bin");
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$0));
    param$classLibrary$1 = SPL::rstring("../../../impl/lib/twitter4j-async-4.0.1.jar");
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$1));
    param$classLibrary$2 = SPL::rstring("../../../impl/lib/twitter4j-core-4.0.1.jar");
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$2));
    param$classLibrary$3 = SPL::rstring("../../../impl/lib/twitter4j-stream-4.0.1.jar");
    addParameterValue ("classLibrary", SPL::ConstValueHandle(param$classLibrary$3));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$0));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}






