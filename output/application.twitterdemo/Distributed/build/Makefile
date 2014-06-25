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
                build/operator/Sink.o 
SPL_PE_OBJS = build/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.o \
              build/pe/BeJwzCc7My44HAAcAAIp.o 
SPL_PE_BINS = bin/application.twitterdemo-a.dpe \
              bin/application.twitterdemo-b.dpe 

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

-include build/operator/Sink.d
build/operator/Sink.o: \
	    src/operator/Sink.h \
	    src/operator/Sink.cpp\
	    build/dep/operator/Sink.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Sink'
	@$(CXX) -o $@ -MD -c $(SPL_CXXFLAGS) src/operator/Sink.cpp

build/operator:
	-@mkdir -m 755 -p build/operator

functions: $(SPL_FUNCTIONS)

pes: $(SPL_PE_BINS)

build/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.o: \
	    src/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.h \
	    src/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe application.twitterdemo-a'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.cpp

PEapplication.twitterdemo-a = \
	    build/pe/BeJwzNA8pzywpSS0Kzi8tSk6Nzy8tiQcATt0HDj.o \
	    build/operator/TwitterSource_out.o \
	    build/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.o 

bin/application.twitterdemo-a.dpe: \
	$(PEapplication.twitterdemo-a) \
	build/dep/application.twitterdemo-a.dep \
	build/ldOptions
	@echo ' [LD-pe] pe application.twitterdemo-a'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/application.twitterdemo-a.dpe -fPIC -shared $(PEapplication.twitterdemo-a) -lstreams-stdtk-javaop -L /opt/ibm/java-x86_64-60/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/java-x86_64-60/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

build/pe/BeJwzCc7My44HAAcAAIp.o: \
	    src/pe/BeJwzCc7My44HAAcAAIp.h \
	    src/pe/BeJwzCc7My44HAAcAAIp.cpp  \
	    build/cppOptions \
	    | build/pe
	@echo ' [CXX-pe] pe application.twitterdemo-b'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/pe/BeJwzCc7My44HAAcAAIp.cpp

PEapplication.twitterdemo-b = \
	    build/pe/BeJwzCc7My44HAAcAAIp.o \
	    build/operator/Sink.o \
	    build/type/BeJwrMSk2KS1OLSo2yUnMS88pMs9ILM4oSUwvNilJrSgBALIkAu5.o 

bin/application.twitterdemo-b.dpe: \
	$(PEapplication.twitterdemo-b) \
	build/dep/application.twitterdemo-b.dep \
	build/ldOptions
	@echo ' [LD-pe] pe application.twitterdemo-b'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/application.twitterdemo-b.dpe -fPIC -shared $(PEapplication.twitterdemo-b) $(SPL_LDFLAGS)

build/pe:
	-@mkdir -m 755 build/pe

standalone: 
	@rm -f bin/standalone

