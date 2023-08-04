#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 2
#define LEARNING_RATE 0.5
#define EPOCHS 10000

type def struct
{
    ​​​​​​​​ double weights[INPUT_SIZE];
    double bias;
}
​​​​​​​​ Perceptron;

double sigmoid(doublex)
{
    ​​return 1.0 / (1.0 + exp(-x));
}
double predict(Perceptron *perceptron, doubleinput[INPUT_SIZE])
{
    double sum = 0.0;
    for (int i = 0; i < INPUT_SIZE; ++i)
    {
        sum += perceptron->weights[i] * input[i]; // in1*w1_1 + in2*x1_2
    }
    return sigmoid(sum + perceptron->bias); // activation_function(in1*w1_1 + in2*x1_2 + b1)
    // sigmoid says if in f(x)
    // x => -inf so f(x)=0
    // x => +inf so f(x)=1
    // threshhold could be = 0.5!
}

void train(Perceptron *perceptron, doubleinput[INPUT_SIZE], intlabel)
{
    double predicted = predict(perceptron, input);
    double error = label - predicted;

    for (inti = 0; i < INPUT_SIZE; ++i)
    {
        perceptron->weights[i] += LEARNING_RATE * error * predicted * (1 - predicted) * input[i];
    }
    perceptron->bias += LEARNING_RATE * error * predicted * (1 - predicted);
}
int main()
{
    // Sample dataset for XOR function
    double inputs[][INPUT_SIZE] = {​​​​​​​​ {​​​​​​​​0.2, 0.8}​​​​​​​​,
                                   {​​​​​​​​0.7, 0.4}​​​​​​​​,
                                   {​​​​​​​​0.1, 0.1}​​​​​​​​}​​​​​​​​;
    intlabels[] = {​​​​​​​​1, 0, 1};

    Perceptron perceptron;

    // random initializing
    perceptron.weights[0] = 0.3;
    perceptron.weights[1] = 0.5;
    perceptron.bias = 0.1;
    // error = 0.36354745971843361

    // Training the perceptron
    for (int epoch = 0; epoch < EPOCHS; ++epoch)
    {
        ​​​​​​​​ for (int i = 0; i < 3; ++i)
        {
            ​​​​​​​​ // 4 is equal to the number of samples we have for train data
                train(&perceptron, inputs[i], labels[i]);
        }
        ​​​​​​​​
    }
    ​​​​​​​​

        // Validation
        printf("Predictions:\n");
    for (int i = 0; i < 3; ++i)
    {
        ​​​​​​​​ double prediction = predict(&perceptron, inputs[i]);
        printf("Input: (%f, %f), Prediction: %.2f, Label: %d\n", inputs[i][0], inputs[i][1], prediction, labels[i]);
    }
    ​​​​​​​​
}