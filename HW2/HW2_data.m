% Gonzales, Sierra
% CS776 - HW2

%% evalCPP() data
clc, clear all, close all, format compact
datacpp = load('CPP_stat_statistics.txt');

A = mean(datacpp);

called_eval = [0:100150];
subplot(2,1,1)
plot(called_eval, A,'g-')
xlabel('Number of EvalCPPs() called');
ylabel('Ave. Best Fitness Found So Far');
title('CPP - Average Best Fitnesses for 10 Statistical Runs');
%axis([0 100151 32 64]);

%hold on
datacpp1 = load('CPP1_stat_statistics.txt');
B = mean(datacpp1);
called_eval2 = [0:1150];
subplot(2,1,2)
plot(called_eval2,B,'r-');
xlabel('Number of EvalCPP1s() called');
ylabel('Ave. Best Fitness Found So Far');
title('CPP1 - Average Best Fitnesses for 10 Statistical Runs');
