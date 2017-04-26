include $(ROOTSYS)/etc/Makefile.arch

EVENTO        = Event.$(ObjSuf) EventDict.$(ObjSuf)
EVENTSO       = libEvent.$(DllSuf)
EVENT         = Event$(ExeSuf)

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

all:            $(EVENT)

$(EVENTSO):     $(EVENTO)
	$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)

$(EVENT):       $(EVENTSO)
	$(LD) $(LDFLAGS) $(EVENTO) $(LIBS) $(OutPutOpt)$@
	$(MT_EXE)
	@echo "$@ done"

Event.$(ObjSuf): Event.h

EventDict.$(SrcSuf): Event.h EventLinkDef.h
	@echo "Generating dictionary $@..."
	$(ROOTCLING) -f $@ -c $^

.$(SrcSuf).$(ObjSuf):
	$(CXX)  $(CXXFLAGS) -c $<

clean:
	@rm -f $(EVENTO) $(EVENTSO) *Dict.* *.pcm
