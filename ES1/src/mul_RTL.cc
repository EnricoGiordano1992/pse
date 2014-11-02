#include "mul_RTL.hh"

void mul_RTL :: elaborate_mul_FSM(void){

	sc_lv<11> exp1;
	sc_lv<53> mantissa1;

	sc_lv<11> exp2;
	sc_lv<53> mantissa2;

	sc_lv<11> exp_tot;
	sc_lv<11> mantissa_tot;

	if (reset.read() == 0){
		STATUS = SR;
	}
	else if (clk.read() == 1) {


		STATUS = NEXT_STATUS;

		switch(STATUS){
		//allo stato di reset non fa niente
		case SR:
			result.write(0);
			result_isready.write(0);

			break;

			//preparazione del sistema
		case S0:
			result.write(0);
			result_isready.write(0);
			vcl_number_a.write(0);
			vcl_number_b.write(0);
			vcl_result.write(0);

			break;

			//leggo i numeri
		case S0I:
			vcl_number_a.write(number_a.read());
			vcl_number_b.write(number_b.read());

			exp1 = (number_a.read().range(1,12));
			exp2 = (number_b.read().range(1,12));

			mantissa1 = (number_a.read().range(13,64));
			mantissa2 = (number_b.read().range(13,64));

			break;

			//sommo gli esponenti
		case S1:
			//exp_tot = exp1 + exp2;

			break;

			//polarizzo il risultato
		case S2:
			//exp_tot = exp_tot -1023;

			break;

			//prodotto tra mantisse
		case S3:

			break;

			//normalizzo il risultato
		case S4:

			break;

		case S5:

			break;

		case S6:

			break;

		case S7:

			break;

		case S8:

			break;

		case S9:

			break;

		}
	}
}


void mul_RTL :: elaborate_mul(void){

	/*
  NEXT_STATUS = STATUS;

  switch(STATUS){
    case Reset_ST:
      NEXT_STATUS = ST_0;
      break;

    case ST_0:
      if (number_isready.read() == 1){
        NEXT_STATUS = ST_1;
      } else {
        NEXT_STATUS = ST_0;
      }
      break;

    case ST_1:
      NEXT_STATUS = ST_2;
      break;

    case ST_2:
      if (Counter.read() < 16){
        NEXT_STATUS = ST_3;
      } else {
        NEXT_STATUS = ST_4;
      }
      break;

    case ST_3:
      NEXT_STATUS = ST_2;
      break;

    case ST_4:
      NEXT_STATUS = ST_0;
      break;
  }
	 */
}
