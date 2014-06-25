// eJxjdCwtyWdkNGQMKc8sKUktCs4vLUpOjc8vLQEAaL8IDq


#include "BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>

#include <SPL/Runtime/Utility/MessageFormatter.h>

#include <streams_boost/filesystem/operations.hpp>
namespace bf = streams_boost::filesystem;


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj


#include <SPL/Runtime/Type/SPLType.h>

static std::vector<std::string> * javaVMArgs() {
    std::vector<std::string> * result = new std::vector<std::string>();

    return result;
}


MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, javaVMArgs())
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}


void MYPE::registerResources(const std::string & applicationDir, const std::string & streamsInstallDir)
{
    SPL::RuntimeMessageFormatter & formatter = SPL::RuntimeMessageFormatter::instance(); 
    { 
        bf::path p(streamsInstallDir);
        p /= "/toolkits/com.ibm.streams.db";
        formatter.registerToolkit("com.ibm.streams.db", p.string()); 
    } 
    { 
        bf::path p(streamsInstallDir);
        p /= "/toolkits/com.ibm.streams.inet";
        formatter.registerToolkit("com.ibm.streams.inet", p.string()); 
    } 
    { 
        bf::path p(streamsInstallDir);
        p /= "/toolkits/com.ibm.streams.mining";
        formatter.registerToolkit("com.ibm.streams.mining", p.string()); 
    } 
}


MAKE_PE(SPL::MYPE);

