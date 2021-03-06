/*
 * main.cc
 *
 *      Author: Matteo Calabria
 */

#include <systemc-ams.h>
#include <systemc.h>
#include "controller.h"
#include "controller_err.h"
#include "p_plant.h"
#include "testbench.h"

//----------LSF Modules----------

//----------ELN Modules----------

//----------TDF Modules----------

int sc_main(int argc, char* argv[]) {
    sc_core::sc_set_time_resolution(1.0, sc_core::SC_FS);

    //--------------------Local Ports Here--------------------
    sc_signal< sc_logic >         clock;

    sc_signal<double> r_in;
//    sca_tdf::sca_signal<double> e_t;
    sca_tdf::sca_signal<double> k_t;
    sca_tdf::sca_signal<double> y_out;
    sca_tdf::sca_signal<double> errore;

    //---------------------Modules Here-----------------------
    testbench testbench_module ("testbench");
    controller controller_istance("controller");
    controller_err controller_err_istance("controller_err");
    p_plant	physical_plant_istance("physical_plant");

    //-----------------Interconnections Here------------------
    testbench_module.number(r_in);
    testbench_module.clk(clock);

    //-----ELN Modules-----

    //-----TDF Modules-----
    controller_err_istance.r_input(r_in);
    controller_err_istance.y_input(y_out);
    controller_err_istance.err_out(errore);

    controller_istance.err_in(errore);   
    controller_istance.k_out(k_t);

    physical_plant_istance.k_input(k_t);
    physical_plant_istance.y_out(y_out);


    //-----LSF Modules-----

    //-----------------------Traces Here----------------------

    //-----------------------Start Here-----------------------
	sca_util::sca_trace_file* atf = sca_util::sca_create_tabular_trace_file("execution.log");
	sca_util::sca_trace(atf, r_in   , "r");
	sca_util::sca_trace(atf, y_out   , "y");

	
	sc_core::sc_start();
	
	//sca_util::sca_close_vcd_trace_file(atf);
	sca_util::sca_close_tabular_trace_file(atf);
    //--------------------Close Traces Here-------------------

    return 0;
}
