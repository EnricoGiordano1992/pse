/*
 * controller.h
 *
 *
 */

#ifndef CONTROLLER_ERR_H_
#define CONTROLLER_ERR_H_

#include <systemc-ams.h>

#include <systemc.h>

SCA_TDF_MODULE (controller_err )
{

public:
	sca_tdf::sca_de::sca_in<double> r_input;
	sca_tdf::sca_in<double> y_input;

	//sca_tdf::sca_out<double> k_out;
	sca_tdf::sca_out<double> err_out;


	double r_calc;
	double y_calc;

	double err_calc;
	double err_calc_pre;

	double k_calc;
	double k_calc_pre;

	ofstream log;

	void set_attributes ();
	// [] rate,tstep,delay
	void initialize();
	// [] state
	void processing ();
	// ! behavior


	SCA_CTOR(controller_err)
	{
	}

};

#endif /* CONTROLLER_ERR_H_ */
