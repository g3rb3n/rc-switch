all: RCSend RCSnif

RCSend: RCSwitch.cpp RCSend.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

RCSnif: RCSwitch.cpp RCSnif.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

RCSend.cpp:
	g++ -g -c RCSend.cpp

RCSnif.cpp:
	g++ -g -c RCSnif.cpp

RCSwitch.cpp:
	g++ -g -c RCSwitch.cpp

clean:
	$(RM) *.o RCSend RCSnif
