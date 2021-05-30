module FSM(Estado, clk, rst, output);

	input clk;
	input rst;

	output reg [2 : 0] output;


	parameter S0 = 3'b000;
	parameter S1 = 3'b001;
	parameter S2 = 3'b010;
	parameter S3 = 3'b011;
	parameter S4 = 3'b100;
	parameter S5 = 3'b101;
	parameter S6 = 3'b110;
	parameter S7 = 3'b111;

output reg [3 : 0] Estado;

assign Estado = state;
	
reg [3 : 0] state, next_state;

always @ (posedge clk or rst)
  begin
	if (rst)
		state <= S0;
	else
		state <= next_state;
  end

always @ (state)
  begin
	case (state)
		S0:
		  begin
			next_state = S1;
		  end

		S1:
		  begin
			next_state = S2;
		  end

		S2:
		  begin
			next_state = S3;
		  end

		S3:
		  begin
			next_state = S4;
		  end

		S4:
		  begin
			next_state = S5;
		  end

		S5:
		  begin
			next_state = S6;
		  end

		S6:
		  begin
			next_state = S7;
		  end

		S7:
		  begin
			next_state = S0;
		  end

		default: next_state = S0;
	endcase

  end


always @ (state)
  begin
	case(state)
		S0:
		  begin
			output= 0;
		  end
		S1:
		  begin
			output= 1;
		  end
		S2:
		  begin
			output= 2;
		  end
		S3:
		  begin
			output= 3;
		  end
		S4:
		  begin
			output= 4;
		  end
		S5:
		  begin
			output= 5;
		  end
		S6:
		  begin
			output= 6;
		  end
		S7:
		  begin
			output= 7;
		  end
		default:
		  begin
			output= 'bz;
		  end
	endcase

  end


endmodule
