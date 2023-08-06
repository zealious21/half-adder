#include <systemc.h>
using namespace std;

SC_MODULE(HALF_ADDER) {
	sc_in<bool> input_a;
	sc_in<bool> input_b;
	sc_out<bool> carry;
	sc_out<bool> sum;
	SC_CTOR(HALF_ADDER) {
		SC_METHOD(half_adder_logic);
		sensitive << input_a << input_b;
	}

	void half_adder_logic() {
		sum.write(input_a.read() ^ input_b.read());
		carry.write(input_a.read() && input_b.read());
	}

};

int sc_main(int, char* []) {
	sc_signal<bool> signal_a, signal_b, SUM, CARRY;
	HALF_ADDER half_adder("Half_adder");
	half_adder.input_a(signal_a);
	half_adder.input_b(signal_b);
	half_adder.carry(CARRY);
	half_adder.sum(SUM);

	signal_a = false;
	signal_b = false;
	sc_start(1, SC_NS);
	cout << "when A=0 AND B=0,sum =" << SUM.read() << "and carry=" << CARRY.read() << endl;

	signal_a = false;
	signal_b = true;
	sc_start(1, SC_NS);
	cout << "when A=0 AND B=1,sum =" << SUM.read() << "and carry=" << CARRY.read() << endl;


	signal_a = true;
	signal_b = false;
	sc_start(1, SC_NS);
	cout << "when A=1 AND B=0,sum =" << SUM.read() << "and carry=" << CARRY.read() << endl;

	signal_a = true;
	signal_b = true;
	sc_start(1, SC_NS);
	cout << "when A=1 AND B=1,sum =" << SUM.read() << "and carry=" << CARRY.read() << endl;

	return 0;
}
