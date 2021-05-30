#include <iostream>
#include <vector>

#include <ctime> 



//---------------------------------------------------------------- Librerias creadas por nosotros
#include "clases.h"


//------------------------------ Algo nuestro
using namespace std;

//---------------------------------------------------------------------------------------



int main(int argc, char *argv[])
{
    unsigned t0, t1;
    string file;
    if (argc > 1)
    {
        file = argv[1];
    }
    else
    {
        file = "FMS_5";
    }
    
    string config = "Salidas/" + file + ".txt";
    string design = "Salidas/" + file + "_design.sv";
    string testbench = "Salidas/" + file + "_testbench.sv";


    python(file);

    t0=clock();
    
    cout << "******************" << endl
         << "*   Esto es C++  *" << endl
         << "******************" << endl;


    Moore FSM(config, testbench, design);
    FSM.abrir_archivo();
    FSM.config_variables_inputs();
    FSM.config_variables_outputs();
    FSM.config_variables_states();
    FSM.config_conditions();
    FSM.config_output_values();
    FSM.write_design();
    FSM.write_test();
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    if(argc < 1)
    {
        system("pause");
        return 0;
    }
    else
    {
        cout << "-------------------------------------- otro ----------------" << endl;
    }
}
//----------------------------------------------------------------------------------------