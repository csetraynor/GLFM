%% demo TOY IMAGES
close
clear
addpath(genpath('../../src/GLFMmatlab/'));
addpath(genpath('../../src/Ccode/'));

randn('seed',round(sum(1e5*clock)));
rand('seed',round(sum(1e5*clock)));

%% GENERATIVE MODEL
N =1000;
s2x = 0.5;
[data,gT] = generate_toy_images(N,s2x);

%% INITIALIZATION + PARAMETER SETTINGS
Zini = double(rand(N,1)>0.8);
hidden.Z = Zini;

% define params
params.missing = -10;
params.s2Y = 1;    % Variance of the Gaussian prior on the auxiliary variables (pseudoo-observations) Y
params.s2u = .01;
params.s2B = 1;      % Variance of the Gaussian prior of the weigting matrices B
params.alpha = 5;    % Concentration parameter of the IBP
params.Niter = 100;  % Number of iterations for the gibbs sampler
params.maxK = 10;
params.bias = 0;
params.func = 1*ones(1,size(data.X,2));

%% INFERENCE
hidden = IBPsampler_run(data, hidden, params);

%% PLOT REAL Vs INFERRED LATENT FEATURE
Kest = size(hidden.B,2);
Zp = eye(Kest);
% compute observations resulting when each of the latent features is active
X_map = IBPsampler_MAP(data.C, Zp, hidden);

figure(1); title('Ground truth');
for k=1:size(gT.B,1)
    subplot(3,3,k);
    imagesc(reshape(gT.B(k,:), [6 6]));
end
hold off;

figure(2); title('Inferred Latent Features');
for k=1:Kest
    subplot(3,3,k);
    imagesc(reshape(X_map(k,:), [6 6]));
end
hold off;