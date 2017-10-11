clear all, clc, close all
% When importing new data

data1 = load('H4-max.txt');
data2 = load('H4-min.txt');
data3 = load('H4-ave.txt');
data4 = load('Best_fitness_history.txt');

time = [1:500];
generations = [1:2000];
stat_runs = [1:30];

A=mean(data1,2);%%average each column 
B=mean(data2,2);
% 
% subplot(2,1,1)
% plot(stat_runs, A)
% hold on
% plot(stat_runs, B)
% legend('max','min')
% xlabel('stat_runs');
% ylabel('fitness');

A1=mean(data1,1);%%average each column 
B1=mean(data2,1);

C1=mean(data3,1);
Ave_Best_Solution=mean(data4,2)
Best_Overall=min(data4)
Ba=B1<Ave_Best_Solution;
Baa=data2(Ba);
count = length(Baa);
reliabitiy=count/2000

% subplot(2,1,2)
plot(generations, A1)
hold on
plot(generations, B1)
plot(generations, C1)
legend('max','min','ave')
title('Berlin52.tsp');
xlabel('Generation');
ylabel('Average Fitness per Simulation');
speed = interp1(generations,B1,Ave_Best_Solution)


