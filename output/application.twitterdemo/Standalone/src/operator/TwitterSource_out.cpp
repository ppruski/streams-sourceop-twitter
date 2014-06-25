// eJy1lNFugjAUhtNXIbvYLqCAOB1ZlujFEh24JcwHOGAn1dKStuh4_01VxMzoi2bIFEtKvf_162_1zkUypLRDDQVPAxft1RrIhNRyYwgd_194yHIcrOuS4DGZbmWcrP2nxHuOEuHXcx4nw2EZq7tJFAcimW83M8qmMlmOR9FkPar6Tm4ZkyFiVF_05KHmJwlAqLSlfoj3zWpjfwnotLGhh_1RZ228IGZwzhXBQEmyEsCsoxg1Rh3eRhl1RouZsjUChb7eMRpX2YxgvQgLjgBPVQxkCpGRQEnZ3s9PDXFhyDd05yt27QSBtRWmnyKAlpLCOaSpA1Ci67mlI1Ly1KhlewAZxS_1s3yBx6Mpp85BCsbVM0zO3Bcx3NWIP_1OOBOS_1IdvU7QLzm_0UGaXp0JMlvEPDXtiFd_0jfTonfLel1S4JuSb9bctstGZxJdleAi0Qp5Ncf_1JuLABVImu6tlAn7WEgG5nMc5qByDUuzD6XvqwY_1GK7Juz7K3A_0Z9IQo


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
   osi->setParameter(env, setup, "filter", lit$1);
   osi->setParameter(env, setup, "filter", lit$2);
   osi->setParameter(env, setup, "filter", lit$3);
   osi->setParameter(env, setup, "filter", lit$4);
   osi->setParameter(env, setup, "filter", lit$5);
   osi->setParameter(env, setup, "filter", lit$6);
   osi->setParameter(env, setup, "filter", lit$7);


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
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    initRTC(*this, lit$7, "lit$7");
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
    addParameterValue ("filter", SPL::ConstValueHandle(lit$1));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$2));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$3));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$4));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$5));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$6));
    addParameterValue ("filter", SPL::ConstValueHandle(lit$7));
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






