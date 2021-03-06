/*
 * p_plant.h
 *
 *
 */

#ifndef P_PLANT_H_
#define P_PLANT_H_

#include <systemc-ams.h>

#include <systemc.h>



SCA_TDF_MODULE (p_plant )
{

public:
	sca_tdf::sca_in<double> k_input;

	sca_tdf::sca_out<double> y_out;


	void set_attributes ();
	// [] rate,tstep,delay
	void initialize();
	// [] state
	void processing ();
	// ! behavior


	SCA_CTOR(p_plant)
	{
	}

private:

    // 3dB cut-off frequency in Hz
    double fc;
    // DC gain
    double h0;
	//funzione di trasferimento
	sca_tdf::sca_ltf_nd ltf_nd;

	sca_util::sca_vector<double> num, den; // numerator and denominator coefficients


};

#endif /* P_PLANT_H_ */
