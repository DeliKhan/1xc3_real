#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sodium.h> // For randombytes_buf function

#include "constants.h"
#include "mymodel.h"

int main()
{
    // Initialize the 2D array to store the data
    // double data[MAX_ROWS][MAX_COLS];
    int num_train = 120;
    int num_val = MAX_ROWS - 120;

    double X_train[num_train][num_inputs];
    double Y_train[num_train][num_outputs];
    double X_val[num_val][num_inputs];
    double Y_val[num_val][num_outputs];
    parse_file(num_train, X_train, Y_train, X_val, Y_val);
    // int num_train = MAX_ROWS *train_split;
    // int num_val = MAX_ROWS *(1-train_split); ##########################################################################

    double W2[num_neurons_layer2][num_inputs];
    double b2[num_neurons_layer2][1]; // only one bias (wouldn't that be 0 then?)

    double W3[num_neurons_layer3][num_neurons_layer2];
    double b3[num_neurons_layer3][1];

    double W4[num_outputs][num_neurons_layer3];
    double b4[num_outputs][1];

    // Initialize W2 and b2 arrays with random values between -a and +a
    for (int i = 0; i < num_neurons_layer2; i++)
    {
        for (int j = 0; j < num_inputs; j++)
        {
            W2[i][j] = random_double(-initial_range, initial_range);
        }
        b2[i][0] = random_double(-initial_range, initial_range);
    }

    // Initialize W3 and b3 arrays with random values between -a and +a
    for (int i = 0; i < num_neurons_layer3; i++)
    {
        for (int j = 0; j < num_neurons_layer2; j++)
        {
            W3[i][j] = random_double(-initial_range, initial_range);
        }
        b3[i][0] = random_double(-initial_range, initial_range);
    }

    // Initialize W4 and b4 arrays with random values between -a and +a
    for (int i = 0; i < num_outputs; i++)
    {
        for (int j = 0; j < num_neurons_layer3; j++)
        {
            W4[i][j] = random_double(-initial_range, initial_range);
        }
        b4[i][0] = random_double(-initial_range, initial_range);
    }

    // the final output of each layer, every column is for a set of inputs
    double a2[num_neurons_layer2][num_train];
    double a3[num_neurons_layer3][num_train];
    double a4[num_outputs][num_train];

    for (int ep = 0; ep < epochs; ep++)
    {
        ForwardPass(num_train, X_train,
                    W2, W3, W4,
                    b2, b3, b4,
                    a2, a3, a4); // forward pass goes through the entire sample to get output for all sample
        // the backward pass will compare this to the answers to see amount of error
        BackwardPass(num_train, X_train, Y_train,
                     W2, W3, W4,
                     b2, b3, b4,
                     a2, a3, a4);
        // every hundred iterations, print out information regarding accuracy
        if (ep % 100 == 0)
        {
            Evaluation(ep, num_train, num_val, X_train, Y_train, X_val, Y_val,
                       W2, W3, W4,
                       b2, b3, b4,
                       a2, a3);
        }
        //     for (int i = 0; i < num_train; i++)
        //     {
        //         printf("%lf,  %lf", a4_eval_train[0][i], a4_eval_train[1][i]);
        //         printf("      %lf,  %lf\n", Y_train[i][0], Y_train[i][1]);

        //         break;
        //     }

        // ###################################################### Evaluation of accuracies ends
    }
}
