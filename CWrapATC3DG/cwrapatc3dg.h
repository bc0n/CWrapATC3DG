#pragma once


#include <iostream>
#include "ATC3DG.h"


#ifndef CWRAPATC3DG
#define CWRAPATC3DG

#ifndef M_PI
#   define M_PI 3.14159265358979323846
#endif
#ifndef M_DEG2RAD
#	define M_DEG2RAD 0.017453292519943
#endif

/* building a DLL */
#define DLLIMPORT __declspec (dllexport)

#ifdef __cplusplus
extern "C" { /* using a C++ compiler */
#endif

	typedef struct watc watc; //make class opaque to the wrapper---why do we want this?

	DLLIMPORT watc* createCWrapATC3DG(void);
	
	// errorCode = initializeAscension();
	// Resets the device, initializes what?
	DLLIMPORT int initializeAscension(void);

	//DLLIMPORT int closeAscension();

// Getters --------------------------------------------------------------------
	DLLIMPORT int getSystemCfg(double *measureRate, double *powerFreq, double *maxRange, 
		int *agcMode, int *numBoards, int *numSensors, int *numTransmitters, 
		int *runningTransmitterNum, bool *metricYN);

	//DLLIMPORT int getTransmitterCfg(int transmitterNum, TRANSMITTER_CONFIGURATION txCfg);

	//DLLIMPORT int getSensorCfg(int sensorNum, SENSOR_CONFIGURATION senCfg);

	//DLLIMPORT int getBoardCfg(int boardNum, BOARD_CONFIGURATION boardCfg);

	//GetAsynchronousRecord is expanded for each of the record types to help labview pass data structures
	// A call to asynchronous record returns with the most current sensor information, a POINT call
		DLLIMPORT int getAsynchronousSensorPositionAngles(int sensorNum, double *pos, double *ang);
		
		DLLIMPORT int getAsynchronousSensorPositionMatrix(int sensorNum, double *pos, double *rmx);

		DLLIMPORT int getAsynchronousSensorPositionQuaternion(int sensorNum, double *pos, double *quat);

		DLLIMPORT int getAsynchronousAllSensorsPositionQuaternion(double *pos0, double *quat0, double *pos1, double *quat1, double *pos2, double *quat2, double *pos3, double *quat3);

		DLLIMPORT int getSynchronousSensorPositionQuaternion(int sensorNum, double *pos, double *quat);

		DLLIMPORT int getSynchronousAllSensorsPositionQuaternion(double *pos0, double *quat0, double *pos1, double *quat1, double *pos2, double *quat2, double *pos3, double *quat3);

	//GetSynchronousRecord is expanded for each of the record types to help labview pass data structures
	// A call to synchronous places the unit in STREAM, returning a record and continuing to measure
	// such that future calls are answered from an 8-record buffer.
		// errorCode= getSynchronousSensorPositionMatrix( int sensorNum, double pos[x,y,z], double rmx[r11,r21,r31...]
		//DLLIMPORT int getSynchronousSensorPositionMatrix(int sensorNum, double *pos, double *rmx);

//DLLIMPORT int getSystemParameter(SYSTEM_PARAMETER_TYPE paramType)

//DLLIMPORT int getSensorParameter(); expanded
		DLLIMPORT int getSensorDataFormat(int sensorNum, int *dataRecordType);

		DLLIMPORT int getAngleAlign(int sensorNum, double *angleAER);

		DLLIMPORT int getSensorOffset(int sensorNum, double *posOffset);

		DLLIMPORT int getHemisphere(int sensorNum, int *hemisphereType);

		DLLIMPORT int getFilterACWideNotch(int sensorNum, int *filterOnOff);

		DLLIMPORT int getFilterACNarrowNotch(int sensorNum, int *filterOnOff);

		DLLIMPORT int getFilterDCAdaptive(int sensorNum, double *value);

		DLLIMPORT int getFilterAlphaAdaptive(int sensorNum, int *alphaMax, int *alphaMin, int *noiseVm, int *alphaOn);

		DLLIMPORT int getFilterLargeChange(int sensorNum, int *filterOnOff);

		DLLIMPORT int getQuality(int sensorNum, int *errorOffset, int *errorSensitivity, int *errorSlope, int *filterAlpha);

//DLLIMPORT int getTransmitterParameter(); expanded
		DLLIMPORT int getTxReferenceFrame(int transmitterNum, double *transmitterAER, int *transmitterXYZOn);

	//DLLIMPORT int getBirdError();

	//DLLIMPORT int getErrorText();

	//DLLIMPORT int getSensorStatus();

	//DLLIMPORT int getTransmitterStatus();

	//DLLIMPORT int getBoardStatus();

	//DLLIMPORT int getBoardParameter();

//Setters SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
	// SetSystemParameter expanded:
		DLLIMPORT int setSelectedTransmitter(int transmitterNum);

		//DLLIMPORT int setPowerLineFrequency(int setTo50)

		DLLIMPORT int setAutoGainMode(int autoTransGainOn);

		DLLIMPORT int setMeasurementRate(double *measureRateHz);

		//DLLIMPORT int setMaximumRange(double maxRange);

		DLLIMPORT int setMetric(int metricOn);

		//DLLIMPORT int setVitalProductData();
		//DLLIMPORT int setPostError();
		//DLLIMPORT int setDiagnosticTest();
		
		DLLIMPORT int setReportRate(int reportRate);
		
		//DLLIMPORT int setCommunicationsMedia();
		//DLLIMPORT int setLogging();

		DLLIMPORT int setResetOnInit(int resetOnOff);

		//DLLIMPORT int setAutoconfig(int numSensors);

	//DLLIMPORT int setSensorParameter(); expanded
		DLLIMPORT int setSensorDataFormat(int sensorNum, int dataRecordType);

		// angleAER in radians
		DLLIMPORT int setAngleAlign(int sensorNum, double *angleAER);

		DLLIMPORT int setSensorOffset(int sensorNum, double *posOffset);

		DLLIMPORT int setHemisphere(int sensorNum, int *hemisphereType);

		DLLIMPORT int setFilterACWideNotch(int sensorNum, int *filterOnOff);

		DLLIMPORT int setFilterACNarrowNotch(int sensorNum, int *filterOnOff);

		DLLIMPORT int setFilterDCAdaptive(int sensorNum, double *value);

		DLLIMPORT int setFilterAlphaAdaptive(int sensorNum, int *alphaMax, int *alphaMin, int *noiseVm, int *alphaOn);

		DLLIMPORT int setFilterLargeChange(int sensorNum, int *filterOnOff);

	//DLLIMPORT int setTransmitterParameter(); expanded
		DLLIMPORT int setTxReferenceFrame(int transmitterNum, double *transmitterANG, int *transmitterXYZOn);

	//DLLIMPORT int setBoardParameter();

//Save/set system configuration------------------------------------------------
	//DLLIMPORT int saveSystemConfiguration();
	//DLLIMPORT int restoreSystemConfiguration();


#ifdef __cplusplus
}
#endif


#endif //CWRAPATC3DG