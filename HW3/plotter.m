%% Gonzales, Sierra
% sierrag@nevada.unr.edu
% Homework 3
%https://github.com/sierra121314/CS-776/tree/master/HW3

%% DeJong Function 1
clc, clear all, close all, format compact

data1_low_min = load('F1-low-min.txt');
data1_low_max = load('F1-low-max.txt');
data1_low_ave = load('F1-low-ave.txt');


% eval() data

A1_low_min = mean(data1_low_min);
A1_low_max = mean(data1_low_max);
A1_low_ave = mean(data1_low_ave);
pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_low_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F1 - Average Min-Max-Ave Fitnesses with Low Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_low_max, 'b-')
plot(called_eval, A1_low_ave, 'r')
legend('min','max','ave')
%axis([0 100151 32 64]);

%%
clear all, close all, format compact
data1_high_min = load('F1-high-min.txt');
data1_high_max = load('F1-high-max.txt');
data1_high_ave = load('F1-high-ave.txt');

A1_high_min = mean(data1_high_min);
A1_high_max = mean(data1_high_max);
A1_high_ave = mean(data1_high_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_high_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F1 - Average Min-Max-Ave Fitnesses with High Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_high_max, 'b-')
plot(called_eval, A1_high_ave, 'r')
legend('min','max','ave')

%%
clear all, close all, format compact
data1_nom_min = load('F1-nom-min.txt');
data1_nom_max = load('F1-nom-max.txt');
data1_nom_ave = load('F1-nom-ave.txt');

A1_nom_min = mean(data1_nom_min);
A1_nom_max = mean(data1_nom_max);
A1_nom_ave = mean(data1_nom_ave);
pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_nom_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F1 - Average Min-Max-Ave Fitnesses with Nominal Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_nom_max, 'b-')
plot(called_eval, A1_nom_ave, 'r')
legend('min','max','ave')

%% DeJong Function 2
clc, clear all, close all, format compact

data2_low_min = load('F2-low-min.txt');
data2_low_max = load('F2-low-max.txt');
data2_low_ave = load('F2-low-ave.txt');


% eval() data

A1_low_min = mean(data2_low_min);
A1_low_max = mean(data2_low_max);
A1_low_ave = mean(data2_low_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_low_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F2 - Average Min-Max-Ave Fitnesses with Low Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_low_max, 'b-')
plot(called_eval, A1_low_ave, 'r')
legend('min','max','ave')
%axis([0 100151 32 64]);

%%
clear all, close all, format compact
data2_high_min = load('F2-high-min.txt');
data2_high_max = load('F2-high-max.txt');
data2_high_ave = load('F2-high-ave.txt');

A1_high_min = mean(data2_high_min);
A1_high_max = mean(data2_high_max);
A1_high_ave = mean(data2_high_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_high_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F2 - Average Min-Max-Ave Fitnesses with High Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_high_max, 'b-')
plot(called_eval, A1_high_ave, 'r')
legend('min','max','ave')

%%
clear all, close all, format compact
data2_nom_min = load('F2-nom-min.txt');
data2_nom_max = load('F2-nom-max.txt');
data2_nom_ave = load('F2-nom-ave.txt');

A1_nom_min = mean(data2_nom_min);
A1_nom_max = mean(data2_nom_max);
A1_nom_ave = mean(data2_nom_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_nom_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F2 - Average Min-Max-Ave Fitnesses with Nominal Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_nom_max, 'b-')
plot(called_eval, A1_nom_ave, 'r')
legend('min','max','ave')

%% DeJong Function 3
clc, clear all, close all, format compact

data3_low_min = load('F3-low-min.txt');
data3_low_max = load('F3-low-max.txt');
data3_low_ave = load('F3-low-ave.txt');


% eval() data

A1_low_min = mean(data3_low_min);
A1_low_max = mean(data3_low_max);
A1_low_ave = mean(data3_low_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_low_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F3 - Average Min-Max-Ave Fitnesses with Low Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_low_max, 'b-')
plot(called_eval, A1_low_ave, 'r')
legend('min','max','ave')
%axis([0 100151 32 64]);

%%
clear all, close all, format compact
data3_high_min = load('F3-high-min.txt');
data3_high_max = load('F3-high-max.txt');
data3_high_ave = load('F3-high-ave.txt');

A1_high_min = mean(data3_high_min);
A1_high_max = mean(data3_high_max);
A1_high_ave = mean(data3_high_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_high_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F3 - Average Min-Max-Ave Fitnesses with High Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_high_max, 'b-')
plot(called_eval, A1_high_ave, 'r')
legend('min','max','ave')

%%
clear all, close all, format compact
data3_nom_min = load('F3-nom-min.txt');
data3_nom_max = load('F3-nom-max.txt');
data3_nom_ave = load('F3-nom-ave.txt');

A1_nom_min = mean(data3_nom_min);
A1_nom_max = mean(data3_nom_max);
A1_nom_ave = mean(data3_nom_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_nom_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F3 - Average Min-Max-Ave Fitnesses with Nominal Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_nom_max, 'b-')
plot(called_eval, A1_nom_ave, 'r')
legend('min','max','ave')

%% DeJong Function 4
clc, clear all, close all, format compact

data4_low_min = load('F4-low-min.txt');
data4_low_max = load('F4-low-max.txt');
data4_low_ave = load('F4-low-ave.txt');


% eval() data

A1_low_min = mean(data4_low_min);
A1_low_max = mean(data4_low_max);
A1_low_ave = mean(data4_low_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_low_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F4 - Average Min-Max-Ave Fitnesses with Low Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_low_max, 'b-')
plot(called_eval, A1_low_ave, 'r')
legend('min','max','ave')
%axis([0 100151 32 64]);

%%
clear all, close all, format compact
data4_high_min = load('F4-high-min.txt');
data4_high_max = load('F4-high-max.txt');
data4_high_ave = load('F4-high-ave.txt');

A1_high_min = mean(data4_high_min);
A1_high_max = mean(data4_high_max);
A1_high_ave = mean(data4_high_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_high_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F4 - Average Min-Max-Ave Fitnesses with High Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_high_max, 'b-')
plot(called_eval, A1_high_ave, 'r')
legend('min','max','ave')

%%
clear all, close all, format compact
data4_nom_min = load('F4-nom-min.txt');
data4_nom_max = load('F4-nom-max.txt');
data4_nom_ave = load('F4-nom-ave.txt');

A1_nom_min = mean(data4_nom_min);
A1_nom_max = mean(data4_nom_max);
A1_nom_ave = mean(data4_nom_ave);

pop_size = 60;
called_eval = [0:79]*pop_size;
plot(called_eval, A1_nom_min,'g-')
xlabel('Number of Evals() called');
ylabel('Ave. Fitness Found So Far');
title('F4 - Average Min-Max-Ave Fitnesses with Nominal Mutations for 30 Statistical Runs');
hold on 
plot(called_eval, A1_nom_max, 'b-')
plot(called_eval, A1_nom_ave, 'r')
legend('min','max','ave')
