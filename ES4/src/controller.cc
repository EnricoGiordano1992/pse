/*
 * controller.cc
 *
 *
*/

#include "controller.h"

// ! Constructor
void controller::set_attributes (){

	set_timestep( 20.0, sc_core::SC_MS); 	// module time step assignment of a of 10 ms
	k_out.set_delay(1.0); 						// set delay of port out to 2 samples
}
// [] rate,tstep,delay
void controller::initialize(){

	k_calc_pre = 0;
	err_calc_pre = 0;

}
// [] state
void controller::processing (){

	err_calc = err_in.read();

	k_calc = k_calc_pre + 100 * (err_calc - err_calc_pre) + get_timestep().to_seconds() * err_calc;

	k_calc_pre = k_calc;
	err_calc_pre = err_calc;

	k_out.write(k_calc);


}
// ! behavior



// [] ac-behavior

