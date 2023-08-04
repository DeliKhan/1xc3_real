#ifndef CONSTANTS_H
#define CONSTANTS_H

#define num_inputs 2          // there are 2 inputs in the first layer (x,y)
#define num_neurons_layer2 14 // layer 2 contains 40 neurons, each which will use specific weights to process the inputs
#define num_neurons_layer3 13 // layer 3 contains 20 neurons, which will take the values from layer 2 and use weights to further modify
#define num_outputs 2         // 2 neurons in the last layer that will output binary values
#define initial_range 0.2

#define Learning_rate 0.019 // rate to update the weights (0-1, but usually 0.01-0.0001) a lower number will take longer, but weights will be more accurate, vice versa for larger number
#define epochs 27001        // how many times to do the forward and backward pass

#define MAX_ROWS 48120    // how many rows are in data.txt
#define MAX_COLS 4        // how many columns are in data.txt
#define train_split 0.007 // 0.3 percent of data will be used to train the ANN

#endif // CONSTANTS_H