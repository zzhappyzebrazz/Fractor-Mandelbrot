#include <iostream>

class Machine {
public:
	Machine() {
		std::cout << "Machine ctor\n" << std::flush;
	}
	virtual void play() {
		std::cout << "Play Machine\n" << std::flush;
	}
	virtual void reset() {
		std::cout << "Reset Machine\n" << std::flush;
	}
	virtual ~Machine() {
		std::cout << "Machine dtor\n" << std::flush;
	}
};
class Instrument {
public:
	Instrument() {
		std::cout << "Instrument ctor\n" << std::flush;
	}
	virtual void play() {
		std::cout << "Play Instrument\n" << std::flush;
	}
	virtual void reset() {
		std::cout << "Reset Instrument\n" << std::flush;
	}
	virtual ~Instrument() {
		std::cout << "Instrument dtor\n" << std::flush;
	}
};
class Synthesizer : public Machine, public Instrument {
public:
	Synthesizer() {
		std::cout << "Synthesizer ctor\n" << std::flush;
	}
	virtual ~Synthesizer() {
		std::cout << "Synthesizer dtor\n" << std::flush;
	}
};

int mainMultiInherit() {

	Synthesizer* pSynth = new Synthesizer();
	pSynth->Machine::play();

	delete pSynth;
	std::cin.get();
	return 0;
}