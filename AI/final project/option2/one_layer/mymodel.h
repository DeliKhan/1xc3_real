#ifndef MYMODEL_H
#define MYMODEL_H

int parse_file(int num_train, double X_train[][num_inputs], double Y_train[][num_outputs],
               double X_val[][num_inputs], double Y_val[][num_outputs]);
double sigmoid(double x);
double random_double(double min, double max);
void ForwardPass(int num_train, double X_train[][num_inputs],
                 double W2[][num_inputs], double W3[][num_neurons_layer2],
                 double b2[][1], double b3[][1],
                 double a2[][num_train], double a3[][num_train]);
void BackwardPass(int num_train, double X_train[][num_inputs], double Y_train[][num_outputs],
                  double W2[][num_inputs], double W3[][num_neurons_layer2],
                  double b2[][1], double b3[][1],
                  double a2[][num_train], double a3[][num_train]);
void Evaluation(int ep, int num_train, int num_val, double X_train[][num_inputs], double Y_train[][num_outputs], double X_val[][num_inputs], double Y_val[][num_outputs],
                double W2[][num_inputs], double W3[][num_neurons_layer2],
                double b2[][1], double b3[][1],
                double a2[][num_train], double a3[][num_train]);

#endif // MYMODEL_H
