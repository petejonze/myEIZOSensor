% compile to generate 32-bit mex file: EIZOSensor.mexw32	
cd ./Src
mex -v EIZOSensor.cpp -I../Lib ../Lib/x86/libEizMonCtrl_Cal.lib ../Lib/x86/libEizMonCtrl.lib -outdir ../Release/x86

% example use
cd ../Release/x86;          % move to .mex file directory (or could add this folder to the path for future use)
EIZOSensor('init');         % connect to EIZO monitor
EIZOSensor('skipcalib');    % or: EIZOSensor('calibrate')
x = EIZOSensor('measure')   % get xyZ measurement (Z should be near 0 since photomoter still inside monitor)
EIZOSensor('raise');        % raise the photometric swing sensor
x = EIZOSensor('m')         % make screen measurement (NB: only need first letter of the command)
EIZOSensor('lower');        % lower the sensor

% finish up, release memory
clear all