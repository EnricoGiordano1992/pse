/*
 * controller_err.cc
 *
 *
 */

#include "controller_err.h"

// costruttore
// [] rate,tstep,delay
void controller_err::set_attributes (){

	set_timestep( 20.0, sc_core::SC_MS); 	// module time step assignment of a of 10 ms
	err_out.set_delay(1.0); 		// set delay of port out to 2 samples
}

// inizializzazioni
// [] state
void controller_err::initialize(){

	k_calc_pre = 0;
	err_calc_pre = 0;

}

// operazioni eseguite
// ! behavior
void controller_err::processing (){

	r_calc = r_input.read();
	y_calc = y_input.read();

	//cout << "ho letto questo numero dal FPM: " << r_calc << endl;

	err_calc = r_calc - y_calc;

	err_out.write(err_calc);
	
}
