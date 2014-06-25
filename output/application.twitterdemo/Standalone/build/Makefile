# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

ifeq ($(CXX),)
  CXX=g++
endif
PKGCONFIG := /opt/ibm/InfoSphereStreams/bin/dst-pe-pkg-config.sh
PE_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
PE_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
PE_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(PE_INCLUDE) 
SPL_LDFLAGS = $(PE_LIB)

SPL_TYPES = build/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/TwitterSource_out.o \
                build/operator/Sink_file.o \
                build/operator/Sink_console.o 
SPL_PE_OBJS = build/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.o 
SPL_PE_BINS = bin/application.twitterdemo-a.dpe 

.PHONY: distclean clean all types functions operators pes svar

all: bin types functions operators pes svar standalone

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/pe build/svar build/standalone

bin:
	@mkdir -m 755 bin

types: $(SPL_TYPES)

build/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.o: \
	    src/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.h \
	    src/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring user,rstring lang,list<ustring> hashtag,rstring text>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.cpp

build/type:
	-@mkdir -m 755 build/type

operators: $(SPL_OPERATORS)

-include build/operator/TwitterSource_out.d
build/operator/TwitterSource_out.o: \
	    src/operator/TwitterSource_out.h \
	    src/operator/TwitterSource_out.cpp\
	    build/dep/operator/TwitterSource_out.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TwitterSource_out'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphereStreams/toolkits/spl/spl/utility/JavaOp/../../../impl/include -I /opt/ibm/java-x86_64-60/include -c $(SPL_CXXFLAGS) src/operator/TwitterSource_out.cpp

-include build/operator/Sink_file.d
build/operator/Sink_file.o: \
	    src/operator/Sink_file.h \
	    src/operator/Sink_file.cpp\
	    build/dep/operator/Sink_file.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Sink_file'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphereStreams/toolkits/spl/impl/include -c $(SPL_CXXFLAGS) src/operator/Sink_file.cpp

-include build/operator/Sink_console.d
build/operator/Sink_console.o: \
	    src/operator/Sink_console.h \
	    src/operator/Sink_console.cpp\
	    build/dep/operator/Sink_console.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Sink_console'
	@$(CXX) -o $@ -MD -c $(SPL_CXXFLAGS) src/operator/Sink_console.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

pes: $(SPL_PE_BINS)

build/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.o: \
	    src/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.h \
	    src/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe application.twitterdemo-a'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.cpp

PEapplication.twitterdemo-a = \
	    build/pe/BeJwzNArOzMuOT87PK87PSY23BPPSMoFMQ_1OQ8sySktSi4PzSouTU_0PzSkngAlA8RC4.o \
	    build/operator/TwitterSource_out.o \
	    build/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.o \
	    build/operator/Sink_file.o \
	    build/operator/Sink_console.o 

bin/application.twitterdemo-a.dpe: \
	$(PEapplication.twitterdemo-a) \
	build/dep/application.twitterdemo-a.dep \
	build/ldOptions
	@echo ' [LD-pe] pe application.twitterdemo-a'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/application.twitterdemo-a.dpe -fPIC -shared $(PEapplication.twitterdemo-a) -lstreams-stdtk-javaop -L /opt/ibm/java-x86_64-60/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/java-x86_64-60/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime -lstreams-stdtk-runtime $(SPL_LDFLAGS)

build/pe:
	-@mkdir -m 755 build/pe

standalone: bin/standalone 

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/standalone build/standalone/standalone.o $(PE_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/application.twitterdemo
build/standalone:
	-@mkdir -m 755 build/standalone

